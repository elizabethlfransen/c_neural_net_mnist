//
// Created by liz on 2/2/23.
//

#include "app.h"
#include <stdio.h>
#include <ncurses.h>
#include <stdbool.h>
#include "../mnist.h"
#include "state.h"
#include "colors.h"
#include "data_viewer.h"

bool init_console_app(t_mnist_dataset *dataset) {
    if (initscr() == NULL) {
        fprintf(stderr, "Unable to start rendering");
        return false;
    }
    init_colors();
    init_state();
    init_data_viewer(dataset, "Training Data");
    return true;
}

void render_console_app() {
    render_data_viewer();
}

void update_console_app() {
    update_data_viewer();
}

bool run_console_app(t_mnist_dataset *dataset) {
    if (!init_console_app(dataset)) return false;
    while (APP_STATE.running) {
        clear();
        render_console_app();
        refresh();
        update_console_app();
    }
    if (endwin() == ERR) return false;
    return true;
}
