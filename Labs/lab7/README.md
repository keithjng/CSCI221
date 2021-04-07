# Highest

This assignment was done for lab 7 of Reed College's CSCI 221. Its purpose is to return the highest element that contains a given value in an array.

## Makefile

`highest.cc` is compiled by typing `make` into the command line and can be run with `./highest`. The `makefile` also copies and converts `.txt` files added to the `makefile` to `.wc` files.

## Debugging

To be honest, I relied on print statements for a lot of debugging (old habits die hard). However, since the assignment was done recursively, GDB's "where" function and breakpoints were really useful for identifying which lines broke. They were more useful than print statements, since print statements would just dump a bunch of facts when the function ran recursively from which it would be hard to discern what was broken.

## Clean Up

Clean up, everybody, everywhere! Deleting the created files off your drive is simple, just type `make clean` and all `.o` and `.wc` files will be deleted from this directory automatically.
