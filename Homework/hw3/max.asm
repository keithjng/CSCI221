# max.asm
# Program that takes x numbers and returns the highest number

    .data
x: .asciiz    "Enter how many values you will enter (x): "
input: .asciiz    "Enter a value: "

    .text
    .globl main

main:
    li $v0, 4             # System call to print string
    la $a0, x             # Address of string
    syscall

    li $v0, 5             # System call to read an integer
    syscall
    move $t0, $v0         # Stores the read integer

    ble $t0, 0, exit      # Exits if the input is 0, negative, or not an integer

    li $t1, 0             # Set an integer to be the counter (i)
    li $v1, 0             # Set an integer to be the output (the highest value)

    loop:
        addi $t1, $t1, 1      # Increments the i counter by 1 each loop
        li $v0, 4             # System call to print string
        la $a0, input         # Address of string
        syscall

        li $v0, 5             # System call to read an integer
        syscall
        move $t2, $v0         # Stores the read integer

        bgt $t2, $v1, new_max # Check if the new input is bigger than the highest value
        beq $t0, $t1, stop    # Checks to see if i is equal to x, if it is, branch to stop
        j loop                # If i and x are not equal, loop again

    new_max:
        move $v1, $t2         # Since the new input is greater than the previous max, max switches to the latest input
        beq $t0, $t1, stop    # Checks to see if i is equal to x, if it is, branch to stop, since the stated number of inputs has been reached
        j loop                # If i and x are not equal, jump back to loop 

    stop:
        li $v0, 1             # System call to print biggest number
        move $a0, $v1         # Move the output to the argument for printing
        syscall

        jr    $ra             # Return control back to the caller

    exit:
        jr    $ra             # Return control back to the caller (this happens if input x is not a positive integer)
