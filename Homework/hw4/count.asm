# count.asm
# Program that counts the number of occurrences of a user inputted character in a string (I am assuming that upper and lower case characters are different)
    .data
str: .asciiz "This is the test string"  # Global string with 1 T, 4 t's, 2 h's, 3 i's, 4 s's, 2 e's, 1 r, 1 n, and 1 g
c: .asciiz "Enter a character: "
newline: .asciiz "\n"
    .text
    .align 2
    .globl main

main:
    addi $sp, $sp, -4       # Extend the stack
    sw $ra, 0($sp)          # Save return address in the stack

    li $v0, 4               # System call to print string
    la $a0, c               # Address of string
    syscall

    li $v0, 12              # System call to read character
    syscall
    move $t0, $v0           # Stores the read character to $t0

    la $t1, str             # Store the global string into $t1
    li $t2, 0               # This will be the counter that increments every time it sees the same character

    jal countOccurrences    # Jumps to countOccurrences helper function

    li $v0, 4               # System call to print string
    la $a0, newline         # Load address of the string to be printed (which is actually just a new line)
    syscall

    li $v0, 1               # System call to print integer
    move $a0, $t2           # Move the counter to the argument for the system call to print the int
    syscall

    lw $ra, 0($sp)          # Restore $ra from the stack
    addi $sp, $sp, 4        # Restore the stack

    j done

countOccurrences:
    lb $t3, 0($t1)          # Load the starting character of the string
    beq $t3, 0, done        # If the loaded byte is 0, we are done looping since there are no more characters to check
    addi $t1, $t1, 1        # Increment str pointer
    beq $t3, $t0, sameVal   # If the loaded byte is equal to the input character, jump to a helper function that increments the counter

    j countOccurrences

sameVal:
    addi $t2, $t2, 1        # Increment the counter by 1

    j countOccurrences

done:
    jr $ra                  # Return back to caller
