/*
LeetCode Problem 797: All Paths From Source to Target
Difficulty: Medium
Algorithm: Depth-First Search (DFS) for Path Finding
Time Complexity: O(2^(V + E)), where V is the number of vertices and E is the number of edges (in the worst case, all paths are explored)
Space Complexity: O(V) for the recursion stack and path storage

Description:

Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

 

Example 1:


Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
Example 2:


Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
 

Constraints:

n == graph.length
2 <= n <= 15
0 <= graph[i][j] < n
graph[i][j] != i (i.e., there will be no self-loops).
All the elements of graph[i] are unique.
The input graph is guaranteed to be a DAG.
*/

#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, vector<int>& path, const vector<vector<int>>& graph, vector<vector<int>>& res) {
    if (u == graph.size() - 1) res.push_back(path);
    for (int v : graph[u]) {
        path.push_back(v);
        dfs(v, path, graph, res);
        path.pop_back();
    }
}

vector<vector<int>> allPathsSourceTarget(const vector<vector<int>>& graph) {
    vector<vector<int>> res;
    vector<int> path = {0};
    dfs(0, path, graph, res);
    return res;
}

int main() {
    int n;                      // number of nodes
    cin >> n;
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; ++i) {
        int k;                  // number of neighbours of node i
        cin >> k;
        graph[i].resize(k);
        for (int j = 0; j < k; ++j) cin >> graph[i][j];
    }

    vector<vector<int>> paths = allPathsSourceTarget(graph);
    for (const auto& p : paths) {
        for (size_t i = 0; i < p.size(); ++i) {
            cout << p[i] << (i + 1 == p.size() ? '\n' : ' ');
        }
    }
    return 0;
}