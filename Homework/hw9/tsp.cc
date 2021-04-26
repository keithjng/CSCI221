#include "cities.hh"
#include "cities.cc"

#include <iostream>
#include <fstream>
#include <algorithm>

Cities::permutation_t random_permutation(unsigned len) // Generates a random new order of the numbers 0 to len - 1
{
	Cities::permutation_t shuffled;
	for(int i = 0; i < len; i++) { // Add all the numbers that need to be scrambled to a new vector
		shuffled.push_back(i);
	}
	std::random_shuffle(shuffled.begin(), shuffled.end()); // Use the random shuffle function from the STL
	return shuffled;
}

int main(int argc, char** argv)
{
	std::ifstream input_file(argv[1]); // Opens the input file
	if (!input_file.is_open()) { // Check if the input file has been opened
		std::cerr << "The input file could not be accessed." << "\n";
	}
	std::ofstream output_file("shortest.tsv"); // Sets up an output file for the list of cities with the shortest path
	if (!output_file.is_open()) {
		std::cerr << "The output file, shortest.tsv, could not be accessed." << "\n";
	}
  else {
    Cities cities; // Make a new Cities object
  	input_file >> cities; // Read the input file into the Cities object
  	int number_iterations = 1000000; // Set the total number of iterations to one million
    Cities::permutation_t random_order_1 = random_permutation(cities.get_cities().size()); // Create a random series of cities
  	double calc_dist_1 = cities.total_path_distance(random_order_1); // Calculate the distance of the current random order
  		for(int i = 1; i < number_iterations; i++) {
  			Cities::permutation_t random_order_2 = random_permutation(cities.get_cities().size()); // Create a second random series of cities to compare to the current best
  			double calc_dist_2 = cities.total_path_distance(random_order_2);
  			if(calc_dist_1 > calc_dist_2) { // If the distance of the new order is less than the best one, the new becomes the best
          random_order_1 = random_order_2;
  				calc_dist_1 = calc_dist_2;
  				std::cout << i << " " << calc_dist_1 << std::endl; // Print the iteration and distance
  			}
  		}
    for(int i = 0; i < random_order_1.size(); i++) {
      output_file << random_order_1[i] << std::endl;
    }
  }
	return 0;
}
