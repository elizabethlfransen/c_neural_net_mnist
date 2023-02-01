//
// Created by liz on 2/1/23.
//

#include "mnist.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void initDataset(t_mnist_dataset *dataset) {
    dataset->images = NULL;
    dataset->labels = NULL;
}

bool read_mnist_dataset(t_mnist_dataset *dataset, char *imagesFilePath, char *labelsFilePath) {
    FILE *imagesFile, *labelsFile;
    uint8_t magic[4];


    // initialize
    initDataset(dataset);

    // open file handles
    imagesFile = fopen(imagesFilePath, "rb");
    if(imagesFile == NULL)
        return false;
    labelsFile = fopen(labelsFilePath, "rb");
    if (labelsFile == NULL) {
        // cleanup
        fclose(imagesFile);
        return false;
    }

    // read magic numbers
    fread(&magic,1,4,imagesFile);
    printf("%d", magic);

    // cleanup
    fclose(imagesFile);
    fclose(labelsFile);
    return true;

}

void dispose_mnist_dataset(t_mnist_dataset *dataset) {
    free(dataset->images);
    free(dataset->labels);
}