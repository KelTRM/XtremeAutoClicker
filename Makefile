CC=gcc
CF=-o3

FIL=./src/main.c
OBJ=./objs/main.o

OFW=./bin/out.exe
OFL=./bin/out

INCLUDE_DIR=Include

META_SRC=metadata/meta.rc
META_OUT=bin/metadata.res

all:
	make build clean

build:
	windres ${META_SRC} -O coff -o ${META_OUT}
	${CC} ${FIL} -I ${INCLUDE_DIR} -c -o ${OBJ}
	${CC} ${CF} ${OBJ} -I ${INCLUDE_DIR} -o ${OFW} ${META_OUT}

clean:
	del objs\**

run:
	${OFW}