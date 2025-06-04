/*
LeetCode Problem (217): Contains Duplicate
Difficulty : Easy
Time Complexity : O(n log n)
Algorithm used : Sorting + Linear Scan

DESCRIPTION :

Given an integer array `nums`, return `true` if any value appears at least twice in the array, 
and return `false` if every element is distinct.

The task is to detect duplication efficiently. Using sorting brings equal values next to each other,
so we only need to scan once to find duplicates.

Example 1:
Input: nums = [1, 2, 3, 1]
Output: true
Explanation: The number 1 is present more than once.

Example 2:
Input: nums = [1, 2, 3, 4]
Output: false
Explanation: All elements are unique.

Example 3:
Input: nums = [1, 1, 1, 3, 3, 4, 3, 2, 4, 2]
Output: true
Explanation: Multiple elements are repeated.

Constraints:
1 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
*/

#include <iostream>
#include <vector>
#include <algorithm> // for sort()

using namespace std;

// Function to check if array contains any duplicates
bool containsDuplicate(vector<int>& nums) {
    int n = nums.size();

    // Sort the array so that duplicates come next to each other
    sort(nums.begin(), nums.end());

    // Check consecutive elements for duplication
    for (int i = 1; i < n; i++) {
        if (nums[i - 1] == nums[i]) {
            return true; // Duplicate found
        }
    }

    return false; // No duplicates found
}

int main() {
    // Example usage
    vector<int> nums = {1, 2, 3, 4, 1};

    if (containsDuplicate(nums)) {
        cout << "Duplicate exists in the array." << endl;
    } else {
        cout << "All elements are unique." << endl;
    }

    return 0;
}