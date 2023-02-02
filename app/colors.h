//
// Created by liz on 2/2/23.
//

#ifndef C_NEURAL_NET_MNIST_COLORS_H
#define C_NEURAL_NET_MNIST_COLORS_H

#include <stdbool.h>

#define GRAY_COLOR_PAIRS_START 1
#define GRAY_COLOR_PAIRS_COUNT 23
#define GRAY_COLOR_PAIRS_END (GRAY_COLOR_PAIRS_START + GRAY_COLOR_PAIRS_COUNT)


bool init_grays();

bool init_colors();

#endif //C_NEURAL_NET_MNIST_COLORS_H
