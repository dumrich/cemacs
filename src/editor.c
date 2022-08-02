#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>
#include "editor.h"
#include "buffer.h"
#include "window.h"
#include <ncurses.h>

struct Editor* editor_init(FILE* fp, bool win)
{
    struct Editor* e = malloc(sizeof(struct Editor));

    struct winsize term_w;
    if(!win) {
        // Get the (initial) size of the terminal
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &term_w);
        e->esize = ((unsigned)(term_w.ws_row) << 0xF) | term_w.ws_col;
    }

    // Allocate for a list of buffers and set current buffer
    struct Buffer* head = calloc(1, sizeof(struct Buffer));
    e->blist = &head;

    e->buf_index = 0;

    // Set the editor theme
    editor_set_theme(e);

    // Editor Flags
    if(!win)
        e->eflags |= 1 << RENDER_BACKEND;

    // Initialize window to NULL
    e->window = NULL;

    return e;
}


void editor_render(struct Editor* e) {
    if(e->eflags & (1 << RENDER_BACKEND)) {
        editor_render_curses(e);
    } 
}

static void editor_render_curses(struct Editor* e) {
    initscr();

    int height, width, start_y, start_x;

    height = e->esize >> 16;
    width = e->esize & 0xFFFF;

    start_y = start_x = 0;

    e->window = window_init(TERM, height, width, start_y, start_x);

}

void editor_free(struct Editor* e) {
    free(*e->blist);
    window_destroy(e->window);
}

void editor_set_theme(struct Editor* e)
{
    e->theme = TERMINAL_DEFAULT;
}
