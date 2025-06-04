// LeetCode Problem (540) : Single Element in a Sorted Array.
// Difficulty : Medium
// Time Complexity : O(logn)
// Algorithm used : Binary Search

// DESCRIPTION : 

// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

// Return the single element that appears only once.

// Your solution must run in O(log n) time and O(1) space.

 

// Example 1:

// Input: nums = [1,1,2,3,3,4,4,8,8]
// Output: 2
// Example 2:

// Input: nums = [3,3,7,7,10,11,11]
// Output: 10
 

// Constraints:

// 1 <= nums.length <= 105
// 0 <= nums[i] <= 105



#include <iostream>
#include <vector>

using namespace std;

// Function to find the single non-duplicate element in a sorted array
int singleNonDuplicate(vector<int>& nums) {
    int start = 0, end = nums.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;  // Calculate the middle index

        // Edge case: If the first element is the unique one
        if (mid == 0 && (nums.size() == 1 || nums[0] != nums[1])) {
            return nums[0];  // Return the first element if it's unique
        }

        // Edge case: If the last element is the unique one
        if (mid == nums.size() - 1 && nums[mid] != nums[mid - 1]) {
            return nums[mid];  // Return the last element if it's unique
        }

        // If the middle element is unique (not equal to its neighbors)
        if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1]) {
            return nums[mid];  // Return the unique element
        }

        // The core logic: Checking the pattern in pairs
        if (mid % 2 == 0) {  // If `mid` is even
            if (nums[mid - 1] == nums[mid]) {
                end = mid - 1;  // Unique element must be on the left side
            } else {
                start = mid + 1;  // Unique element is on the right side
            }
        } else {  // If `mid` is odd
            if (nums[mid - 1] == nums[mid]) {
                start = mid + 1;  // Unique element is on the right side
            } else {
                end = mid - 1;  // Unique element must be on the left side
            }
        }
    }
    return -1; // If Single element is not present
}

int main() {
    // Example input: Every element appears twice except for one unique element
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4};

    cout << "Single non-duplicate element: " << singleNonDuplicate(nums) << endl;

    return 0;
}