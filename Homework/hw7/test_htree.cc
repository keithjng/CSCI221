/*
 * test_tree: A simple unit test for the Tree data structure.
 */

#include "htree.hh"
#include <cassert>
#include <iostream>

using namespace std;

// Create an elaborate example test tree:
HTree::tree_ptr_t create_test_tree()
{
  return
    make_shared<HTree>(5, 10, make_shared<HTree>(6, 9, make_shared<HTree>(7, 8), make_shared<HTree>(8, 7)), make_shared<HTree>(1, 1, make_shared<HTree>(2, 3), make_shared<HTree>(4, 5, make_shared<HTree>(15, 20))));
}

void test_htree(const HTree::tree_ptr_t root)
{
  // Testing get_key
  assert(root->get_key() == 5); // Get the key of the root node
  assert(root->get_child(HTree::Direction{0})->get_key() == 6); // Get the key of the left child
  assert(root->get_child(HTree::Direction{1})->get_child(HTree::Direction{1})->get_child(HTree::Direction{0})->get_key() == 15); // Get the key of the farthest node

  // Testing get_value
  assert(root->get_value() == 10); // Get the value of the root node
  assert(root->get_child(HTree::Direction{0})->get_value() == 9); // Get the value of the left child
  assert(root->get_child(HTree::Direction{1})->get_child(HTree::Direction{1})->get_child(HTree::Direction{0})->get_value() == 20); // Get the value of the farthest node

  // Testing get_child
  assert(root->get_child(HTree::Direction{0}) == root->left_); //Test left child
  assert(root->get_child(HTree::Direction{1}) == root->right_); //Test right child
  assert(root->get_child(HTree::Direction{0})->get_child(HTree::Direction{1}) == root->left_->right_); //Test right child of left child

  // Testing path_to
  assert(*(root->path_to(5)) == HTree::path_t({ })); // Test root node
  assert(*(root->path_to(6)) == HTree::path_t({HTree::Direction{0}})); // Test left child
  assert(*(root->path_to(2)) == HTree::path_t({HTree::Direction{1}, HTree::Direction{0}})); // Test left child of right child
  assert((root->path_to(17)) == nullptr); // Test a node not in tree
  cout << "All tests passed!" << endl;
}

int main()
{
  auto root = create_test_tree();
  test_htree(root);

  return 0;
}
