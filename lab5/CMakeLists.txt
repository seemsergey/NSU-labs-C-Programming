cmake_minimum_required(VERSION 3.5.1)
project(lab5 C)

set(SRC src/main.c
        src/lib/huffman.c
        src/lib/huffman.h
        src/lib/encoder.c
        src/lib/decoder.c
        src/lib/encoder.h
        src/lib/decoder.h
        src/lib/config.h
)

add_executable(${PROJECT_NAME} ${SRC})

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../modules")
include(common_lab)
