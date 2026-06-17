# A short program that reverses an array by swapping elements.

# Constants
N_SIZE = 10
N_SIZE_M_1 = N_SIZE - 1
N_SIZE_D_2 = N_SIZE / 2

        .text
main:

prologue:

swap_loop_init:
        li      $t0, 0                  # i = 0

swap_loop_cond:
        bge     $t0, N_SIZE_D_2, swap_loop_end  # while (i < N_SIZE_D_2) {

        mul     $t1, $t0, 4             # 1) Find the number of bytes we need to offset inside the array
                                        #    Since this is a 4-byte integer, we need to multiply by 4.
        la      $t2, numbers            # 2) Find the base address of the array
        add     $t3, $t1, $t2           # 3) Add the offset to the base address
        lw      $t4, ($t3)              # 4) Load the 4-byte integer, numbers[i], into $t4 (x) to work with


        li      $t5, N_SIZE_M_1
        sub     $t5, $t5, $t0           # 1) Find the index of the second number to swap
        mul     $t6, $t5, 4             # 2) Find the number of bytes we need to offset inside the array
        add     $t7, $t6, $t2           # 3) Add the offset to the base address
        lw      $t8, ($t7)              # 4) Load the 4-byte integer, numbers[N_SIZE_M_1 - i], into $t8 (y) to work with

                                        # Store the second number in the first position,
                                        # and the first number in the second position.
        sw      $t8, ($t3)              # numbers[i] = y
        sw      $t4, ($t7)              # numbers[N_SIZE_M_1 - i] = x

swap_loop_iter:
        addi    $t0, $t0, 1             # i++;
        j       swap_loop_cond

swap_loop_end:

epilogue:
	li	$v0, 0
        jr      $ra                     # return

        .data

numbers:
        .word 0, 1, 2, 3, 4, 5, 6, 7, 8, 9