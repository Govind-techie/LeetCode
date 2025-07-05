/*
LeetCode Problem 743: Network Delay Time
Difficulty: Medium
Algorithm: Dijkstra's Algorithm for Shortest Path in Directed Graphs
Time Complexity: O((V + E) log V), where V is the number of nodes
Space Complexity: O(V + E) for the adjacency list and priority queue

Description:
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

 

Example 1:


Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
 

Constraints:

1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Build the graph
void buildGraph(const vector<vector<int>>& times, vector<vector<pair<int, int>>>& graph) {
    for (const auto& t : times) {
        int u = t[0];
        int v = t[1];
        int wt = t[2];
        graph[u].push_back({v, wt});
    }
}

// Dijkstra function
int dijkstra(int src, const vector<vector<pair<int, int>>>& graph, int n) {
    vector<int> minTime(n + 1, INT_MAX); // store shortest time to reach each node
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    minTime[src] = 0;
    pq.push({0, src}); // {time, node}

    while (!pq.empty()) {
        int time = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (time > minTime[node]) continue; // skip outdated entries

        for (const auto& edge : graph[node]) {
            int neighbor = edge.first;
            int weight = edge.second;

            if (minTime[neighbor] > minTime[node] + weight) {
                minTime[neighbor] = minTime[node] + weight;
                pq.push({minTime[neighbor], neighbor});
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= n; ++i) {
        if (minTime[i] == INT_MAX) return -1; // unreachable node
        result = max(result, minTime[i]);     // track max delay time
    }
    return result;
}

// Main function
int main() {
    int n, m, k;
    cout << "Enter number of nodes, number of edges, and starting node: ";
    cin >> n >> m >> k;

    vector<vector<int>> times(m, vector<int>(3));
    cout << "Enter each edge as: from to weight\n";
    for (int i = 0; i < m; ++i) {
        cin >> times[i][0] >> times[i][1] >> times[i][2];
    }

    vector<vector<pair<int, int>>> graph(n + 1);
    buildGraph(times, graph);

    int ans = dijkstra(k, graph, n);
    cout << "Network delay time = " << ans << endl;

    return 0;
}