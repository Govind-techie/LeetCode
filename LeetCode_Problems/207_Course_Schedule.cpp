/*
LeetCode Problem 207: Course Schedule
Difficulty: Medium
Algorithm: Depth-First Search (DFS) for Cycle Detection in Directed Graphs
Time Complexity: O(V + E), where V is the number of courses and E is the number of prerequisites
Space Complexity: O(V + E) for the adjacency list and recursion stack

Description:
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.
*/

#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<list<int>> adjList;

void buildGraph(int numCourses, const vector<vector<int>>& prerequisites) {
    adjList.assign(numCourses, {});
    for (auto edge : prerequisites) {
        int course = edge[0];
        int prereq = edge[1];
        adjList[prereq].push_back(course);
    }
}

bool dfs(int src, vector<bool>& vis, vector<bool>& recPath) {
    vis[src] = true;
    recPath[src] = true;

    for (int v : adjList[src]) {
        if (!vis[v]) {
            if (!dfs(v, vis, recPath)) return false;
        } else if (recPath[v]) return false;
    }
    recPath[src] = false;
    return true;
}

bool canFinish(int numCourses, const vector<vector<int>>& prerequisites) {
    buildGraph(numCourses, prerequisites);
    vector<bool> vis(numCourses, false);
    vector<bool> recPath(numCourses, false);
    for (int i = 0; i < numCourses; ++i)
        if (!vis[i] && !dfs(i, vis, recPath)) return false;
    return true;
}

int main() {
    int numCourses, m;
    cin >> numCourses >> m;
    vector<vector<int>> prerequisites(m, vector<int>(2));
    for (int i = 0; i < m; ++i) cin >> prerequisites[i][0] >> prerequisites[i][1];

    bool ok = canFinish(numCourses, prerequisites);
    cout << (ok ? "Yes" : "No") << '\n';
    return 0;
}