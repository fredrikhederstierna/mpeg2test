
# uncomment the following two lines if you want to include X11 support
# (mpeg2decode)

#USE_DISP = -DDISPLAY
#LIBS = -lX11

# uncomment the following two lines if you want to use shared memory
# (faster display if server and client run on the same machine)
# (mpeg2decode)

#USE_SHMEM = -DSH_MEM
#LIBS = -lXext -lX11

# if your X11 include files / libraries are in a non standard location:
# set INCLUDEDIR to -I followed by the appropriate include file path and
# set LIBRARYDIR to -L followed by the appropriate library path
# (mpeg2decode)

#INCLUDEDIR = -I/usr/openwin/include
#LIBRARYDIR = -L/usr/openwin/lib

# select one of the following CC CFLAGS settings

#
# GNU gcc
#
CC = gcc
CFLAGS = -Os -I.

all: mpeg2encode

mpeg2encode:
	cd mpeg2enc; make 'CC=$(CC)' 'CFLAGS=$(CFLAGS)'

clean:
	cd mpeg2enc; make clean
