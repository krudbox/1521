/**
 * The following program sums up command-line arguments.
 *
 * 1. Why do we need the function atoi in the following program?
 * 2. The program assumes that command-line arguments are integers.
 * What if they are not integer values?
*/

/**
 * 1. To convert the string encoded integer command-line arguments into regular
 *  integers
 *
 * 2. Use strtol!
*/


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int sum = 0;
  for (int i = 0; i < argc; i++) {
    sum += atoi(argv[i]);
  }
  printf("sum of command-line arguments = %d\n", sum);

  return 0;
}
