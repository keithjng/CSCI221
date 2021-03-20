# Program that takes an input and prints the corresponding uppercase letter if input is a lowercase letter, otherwise outputs 0
    .data
inputLetter: .asciiz "Enter a letter: "

    .text
    .align 2
    .globl main
main:
    li $v0, 4               # System call to print string
    la $a0, inputLetter     # Identify the string to be printed
    syscall

    li $v0, 12              # System call to read character
    syscall
    move $t0, $v0           # Stores the read character

    blt $t0, 97, notLower   # Jumps to notLower if the input is less than 97 (and is thus not a lowercase letter)
    bgt $t0, 122, notLower  # Jumps to notLower if the input is greater than 122 (and is thus not a lowercase letter)

    sub $t0, $t0, 32        # Subtracts 32 from the input value, which would make the uppercase version

    li $v0, 11              # System call to print character
    move $a0, $t0           # Character to be printed is $t0, the uppercase version of the input
    syscall

    jr    $ra               # Return control back to the caller

notLower:
    li $v0, 1               # System call to print number
    move $a0, $0            # Number to be printed is 0
    syscall

    jr    $ra               # Return control back to the caller
