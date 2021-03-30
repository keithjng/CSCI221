/*
 * HForest: a class to represent a collection of HTrees with two values: a key
 * and a value.
 */

#pragma once

#include <memory>
#include <vector>
#include "htree.hh"

class HForest {
	public:
		using heap_t = std::vector<HTree::tree_ptr_t>;
		heap_t heap;
    using forest_ptr_t = std::shared_ptr<HForest>;

    //Initialize an empty forest
    HForest();
    ~HForest() = default;

    // The 3 methods of this class: 
    int size(); // Return the size of the forest
    void add_tree(HTree::tree_ptr_t htree); // Add an HTree to the forst
    HTree::tree_ptr_t pop_tree(); // Removes the HTree with the highest value in the root node

};
