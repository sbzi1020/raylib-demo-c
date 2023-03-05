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
OUTPUT_FILE=${OUTPUT_FILE/src\//}

#
# Echo full command
#
echo "cc ${SRC_FILE} `pkg-config --libs --cflags raylib` -o build/${OUTPUT_FILE} && build/${OUTPUT_FILE}"

#
# Execute full command
#
cc ${SRC_FILE} `pkg-config --libs --cflags raylib`  -o build/${OUTPUT_FILE} && build/${OUTPUT_FILE}
