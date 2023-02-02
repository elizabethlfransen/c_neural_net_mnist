//
// Created by liz on 2/1/23.
//

#ifndef C_NEURAL_NET_MNIST_MNIST_H
#define C_NEURAL_NET_MNIST_MNIST_H

#include <stdint.h>
#include <stdbool.h>

#define TRAINING_IMAGES_DEFAULT_FILE_NAME "data/train-images-idx3-ubyte"
#define TRAINING_LABELS_DEFAULT_FILE_NAME "data/train-labels-idx1-ubyte"
#define TEST_IMAGES_DEFAULT_FILE_NAME "data/T10K-labels-idx1-ubyte"
#define TEST_LABELS_DEFAULT_FILE_NAME "data/T10K-labels-idx1-ubyte"
#define MNIST_IMAGE_SIZE 28
#define MNIST_IMAGES_MAGIC_NUMBER 0x0803
#define MNIST_LABELS_MAGIC_NUMBER 0x0801
#define MNIST_IMAGE_PIXEL_COUNT MNIST_IMAGE_SIZE * MNIST_IMAGE_SIZE
#define TRAINING_DATASET_PARAMS TRAINING_IMAGES_DEFAULT_FILE_NAME, TRAINING_LABELS_DEFAULT_FILE_NAME
#define TEST_DATASET_PARAMS TEST_IMAGES_DEFAULT_FILE_NAME, TEST_LABELS_DEFAULT_FILE_NAME


typedef struct mnist_dataset {
    uint32_t count;
    uint8_t *images;
    uint8_t *labels;
} t_mnist_dataset;

bool read_mnist_dataset(t_mnist_dataset *database, char *imagesFilePath, char *labelsFilePath);
void dispose_mnist_dataset(t_mnist_dataset *dataset);

#endif //C_NEURAL_NET_MNIST_MNIST_H
