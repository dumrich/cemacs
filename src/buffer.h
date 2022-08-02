#ifndef BUFFER_H
#define BUFFER_H

#include <stdio.h>

enum Flags {
    IS_FILE,
    SHOW_CURSOR,
    WRITABLE,
    MODIFIED,
    REMOTE,
    ACTIVE,
    // Buffer is synced
    SYNCED,
};

struct Buffer {

    // Non-file buffers begin with *
    char* bname;

    // File pointer || Render
    union {
        FILE* f;
        int (*display) (void);
    };

    // Text Rope
    // Rope* rope;

    long long x_pos;
    long long y_pos;

    long long num_lines;

    // Mode Array
    // Mode** modes; 
    
    // Miscellaneous Buffer Flags
    unsigned int bflags;
};

void window_render_statusline(struct Window*, struct Buffer*);
void window_render_buffer(struct Window*, struct Buffer*);

#endif
