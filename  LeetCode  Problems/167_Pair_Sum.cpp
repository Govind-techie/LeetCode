/*
LeetCode 167. Two Sum II - Input Array Is Sorted
Difficulty: Medium
Time Complexity: O(n)
Algorithm: Two Pointers

DESCRIPTION:
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.

 

Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
Example 3:

Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
 

Constraints:

2 <= numbers.length <= 3 * 104
-1000 <= numbers[i] <= 1000
numbers is sorted in non-decreasing order.
-1000 <= target <= 1000
The tests are generated such that there is exactly one solution.
*/

#include <vector>
#include <iostream>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int st = 0;           // Start pointer
    int end = nums.size() - 1; // End pointer

    while (st < end) {
        int sum = nums[st] + nums[end];

        if (sum == target) {
            return {st + 1, end + 1};  // Return 1-based indices
        }
        else if (sum < target) {
            st++;  // Move start pointer to the right
        } else {
            end--;  // Move end pointer to the left
        }
    }

    return {};  // No solution found
}

int main() {
    // Example 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = twoSum(nums1, target1);

    if (!result1.empty()) {
        cout << "Test Case 1 - Indices: " << result1[0] << ", " << result1[1] << endl;
    } else {
        cout << "Test Case 1 - No solution found!" << endl;
    }

    // Example 2
    vector<int> nums2 = {1, 2, 3, 4, 5};
    int target2 = 7;
    vector<int> result2 = twoSum(nums2, target2);

    if (!result2.empty()) {
        cout << "Test Case 2 - Indices: " << result2[0] << ", " << result2[1] << endl;
    } else {
        cout << "Test Case 2 - No solution found!" << endl;
    }

    // Example 3 (No solution)
    vector<int> nums3 = {1, 2, 3, 4};
    int target3 = 10;
    vector<int> result3 = twoSum(nums3, target3);

    if (!result3.empty()) {
        cout << "Test Case 3 - Indices: " << result3[0] << ", " << result3[1] << endl;
    } else {
        cout << "Test Case 3 - No solution found!" << endl;
    }

    return 0;
}