/*
LeetCode Problem 560: Subarray Sum Equals K
Difficulty: Medium
Algorithm: Hash Map
Time Complexity: O(n)
Space Complexity: O(n)

Description:

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to count number of subarrays with sum equal to k
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    m[0] = 1; // Handle subarrays starting at index 0

    int sum = 0;
    int subArrayCount = 0;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];

        // Check if there is a prefix sum that we can subtract to get k
        if (m.find(sum - k) != m.end()) {
            subArrayCount += m[sum - k];
        }

        // Record the current prefix sum
        m[sum]++;
    }

    return subArrayCount;
}

int main() {
    vector<int> nums = {1, 2, 3, -1, 2, 1};
    int k = 3;

    int result = subarraySum(nums, k);
    cout << "Number of subarrays with sum " << k << " is: " << result << endl;

    return 0;
}