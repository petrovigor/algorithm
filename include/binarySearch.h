#pragma once

#include <vector>

//search for a number 'target' in the array 'arr'
//arr should be sorted before passed into the fn
//searches with O(log n) complexity
//returns false if number is not found, returns true instead
bool binarySearch(const std::vector<int>& arr, const int target);

//search for a number 'target' in the sorted two-dimensional matrix
bool matrixBinarySearch(const std::vector<std::vector<int>>& mat, const int target);
