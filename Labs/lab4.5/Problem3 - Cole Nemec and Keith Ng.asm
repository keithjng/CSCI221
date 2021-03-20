# Program that takes 2 integers and prints the larger of the 2 values
    .data
input1: .asciiz "Enter first integer: "
input2: .asciiz "Enter second integer: "

    .text
    .align 2
    .globl main
main:

  li $v0, 4         # Get syscall ready to print string
  la $a0, input1    # Set the argument for printing a string
  syscall

  li $v0, 5         # Get ready to read an int from the user
  syscall
  move $t0, $v0     # Stores the read int

  li $v0, 4         # Get syscall ready to print second input string
  la $a0, input2    # Set the argument for printing a string
  syscall

  li $v0, 5         # Get ready to read an int from the user
  syscall
  move $t1, $v0     # Stores the read int

  bgt $t0, $t1, input1GreaterThanInput2   # Check if first input is greater than second input

  li $v0, 1         # Syscall to print int
  move $a0, $t1     # Set argument for print
  syscall

  jr $ra            # Exit command

input1GreaterThanInput2:
  li $v0, 1         # Get syscall ready to print int
  move $a0, $t0     # Set the argument for printing int
  syscall

  jr $ra            # Exit command
