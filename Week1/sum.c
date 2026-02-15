/**
 * This program scans in a number n and prints the sum of all positive integers
 * up to and including n.
 * Rewrite the sum function so it uses recursion instead of a loop.
 *
 * 1. What is the difference between the loop and recursive versions?
 *
*/

/**
 * 1. The for loop uses 2 variables to iteratively determine the sum. The
 * recursive solution uses n stack frames to determine the sum. Stack frames are
 * more memory intensive than simple variables.
*/

#include <stdio.h>

int sum(int n);
int sumRecursive(int n);

int main(int argc, char *argv[]) {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);

  int result = sumRecursive(n);
  printf("Sum of all numbers up to %d = %d\n", n, result);

  return 0;
}

int sum(int n) {
    int result = 0;
    for (int i = 0; i <= n; i++) {
        result += i;
    }
    return result;
}


int sumRecursive(int n) {
  if (n == 0) {
    return 0;
  }

  return n + sumRecursive(n - 1);
}