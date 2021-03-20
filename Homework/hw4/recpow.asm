# recpow.asm
# Program that calculates a number to the power of another number recursively (No counters or anything, try and find a way to reduce it down to a base case)
    .data
base: .asciiz "Enter a number (base): "
power: .asciiz "Enter a number (power): "
    .text
    .align 2
    .globl main

main:
    sub $sp, $sp, 4         # Extend the stack
    sw $ra, 0($sp)          # Save return address in the stack

    li $v0, 4               # System call to print string (printing the power question)
    la $a0, power           # Address of string
    syscall

    li $v0, 5               # System call to read an integer
    syscall
    move $a1, $v0           # Stores the read integer (power) to $a1

    li $v0, 4               # System call to print string (printing the base question)
    la $a0, base            # Address of string
    syscall

    li $v0, 5               # System call to read an integer
    syscall
    move $a0, $v0           # Stores the read integer (base) to $a0

    li $v1, 1               # Set the output to 1

    jal pow                 # Jump to recursive pow function

    li $v0, 1               # System call to print integer
    move $a0, $v1           # Move the counter to the argument for the system call to print the int
    syscall

    lw $ra, 0($sp)          # Restore $ra from the stack
    addi $sp, $sp, 4        # Restore the stack

    j done                  # Exit main

pow:                        # If the power is 0, the output is 1
    bne $a1, $0, powOne     # If the power is NOT 0, then go to next case
    li $v1, 1               # Set the output $v1 to 1
    j done                  # Return to main

    powOne:                 # Base case: if the power is 1, the output is the base
        bne $a1, 1, notOne  # If the power is NOT 1, then go to third case
        move $v1, $a0       # Set the output $v1 to the base ($a0)
        j done              # Return to main

    notOne:                 # If the power is greater than one, decrease it then multiply final output by base
        sub $sp, $sp, 4     # Extend the stack
        sw $ra, 0($sp)      # Save return address in the stack

        sub $a1, $a1, 1     # Subtract one from the power
        jal pow             # Recursive call with new parameters

        mul $v1, $v1, $a0   # Multiply the output by the base
        lw $ra, 0($sp)      # Restore $ra from the stack
        addi $sp, $sp, 4    # Restore the stack
        j done              # Return to caller

done:
    jr $ra                  # Return to caller
