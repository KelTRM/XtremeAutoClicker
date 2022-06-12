CC=gcc
CF=-o3

FIL=./src/main.c
OBJ=./bin/main.o

OUT=./bin/out.exe

INCLUDE_DIR=Include

META_SRC=metadata/meta.rc
META_OUT=bin/metadata.res

all:
	make build clean

build:
	windres ${META_SRC} -O coff -o ${META_OUT}
	${CC} ${FIL} -I ${INCLUDE_DIR} -c -o ${OBJ}
	${CC} ${CF} ${OBJ} -I ${INCLUDE_DIR} -o ${OUT} ${META_OUT}

clean:
	del bin\*.o
	del bin\*.res

run:
	${OUT}