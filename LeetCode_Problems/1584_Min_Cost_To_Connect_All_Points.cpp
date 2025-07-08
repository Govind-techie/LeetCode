/*
LeetCode Problem 1584: Minimum Cost to Connect All Points
Difficulty: Medium
Algorithm: Prim's Algorithm for Minimum Spanning Tree (MST)
Time Complexity: O(E log V), where E is the number of edges and V is the number of vertices (points).
Space Complexity: O(V), where V is the number of vertices (points).

Description:
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

 

Example 1:


Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation: 

We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.
Example 2:

Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18
 

Constraints:

1 <= points.length <= 1000
-106 <= xi, yi <= 106
All pairs (xi, yi) are distinct.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>

using namespace std;

// Function to calculate minimum cost to connect all points
int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    vector<bool> mstSet(n, false);
    vector<int> minCost(n, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0}); // {cost, node}

    int res = 0;
    int edges = 0;
    while (edges < n) {
        auto [cost, u] = pq.top();
        pq.pop();

        if (mstSet[u]) continue;

        mstSet[u] = true;
        res += cost;
        edges++;

        for (int v = 0; v < n; v++) {
            if (!mstSet[v]) {
                int wt = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                if (wt < minCost[v]) {
                    minCost[v] = wt;
                    pq.push({wt, v});
                }
            }
        }
    }
    return res;
}

int main() {
    // Example test case
    vector<vector<int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    
    int cost = minCostConnectPoints(points);
    cout << "Minimum cost to connect all points: " << cost << endl;

    return 0;
}