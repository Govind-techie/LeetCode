/*
LeetCode Problem 84: Largest Rectangle in Histogram
Difficulty: Hard
Time Complexity: O(n)
Space Complexity: O(n)

Description:

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4
 

Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to calculate largest rectangle area
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    vector<int> nsr(n); // Next smaller to right
    vector<int> nsl(n); // Next smaller to left
    int area;
    int maxArea = 0;

    // Compute NSL
    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        if (st.empty()) {
            nsl[i] = -1;
        } else {
            nsl[i] = st.top();
        }
        st.push(i);
    }

    // Clear stack before reusing
    while (!st.empty()) st.pop();

    // Compute NSR
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        if (st.empty()) {
            nsr[i] = n;
        } else {
            nsr[i] = st.top();
        }
        st.push(i);
    }

    // Calculate max area
    for (int i = 0; i < n; i++) {
        area = heights[i] * (nsr[i] - nsl[i] - 1);
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main() {
    int n;
    cout << "Enter number of bars in the histogram: ";
    cin >> n;

    vector<int> heights(n);
    cout << "Enter the heights of the bars:\n";
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    int result = largestRectangleArea(heights);
    cout << "Maximum area in histogram: " << result << endl;

    return 0;
}