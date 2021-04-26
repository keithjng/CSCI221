#include "cities.hh"

#include <iostream>
#include <fstream>
#include <cmath>
#include <cassert>

std::istream& operator>>(std::istream& is, Cities& cities) // Allows for the reading and filling of a Cities object
{
	int x; int y;
	while (is >> x) { // Make a pair from each x and y value and add it to the list of cities
		is >> y;
		cities.city_list.push_back(std::make_pair(x,y));
	}
	return is;
}

std::ostream& operator<<(std::ostream& os, Cities& cities) // Allows for the outputting of the Cities object
{
 if (cities.city_list.size() == 0) { // Check if there are no cities in the list
   os << "There seem to be no cities in the city list!";
 }
 else { // Prints each city's x value and y value with a space in between
   int i = 0;
   while(i < cities.city_list.size()) {
     os << cities.city_list[i].first << " " << cities.city_list[i].second;
     i++;
   }
 }
 return os;
}

double Cities::total_path_distance(const permutation_t& ordering) const // Calculate the total distance between each of the cities
{
    assert(city_list.size() == ordering.size()); // Check that the size of the city list is the same as the size of ordering, otherwise, throw an error
    double dist = 0;
    for(int i = 0; i < ordering.size() - 1; i++) // Add the distances between the cities to the dist variable
    {
      dist += std::hypot((city_list[ordering[i + 1]].first - city_list[ordering[i]].first), (city_list[ordering[i + 1]].second - city_list[ordering[i]].second));
    }
    dist += std::hypot((city_list[ordering.front()].first - city_list[ordering.back()].first), (city_list[ordering.front()].second - city_list[ordering.back()].second)); // Adds the distance between the first and last cities
    return dist;
}

Cities Cities::reorder(const permutation_t& ordering) const // Returns a new Cities object in a different order (based on the index)
 {
    Cities city;
    for(int i = 0; i < ordering.size(); i++)
    {
      city.city_list.push_back(city_list[i]);
    }
    return city;
  }

// Provided test code for cities.cc:
// int main()
// {
//   auto fin = std::ifstream("five.tsv");
//   Cities cities;
//   fin >> cities;
//   std::cout << cities.total_path_distance({ 0, 1, 2, 3, 4 }) << "\n"; // Should be 48.8699
//   std::cout << cities.total_path_distance({ 3, 2, 4, 0, 1 }) << "\n"; // Should be 53.42.43
//
//   return 0;
// }
