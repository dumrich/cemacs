#include "window.h"
#include <curses.h>
#include <stdlib.h>

struct Window* window_init(enum Backend b, int h, int width, int y, int x) {
    struct Window* w = malloc(sizeof(struct Window));
    w->backend = b;
    w->win = newwin(h, width, y, x);
    refresh();

    return w;
}

void window_destroy(struct Window* w) {
    if(w->backend == TERM) {
        endwin();
    }
}
