#include "../include/binarySearch.h"

#if _DEBUG
#include <iostream>
#endif //_DEBUG

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
  std::cout << "mid = " << mid << " n = " << n << std::endl;
#endif //_DEBUG

  if(target == arr[mid]) {
#if _DEBUG
    std::cout << "found!" << std::endl << std::endl;
#endif //_DEBUG
    return true;
  }

  if(n == 0)
    return false;

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

std::size_t matrixBinarySearch(const std::vector<std::vector<int>>& mat, const size_t from, const size_t to, const int target) {
  constexpr size_t not_found = std::numeric_limits<std::size_t>::max( );

  if(mat.empty())
    return not_found;

  const size_t n = to - from;
  const size_t mid = from + (n / 2);

  const std::vector<int>& arr = mat[mid];

  if(target >= arr.front() && target <= arr.back()) {
    std::cout << "index: " << mid << std::endl;
    return mid;
  }

  if(n == 0)
    return not_found;

  if(target > arr.back()) {
    return matrixBinarySearch(mat, mid + 1, to, target);
  } else {
    return matrixBinarySearch(mat, from, mid, target);
  }

  return not_found;
}

bool matrixBinarySearch(const std::vector<std::vector<int>>& mat, const int target) {
  constexpr size_t not_found = std::numeric_limits<std::size_t>::max( );

  if(mat.empty())
    return false;

  const size_t index = matrixBinarySearch(mat, 0, mat.size() - 1, target);
  if(index == not_found)
    return false;

  const auto& arr = mat[index];
  return binarySearch(arr, target);
}
