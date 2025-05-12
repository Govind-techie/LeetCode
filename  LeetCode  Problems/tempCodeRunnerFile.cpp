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