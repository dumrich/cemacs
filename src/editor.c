#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>
#include "editor.h"
#include "buffer.h"

Editor* editor_init(FILE* fp, bool win)
{
    struct Editor* e = malloc(sizeof(Editor));

    struct winsize term_w;
    if(!win) {
        // Get the (initial) size of the terminal
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &term_w);
        e->esize = ((unsigned)(term_w.ws_row) << 0xF) | term_w.ws_col;
    }

    // Allocate for a list of buffers and set current buffer
    e->blist = &calloc(1, sizeof(Buffer));
    e->buf_index = 0;

    // Set the editor theme
    editor_set_theme(&e);

    // Editor Flags
    if(!win) {
        e->eflags |= 1 << RENDER_BACKEND;
    }

    
}

void editor_set_theme(Editor** e)
{
    (*e)->theme = TERMINAL_DEFAULT;
}
