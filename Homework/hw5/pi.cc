# include <iostream>

double gridpi(unsigned npoints)
{
  unsigned i, j; // Set i and j as integers that will be used as counters
  double pi, inside = 0, total = 0; // Establish pi as a variable with decimal points that will be the estimate of pi, distance will be the distance of a gridpoint from (0, 0). Inside will be used to count the number of gridpoints inside the circle, total counts the total number of gridpoints
  for (i = 0; i < (npoints); i++) { // Set i to 0, then loop as many times as i is less than the columns
    for (j = 0; j < (npoints); j++) { // Set j to 0, then loop as many times as j is less than the rows
      if ((j - (npoints / 2)) * (j - (npoints / 2)) + (i - (npoints / 2)) * (i - (npoints / 2)) <= (npoints / 2) * (npoints / 2)) { // Check to see if the gridpoint is inside the circle
        inside++; // Increment inside by 1 if the gridpoint is inside the unit circle
      }
      total++; // Increase the total number of counter gridpoints by 1
    }
  }
  pi = (inside / total) * 4; // Calculate an estimation of pi by dividing the number of points inside the circle by the total number of points, then multiplying by 4
  return pi;
}

int main()
{
  int n; // Establish n as a variable that will hold an integer (n is the number of gridpoints)
  // Uncomment the following 2 lines out if the program should be run with user input
  //std::cout << "Enter the number of gridpoints: "; // Ask the user to enter the number of gridpoints
  //std::cin >> n; // Store the number of gridpoints into the variable n
  double gp; // Establish another variable gp that will be the result found from gridpi
  // Comment the following line if the program should be run with user input
  n = 1000; // Set n to the desired number of columns
  gp = gridpi(n); // Call the gridpi helper function
  std::cout << "The estimate of pi is: " << gp; // Print the result from gridpi
}
