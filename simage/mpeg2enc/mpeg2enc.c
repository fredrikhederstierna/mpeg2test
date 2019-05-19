/* mpeg2enc.c, main() and parameter file reading                            */

/* Copyright (C) 1996, MPEG Software Simulation Group. All Rights Reserved. */

/*
 * Disclaimer of Warranty
 *
 * These software programs are available to the user without any license fee or
 * royalty on an "as is" basis.  The MPEG Software Simulation Group disclaims
 * any and all warranties, whether express, implied, or statuary, including any
 * implied warranties or merchantability or of fitness for a particular
 * purpose.  In no event shall the copyright-holder be liable for any
 * incidental, punitive, or consequential damages of any kind whatsoever
 * arising from the use of these programs.
 *
 * This disclaimer of warranty extends to the user of these programs and user's
 * customers, employees, agents, transferees, successors, and assigns.
 *
 * The MPEG Software Simulation Group does not represent or warrant that the
 * programs furnished hereunder are free of infringement of any third-party
 * patents.
 *
 * Commercial implementations of MPEG-1 and MPEG-2 video, including shareware,
 * are subject to royalty fees to patent holders.  Many of these patents are
 * general enough such that they are unavoidable regardless of implementation
 * design.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#define GLOBAL /* used by global.h */
#include "config.h"
#include "global.h"
#include "api.h"

#include <simage_private.h>

//--------------------------------------------------
static void error_cb(void * userdata, const char *text)
{
  (void)fprintf(stderr, "Error: %s\n", text);
  (void)fflush(stderr);
}

static void warning_cb(void * userdata, const char *text)
{
  (void)fprintf(stderr, "Warning: %s\n", text);
  (void)fflush(stderr);
}

static int progress_cb(void * userdata, float sub, int current_frame, int num_frames)
{
  char buffer[256];

  int logframes = (int)log10(num_frames) + 1;
  (void)sprintf(buffer, "\rwriting frame: %%%dd / %%%dd  -- %%03.1f%%%%  ",
		logframes, logframes);

  (void)fprintf(stdout, buffer, current_frame + 1, num_frames, sub * 100.0);
  (void)fflush(stdout);
  return 1;
}

//--------------------------------------------------
int main(int argc, char *argv[])
{
  if (argc!=3)
  {
    //printf("\n%s, %s\n",version,author);
    printf("Usage: mpeg2encode in.par out.m2v\n");
    exit(0);
  }

  // outfile to write encoded video to
  const char *filename = argv[2];

  s_movie movie;
  s_params params;
  s_image image;

#if 0
  // alternative dynamic alloc of params and movie
  s_params * params = s_params_create();
  if (params == NULL) {
    printf("params NULL\n");
    exit(1);
  }
  s_movie * movie = s_movie_create("out_movie.m2v", params);
  if (movie == NULL) {
    error_cb(NULL, "could not create movie file");
    if (simage_get_last_error()) {
      error_cb(NULL, simage_get_last_error());
    }
    exit(1);
  }
  void *vp = s_image_data(&image);
  s_image *image_h = s_movie_get_image(movie, &image, params);
  s_params_destroy(params);
#endif

  // setup movie params
  s_params_set(&params,
	       "mime-type", S_STRING_PARAM_TYPE, "video/mpeg",
	       "width",  S_INTEGER_PARAM_TYPE, 704, // FREDRIK userpars.width,
	       "height", S_INTEGER_PARAM_TYPE, 576, //FREDRIK userpars.height,

               //"num frames", S_INTEGER_PARAM_TYPE, nr_frames,
               //"num frames", S_INTEGER_PARAM_TYPE, 9,

	       "error callback",    S_FUNCTION_PARAM_TYPE, error_cb,
	       "warning callback",  S_FUNCTION_PARAM_TYPE, warning_cb,
	       "progress callback", S_FUNCTION_PARAM_TYPE, progress_cb,
	       /* use to specify userdata for all callbacks */
	       "callback userdata", S_POINTER_PARAM_TYPE, NULL,

	       /* use to encode as mpeg1 instead of mpeg2 */
               //	       "mpeg1", S_BOOL_PARAM_TYPE, 0,

	       /* use to specify a parameter file */
	       "parameter file", S_STRING_PARAM_TYPE, "input_base_4CIF_96bps_15.par",

	       /* use to specify constraints coded parameter constraints for mpeg2 files,
		  such as bitrate, sample rate, and maximum allowed motion vector range.

		  Value Meaning         Typical use
		  ----  --------------- -----------------------------------------------
		  4     High Level      HDTV production rates: e.g. 1920 x 1080 x 30 Hz
		  6     High 1440 Level HDTV consumer rates: e.g. 1440 x 960 x 30 Hz
		  8     Main Level      CCIR 601 rates: e.g. 720 x 480 x 30 Hz
		  10    Low Level       SIF video rate: e.g. 352 x 240 x 30 Hz
	       */
               "level", S_INTEGER_PARAM_TYPE, 6, //FREDRIK userpars.constraintslevel,

	       /* NULL means no more params */
	       NULL);

  printf("mpeg2enc: Create movie filename %s\n", filename);
  int x = mpeg2enc_movie_create(filename, &movie, &params);
  int y = mpeg2enc_movie_put(&movie, &image, &params);
  mpeg2enc_movie_close(&movie);

  printf("mpeg2enc: Done movie result_create: %d result_put: %d\n", x, y);

  return 0;
}
