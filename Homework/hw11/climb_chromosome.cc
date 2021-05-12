/*
 * Implementation for ClimbChromosome methods
 */

#include "climb_chromosome.hh"

#include <algorithm>
#include <cassert>
#include <random>
#include <chrono>
#include <iostream>

using namespace std;

// Construct like Chromosome class
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
ClimbChromosome::ClimbChromosome(const Cities* cities_ptr)
  : Chromosome(cities_ptr)
{
  assert(is_valid());
}

// Destructor
ClimbChromosome::~ClimbChromosome(){
  assert(is_valid());
}

void ClimbChromosome::mutate() {
  double chromOne = get_fitness(); // Evaluate the fitness of the current (original) chromosome
  uniform_int_distribution<unsigned int> distribution(0, order_.size()-1);
  unsigned int p = distribution(generator_); // Pick a random point p in the chromosome.
  Chromosome* variationOne = clone();
  auto placeholder = variationOne->order_[p];
  if (p == 0) { // swap with the city at index N-1
    variationOne->order_[p] = variationOne->order_[order_.size()-1];
    variationOne->order_[order_.size()-1] = placeholder;
  }
  else { // Swap the city at index p with the city at index p-1
    variationOne->order_[p] = variationOne->order_[p-1];
    variationOne->order_[p-1] = placeholder;
  }
  double chromTwo = variationOne->get_fitness(); // evaluate resulting chrom's fitness
  Chromosome* variationTwo = clone();
  auto placeholder = variationTwo->order_[p];
  if(p == order_.size()-1) { // If p==N-1, swap with the city at index 0 instead of at index N.
    variationTwo->order_[p] = variationTwo->order_[0];
    variationTwo->order_[0] = placeholder;
  }
  else { // Swap the city at index p (from the original chromosome) with the city at index p+1
    variationTwo->order_[p] = variationTwo->order_[p+1];
    variationTwo->order_[p+1] = placeholder;
  }
  double chromThree = variationTwo->get_fitness(); // Evaluate resulting chrom fitness
  // Choose the fittest chromosome of the three as the resulting mutated chromosome
  // if original chromosome is fittest, void, nothing happens
  if (chromTwo > chromOne && chromTwo > chromThree) {
    order_ = variationOne->order_;
  }
  else if (chromThree > chromOne){
    order_ = variationTwo->order_;
  }
}
