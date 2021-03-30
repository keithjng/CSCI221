/*
 * HTree: a class to represent a tree node with two values: a key
 * and a value.
 */

#include "htree.hh"

// Tree planter
HTree::HTree(HTree::key_t key,
             HTree::value_t value,
             HTree::tree_ptr_t left,
             HTree::tree_ptr_t right) {
               key_ = key;
	             value_ = value;
	             left_ = left;
               right_ = right;
             }

// Method that returns a node's key
HTree::key_t
HTree::get_key() const
{
	return key_;
}

// Method that returns a node's value
HTree::value_t
HTree::get_value() const
{
  return value_;
}

// Methoed that returns a node's child
HTree::tree_ptr_t
HTree::get_child(Direction dir) const
{
  if (dir == HTree::Direction{0}) { // Checks which way the input is pointing, 0 is left in Direction, 1 is right
		return left_;
	}
  else if (dir == HTree::Direction{1}) {
		return right_;
	}
  else { // If dir isn't valid, return nullptr
    return nullptr;
  }
}

// Return an optional list of directions from root to a node of a given key.
// If key not contained in this tree, returns nullptr
HTree::possible_path_t
HTree::path_to(key_t key) const
{
  if (get_key() == key) { // This is the base case, when the key of a node is equal to the key we are looking for
    return possible_path_t(new path_t());
  }
  if (get_child(Direction{0})) { // Check if there is a left child
    auto check_left = get_child(Direction{0})->path_to(key); // Recursively searches the left child
 	  if (check_left) { // Checks if there is a path on the left
		  check_left->push_front(Direction{0}); // Adds the left path to the front of the list
 		  return check_left;
    }
  }
  if (get_child(Direction{1})) { // Same process but on the right child
	  auto check_right = get_child(Direction{1})->path_to(key);
 	  if (check_right) {
		  check_right->push_front(Direction{1});
	 	  return check_right;
    }
  }
  return nullptr;
}
