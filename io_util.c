//
// Created by liz on 2/1/23.
//

#include "io_util.h"

size_t read_uint32_t(uint32_t *output, FILE *stream) {
    uint8_t result[4];
    size_t bytes_read;
    bytes_read = fread(result, 1, 4, stream);
    if (bytes_read != 4)
        return bytes_read;
    *output = (uint32_t) result[0];
    *output <<= 8;
    *output |= (uint32_t) result[1];
    *output <<= 8;
    *output |= (uint32_t) result[2];
    *output <<= 8;
    *output |= (uint32_t) result[3];
    return 4;
}