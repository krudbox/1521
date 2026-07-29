

main:

main_prologue:
	push	$ra


main_body:
	li	$a0, 11
	li	$a1, 13
	li	$a2, 17
	li	$a3, 19
	jal	sum4

	move	$t0, $v0

	move	$a0, $t0
	li	$v0, 1
	syscall

	li	$v0, 11
	li	$a0, '\n'
	syscall


main_epilogue:
	pop	$ra

	li	$v0, 0
	jr	$ra


sum4:
sum4_prologue:

	push	$ra
	push	$s0	# res1
	push	$s1	# c
	push	$s2	# d


sum4_body:
	move	$s2, $a2
	move	$s3, $a3

	jal	sum2
	move	$s0, $v0

	move	$a2, $s2
	move	$a3, $s3
	jal	sum2

	move	$a0, $s0
	move	$a1, $v0

	jal	sum2




sum4_epilogue:
	pop	$s2
	pop	$s1
	pop	$s0
	pop	$ra

	jr	$ra


sum2:

sum2_prologue:


sum2_body:
	add	$v0, $a0, $a1

sum2_epilogue:
	jr	$ra