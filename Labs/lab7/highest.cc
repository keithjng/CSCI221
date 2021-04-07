#include <iostream>

const int* highest(int val, const int* start, const int* finish)
{
  auto last = finish - 1; // Since finish technically goes after the array, identify the last element in the array
  if (val == *last) { // Base case for if the value is in the array
	  return last;
  }
  else if (*start == *last || val < *start || val > *last) { // Base case(s) for if the value is not in the array
	  return nullptr;
  }
  auto middle = start; // Start from the beginning of the array, count to determine the middle of the array
  for (int i = 0; i < (last - start) / 2; i++) {
	  middle += 1;
  }
  if (val < *middle) { // The input is to the left of the center
    return highest(val, start, middle);
  }
  else if (val > *middle || val == *(middle + 1)) { // The input is to the right of the center
    return highest(val, middle, last);
  }
  else if (val == *middle) { // The input is the middle value
    return middle;
  }
  else {
    return nullptr;
  }
}

int main()
{
    const int DATA_LEN = 9;
    // const int data[DATA_LEN] = { 1, 1, 1, 4, 4, 5, 6, 7, 10 }; // Example set
    // const int data[DATA_LEN] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }; // Set 1
    // const int data[DATA_LEN] = { 0, 1, 1, 2, 3, 5, 8, 13, 21 }; // Set 2
    const int data[DATA_LEN] = { -3, -1, -1, 2, 2, 2, 8, 32, 200 }; // Set 3

    // for (auto search : { 0, 1, 2, 4, 7, 8, 9, 10, 11 }) { // Expected output on example set: 1 at 2, 4 at 4, 7 at 7, 10 at 8, nothing else found
    // for (auto search : { 1, 2, 3, 4, 5, 6, 7, 8, 9 }) { // Expected output on set 1: All values - 1
    // for (auto search : { 21, 19, 5 + 3, 2) { // Expected output on set 2: 21 at 8, 5 + 3 at 6, 2 at 3, 19 not in set
    for (auto search : { 2, -2 , -3, 5 - 6, 198, 200, 203}) { // Expected output on set 3: 2 at 5, -3 at 0, -1 at 2, 200 at 8, -2, 298, 203 not in set
        const auto where = highest(search, data, data + DATA_LEN);
        std::cout << "Index of elem: " << search << " is: ";
        if (where == nullptr) {
            std::cout << "not found!" << std::endl;
        } else {
            std::cout << (where-data) << std::endl;
        }
    }
    return 0;
}
