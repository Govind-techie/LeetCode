// LeetCode Problem (852) : Peak Index in a Mountain Array.

// Difficulty : Medium.

// Time Complexity : O(logn)

// Algorithm used : Binary Search.



// DESCRIPTION :

// You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

// Return the index of the peak element.

// Your task is to solve it in O(log(n)) time complexity.

 

// Example 1:

// Input: arr = [0,1,0]

// Output: 1

// Example 2:

// Input: arr = [0,2,1,0]

// Output: 1

// Example 3:

// Input: arr = [0,10,5,2]

// Output: 1

 

// Constraints:

// 3 <= arr.length <= 105
// 0 <= arr[i] <= 106
// arr is guaranteed to be a mountain array



#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    int start = 0;
    int end = arr.size() - 1;

    while (start < end) {
        int mid = start + (end - start) / 2;
        
        if (arr[mid] > arr[mid + 1]) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    return start;
}

int main() {
    vector<int> arr = {0, 2, 3, 5, 3, 2, 0}; // Example input
    int peakIndex = peakIndexInMountainArray(arr);
    cout << "Peak Index: " << peakIndex << endl;
    return 0;
}
