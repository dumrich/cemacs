#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>
#include "statusline.h"
#include "keys.h"

enum Backend {
    CURSES,
    GTK4
};

struct Window {
    unsigned int gui : 1;
    union {
        WINDOW* win;
    }
};

Window* window_init_scr();
void window_destroy(Window*);
void window_render(Window*);

void window_render_statusline(Window*, Buffer*);
void window_render_editor(Editor*);
void window_render_buffer(Window*, Buffer*);
Key* window_listen_for_input(Window*);

// void window_render_popup_buffer();
// void window_render_popup_over_list();
// void window_render_term();

#endif
