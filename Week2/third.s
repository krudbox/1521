# Prints every 3rd number from 24 to 42

main:                           # int main(void) {
        # Locals:
        #   - $t0: int i, loop counter

count3_loop_init:
        li      $t0, 24         # i = 24;
count3_loop_cond:
                                # Loop Condition: while(i <= 42)
        bge     $t0, 42, count3_loop_end        # if (i >= 42) goto count3_loop_end;

                                # Loop Body:
        move    $a0, $t0        # printf("%d" i);
        li      $v0, 1
        syscall

        li      $a0, '\n'       # printf("%c", '\n');
        li      $v0, 11
        syscall

                                # Loop Increment and back to Loop Condition.
        addi    $t0, $t0, 3     # i += 3;
        j       count3_loop_cond        # goto print_loop;
count3_loop_end:
                                # Loop End:

epilogue:
        jr      $ra             # return from main.