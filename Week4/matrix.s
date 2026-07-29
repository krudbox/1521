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
     move	$t0, $a0
     move	$t1, $a1
     move	$t2, $a2
     move	$t3, $a3

row_loop_init:
	li	$t4, 0		# t4: int row = 0;
row_loop_cond:
	bge	$t4, $t0, row_loop_end

row_loop_body:

col_loop_init:
	li	$t5, 0
col_loop_cond:
	bge	$t5, $t1, row_loop_end

col_loop_body:
	
	mul	$t6, $t4, $t1	# row * N_COLS
	add	$t6, $t5, $t6	# row * N_COLS + col
	mul 	$t6, $t6, 4	# 4(row * N_COLS + col)
	add	$t6, $t6, $t2

	lw	$t7, ($t6)
	mul	$t7, $t7, $t3
	sw	$t7, ($t6)

col_loop_step:
	addi	$t5, 1
	j	col_loop_cond

col_loop_end:

row_loop_step:
	addi	$t4, 1
	j	row_loop_cond


row_loop_end: