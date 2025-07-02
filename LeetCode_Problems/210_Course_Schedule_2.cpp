/*
LeetCode Problem 210: Course Schedule II
Difficulty: Medium
Algorithm: Topological Sort using DFS for Cycle Detection in Directed Graphs
Time Complexity: O(V + E), where V is the number of courses and E is the number of prerequisites
Space Complexity: O(V + E) for the adjacency list and recursion stack

Description:

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i].length == 2
0 <= ai, bi < numCourses
ai != bi
All the pairs [ai, bi] are distinct.
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void topoSort(int src, vector<bool>& vis, stack<int>& st, const vector<vector<int>>& adj) {
    vis[src] = true;
    for (int v : adj[src]) {
        if (!vis[v]) {
            topoSort(v, vis, st, adj);
        }
    }
    st.push(src);
}

bool cycleDetection(int src, vector<bool>& vis, vector<bool>& rec, const vector<vector<int>>& adj) {
    vis[src] = true;
    rec[src] = true;
    for (int v : adj[src]) {
        if (!vis[v]) {
            if (cycleDetection(v, vis, rec, adj)) return true;
        } else if (rec[v]) return true;
    }
    rec[src] = false;
    return false;
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    for (auto& p : prerequisites) adj[p[1]].push_back(p[0]);

    vector<bool> vis(numCourses, false), rec(numCourses, false);
    for (int i = 0; i < numCourses; ++i) {
        if (!vis[i] && cycleDetection(i, vis, rec, adj)) {
            return {};
        }
    }

    fill(vis.begin(), vis.end(), false);
    stack<int> st;
    for (int i = 0; i < numCourses; ++i) {
        if (!vis[i]) {
            topoSort(i, vis, st, adj);
        }
    }

    vector<int> order;
    while (!st.empty()) {
        order.push_back(st.top());
        st.pop();
    }
    return order;
}

int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}};
    vector<int> result = findOrder(numCourses, prerequisites);
    for (int x : result) cout << x << " ";
    cout << endl;
    return 0;
}