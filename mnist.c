//
// Created by liz on 2/1/23.
//

#include "mnist.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "io_util.h"

void initDataset(t_mnist_dataset *dataset) {
    dataset->images = NULL;
    dataset->labels = NULL;
}

bool cleanup(FILE *stream1, FILE *stream2) {
    fclose(stream1);
    fclose(stream2);
    return false;
}


bool try_read_uint32_t(uint32_t *output, FILE *stream, FILE *other) {
    if (read_uint32_t(output, stream) != 4) {
        return cleanup(stream, other);
    }
    return true;
}

bool try_read_magic_number(FILE *stream, uint32_t expected_magic_number, FILE *other) {
    uint32_t magic;
    if (!try_read_uint32_t(&magic, stream, other))
        return false;
    if (magic != expected_magic_number) {
        return cleanup(stream, other);
    }
    return true;
}


bool read_mnist_dataset(t_mnist_dataset *dataset, char *imagesFilePath, char *labelsFilePath) {
    FILE *images_file, *labels_file;
    uint32_t magic, image_count, label_count;


    // initialize
    initDataset(dataset);

    // open file handles
    images_file = fopen(imagesFilePath, "rb");
    if (images_file == NULL)
        return false;
    labels_file = fopen(labelsFilePath, "rb");
    if (labels_file == NULL) {
        // cleanup
        fclose(images_file);
        return false;
    }

    // read magic numbers
    if (!try_read_magic_number(images_file, MNIST_IMAGES_MAGIC_NUMBER, images_file))
        return false;
    if (!try_read_magic_number(labels_file, MNIST_LABELS_MAGIC_NUMBER, images_file))
        return false;
    if (!try_read_uint32_t(&image_count, images_file, images_file))
        return false;
    if (!try_read_uint32_t(&label_count, labels_file, images_file))
        return false;

    if (image_count != label_count) {
        return cleanup(images_file, labels_file);
    }

    dataset->count = image_count;
    // allocate space for images and labels
    dataset->images = malloc(sizeof(uint8_t) * MNIST_IMAGE_PIXEL_COUNT * image_count);
    if (dataset->images == NULL) {
        return cleanup(images_file, labels_file);
    }
    dataset->labels = malloc(sizeof(uint8_t) * label_count);
    if (dataset->images == NULL) {
        return cleanup(images_file, labels_file);
    }
    if(fread(dataset->images, sizeof(uint8_t) * MNIST_IMAGE_PIXEL_COUNT, image_count,images_file) != image_count) {
        return cleanup(images_file, labels_file);
    }
    if(fread(dataset->labels, sizeof(uint8_t), label_count, labels_file) != label_count) {
        return cleanup(images_file, labels_file);
    }

    cleanup(images_file, labels_file);
    return true;

}

void dispose_mnist_dataset(t_mnist_dataset *dataset) {
    free(dataset->images);
    free(dataset->labels);
}