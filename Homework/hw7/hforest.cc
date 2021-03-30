#include "hforest.hh"
#include "htree.hh"
#include "htree.cc"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Forest constructor
HForest::HForest()
{
}


// Method that returns the size of the forest
int HForest::size()
{
  return heap.size();
}

// Method that adds a tree to the forest
void HForest::add_tree(HTree::tree_ptr_t htree)
{
  heap.insert(heap.begin(), 1, htree);
}

// Helper function that checks if the value of the root node of a tree is greater than another tree's
bool compare_trees(HTree::tree_ptr_t t1, HTree::tree_ptr_t t2) {  // compare_trees() provided by Eitan
    return t1->get_value() < t2->get_value();
}

// Method that removes the tree with the largest value in the root
HTree::tree_ptr_t
HForest::pop_tree()
{
  if (heap.size() == 0) { // Check if there are no trees in the forest
    return nullptr;
  }
  else { // I couldn't figure out another way (I tried to figure out the largest value without sorting, but it kept breaking), so I used Eitan's sorting method
    std::pop_heap(heap.begin(), heap.end(), compare_trees); // Sorts the heap from the smallest root node value to the largest
    auto largest = heap.back();
    heap.pop_back();
    return largest;
  }
}
