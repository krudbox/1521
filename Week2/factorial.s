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

        move    $t0, $v0	# int n

	li	$t1, 1		# int i
	li	$t2, 1		# int fac

while_cond:
	bgt	$t1, $t0, while_end

while_body:
	mul	$t2, $t2, $t1
while_incr:
	addi	$t1, 1
	b	while_cond
while_end:




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