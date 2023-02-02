#include "mnist.h"
#include <stdio.h>
#include <errno.h>
#include "render.h"

int main() {
    t_mnist_dataset training_data;
    if(!read_mnist_dataset(&training_data, TRAINING_DATASET_PARAMS)) {
        fprintf(stderr, "Unable to open training data");
        return errno;
    }

    print_image(training_data.images);

    dispose_mnist_dataset(&training_data);

    return 0;

}
