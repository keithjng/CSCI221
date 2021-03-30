# Forests in C++

This assignment extended the tree data structure from last homework into a collection of trees, called a forest.

Compiling instructions:
- For htree:
```
clang++ --std=c++17 test_htree.cc htree.cc -o htree.exe
```
Then run the created `htree.exe` file.

- For hforest:
```
clang++ --std=c++17 test_hforest.cc hforest.cc -o hforest.exe
```
Then run the created `hforest.exe` file.

## Added Methods

To `htree.cc`, I added:
- `get_key`, which returns a node's key

- `get_value`, which returns a node's value

- `get_child`, which returns a node's child  

- `path_to`, which returns a list of directions in order to reach a specified key

To `hforest.hh`, initializes a forest and specifies the 3 methods a forest uses. These methods were added to `hforest.cc`:

- `size`, which returns the size of a forest

- `add_tree`, which adds a tree to the forest

- `pop_tree`, which takes away the tree with the highest root value, returning it

## Testing

Both htree and hforest had their own test files, `test_htree.cc` and `test_forest.cc` respectively. These files created the data types they were supposed to and ran the methods, as well as tested edge cases.

I utilized `assert` for this section to see which parts of the code gave an unexpected output.

## Learned Things
I learned a lot of new methods this homework, especially those around the `vector` library. I used the vector class to store the trees in a forest, so a lot of methods were used to manipulate a vector.

I also learned that I need to stop procrastinating on CS homework, as I tend to give myself less time than I really need to complete these assignments. 
