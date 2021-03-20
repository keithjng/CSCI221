# This program read in two positive integers, a and b, from the user and
# prints a * b.
# If the user enters a non-positive integer, the program ends.

    .text
    .align 2
    .globl main
main:
    li   $v0, 5          # set up reading of first int
    syscall
    move $t0, $v0        # store first int, a, into $t0
    blt  $t0, $0, done   # go to done if a not positive

    li   $v0, 5          # set up reading of second int
    syscall
    move $t1, $v0        # store second int, b, into $t1
    blt  $t1, $0, done   # go to done if b not positive

    move $v0, $0
loop:
    beq  $t0, $0, print  # loop ends when first value reaches 0
    add  $v1, $v1, $t1   # Changed the $v0 to $v1, since $v0 gets changed later on
    sub  $t0, $t0, 1     # Added a subtraction that decreases the first value
    b loop

print:
    li   $v0, 1       # set up "print int" system call
    move $a0, $v1     # set the argument to print
    syscall           # execute system call

    jr   $ra          # Exit

done:
    jr   $ra          # return from main method
