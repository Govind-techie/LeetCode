/*
LeetCode Problem 2215: Find the Difference of Two Arrays
Difficulty: Easy
Time Complexity: O(n + m) where n = size of nums1, m = size of nums2
Space Complexity: O(n + m) for storing unique elements in sets
Algorithm: Use unordered sets to find unique elements in each array that are not present in the other.

Description:
Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
Note that the integers in the lists may be returned in any order.

 

Example 1:

Input: nums1 = [1,2,3], nums2 = [2,4,6]
Output: [[1,3],[4,6]]
Explanation:
For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums1. Therefore, answer[1] = [4,6].
Example 2:

Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
Output: [[3],[]]
Explanation:
For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
Every integer in nums2 is present in nums1. Therefore, answer[1] = [].
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
-1000 <= nums1[i], nums2[i] <= 1000
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Function to find the difference between two arrays
vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> s1(nums1.begin(), nums1.end());
    unordered_set<int> s2(nums2.begin(), nums2.end());

    vector<int> vec1, vec2;

    // Elements in s1 but not in s2
    for (int i : s1) {
        if (s2.count(i) == 0) {
            vec1.push_back(i);
        }
    }

    // Elements in s2 but not in s1
    for (int i : s2) {
        if (s1.count(i) == 0) {
            vec2.push_back(i);
        }
    }

    return {vec1, vec2};
}

int main() {
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 4, 6};

    vector<vector<int>> result = findDifference(nums1, nums2);

    cout << "Difference in nums1: ";
    for (int num : result[0]) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Difference in nums2: ";
    for (int num : result[1]) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}