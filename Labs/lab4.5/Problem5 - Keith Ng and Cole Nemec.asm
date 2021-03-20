# Program that takes an input and prints 1 if the input is considered lowercase in ASCII
    .data
inputCharMessage: .asciiz "Enter character: "

    .text
    .align 2
    .globl main
main:
    li $v0, 4                       # Get syscall ready to print string
    la $a0, inputCharMessage        # Set the argument for printing a string
    syscall

    li   $v0, 12                    # set up reading of input char
    syscall
    move $t0, $v0                   # store input char in $t0

    blt $t0, 97, charNotLowercase   # If input character is lower than decimal value for the first lowercase character, 97, jump to charNotLowercase
    bgt $t0, 122, charNotLowercase  # If input character is greater than decimal value for the last lowercase character, 122, jump to charNotLowercase
    li $t1, 1                       # If we haven't jumped yet, that means the character is lowercase, and we set the register with our status to 1
    j printStatus                   # Now that we've set the status register, we go to print the status

charNotLowercase:
    li $t1, 0         # Our character is not lowercase, so we set the status register to 0
    j printStatus     # Now that we've set the status register, we go to print the status

printStatus:
    li $v0, 1         # Get syscall ready to print int
    move $a0, $t1     # move the status register ($t1) to the argument for the print-int syscall
    syscall

    j done            # We're done with what we need the program to do, so now we leave

done:
    jr $ra            # Exit
