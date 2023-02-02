//
// Created by liz on 2/2/23.
//
#include "colors.h"
#include <stdbool.h>
#include <stdio.h>
#include <ncurses.h>


bool init_grays() {
    for (int i = 0; i <= GRAY_COLOR_PAIRS_COUNT; i++) {
        if (init_pair(i + GRAY_COLOR_PAIRS_START, 0, 232 + i) == ERR) {
            fprintf(stderr, "Unable to initialize gray colors");
            return false;
        }
    }
    return true;
}

bool init_colors() {
    if (!has_colors() || start_color() == ERR) {
        fprintf(stderr, "This console does not support colors");
        return false;
    }
    if (!init_grays())
        return false;
    return true;
}