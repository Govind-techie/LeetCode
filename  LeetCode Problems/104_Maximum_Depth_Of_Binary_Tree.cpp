/*
LeetCode Problem: 104. Maximum Depth of Binary Tree
Difficulty: Easy
Algorithm: Depth-First Search (DFS)
Time Complexity: O(n), where n is the number of nodes in the tree
Space Complexity: O(h), where h is the height of the tree (due to recursion stack)

Description:

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100
*/

#include<iostream>
#include<vector>
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

int maxDepth(Node* root) {
    if (root == NULL) return 0;

    int leftHt = maxDepth(root->left);
    int rightHt = maxDepth(root->right);

    int currHt = max(leftHt,rightHt)+1;

    return currHt;
}

int main(){
    vector<int> nodes = {3, 9, 20, -1, -1, 15, 7};
    Node* root = buildTree(nodes);
    
    int depth = maxDepth(root);
    cout << "Maximum Depth of Binary Tree: " << depth << endl;
    return 0;

}