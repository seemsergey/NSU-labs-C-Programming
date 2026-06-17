cmake_minimum_required(VERSION 3.5.1)
project(lab4 C)

set(SRC src/main.c
        src/lib/stack.c
        src/lib/stack.h
        src/lib/operatorStruct.h
        src/lib/createPostfixForm.c
        src/lib/createPostfixForm.h
        src/lib/calculatePostForm.c
        src/lib/calculatePostForm.h
)

add_executable(${PROJECT_NAME} ${SRC})

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../modules")
include(common_lab)
