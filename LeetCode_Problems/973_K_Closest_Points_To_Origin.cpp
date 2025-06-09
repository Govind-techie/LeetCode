/*
LeetCode Problem: 973. K Closest Points to Origin
Difficulty: Medium
Algorithm: Min-Heap
Time Complexity: O(N log K)
Space Complexity: O(K)

Description:

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

Example 1:


Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <functional>
#include <utility>
using namespace std;

// Function to calculate Euclidean distance from origin
double getDis(const vector<int>& arr) {
    int x = arr[0];
    int y = arr[1];
    return sqrt((x * x) + (y * y));
}

// Function to return k closest points to the origin
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, greater<>> pq;
    
    for (int i = 0; i < points.size(); i++) {
        pq.push({getDis(points[i]), points[i]});
    }

    vector<vector<int>> closest;
    for (int i = 0; i < k; i++) {
        closest.push_back(pq.top().second);
        pq.pop();
    }

    return closest;
}

// Main function for testing
int main() {
    vector<vector<int>> points = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
    int k = 2;

    vector<vector<int>> result = kClosest(points, k);

    cout << k << " closest points to the origin are:" << endl;
    for (const auto& point : result) {
        cout << "[" << point[0] << ", " << point[1] << "]" << endl;
    }

    return 0;
}