/*
LeetCode Problem 46: Permutations
Difficulty: Medium
Time Complexity: O(n!)
Space Complexity: O(n)

Description:

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:

Input: nums = [1]
Output: [[1]]

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
*/

#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<int> nums, vector<int> current, vector<vector<int>>& result) {
    int n = nums.size();
    if (nums.size() == 0) {
        result.push_back(current);
        return;
    }

    for (int i = 0; i < n; i++) {
        current.push_back(nums[i]);
        vector<int> remaining = nums;
        remaining.erase(remaining.begin() + i);
        backtrack(remaining, current, result);
        current.pop_back();
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    backtrack(nums, current, result);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = permute(nums);

    cout << "All permutations:\n";
    for (auto& permutation : result) {
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}