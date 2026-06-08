// Print every third number from 24 to 42.
#include <stdio.h>

int main(void) {
  // This 'for' loop is effectively equivalent to a while loop.
  // i.e. it is a while loop with a counter built in.
  for (int x = 24; x < 42; x += 3) {
    printf("%d\n", x);
  }
}


#include <stdio.h>

int main(void) {
  int x = 24;

count3_loop_cond:
  // Check the loop condition
  if (x >= 42) goto count3_loop_end;

  // We split the print statement into two sections to prepare to
  // do it in MIPS
  printf("%d", x);
  printf("%c", '\n');

  // Increment the counter and jump to the start of the loop.
  x += 3;
  goto count3_loop_cond;

count3_loop_end:
  // This is the end of the loop.
  return 0;
}