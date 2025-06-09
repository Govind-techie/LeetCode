/*
LeetCode Problem: Sliding Window Maximum
Algorithm: Sliding Window Maximum using Priority Queue
Time Complexity: O(n log k) where n is the number of elements in the array and k is the size of the sliding window.
Space Complexity: O(k) for the priority queue.

Description:

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to compute max in each sliding window
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    priority_queue<pair<int, int>> pq;  // Max-heap: {num, index}
    vector<int> result;

    for (int i = 0; i < nums.size(); ++i) {
        pq.push({nums[i], i});

        // Remove elements that are out of the current window
        while (pq.top().second <= i - k) {
            pq.pop();
        }

        // Add max of the current window to result
        if (i >= k - 1) {
            result.push_back(pq.top().first);
        }
    }

    return result;
}

int main() {
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "Enter window size k: ";
    cin >> k;

    vector<int> result = maxSlidingWindow(nums, k);

    cout << "Sliding window maximums:\n";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}