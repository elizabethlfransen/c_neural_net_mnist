//
// Created by liz on 2/2/23.
//

#ifndef C_NEURAL_NET_MNIST_STATE_H
#define C_NEURAL_NET_MNIST_STATE_H
#include <stdbool.h>
#include "../mnist.h"

typedef struct app_state {
    bool running;
} app_state_t;

extern app_state_t APP_STATE;

void init_state();

#endif //C_NEURAL_NET_MNIST_STATE_H
