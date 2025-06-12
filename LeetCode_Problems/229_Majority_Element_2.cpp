/*
LeetCode Problem 229: Majority Element II
Difficulty: Medium
Data Structures: Vector, unordered_map, unordered_set
Time Complexity: O(n)
Space Complexity: O(n)

Description:

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
 

Constraints:

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Function to find elements that appear more than ⌊n/3⌋ times
vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> m;
    unordered_set<int> s;
    vector<int> vec;

    for (int i = 0; i < n; i++) {
        m[nums[i]]++;
        // If frequency crosses n/3 and not already added to result
        if (m[nums[i]] > (n / 3) && s.count(nums[i]) == 0) {
            vec.push_back(nums[i]);
            s.insert(nums[i]);
        }
    }

    return vec;
}

int main() {
    vector<int> nums = {1, 2, 3, 1, 1, 2, 2, 3, 2, 1, 1};
    
    vector<int> result = majorityElement(nums);

    cout << "Majority Elements (> n/3): ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}