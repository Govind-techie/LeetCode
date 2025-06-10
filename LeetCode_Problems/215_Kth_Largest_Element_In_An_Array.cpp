/*
LeetCode Problem 215: Kth Largest Element in an Array
Difficulty: Medium
Algorithm: priority queue (max heap)
Time Complexity: O(n log k)
Space Complexity: O(k)

Description:

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to find the kth largest element
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq;

    // Push all elements into the max-heap
    for (int i : nums) {
        pq.push(i);
    }

    // Pop k-1 elements from the top
    for (int i = 0; i < k - 1; i++) {
        pq.pop();
    }

    // The top element is the kth largest
    return pq.top();
}

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    int result = findKthLargest(nums, k);

    cout << "The " << k << "th largest element is: " << result << endl;

    return 0;
}