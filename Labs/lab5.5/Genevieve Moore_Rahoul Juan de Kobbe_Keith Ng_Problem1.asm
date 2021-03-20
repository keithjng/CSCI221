# Problem1.asm
# Program that takes as input a string, transforms all lowercase letters to uppercase letters, then prints the modified string
    .data
prompt: .asciiz "Enter a string: "
str: .space 20

    .text
    .align 2
    .globl main

main:
    addi $sp, $sp, -4         # Extend the stack
    sw $ra, 0($sp)            # Save return address in the stack

    li $v0, 4                 # System call to print string
    la $a0, prompt            # Identify the string to be printed
    syscall

    la $a0, str               # Load the address of str into $a0 so it can be passed to convertString
    li $v0, 8                 # System call to read string
    syscall

    jal convertString         # Jump to the convertString function to begin converting the string

    li $v0, 4                 # System call to print string
    la $a0, str               # Load address of the string to be printed
    syscall

    j done                    # Restore stack, exit main

isLowerCase:                  # This is the first helper function convertString will call, it will output 1 if the character is lowercase
    addi $sp, $sp, -4         # Extend the stack
    sw $ra, 0($sp)            # Save return address in the stack

    blt $a0, 97, notLower     # If input character is lower than decimal value for the first lowercase character, 97, jump to charNotLowercase
    bgt $a0, 122, notLower    # If input character is greater than decimal value for the last lowercase character, 122, jump to charNotLowercase
    li $v0, 1                 # If we haven't jumped yet, that means the character is lowercase, and we set the register with our status to 1
    j done                    # Jump back to convertString

getUpperCase:
    addi $sp, $sp, -4         # Extend the stack
    sw $ra, 0($sp)            # Save return address in the stack

    blt $a0, 97, notLower     # Jumps to notLower if the input is less than 97 (and is thus not a lowercase letter)
    bgt $a0, 122, notLower    # Jumps to notLower if the input is greater than 122 (and is thus not a lowercase letter)

    sub $a0, $a0, 32          # Subtracts 32 from the input value, which would make the uppercase version
    move $v0, $a0             # Make the return value the new uppercase letter for convertString to retrieve

    j done                    # Jump back to convertString

notLower:                     # Enter this function if the character from isLowerCase or getUpperCase is not lowercase and thus the output should be 0
    li $v0, 0                 # Our character is not lowercase, so we set the status register to 0

    j done                    # Jump back to convertString

alreadyUpper:                 # Enter this function only if isLowerCase returns 0, in which case the character is already uppercase or cannot become lowercase
    addi $sp, $sp, -4         # Extend the stack
    sw $ra, 0($sp)            # Save return address in the stack
    move $v0, $a0             # Specifies that $v0 should be the originally read letter (otherwise the function ends early!)

    j done                    # Return to convertString

convertString:
    addi $sp, $sp, -8         # Extend the stack (this time by 8, since we are also saving $a0)
    sw $ra, 4($sp)            # Save return address in the stack
    sw $a0, 0($sp)            # Save $a0 in the stack

    lb $a0, 0($a0)            # Load a byte from the string into $a0 so it can be passed to isLowerCase
    beq $a0, 0, converted     # If the loaded byte is 0, there are no more characters to check, so we jump to converted

    jal isLowerCase           # Jump to the isLowerCase function, which will check to see if the loaded byte is lowercase

    beq $v0, 1, getUpperCase  # If the return value comes back as 1, then we branch to getUpperCase, since the loaded byte is lowercase
    beq $v0, 0, alreadyUpper  # Change $v0 to $a0 if $v0 is currently 0, since $a0 is already an uppercase letter or cannot become lowercase (maybe it's a number?)

    lw $a0, 0($sp)            # Restore $a0 from the stack
    lw $ra, 4($sp)            # Restore $ra from the stack
    addi $sp, $sp, 8          # Restore the stack

    sb $v0, 0($a0)            # Since $a0 just got restored, we can store the character from $v0 into $a0
    addi $a0, $a0, 1          # Increment to the next byte in the address $a0

    j convertString           # Jump back to convertString in order to check the next characters

converted:                    # An exit function that retrieves the return address as well as $a0 and restores the stack, then returns to caller
    lw $a0, 0($sp)            # Restore $a0 from the stack
    lw $ra, 4($sp)            # Restore $ra from the stack
    addi $sp, $sp, 8          # Restore the stack

    jr $ra                    # Return to caller

done:                         # An exit function that also retrieves the return address and restores the stack
    lw $ra, 0($sp)            # Restore $ra from the stack
    addi $sp, $sp, 4          # Restore the stack

    jr $ra                    # Return to caller
