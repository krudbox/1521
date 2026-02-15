/**
 * 1. What will happen when the above program is compiled and executed?
 * 2. In particular, what does this look like in memory?
 * 3. How could we fix this program?
*/

/**
 * 1. Undefined behaviour
 * 2. Two characters followed by a squence of random bytes
 * 3. Set the null character!
*/

#include <stdio.h>

int main(void) {
    char str[10];
    str[0] = 'H';
    str[1] = 'i';
    printf("%s", str);
    return 0;
}