//
// Created by liz on 2/2/23.
//

#include "data_viewer.h"
#include <stdint.h>
#include <ncurses.h>
#include "../mnist.h"
#include "colors.h"
#include "state.h"

t_mnist_dataset *DATASET;
int IMAGE_INDEX;
const char *DATASET_NAME;

int get_color(uint8_t v) {
    return v * GRAY_COLOR_PAIRS_COUNT / 255 + GRAY_COLOR_PAIRS_START;
}

void render_image(uint8_t *image) {
    int row, col, color;
    for (row = 0; row < MNIST_IMAGE_SIZE; row++) {
        for (col = 0; col < MNIST_IMAGE_SIZE; col++) {
            color = get_color(image[row * MNIST_IMAGE_SIZE + col]);
            attron(COLOR_PAIR(color));
            addstr("  ");
            attroff(COLOR_PAIR(color));
        }
        addch('\n');
    }
}

void init_data_viewer(t_mnist_dataset *dataset, const char *dataset_name) {
    DATASET = dataset;
    IMAGE_INDEX = 0;
    DATASET_NAME = dataset_name;
}

void render_data_viewer() {
    attron(A_BOLD);
    addstr(DATASET_NAME);
    attroff(A_BOLD);
    printw(" (%d / %d)", IMAGE_INDEX, DATASET->count);
    render_image(get_image(DATASET->images, IMAGE_INDEX));
}

void update_data_viewer() {
    chtype pressed_key;
    pressed_key = getch();
    switch (pressed_key) {
        case 'n':
            IMAGE_INDEX++;
            break;
        case 27:
            APP_STATE.running = false;
            break;
        default:
            break;
    }
}