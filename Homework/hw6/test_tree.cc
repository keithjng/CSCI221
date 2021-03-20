#include "tree.hh"
#include <iostream>
#include <cassert>

using namespace std;

int main() {
  // Test create_tree function
  tree_ptr_t test = create_tree(5, 10);
  cout << "Tree created! Root has key " << test->key_ << " and value " << test->value_ << endl;
  test->left_ = create_tree(6, 9, create_tree(7, 8), create_tree(8, 7)); // Add a left child with 2 children
  cout << "Left node created! Node has key " << test->left_->key_ << " and value " << test->left_->value_ << endl;
  test->right_ = create_tree(1, 1, create_tree(2, 3), create_tree(4, 5, create_tree(15, 20))); // Add a right child with 2 children and a grandchild
  cout << "Right node created! Node has key " << test->right_->key_ << " and value " << test->right_->value_ << endl;

  // Test path_to function
  cout << "The path to the key 5 is " << path_to(test, 5) << endl;
  cout << "The path to the key 6 is " << path_to(test, 6) << endl;
  cout << "The path to the key 1 is " << path_to(test, 1) << endl;
  cout << "The path to the key 7 is " << path_to(test, 7) << endl;
  cout << "The path to the key 8 is " << path_to(test, 8) << endl;
  cout << "The path to the key 2 is " << path_to(test, 2) << endl;
  cout << "The path to the key 4 is " << path_to(test, 4) << endl;
  cout << "The path to the key 15 is " << path_to(test, 15) << endl;
  cout << "The path to the key 3 is " << path_to(test, 3) << endl;
  cout << "The path to the key a is " << path_to(test, 'a') << endl;

  // Test node_at function
  cout << "The node at the root is " << node_at(test, "") << endl;
  cout << "The node from path L is " << node_at(test, "L") << endl;
  cout << "The node from path R is " << node_at(test, "R") << endl;
  cout << "The node from path LL is " << node_at(test, "LL") << endl;
  cout << "The node from path LR is " << node_at(test, "LR") << endl;
  cout << "The node from path RL is " << node_at(test, "RL") << endl;
  cout << "The node from path RR is " << node_at(test, "RR") << endl;
  cout << "The node from path RRL is " << node_at(test, "RRL") << endl;
  cout << "The node from path 123 is " << node_at(test, "123") << endl;
  cout << "The node from path RRR is " << node_at(test, "RRR") << endl;

  // Test destroy_tree function
  destroy_tree(test);
	std::cout << "Tree has been destroyed!" << std::endl;
  return 0;
}
