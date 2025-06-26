/*
LeetCode Problem 684: Redundant Connection
Difficulty: Medium
Algorithm: Depth-First Search (DFS)
Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
Space Complexity: O(V + E) for the adjacency list and visited array.

Description:
In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

 

Example 1:


Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
Example 2:


Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]
 

Constraints:

n == edges.length
3 <= n <= 1000
edges[i].length == 2
1 <= ai < bi <= edges.length
ai != bi
There are no repeated edges.
The given graph is connected.

*/

#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<list<int>> adjList;

bool dfs(int src, vector<bool>& vis, int par) {
    vis[src] = true;
    for (int v : adjList[src]) {
        if (!vis[v]) {
            if (dfs(v, vis, src)) return true;
        } else if (v != par) {
            return true;
        }
    }
    return false;
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    adjList.resize(n + 1);

    for (auto& edge : edges) {
        int u = edge[0], v = edge[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);

        vector<bool> vis(n + 1, false);
        if (dfs(u, vis, -1)) return edge;
    }
    return {};
}

int main() {
    vector<vector<int>> edges = {
        {1, 2}, {1, 3}, {2, 3}
    };

    vector<int> ans = findRedundantConnection(edges);
    if (!ans.empty()) {
        cout << "Redundant edge: " << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}