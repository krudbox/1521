# Scans a number from stdin and prints out the number plus 5

	.text
main__prologue:
	push $ra

main__body:
	la	$a0, prompt
	li	$v0, 4
	syscall

	li	$v0, 5
	syscall
	move	$t0, $v0

	add	$t1, $t0, 5

	move	$a0, $t1
	li	$v0, 1
	syscall

	li	$a0, 11
	li	$v0, 1
	syscall

main__epilogue:
	li	$v0, 0
	jr	$ra

	.data
prompt:
	.asciiz "Enter a whole number: "
