
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

WARNINGS = -Wall -W -Wextra -Wno-unused-variable -Wno-unused-const-variable -Wno-unused-function -Wno-unused-parameter -Wno-unused-but-set-variable
WARNINGS += -Wno-maybe-uninitialized -Wno-misleading-indentation -Wno-unused-result -Wno-clobbered -Wno-format-overflow

INCLUDES = -I. -Iinclude -I../include

OPTIMIZE = -Os --std=c99

CFLAGS = $(OPTIMIZE) $(WARNINGS) $(INCLUDES)
CFLAGS += -DSIMAGE_MAJOR_VERSION="1" -DSIMAGE_MINOR_VERSION="2" -DSIMAGE_MICRO_VERSION="3" -DSIMAGE_MPEG2ENC_SUPPORT=1

all: mpeg2encode

mpeg2encode:
	cd mpeg2enc; make 'CC=$(CC)' 'CFLAGS=$(CFLAGS)'
        # copy encoder to test catalog
	cp ./mpeg2enc/mpeg2encode ./input_base/

clean:
	cd mpeg2enc; make clean
