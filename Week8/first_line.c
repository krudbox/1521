/**
* Writes the first line of bytes from a file to stdout
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Argument usage should be: ./first_line [filepath]
    if (argc > 2) {
        fprintf(stderr, "Wrong number of command line arguments\n");
        exit(1);
    }

    char *filepath = argv[1];
    char *mode = "r";

    // Opens file
    FILE *f = fopen(filepath, mode);
    if (f == NULL) {
        perror("");
        exit(1);
    }

    // Reads contents byte by byte and writes to stdout
    int c = fgetc(f);
    while (c != EOF && c != '\n') {
        putchar(c);
        c = fgetc(f);
    }
    
    // Closes file
    if (fclose(f) != 0) {
        perror("");
        exit(1);

    }

    return 0;
}
