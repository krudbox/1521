# Sum 4 numbers using function calls.
# Note the use of the stack to save $ra in main, 
# and $ra $a0, $a1, $s0 in sum2.
# For simplicity we are not using a frame pointer
# Only push/pop are needed for this.

main:
        push    $ra             # move stack pointer down to make room
                                # save $ra on $stack

        li      $a0, 11         # sum4(11, 13, 17, 19)
        li      $a1, 13
        li      $a2, 17
        li      $a3, 19
        jal     sum4

        move    $a0, $v0        # printf("%d", z);
        li      $v0, 1
        syscall

        li      $a0, '\n'       # printf("%c", '\n');
        li      $v0, 11
        syscall

        pop     $ra             # recover $ra from $stack
                                # move stack pointer back up to what it was when main called
                                # equivalent to `pop $ra`

        li      $v0, 0          # return 0 from function main
        jr      $ra             # return from function main


#
# We use $s0 for 'e' because its value must survive a function call to sum4. 
# So by convention we must store $s0's original value on the stack, and then
# we can restore it before sum4 returns.
#
# Note sum2 is simple function which changes only $v0.
# We could simplify sum4 by relying on this, 
# but in general we don't do this.
# We assume only registers $s0..$s7 survive function calls
#

# Registers:
# a,b,c,d are in $a0,$a1,$a2,$a3
# res1 is in $s0, res2 is in $v0
# c and d are in $s2,$s3 to be preserved across calls
# Final return is in $v0
sum4:
                                # Prologue:
                                # move stack pointer down to make room
        push    $ra             # save $ra on $stack
        push    $s0             # save $s0 on $stack
        push    $s2             # save $s2 on $stack
        push    $s3             # save $s3 on $stack
                                # We need to get the order out right as well!

sum4__body:
        move    $s2, $a2        # save $a2 in $s2
        move    $s3, $a3        # save $a3 in $s3

        jal     sum2            # sum2(a, b)
        move    $s0, $v0        # move result to $s0 to save it for later

                                # Move the preserved values back into the $a registers
	move	$a0, $s2
	move	$a1, $s3

        jal     sum2            # sum2(c, d);

        move    $a0, $s0        # Sum the first and second results
        move    $a1, $v0
        jal     sum2            # sum2(res1, res2)

sum4__epilogue:
        pop     $s3             # pop from the stack into $s3
        pop     $s2             # pop from the stack into $s2
        pop     $s0             # pop from the stack into $s0
        pop     $ra             # pop from the stack into $ra

        jr      $ra             # return from sum_product



sum2:                           # sum2 doesn't call other functions,
                                # so it doesn't need to save any registers.
        add     $v0, $a0, $a1   # return argument + argument 2
        jr      $ra             #
