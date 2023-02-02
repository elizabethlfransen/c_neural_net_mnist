//
// Created by liz on 2/2/23.
//

#ifndef C_NEURAL_NET_MNIST_DATA_VIEWER_H
#define C_NEURAL_NET_MNIST_DATA_VIEWER_H

#include "../mnist.h"

void init_data_viewer(t_mnist_dataset *dataset, const char *dataset_name);
void render_data_viewer();
void update_data_viewer();

#endif //C_NEURAL_NET_MNIST_DATA_VIEWER_H
