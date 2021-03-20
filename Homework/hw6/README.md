# Trees in C++

This assignment was designed to help students better understand the tree data structure in C++.

The files tree.cc and test_tree.cc were created for homework 6 of Reed College's CSCI 221 class. tree.hh is a header file provided by the instructor and represents an uneditable public API.

## Design Choices

My solutions primarily relied on recursion to complete their tasks. This is because recursion seemed like the easiest way to achieve my goal. Most of the functions needed to iterate throughout the whole tree, and calling on the same function to continue what it was doing but with a new node was easier than trying to figure out a stopping point with a while or for loop.

## Learned Things

From this assignment, I sort of have a feel as to how trees work in C++. I can see how they are similar to the trees in Python (I remember trees in Python needed to use self.left and self.right, similar to the pointer in C++), but I also realize how they are different.

I learned and used 2 built-in functions: front and substr. front identifies the first element while substr can break a string into a substring at a certain index. Using these functions together made it easy to split up and follow the given path in node_at.
