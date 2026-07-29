
main:
	li	$t0, 4

	addi	$sp, $sp, -4
	sw	$ra, 0($sp)

	push $ra


	# function call
	move	$a0, $t0
	jal	function


	lw	$ra, 0($sp)
	addi	$sp, $sp, 4

	pop	$ra


	li	$v0, 0
	jr	$ra


function:
	move	$t0, $a0
	addi	$t0, 5

	move	$a0, $t0
	li	$v0, 1
	syscall

	li	$v0, 11
	li	$a0, '\n'
	syscall

	jr	$ra

