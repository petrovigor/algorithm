#include <vector>

#if _DEBUG
#include <iostream>
#endif //_DEBUG

#include <cassert> //debug only

bool binarySearch(const std::vector<int>& arr, const size_t from, const size_t to, const int target) {
#if _DEBUG
  std::cout << "bs: from: " << from << " to: " << to << " target: " << target << std::endl;

  for(size_t i = from; i <= to; ++i) {
    std::cout << arr[i] << ", ";
  }
  std::cout << std::endl;
#endif //_DEBUG

  if(arr.empty())
    return false;

  const size_t n = to - from;
  const size_t mid = from + (n / 2);

#if _DEBUG
  std::cout << "mid = " << mid << std::endl;
#endif //_DEBUG

  if(target == arr[mid]) {
#if _DEBUG
    std::cout << "found!" << std::endl << std::endl;
#endif //_DEBUG
    return true;
  }

  if(target > arr[mid]) {
    return binarySearch(arr, mid + 1, to, target);
  } else {
    return binarySearch(arr, from, mid, target);
  }

  return true;
}

bool binarySearch(const std::vector<int>& arr, const int target) {
  if(arr.empty())
    return false;

  return binarySearch(arr, 0, arr.size() - 1, target);
}

int main() {
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

  return 0;
}
