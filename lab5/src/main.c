#include "lib/decoder.h"
#include "lib/encoder.h"
#include "lib/config.h"

#include <stdio.h>

int main(void) {
    SET_BINARY_MODE(stdin);
    SET_BINARY_MODE(stdout);

    const unsigned char mode = fgetc(stdin);
    if (mode == MODE_COMPRESS) {
        Encode();
    } else if (mode == MODE_DECODE) {
        Decode();
    }

    return EXIT_SUCCESS;
}
