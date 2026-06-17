//
// Created by SeemS on 22.02.2026.
//

#ifndef LAB5_CONFIG_H
#define LAB5_CONFIG_H

// Режимы работы
#define MODE_COMPRESS 'c'
#define MODE_DECODE 'd'

// Размер алфавита ASCII
#define ALPHABET_SIZE 256


#ifdef _WIN32 //я не знал что так можно, спасибо инету
#include <fcntl.h>
#include <io.h>
#define SET_BINARY_MODE(stream) _setmode(_fileno(stream), _O_BINARY)
#else
#define SET_BINARY_MODE(stream) ((void)0)
#endif


#endif //LAB5_CONFIG_H
