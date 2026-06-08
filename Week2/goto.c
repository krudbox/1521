int main(void) {


  // Conditionals

  // V1
  int height = 120;
  if (height >= 143) {
    printf("You can enter this ride");
  } else {
    printf("You cannot enter this ride");
  }

  // V2
  if (height < 143) goto cannotRide;

  printf("You can enter this ride");
  goto endIfStatement;

cannotRide:
  printf("You cannot enter this ride");

endIfStatement:

  // Loops

  // V1
  int x = 0;
  while (x < 10) {
    printf("%d\n", x);
    x = x + 1;
  }

  // V2
  x = 10;

startLoop:
  if (x >= 10) {
    goto endLoop;
  }

  printf("%d\n", x);
  x = x + 1;
  goto startLoop;

endLoop:


  return 0;
}




/**
 *
 *
 *      if (condition) {               if (!condition) goto label1
 *           ...                            ...
 *                                     goto label2
 *      } else {
 *          ...                        label1:
 *                                          ...
 *      }
 *                                     label2:
 *
 */


/**
 *
 *                                        label1:
 *      while (condition) {               if (!condition) goto label2
 *         ...                            ...
 *                                        increment counter
 *         increment counter              goto label1
 *      }
 *                                        label2:
 *
 */