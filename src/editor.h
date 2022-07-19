#ifndef EDITOR_H
#define EDITOR_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "buffer.h"
#include "window.h"
#include "keys.h"

#define RENDER_BACKEND 0x0

enum Theme {
    TERMINAL_DEFAULT,
    GRUVBOX_DARK,
    ATOM_ONEDARK
};

struct Editor {
    // Pointer to the display, term or GUI
    Window* window;

    // List of Buffers
    Buffer** blist;
    size_t buf_index;

    // Global Keymaps
    Keymap* global_keymap;

    // Theme
    enum Theme theme;

    // Editor Size (16 bits, 16 bits)
    unsigned int esize;

    // Configuration bits
    uint16_t eflags;
};

Editor* editor_init(FILE*, bool);
int editor_start(Editor*);
void editor_render(Editor*);
void editor_switch_buffer(Editor*);
void editor_set_keymap(Editor*);
void editor_free(Editor*);

// Other functions
void editor_set_theme(*Editor);

#endif
