#!/bin/sh

#
# Show usage if missing source file
#
if [ "$#" -ne 1 ]; then
    echo "Usage: ./compile.sh SOURCE_FILENAME\n"
    exit 1
fi

SRC_FILE=${1}
OUTPUT_FILE=${SRC_FILE/.c/}

#
# Echo full command
#
# echo "cc ${SRC_FILE} -I/opt/homebrew/Cellar/raylib/4.2.0/include -L/opt/homebrew/Cellar/raylib/4.2.0/lib -lraylib  -o ${OUTPUT_FILE} && ./${OUTPUT_FILE}"
echo "cc ${SRC_FILE} `pkg-config --libs --cflags raylib` -o ${OUTPUT_FILE} && ./${OUTPUT_FILE}"

#
# Execute full command
#
cc ${SRC_FILE} `pkg-config --libs --cflags raylib`  -o ${OUTPUT_FILE} && ./${OUTPUT_FILE}
