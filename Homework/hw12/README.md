# Traveling Salesperson Problem (Part 4)

This is my attempt at implementing a genetic algorithm search that uses threads for the extra credit problem.  

I used Eitan's code for cities and tsp, but I used my group's solutions for part 2 and 3 for Chromosome and Deme classes, as well as the subclasses ClimbChromosome and TournamentDeme. My group members from the previous homeworks were Austin Zeng and Geneveive Moore.

## Compiling Instructions

All files can be compiled with `make`. The Makefile creates an executable `./tsp`, which can be run on tsv files.

## Multithreading Implementation

To implement a genetic algorithm with multi-threading, I labeled the old version of the genetic algorithm search "orig_ga_search". I would use thiss function later inside the new ga_search. I then found a random sequence from the cities and set that as the best ordering.

For the program to run the genetic algorithm search, I define a lambda that will call the orig_ga_search helper function. The lambda also compares the old distance with the new one. By doing this, I can use a for loop to have each of the defined number of threads run the ga search simultaneously.

Once the threads have gone through the desired number of iterations, they are recombined with join().

## Results

My laptop is coming up on 7 years old and it's 4 cores were struggling throughout the duration of my testing.

Using a total of 2,000,000 iterations, with the example parameters of 1000 in a population and 0.3 as a mutation rate, as well as 4 threads, my program ran for 4 minutes and 33 seconds.

This might sound like an astonishingly high number, but you will be glad to hear that it was significantly shorter than my run with 1 thread. Using the same parameters but with a single thread, my program ran for about 6 minutes and 22 seconds.

My best results were 8878.13, which didn't beat the value in the example but beat my previous results (from part 3) by 3828.27. The best found path can be found in the attached shortest.tsv file. 

## Update on Results 

After my submission, I decided to try running my code on a different machine. I got my dad's Macbook and ran the code. With 4 threads, the code ran in a minute and 33 seconds. With just one thread, it took 5 minutes and 7 seconds. I feel like these results were much more conclusive and showcase the power of multithreading! The results are nowhere near the examples, but they still felt pretty satisfying to see. 
