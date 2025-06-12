/*
LeetCode Problem 349: Intersection of Two Arrays
Difficulty: Easy
Time Complexity: O(n + m) n = size of nums1, m = size of nums2
Space Complexity: O(n) 
Algorithm: Use a hash map to count occurrences in the first array and check against the second array.

Description:

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000

*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to compute the intersection of two arrays (unique elements only)
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> intersection;
    unordered_map<int, int> m;

    // Count frequency of elements in the first array
    for (int i : nums1) {
        m[i]++;
    }

    // Check for intersection with the second array
    for (int i : nums2) {
        if (m[i] > 0) {
            intersection.push_back(i);
            m[i] = 0; // Set to 0 to avoid duplicates in result
        }
    }

    return intersection;
}

int main() {
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    vector<int> result = intersection(nums1, nums2);

    cout << "Intersection: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}