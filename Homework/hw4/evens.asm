# evens.asm
# Program that determines the number of even values in an array
    .data
arr: .word 3, 5, 8, 10, 15
size: .word 5
    .text
    .align 2
    .globl main

main:
    addi $sp, $sp, -4       # Extend the stack
    sw $ra, 0($sp)          # Save return address in the stack

    la $t0, arr             # Store the global array into $t0
    la $t1, size            # Store the length of the array into $t1 for future use
    li $t2, 0               # This will be the counter that increments when a number is even

    jal numEvens            # Jumps to numEvens helper function

    li $v0, 1               # System call to print integer
    move $a0, $t2           # Move the counter to the argument for the system call to print the int
    syscall

    lw $ra, 0($sp)          # Restore $ra from the stack
    addi $sp, $sp, 4        # Restore the stack

    j done                  # Jump to done

numEvens:
    beq $t1, $t0, done      # If the array size reaches 0, we are done looping since we have checked every value in the array
    lw $t3, 0($t0)          # Load a number from the array

    sub $t1, $t1, 1         # Decrease size counter by 1
    addi $t0, $t0, 4        # Increment arr pointer (since a word is 4 bytes)

    and $t4, $t3, 1         # This makes the value of $t4 0 if the number is even and 1 if the number is odd

    beq $t4, $0, isEven     # If the number in the array is even, jump to a helper function that increments the counter

    j numEvens              # Loop back

isEven:
    addi $t2, $t2, 1        # Increment the evens counter by 1

    j numEvens              # Jump back to loop

done:
    jr $ra                  # Return back to caller
