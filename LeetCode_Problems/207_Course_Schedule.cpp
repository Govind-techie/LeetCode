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
using namespace std;

bool cycleDetection(int src, vector<vector<int>>& adjList, vector<bool>& vis, vector<bool>& recPath) {
    vis[src] = true;
    recPath[src] = true;

    for (int v : adjList[src]) {
        if (!vis[v]) {
            if (cycleDetection(v, adjList, vis, recPath)) return true;
        } else if (recPath[v]) return true; // back-edge found → cycle
    }

    recPath[src] = false; // backtrack
    return false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adjList(numCourses);
    for (auto& p : prerequisites)
        adjList[p[1]].push_back(p[0]); // directed edge: b → a

    vector<bool> vis(numCourses, false);
    vector<bool> recPath(numCourses, false);

    for (int i = 0; i < numCourses; i++) {
        if (!vis[i] && cycleDetection(i, adjList, vis, recPath))
            return false; // cycle found
    }

    return true; // no cycle → can finish all courses
}

int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 1},
        {3, 2}
    };

    if (canFinish(numCourses, prerequisites))
        cout << "Yes, you can finish all courses.\n";
    else
        cout << "No, there's a cycle. Cannot finish all courses.\n";

    return 0;
}