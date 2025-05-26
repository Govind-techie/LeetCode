/*
LeetCode Problem: 102. Binary Tree Level Order Traversal
Difficulty: Medium
Algorithm: Breadth-First Search (BFS)
Time Complexity: O(n), where n is the number of nodes in the tree
Space Complexity: O(n), where n is the maximum number of nodes at any level (due to queue storage)

Description:

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Build tree function (same as yours)
static int i = -1;
Node* buildTree(const vector<int>& nodes) {
    i++;
    if (i >= (int)nodes.size() || nodes[i] == -1) return NULL;

    Node* curr = new Node(nodes[i]);
    curr->left = buildTree(nodes);
    curr->right = buildTree(nodes);
    return curr;
}

// Level order function that returns vector of vectors (level by level)
vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> res;
    if (root == NULL) return res;

    queue<Node*> q;
    q.push(root);
    q.push(NULL); // level delimiter

    vector<int> currentLevel;

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr == NULL) {
            res.push_back(currentLevel);
            currentLevel.clear();

            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            currentLevel.push_back(curr->data);

            if (curr->left != NULL) q.push(curr->left);
            if (curr->right != NULL) q.push(curr->right);
        }
    }
    return res;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};
    Node* root = buildTree(nodes);

    vector<vector<int>> levels = levelOrder(root);

    for (auto &level : levels) {
        for (int val : level) cout << val << " ";
        cout << "\n";
    }

    return 0;
}