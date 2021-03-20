# sum.asm
# Program that takes positive value n and uses a loop to calculate the sum from 1 to n

    .data
n: .asciiz    "Enter a positive value (n): "

    .text
    .globl main

main:
    li $v0, 4             # System call to print string
    la $a0, n             # Address of string
    syscall

    li $v0, 5             # System call to read an integer
    syscall
    move $t0, $v0         # Stores the read integer

    ble $t0, 0, exit      # Exits if the input is 0, negative, or not an integer

    li $t1, 0             # Set an integer to be the counter (i)
    li $v1, 0             # Set an integer to be the output (the total sum)

    loop:
        addi $t1, $t1, 1      # Increments the i counter by 1 each loop
        add $v1, $v1, $t1     # Add the value of i to the output
        beq $t0, $t1, stop    # Checks to see if i is equal to n, if it is, branch to stop
        j loop                # If i and n are not equal, loop again

    stop:
        li $v0, 1             # System call to print integer
        move $a0, $v1         # Move the output to the argument for printing
        syscall

        jr    $ra             # Return control back to the caller

    exit:
        jr    $ra             # Return control back to the caller (this happens if input is not a positive integer)
