# A simple program that will read 10 numbers into an array

N_SIZE = 10

        .text
main:

prologue:


scan_loop_init:
        li      $t0, 0                  # int i = 0

scan_loop_cond:
        bge     $t0, N_SIZE, scan_loop_end

        li      $v0, 5                  # scanf("%d", &numbers[i]);
        syscall

        mul     $t1, $t0, 4             # 1) Find the number of bytes we need to offset inside the array
        la      $t2, numbers            # 2) Find the base address of the array
        add     $t3, $t1, $t2           # 3) Add the offset to the base address
        sw      $v0, ($t3)              # 4) Store entered number in array at the calculated address

        addi    $t0, $t0, 1             # i++;
        j       scan_loop_cond

scan_loop_end:

epilogue:
	li	$v0, 0
        jr      $ra                     # return

        .data

numbers:
        .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0