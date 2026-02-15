#include <stdio.h>

int fibonacci(int n);

int main(void) {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);

  int nth = fibonacci(n);
  printf("The %dth fibonacci number is %d\n", n, nth);

  return 0;
}


int fibonacci(int n) {
  if (n == 0) {
    return 0;
  }

  if (n == 1) {
    return 1;
  }

  return fibonacci(n - 1) + fibonacci(n - 2);
}


