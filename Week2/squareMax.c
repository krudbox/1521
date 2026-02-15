// Squares a number, unless its square is too big for a 32-bit integer.
// If it is too big, prints an error message instead.

#include <stdio.h>

#define SQUARE_MAX 46340

int main(void) {
  int x, y;

  printf("Enter a number: ");
  scanf("%d", &x);

  if (x > SQUARE_MAX) {
    printf("square too big for 32 bits\n");
  } else {
    y = x * x;
    printf("%d\n", y);
  }

  return 0;
}


int main(void) {
  int x, y;

  printf("Enter a number: ");
  scanf("%d", &x);

  if (x <= SQUARE_MAX) goto x_le_square_max;

  // This is the "else" part of the if-statement.
  printf("square too big for 32 bits\n");

  goto epilogue;

x_le_square_max:
  // This is the "if-then" part of the if-statement.
  y = x * x;
  printf("%d\n", y);

epilogue:
  return 0;
}