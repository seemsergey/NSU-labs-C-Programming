cmake_minimum_required(VERSION 3.5.1)
project(lab0 C)

set(SRC src/main.c
        src/lib/ToDecimal.c
        src/lib/ToDecimal.h
        src/lib/FromDecimal.c
        src/lib/FromDecimal.h)

add_executable(${PROJECT_NAME} ${SRC})

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../modules")
include(common_lab)
