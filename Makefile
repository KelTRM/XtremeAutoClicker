CC=gcc
CF=-o2 -mwin32 -std=c99

FIL=./src/main.c
OBJ=./bin/main.o

OUT=./bin/XtremeAutoClicker.exe
OUT_DEBUG=./bin/debug.exe

INCLUDE_DIR=Include

META_SRC=metadata/meta.rc
META_OUT=bin/metadata.res

ifeq (${DEBUG}, 1)
all:
	make debug clean
	gdb ${OUT_DEBUG}
else
all:
	make build clean
endif

debug:
	${CC} -g ${FIL} -I ${INCLUDE_DIR} -c -o ${OBJ}
	${CC} -g ${CF} ${OBJ} -I ${INCLUDE_DIR} -o ${OUT_DEBUG}

build:
	windres ${META_SRC} -O coff -o ${META_OUT}
	${CC} ${FIL} -I ${INCLUDE_DIR} -c -o ${OBJ}
	${CC} ${CF} ${OBJ} -I ${INCLUDE_DIR} -o ${OUT} ${META_OUT}

clean:
	del bin\*.o
	del bin\*.res

run:
	${OUT}