#ifndef EDITOR_H
#define EDITOR_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "buffer.h"
#include "window.h"

#define RENDER_BACKEND 0x0

enum Theme {
    TERMINAL_DEFAULT,
    GRUVBOX_DARK,
    ATOM_ONEDARK
};

struct Editor {
    // Pointer to the display, term or GUI
    struct Window* window;

    // List of Buffers
    struct Buffer** blist;
    size_t buf_index;

    // Global Keymaps
    // struct Keymap* global_keymap;

    // Theme
    enum Theme theme;

    // Editor Size (16 bits, 16 bits)
    unsigned int esize;

    // Configuration bits
    uint16_t eflags;
};

struct Editor* editor_init(FILE*, bool);
int editor_start(struct Editor*);

void editor_render(struct Editor*);

// Separate backends
static void editor_render_curses(struct Editor*);

void editor_switch_buffer(struct Editor*);
void editor_set_keymap(struct Editor*);
void editor_free(struct Editor*);

// Other functions
void editor_set_theme(struct Editor*);

#endif
