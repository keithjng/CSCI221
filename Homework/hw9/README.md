# Traveling Salesperson Problem (Part 1)

While door-to-door salespeople simply go door to door, the traveling salesperson problem asks the question: what if they couldn't go door-to-door? What if they had an inherent fear of adjacent things, or perhaps the next-door neighbors were in fact 2 miles away because the poor salesperson was selling products in the butt-nowhere cheese farms of Wisconsin? What would the salesperson do to minimize the distance traveled while still reaching all those doors he needs to knock on?

This problem has no solution, at least not one accepted as the definitive fastest way to find a path between the places the salesperson needs to get to. However, the objective of this homework assignment is to randomly generate some orders of a list of points, denoted "cities", that the salesperson must reach. The objective is then to compare these random orders with other orders to find the best ordering out of a set number of tests (in my case, I ran it a million times because the assignment suggested it).

## Compiling instructions

- First, to check the Cities class and associated functions, uncomment the main function at the end of cities.cc and compile with:
```
clang++ --std=c++17 cities.cc -o cities.exe
```
This will create an executable file that can be run to check cities.cc

- To run the random traveling salesperson part, compile with:
```
clang++ --std=c++17 tsp.cc -o tsp.exe
```
This creates an executable file that can be run, taking a tsv file as input. For example, to run tsp on the challenge cities, write  `./tsp ./challenge.tsv`.

## Added Methods

To `cities.cc`, I added:
- `>>` and `<<` operators, which allow for the reading and writing of Cities objects  

- `total_path_distance`, which calculates the total distance between cities in the order given

- `reorder`, which returns a new Cities object that is a rearrangement of a given Cities object

To `tsp.cc`, I added:

- `random_permutation`, which creates a random permutation of numbers from 0 to len - 1, which can be used to represent an order for the list of cities  

- The `main` function of tsp.cc runs the randomized search

## Learned Things

This homework was really interesting because we got to interact with and write to external files. I also used a lot of cool new functions imported from other libraries, like hypot and random_shuuffle.

Working with gnuplot was also really cool! It is a really simple way to visualize data and create graphs quickly. While I think there is still a lot for me to learn in it (customization options and stuff like that), using it here was a great first exposure to the tool.  
