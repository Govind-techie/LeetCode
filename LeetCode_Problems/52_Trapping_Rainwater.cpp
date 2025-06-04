/*
LeetCode Problem (42) : Trapping Rain Water
Difficulty : Hard
Time Complexity : O(n)
Algorithm used : Two-pointer technique

DESCRIPTION :

Given an array of non-negative integers representing the height of walls, where each element is the height of a bar, compute how much water it can trap after raining.

The trapped water is the total volume of water that can be trapped between the bars.

For example, for arr = [0,1,0,2,1,0,1,3,2,1,2,1], the total amount of trapped water is 6 units.

You must implement a solution that works in O(n) time complexity.

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The trapped water is represented by the six units of water that will be trapped between the bars.

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9
Explanation: The trapped water is represented by the nine units of water that will be trapped between the bars.

Constraints:
1 <= height.length <= 10^5
0 <= height[i] <= 10^5
height contains non-negative integers representing the height of bars.
*/

#include <iostream>
#include <vector>
using namespace std;


int trap(vector<int>& arr) {
    int n = arr.size();  // Size of the array
    int largestBar1 = 0;  // Holds the largest element encountered from the right side
    int largestBar2 = 0;  // Holds the largest element encountered from the left side
    int leftMax = 0;      // Left pointer
    int rightMax = n - 1; // Right pointer
    int waterTrapped = 0; // Variable to store the amount of water trapped

    // If the array size is less than 3, no water can be trapped
    if (n < 3) return 0;

    // Two-pointer technique: Iterate through the array from both ends
    while (leftMax <= rightMax) {
        // If the height at the left pointer is smaller or equal to the height at the right pointer
        if (arr[leftMax] <= arr[rightMax]) {
            // Update the largest element from the left side (leftMax)
            largestBar2 = max(largestBar2, arr[leftMax]);

            // Calculate the water trapped by subtracting the height of the current bar from the largestBar2
            waterTrapped += largestBar2 - arr[leftMax];

            // Move the left pointer to the right
            leftMax++;
        } else {
            // Update the largest element from the right side (rightMax)
            largestBar1 = max(largestBar1, arr[rightMax]);

            // Calculate the water trapped by subtracting the height of the current bar from the largestBar1
            waterTrapped += largestBar1 - arr[rightMax];

            // Move the right pointer to the left
            rightMax--;
        }
    }


    return waterTrapped;
}

int main() {

    vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    int result = trap(arr);
    cout << "Amount of water trapped: " << result << endl;

    return 0;
}