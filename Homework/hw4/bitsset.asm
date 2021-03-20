# bitsset.asm
# Program that computes the number of bits in a word that are set to 1
    .data
int: .asciiz "Type an integer: "
    .text
    .align 2
    .globl main

main:
    sub $sp, $sp, 4         # Extend the stack
    sw $ra, 0($sp)          # Save return address in the stack

    li $v0, 4               # System call to print "int" string
    la $a0, int             # Address of string
    syscall

    li $v0, 5               # System call to read an integer
    syscall
    move $a0, $v0           # Stores the read integer input to $a0

    li $v0, 0               # Set a counter for the number of 1 bits

    jal bitsset             # Jump to bitsset recursive helper function

    move $t0, $v0           # Store the output into a temporary register, since $v0 will be altered

    li $v0, 1               # System call to print integer
    move $a0, $t0           # Move the counter to the argument for the system call to print the int
    syscall

    j done                  # Return from main to caller

bitsset:
    sub $sp, $sp, 4         # Extend the stack
    sw $ra, 0($sp)          # Save return address in the stack

    beq $a0, $0, done       # Exit recursion if condition is met
    and $t0, $a0, 1         # Check if there is a "1" bit, save either a 1 or a 0 to $t0
    srl $a0, $a0, 1         # Shift to the next bit

    jal bitsset             # Jump back to bitsset for recursion
    bne $t0, $0, oneFound   # If $t0 is not equal to 0, it must be 1 and so the counter should increase
    j done                  # Return to main

oneFound:
    addi $v0, $v0, 1        # Increment the counter of "1 bits" by 1

    j done                  # Return to main

done:                       # Restores return address and stack before returning to caller
    lw $ra, 0($sp)          # Restore $ra from the stack
    addi $sp, $sp, 4        # Restore the stack
    jr $ra                  # Return to caller
