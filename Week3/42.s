# A Short program that will load each element of an array, add 42 to it if
# it is a negative number, and then store it back if it was modified.

N_SIZE = 10
        .text
main:

prologue:

add42_loop_init:
        li      $t0, 0                  # i = 0

add42_loop_cond:
        bge     $t0, N_SIZE, add42_loop_end     # while (i < N_SIZE) {

        mul     $t1, $t0, 4             # 1) Find the number of bytes we need to offset inside the array
        la      $t2, numbers            # 2) Find the base address of the array
        add     $t3, $t1, $t2           # 3) Add the offset to the base address
        lw      $t5, ($t3)              # 4) Load the 4-byte integer, numbers[i], into $t5 to work with

        bge     $t5, 0, add42_loop_iter

        addi    $t5, $t5, 42            # numbers[i] += 42
        sw      $t5, ($t3)

add42_loop_iter:
        addi    $t0, $t0, 1             # i++;
        j       add42_loop_cond

add42_loop_end:

epilogue:
	li	$v0, 0
        jr      $ra                     # return


        .data

numbers:
        .word 0, 1, 2, -3, 4, -5, 6, -7, 8, 9