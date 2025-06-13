/*
LeetCode Problem 974: Subarray Sums Divisible by K
Difficulty: Medium
Algorithm: Hash Map
Time Complexity: O(n)
Space Complexity: O(n)

Description:
Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
Example 2:

Input: nums = [5], k = 9
Output: 0
 

Constraints:

1 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
2 <= k <= 104
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to count subarrays divisible by k
int subarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    m[0] = 1;  // Base case: sum = 0 is divisible by k

    int sum = 0;
    int count = 0;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];

        // Normalize modulo to handle negative values
        int mod = ((sum % k) + k) % k;

        // If mod has been seen before, add its frequency to count
        if (m.find(mod) != m.end()) {
            count += m[mod];
        }

        // Increase the frequency of current mod
        m[mod]++;
    }

    return count;
}

int main() {
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;

    int result = subarraysDivByK(nums, k);
    cout << "Count of subarrays divisible by " << k << " is: " << result << endl;

    return 0;
}