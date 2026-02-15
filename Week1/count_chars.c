/**
 *
 * Write a C program that uses getchar to read in characters until the user
 * enters Ctrl-D and then prints the total number of characters entered.
 *
 */

#include <stdio.h>

int main(void) {
  int c = 0;
  int buf;
  while ((buf = getchar()) != EOF) {
    c++;
  }

  printf("%d characters were read\n", c);

  return 0;
}