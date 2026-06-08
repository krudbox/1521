#include <stdio.h>

int main(void) {
  int x;
  printf("Enter a number: ");
  scanf("%d", &x);

  if (x > 100 && x < 1000) {
    printf("medium\n");
  } else {
    printf("small/big\n");
  }
}


int main(void) {
  int x;

  printf("Enter a number: ");
  scanf("%d", &x);

  // Combined, these two conditional branches effectively implement an && as it
  // would be in a single if-statement.
  if (x <= 100) goto x_lt_100_gt_1000;

  if (x >= 1000) goto x_lt_100_gt_1000;

  // This becomes the else-case of the if-statement.
  printf("medium\n");
  goto epilogue;

x_lt_100_gt_1000:
  printf("small/big\n");

epilogue:
  return 0;
}