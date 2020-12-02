#include "include/reversePolishNotation.h"
#include "include/binarySearch.h"

#include <cassert> //debug only

void test_binarySearch() {
  std::vector<int> arr1 { 10, 11, 16, 20 };
  assert(binarySearch(arr1, 10));
  assert(binarySearch(arr1, 11));
  assert(binarySearch(arr1, 16));
  assert(binarySearch(arr1, 20));

  std::vector<int> arr2 { 10 };
  assert(binarySearch(arr2, 10));

  std::vector<int> arr3 { 1, 2, 3 };
  assert(binarySearch(arr3, 1));
  assert(binarySearch(arr3, 2));
  assert(binarySearch(arr3, 3));

  std::vector<int> arr4 { };
  assert(!binarySearch(arr4, 1));
}

void test_reversePolishNotation() {
  assert(ReversePolishNotation("") == "");
  assert(ReversePolishNotation("2+3*5+9") == "2 3 5 *+9 +");
  assert(ReversePolishNotation("2*9+9+9/8/7/6/5*1*3") == "2 9 *9 +9 8 /7 /6 /5 /1 *3 *+");
  assert(ReversePolishNotation("1+2+3+4+5") == "1 2 +3 +4 +5 +");
  assert(ReversePolishNotation("1+2-3+4-5") == "1 2 +3 -4 +5 -");
}

int main() {
  test_reversePolishNotation();
  test_binarySearch();

  return 0;
}
