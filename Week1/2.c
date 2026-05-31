/**
 * 1. What does the memory layout of a typical program look like?
 * 2. What is a global variable?
 * 3. How do they differ from local variables? Where are they each located in memory?
 * 4. What is a string literal? Where are they located in memory?
*/

/**
 * 1. See slides
 * 2. A variable accessible by any function at any point in the program
 * 3. Local variables are only accessible within the stack frame in which they are declared. Local variables are located on the stack. Global variables are located in
 * 4. A string literal is a sequence of characters used to initalise a READ ONLY character array. String literals are located in a read only subsection in data
*/

#include <stdio.h>

char *s1 = "abc";

int main(void) {
  char *s2 = "def";

  // Undefined Behaviour...
  s2[2] = 'z';
  printf("%s\n", s2);

  // Read-Write String
  char s3[] = "hij";
  s3[2] = 'z';
  printf("%s\n", s3);
}
