## Conditionals In MIPS
	.text

	li	$t0, 180

	blt	$t0, 143, cannotRide

	la	$a0, canRideString
	li	$v0, 4
	syscall

	j	endIfStatement

cannotRide:
	la	$a0, cannotRideString
	li	$v0, 4
	syscall

	j	endIfStatement

endIfStatement:
	li	$v0, 0
	jr 	$ra

	.data

canRideString:
	.asciiz "You can enter this ride"

cannotRideString:
	.asciiz "You cannot enter this ride"


## Loops In Mips
	.text

	li	$t0, 10

startLoop:
	bge	$t0, 10, endLoop

	move	$a0, $t0
	li	$v0, 1
	syscall

	li	$a0, 11
	li	$v0, 5
	syscall

	addi	$t0, $t0, 1

endLoop:
	li	$v0, 0
	jr	$ra