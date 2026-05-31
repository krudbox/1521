/**
 * For each of the following commands, describe what kind of output would be produced:
 *
 *
 * a. clang -E x.c
 * b. clang -S x.c
 * c. clang -c x.c
 * d. clang x.c
 *
 *
 * In particular, how do these commands relate to what we will be studying in COMP1521?
*/

/**
 * a. clang -E x.c - A preprocessed C file aka a pure C file - Comments are removed, #includes are expanded and #defines are replaced
 * b. clang -S x.c - An equivalent assembly file
 * c. clang -c x.c - An almost executable file awaiting linking to libraries
 * d. clang x.c    - An executable file comprised of 1s and 0s
 *
 *
*/

#include <stdio.h>
#define N 10

int main(void) {
    char str[N] = { 'H', 'i', '\0' };
    printf("%s\n", str);
    return 0;
}