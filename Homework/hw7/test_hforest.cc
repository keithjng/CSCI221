/*
 * test_hforest: Test the forest data structure.
 */

#include "htree.hh"
#include "hforest.hh"
#include <cassert>
#include <iostream>

using namespace std;

// Create a forest
HForest::forest_ptr_t create_forest() {
  return make_shared<HForest>();
}

// Create some test trees
HTree::tree_ptr_t create_big_tree()
{ // This is the tree from test_tree with 4 generations
  return
    make_shared<HTree>(5, 10, make_shared<HTree>(6, 9, make_shared<HTree>(7, 8), make_shared<HTree>(8, 7)), make_shared<HTree>(1, 1, make_shared<HTree>(2, 3), make_shared<HTree>(4, 5, make_shared<HTree>(15, 20))));
}

HTree::tree_ptr_t create_med_tree()
{ // Test tree with just 2 generations
  return
    make_shared<HTree>(50, 50, make_shared<HTree>(19, 21), make_shared<HTree>(76, 69));
}

HTree::tree_ptr_t create_small_tree()
{ // Test tree with just a root node
  return
    make_shared<HTree>(100, 200);
}

void test_hforest(const HForest::forest_ptr_t forest)
{
  auto big_tree = create_big_tree();
  auto med_tree = create_med_tree();
  auto small_tree = create_small_tree();

  // Testing add_tree
  forest->add_tree(big_tree);
  forest->add_tree(med_tree);
  forest->add_tree(small_tree);

  // Testing size
  assert(forest->size() == 3); // Testing the current forest
  auto empty_forest = create_forest();
  assert(empty_forest->size() == 0); // Testing an empty forest

  // Testing pop_tree
  assert(forest->pop_tree() == small_tree); // Testing the current forest
  assert(forest->size() == 2);
  assert(empty_forest->pop_tree() == nullptr); // Testing an empty forest
  cout << "All tests passed!" << endl;
}

int main()
{
  auto forest = create_forest();
  test_hforest(forest);

  return 0;
}
