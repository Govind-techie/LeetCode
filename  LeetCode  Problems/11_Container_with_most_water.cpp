// LeetCode Problem (11) : Container with most water (2 Pointer Approach)

// Difficulty : Medium

// Time Complexity : O(n)

// // DESCRIPTION : 

// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.

// Notice that you may not slant the container

// Example 1:

// (Height)

// 8 |       |                   |
// 7 |       |                   |       |
// 6 |       |       |           |       |
// 5 |       |       |       |   |       |
// 4 |       |       |       |   |   |   |
// 3 |       |       |       |   |   |   |   |
// 2 |       |       |   |   |   |   |   |   |
// 1 |   |   |   |   |   |   |   |   |   |
//   -----------------------------------------
//     0   1   2   3   4   5   6   7   8   (Index)

// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
// Example 2:

// Input: height = [1,1]
// Output: 1
 

// Constraints:

// n == height.length
// 2 <= n <= 105
// 0 <= height[i] <= 104


#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
    int leftBoundary = 0;
    int rightBoundary = height.size() - 1;
    int currentCapacity = 0;
    int maxCapacity = 0;

    while (leftBoundary < rightBoundary){
        int smallBoundary = min(height[leftBoundary], height[rightBoundary]);
        int width = (rightBoundary - leftBoundary);
        currentCapacity = width * smallBoundary;

        maxCapacity = max(currentCapacity, maxCapacity);

        if (height[leftBoundary] < height[rightBoundary]){
            leftBoundary++;
        }else{
            rightBoundary--;
        }
    }
    return maxCapacity;
}

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7}; // Example input
    cout << maxArea(height) << endl;
    return 0;
}