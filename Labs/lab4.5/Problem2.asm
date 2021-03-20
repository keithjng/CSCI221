# This program prints the value of variables x-y to the console.
    .data
x:  .word   7                   # global variable x has value 5
y:  .word   4
    .text
    .align  2
    .globl  main
main:
    addi    $sp, $sp, -4        # grow the stack
    sw      $ra, 0($sp)         # store the return address onto the stack
    la      $t0, x              # t0 = x, t1 = y
    la      $t1, y
    lw      $t0, 0($t0)
    lw      $t1, 0($t1)
    sub     $a0, $t0, $t1       # arg1 = x-y
    li      $v0, 1              # set up "print int" system call
    syscall                     # execute system call
    lw      $ra, 0($sp)         # get the return address from the stack
    addi    $sp, $sp, 4         # shrink the stack
    jr      $ra                 # return from main method
