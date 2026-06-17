# Simple program to calculate the length of a predefined string literal

	.text

main:

prologue:

strlen_loop_init:
	li	$t0, 0
	li	$t1, 0


strlen_loop_cond:
	mul	$t2, $t1, 1
	la	$t3, string

	add	$t4, $t3, $t2
	lb	$t5, ($t4)

	beqz	$t5, strlen_loop_end


strlen_loop_incr:
	addi	$t1, $t1, 1
	j	strlen_loop_cond


strlen_loop_end:
	move	$a0, $t5
	li	$v0, 1
	syscall

	li	$a0, 11
	li	$v0, 11
	syscall

epilogue:
	li	$v0, 0
	jr	$ra



   	.data
string:
   .asciiz  "...."