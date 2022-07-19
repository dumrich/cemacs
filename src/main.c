#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "editor.h"

int main(int argc, char** argv) {
    unsigned char c;
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
            fp = fopen(argv[i], "w+");
        }
    }
    

    // Init dashboard or file
    editor_init(fp, window);


    if(fp)
        // Close file descriptor, if it exists
        fclose(fp);

    return 0;
    
}

void print_help(FILE* output) {
    fprintf(output, "Usage: cemacs [options] [target]\nOptions:\n\t-h\tShow this message and exit");
}
