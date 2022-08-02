#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "editor.h"

static void print_help(FILE*);

int main(int argc, char** argv) {
    char c;
    FILE* fp = NULL;
    bool window = false;
    
    if((c = getopt(argc, argv, ":h")) != -1) {
        switch(c) {
            case 'w':
                window = true;
                break;
            case 'h':
                print_help(stdout);
                return EXIT_SUCCESS;
            case '?':
                print_help(stderr);
                return EXIT_FAILURE;
        }
    }

    for(int i = 1; i < argc; i++) {
        if(argv[i][0] != '-') {
            fp = fopen(argv[i], "r+");
        }
    }
    

    /* Initiailize editor modes */
    struct Editor* e = editor_init(fp, window);
    editor_render(e);




    sleep(10);
    editor_free(e);
    /* End initialize editor modes */

    return 0;
    
}

static void print_help(FILE* output) {
    fprintf(output, "Usage: cemacs [options] [target]\nOptions:\n\t-h\tShow this message and exit");
}
