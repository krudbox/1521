/**
 *
 * 1. What will be the output of the following commands?
 *
 *       dcc -o print_arguments print_arguments.c
 *      ./print_arguments I love MIPS
 *
 */


 /**
 * 1.
 *      argv[0]=./printarguments
 *      argv[1]=I
 *      argv[2]=love
 *      argv[3]=MIPS
 *
 */


#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("argc=%d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv[%d]=%s\n", i, argv[i]);
    }

    return 0;
}
