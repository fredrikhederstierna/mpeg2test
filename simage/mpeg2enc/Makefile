# Makefile for mpeg2encode

# Copyright (C) 1996, MPEG Software Simulation Group. All Rights Reserved. */

#
# Disclaimer of Warranty
#
# These software programs are available to the user without any license fee or
# royalty on an "as is" basis.  The MPEG Software Simulation Group disclaims
# any and all warranties, whether express, implied, or statuary, including any
# implied warranties or merchantability or of fitness for a particular
# purpose.  In no event shall the copyright-holder be liable for any
# incidental, punitive, or consequential damages of any kind whatsoever
# arising from the use of these programs.
#
# This disclaimer of warranty extends to the user of these programs and user's
# customers, employees, agents, transferees, successors, and assigns.
#
# The MPEG Software Simulation Group does not represent or warrant that the
# programs furnished hereunder are free of infringement of any third-party
# patents.
#
# Commercial implementations of MPEG-1 and MPEG-2 video, including shareware,
# are subject to royalty fees to patent holders.  Many of these patents are
# general enough such that they are unavoidable regardless of implementation
# design.
#
#

# select one of the following CC CFLAGS settings

#
# GNU gcc
#
CC = gcc
CFLAGS = -O2 -Wall -Iinclude -I../include -I../src -DSIMAGE_MAJOR_VERSION="1" -DSIMAGE_MINOR_VERSION="2" -DSIMAGE_MICRO_VERSION="3"

OBJ = ../src/movie.o ../src/params.o mpeg2enc.o api.o conform.o putseq.o putpic.o puthdr.o putmpg.o putvlc.o putbits.o motion.o predict.o readpic.o writepic.o transfrm.o fdctref.o idct.o quantize.o ratectl.o stats.o ../src/simage12.o ../src/simage.o ../src/simage_write.o

all: mpeg2encode

clean:
	rm -f ../src/*.o *.o *% core mpeg2encode

mpeg2encode: $(OBJ)
	$(CC) $(CFLAGS) -o mpeg2encode $(OBJ) -lm

simage_write.o  : ../src/simage_write.c config.h
simage.o  : ../src/simage.c config.h
simage12.o  : ../src/simage12.c config.h
params.o  : ../src/params.c config.h
movie.o  : ../src/movie.c config.h
conform.o : conform.c config.h global.h mpeg2enc.h 
fdctref.o : fdctref.c config.h 
idct.o : idct.c config.h 
motion.o : motion.c config.h global.h mpeg2enc.h 
mpeg2enc.o : mpeg2enc.c config.h global.h mpeg2enc.h 
predict.o : predict.c config.h global.h mpeg2enc.h 
putbits.o : putbits.c config.h 
puthdr.o : puthdr.c config.h global.h mpeg2enc.h 
putmpg.o : putmpg.c config.h global.h mpeg2enc.h 
putpic.o : putpic.c config.h global.h mpeg2enc.h 
putseq.o : putseq.c config.h global.h mpeg2enc.h 
putvlc.o : putvlc.c config.h global.h mpeg2enc.h vlc.h 
quantize.o : quantize.c config.h global.h mpeg2enc.h 
ratectl.o : ratectl.c config.h global.h mpeg2enc.h 
readpic.o : readpic.c config.h global.h mpeg2enc.h 
stats.o : stats.c config.h global.h mpeg2enc.h 
transfrm.o : transfrm.c config.h global.h mpeg2enc.h 
writepic.o : writepic.c config.h global.h mpeg2enc.h 
api.o : api.c config.h global.h mpeg2enc.h 
