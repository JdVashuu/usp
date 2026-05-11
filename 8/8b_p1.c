#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *filename = argv[1];
    if (access(filename, F_OK) == 0) {
        printf("File '%s' exists and can be accessed.\n", filename);
    } else {
        printf("File '%s' does not exist or cannot be accessed.\n", filename);
    }
    return 0;
}

// Commands to Execute:
// vi program_name.c (type program here)
// vi p1.c
// cc -o p1 p1.c
// cc program_name.c
// ./a.out
