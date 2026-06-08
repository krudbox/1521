# A simple program demonstrating how to represent a implementing an && in an
# if-statement in MIPS.
# This version: MIPS.

main:
        # Locals:
        # - $t0: int x

        la      $a0, prompt_str                     # printf("Enter a number: ");
        li      $v0, 4
        syscall

        li      $v0, 5                          # scanf("%d", &x);
        syscall
        move    $t0, $v0

        ble     $t0, 100, x_lt_100_gt_1000      # if (x <= 100) goto x_lt_100_gt_1000;
        bge     $t0, 1000, x_lt_100_gt_1000     # if (x >= 1000) goto x_lt_100_gt_1000;
                                                # Combined, these two conditional branches effectively implement an && in an if-statement.

                                                # If we get here, x is between 100 and 1000.
                                                # This becomes the else-case of the original if-statement.
        la      $a0, medium_str                 # printf("medium\n");

        li      $v0, 4
        syscall

        j       epilogue                        # goto epilogue;

x_lt_100_gt_1000:
        la      $a0, small_big_str              # printf("small/big\n");
        li      $v0, 4
        syscall
epilogue:
        jr      $ra                             # return 0;


        .data
prompt_str:
        .asciiz "Enter a number: "
medium_str:
        .asciiz "medium\n"
small_big_str:
        .asciiz "small/big\n"