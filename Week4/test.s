main:
	push	$ra
	push	$s0

	li      $s0, 4
	move	$a0, $s0

    	jal     function

	move	$a0, $s0
	li	$v0, 1
	syscall

	push	$s0
	pop	$ra

main_end:
    	li      $v0, 0
    	jr      $ra


function:
	push	$ra
	push	$s0

   	li      $t0, 5
	add	$s0, $a0, $t0

	move	$a0, $s0
	jal	function2

	move	$a0, $s0
	li	$v0, 1
	syscall

	li	$a0, '\n'
	li	$v0, 11
	syscall

	pop	$s0
	pop	$ra

	jr      $ra


















function2:
	jr	$ra
















m:

li	$s0, 2
li	$s1, 3

push	$s0
push	$s1

pop	$s0
pop	$s1



