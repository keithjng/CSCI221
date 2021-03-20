#include "tree.hh"
#include <iostream>
#include <string>

using namespace std;

//////////////////////////////////////////////////////////////////////////////
tree_ptr_t
create_tree(const key_type& key,
            const value_type& value,
            tree_ptr_t left,
            tree_ptr_t right)
{
  tree_ptr_t newTree = new Tree(); // Create a new tree
  newTree->key_ = key; // Set the given attributes to the tree
  newTree->value_ = value;
  newTree->left_ = left;
  newTree->right_ = right;
  return newTree;
}


//////////////////////////////////////////////////////////////////////////////
void
destroy_tree(tree_ptr_t tree) // Recursively calls itself whenever it finds a branch from the tree
{
  if (tree->left_ != nullptr){
    destroy_tree(tree->left_);
  }
  if (tree->right_ != nullptr){
    destroy_tree(tree->right_);
  }
  delete tree;
}


//////////////////////////////////////////////////////////////////////////////
std::string
path_to(tree_ptr_t tree, key_type key)
{
  string takenPath = "";
  if (tree->key_ == key) {
    return takenPath;
  }
  if (tree->left_ != nullptr) {
    takenPath = path_to(tree->left_, key);
    if (takenPath != "-") { // As long as the recursive call does not return "-", this means there is a path to the key
      return "L" + takenPath;
    }
  }
  if (tree->right_ != nullptr) {
    takenPath = path_to(tree->right_, key);
    if (takenPath != "-") {
      return "R" + takenPath;
    }
  }
  if (takenPath == "") { // If takenPath comes back empty, then there is no key in the tree that matches the give key
    return "-";
  }
  return takenPath;
}


//////////////////////////////////////////////////////////////////////////////
tree_ptr_t
node_at(tree_ptr_t tree, std::string path)
{
  if (path == "") { // Base case for when we reach the end of the path
    return tree;
  }
  else if (path.front() == 'L') {
    return node_at(tree->left_, path.substr(1)); // Run the function again with the same path, just without the first element
  }
  else if (path.front() == 'R') {
    return node_at(tree->right_, path.substr(1));
  }
  return nullptr;
}
