# A simple program that will print 10 numbers from an array

N_SIZE = 10

        .text
main:

prologue:


print_loop_init:
        li      $t0, 0                  # int i = 0

print_loop_cond:
        bge     $t0, N_SIZE, print_loop_end

        mul     $t1, $t0, 4             # 1) Find the number of bytes we need to offset inside the array
        la      $t2, numbers            # 2) Find the base address of the array
        add     $t3, $t1, $t2           # 3) Add the offset to the base address
        lw      $a0, ($t3)              # 4) Copy number at address into $a0

	li	$v0, 1
	syscall

	li	$v0, 11
	li	$a0, 11
	syscall

        addi    $t0, $t0, 1             # i++;
        j       print_loop_cond

print_loop_end:

epilogue:
	li	$v0, 0
        jr      $ra                     # return

        .data

numbers:
        .word 0, 1, 2, 3, 4, 5, 6, 7, 8, 9