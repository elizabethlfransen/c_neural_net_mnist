//
// Created by liz on 2/2/23.
//

#include "render.h"
#include <stdio.h>
#include "mnist.h"

#define GRAY_MIN 232
#define GRAY_MAX 252

int get_color(uint8_t v) {
    return v * (GRAY_MAX - GRAY_MIN) / 255  + GRAY_MIN;
}

void print_image(uint8_t *image) {
    int row,col;
    for(row = 0; row < MNIST_IMAGE_SIZE; row++) {
        for(col = 0; col < MNIST_IMAGE_SIZE; col++) {
            printf("\x1b[48;5;%dm  ", get_color(image[row * MNIST_IMAGE_SIZE + col]));
        }
        printf("\x1b[0m\n");
    }
    printf("IMAGE\n");
}