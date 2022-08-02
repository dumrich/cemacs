#ifndef WINDOW_H
#define WINDOW_H

#include "buffer.h"
#include <ncurses.h>

enum Backend {
    TERM,
    GTK4
};

struct Window {
    enum Backend backend;
    union {
        WINDOW* win;
    };
};

struct Window* window_init(enum Backend, int, int, int, int);

void window_destroy(struct Window*);
void window_render(struct Window*);

// struct Key* window_listen_for_input(struct Window*);

// void window_render_popup_buffer();
// void window_render_popup_over_list();
// void window_render_term();

#endif
