# Computes factorials using no functions (except main)


main:
        # Registers:
        # - $t0: int n   - number to compute factorial up to
        # - $t1: int i   - number to multiply by in each loop iteration. Serves as loop counter
        # - $t2: int fac - factorial of $t0

        li      $t0, 0                  # n = 0

        la      $a0, input_str
        li      $v0, 4
        syscall                         # printf("n  = ")

        li      $v0, 5
        syscall                         # scanf("%d", into $v0)

        move    $t0, $v0

        li      $t2, 1                  # fac = 1

main_fac_init:
                                        # Loop initialisation
        li      $t1, 1                  # i = 1

main_fac_cond:
                                        # Loop condition
        bgt     $t1, $t0, main_fac_end  # while (i <= n)  -->  if (i > n) break
        mul     $t2, $t2, $t1           # fac = fac * i

main_fac_step:
                                        # Loop step and back to the condition
        addi    $t1, $t1, 1             # i++
        j       main_fac_cond

main_fac_end:
                                        # Prints the results
        la      $a0, output_str
        li      $v0, 4
        syscall                         # printf("n! = ")

        move    $a0, $t2                # assume $t2 holds n!
        li      $v0, 1
        syscall                         # printf("%d", fac)

        li      $a0, '\n'
        li      $v0, 11
        syscall                         # printf("\n")

        # la    $a0, newline            # Alternative to print a newline using a string:
        # li    $v0, 4
        # syscall                       # printf("\n")

        jr      $ra                     # return from main

        .data
# Provided strings for printing
input_str:
        .asciiz "n  = "
output_str:
        .asciiz "n! = "
newline_str:
        .asciiz "\n"