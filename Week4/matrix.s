# MIPS function to multiply a matrix by a scalar.
# 
# Used:         [$s0, $s1, $t0, $t1, $t4]
# Clobbered:    [$t0, $t1, $t4]
# Stack:        [$s0, $s1]
# 
# Arguments:
# $a0 - nrows:  Number of rows in the matrix
# $a1 - ncols:  Number of columns in the matrix
# $a2 - M:      Matrix M
# $a3 - factor: Scalar factor to multiply by
# 
# Registers:
# $t0 - t0:     Array offset calculations
# $t1 - M[][]:  Value at an index in the matrix
change:
        # params:        nrows is $a0, ncols is $a1, &M is $a2, factor is $a3
        # registers: row is $s0, col is $s1

        # set up stack frame
        begin                           # move frame pointer
        push    $ra
        push    $s0                     # save row and col registers so we can use them
        push    $s1

        # Alternative method to begin/push:
        # sw    $fp, -4($sp)
        # la    $fp, -4($sp)
        # sw    $ra, -4($fp)
        # sw    $s0, -8($fp)
        # sw    $s1, -12($fp)
        # addi  $sp, $sp, -16

        li      $t4, 4                  # sizeof(int), saved for later
        li      $s0, 0                  # row = 0

change_row_loop:                        # for (int row = 0; row < nrows; row++)
        bge     $s0, $a0, change_row_loop_end

        li      $s1, 0                  # col = 0
change_col_loop:                        # for (int col = 0; col < ncols; col++)
        bge     $s1, $a1, change_col_loop_end

        # get &M[row][col]
        mul     $t0, $s0, $a1           # row offset = row * ncols
        add     $t0, $t0, $s1           # row+col offset = row * ncols + col
        mul     $t0, $t0, $t4           # offset in bytes = row * ncols + col * sizeof(int)
        add     $t0, $t0, $a2           # base address of M + offset in bytes = &M[row][col]

        lw      $t1, ($t0)              # M[row][col]
        mul     $t1, $t1, $a3
        sw      $t1, ($t0)              # M[row][col] = factor * M[row][col]

        addi    $s1, $s1, 1             # col++
        j       change_col_loop         # goto change_col_loop

change_col_loop_end:
        addi    $s0, $s0, 1             # row++
        j       change_row_loop         # goto change_row_loop

change_row_loop_end:

        # clean up stack frame and restore registers
        # Must be in the reverse order to the `push`-es!
        pop     $s1                     # pop from the stack into $s1
        pop     $s0                     # pop from the stack into $s0
        pop     $ra                     # pop from the stack into $ra
        end                             # move frame pointer back

        # Alternative method to clean up:
        # lw    $ra, -4($fp)
        # lw    $s0, -8($fp)
        # lw    $s1, -12($fp)
        # la    $sp, 4($fp)
        # lw    $fp, ($fp)

        jr      $ra                     # return