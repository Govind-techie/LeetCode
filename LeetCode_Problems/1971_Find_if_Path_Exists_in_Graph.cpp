/*
LeetCode Problem: 1971 - Find if Path Exists in Graph
Difficulty: Easy
Algorithm: Depth-First Search (DFS)
Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges
Space Complexity: O(V), for the visited array and adjacency list

Description:
There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.

 

Example 1:


Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
Output: true
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2
Example 2:


Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
Output: false
Explanation: There is no path from vertex 0 to vertex 5.
 

Constraints:

1 <= n <= 2 * 105
0 <= edges.length <= 2 * 105
edges[i].length == 2
0 <= ui, vi <= n - 1
ui != vi
0 <= source, destination <= n - 1
There are no duplicate edges.
There are no self edges.
*/

#include <iostream>
#include <vector>
#include <list>

using namespace std;

// DFS function to check if a valid path exists from src to dest
bool dfs(vector<list<int>>& adjList, int src, int dest, vector<bool>& vis) {
    if (src == dest) return true;

    vis[src] = true;

    for (int v : adjList[src]) {
        if (!vis[v]) {
            if (dfs(adjList, v, dest, vis)) return true;
        }
    }

    return false;
}

// Function to build the graph and check for valid path
bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    vector<list<int>> adjList(n);

    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<bool> vis(n, false);
    return dfs(adjList, source, destination, vis);
}

int main() {
    // Example input
    int n = 6;
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {3, 5},
        {5, 4},
        {4, 3}
    };
    int source = 0;
    int destination = 5;

    // Function call
    if (validPath(n, edges, source, destination)) {
        cout << "Path exists between " << source << " and " << destination << endl;
    } else {
        cout << "No path exists between " << source << " and " << destination << endl;
    }

    return 0;
}