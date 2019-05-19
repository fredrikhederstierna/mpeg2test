#ifndef SIMAGE_PRIVATE_H
#define SIMAGE_PRIVATE_H

/*
 * Copyright (c) Kongsberg Oil & Gas Technologies
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include "simage.h"

#ifdef __cplusplus
extern "C" {
#endif

  struct simage_open_funcs {
    void * (*open_func)(const char * filename,
                        int * w, int * h, int * nc);
    int (*read_line_func)(void * opendata, int y, unsigned char * buf);
    int (*next_line_func)(void * opendata, unsigned char * buf);
    void (*close_func)(void * opendata);
  };

  struct simage_image_s {
    int width;
    int height;
    int components;
    int didalloc;
    int order;
    unsigned char * data;
    /* added for simage 1.6 */
    void * opendata;
    int oktoreadall;
    char * openfilename;
    struct simage_open_funcs openfuncs;
  };

  s_params * s_movie_params(s_movie * movie);

  void * s_stream_context_get(s_stream *stream);
  void s_stream_context_set(s_stream *stream, void *context);

  /** FREDRIK: MOVED STRUCT DEFS FROM <movie.c> */
  struct simage_movie_s {
    char * filename;
    s_movie_open_func * open;
    s_movie_create_func * create;
    s_movie_get_func * get;
    s_movie_put_func * put;
    s_movie_close_func * close;
    s_params * params;
  };
  struct simage_movie_importer {
    s_movie_open_func * open;
    s_movie_get_func * get;
    s_movie_close_func * close;
    struct simage_movie_importer * next;
  };
  struct simage_movie_exporter {
    s_movie_create_func * create;
    s_movie_put_func * put;
    s_movie_close_func * close;
    struct simage_movie_exporter * next;
  };
  // FIXME: convert access to these variables into the singleton
  // pattern. 20010917 mortene.
  static struct simage_movie_importer * importers;
  static struct simage_movie_exporter * exporters;
  /** FREDRIK: END MOVED STRUCT DEFS FROM <movie.c> */

  /** FREDRIK: MOVED STRUCT DEFS FROM <params.c> */
  struct simage_param_data {
    int type;
    char * name;
    union {
      int integerdata;
      float floatdata;
      double doubledata;
      char * stringdata;
      void * pointerdata;
      void (*functiondata)();
    } data;
    struct simage_param_data * next;
  };
  typedef void s_generic_func();
  struct simage_parameters_s {
    struct simage_param_data * list;
  };
  /** FREDRIK: END MOVED STRUCT DEFS FROM <params.c> */

#ifdef __cplusplus
}
#endif

#endif /* SIMAGE_PRIVATE_H */
