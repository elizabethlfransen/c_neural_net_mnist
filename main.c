#include "mnist.h"
#include <stdio.h>
#include <errno.h>
#include <ncurses.h>
#include "app/app.h"

int main() {
    t_mnist_dataset training_data;
    int result;
    if(!read_mnist_dataset(&training_data, TRAINING_DATASET_PARAMS)) {
        fprintf(stderr, "Unable to open training data\n");
        return errno;
    }

    result = run_console_app(&training_data) ? 0 : 1;

    dispose_mnist_dataset(&training_data);

    return result;

}
