/*
LeetCode Problem: 104. Maximum Depth of Binary Tree
Difficulty: Easy
Algorithm: Depth-First Search (DFS)
Time Complexity: O(n), where n is the number of nodes in the tree
Space Complexity: O(h), where h is the height of the tree (due to recursion stack)

Description:

Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

 

Example 1:


Input: root = [1,2,3,4,5,6]
Output: 6
Example 2:

Input: root = []
Output: 0
Example 3:

Input: root = [1]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [0, 5 * 104].
0 <= Node.val <= 5 * 104
The tree is guaranteed to be complete.
*/

#include <iostream>
#include <vector>
using namespace std;

// Definition of a binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a node with a given value
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

// Static variable to track current index while building tree from preorder vector
static int i = -1;

// Function to build binary tree from preorder traversal vector with -1 as NULL marker
Node* buildTree(const vector<int>& nodes) {
    i++;  // Move to the next index in vector

    // If current value is -1, this node is NULL (no child)
    if (i >= (int)nodes.size() || nodes[i] == -1) return NULL;

    // Create current node with value nodes[i]
    Node* currNode = new Node(nodes[i]);
    
    // Recursively build left subtree
    currNode->left = buildTree(nodes);
    // Recursively build right subtree
    currNode->right = buildTree(nodes);

    // Return current node (root of subtree)
    return currNode;
}

// Function to count total nodes in the binary tree
int countNodes(Node* root) {
    if (root == NULL) return 0;

    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);

    return (leftCount + rightCount) + 1;
}

int main() {
    // Preorder traversal input with -1 as NULL marker
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};

    // Build the binary tree
    Node* root = buildTree(nodes);

    // Count total nodes and print
    int total = countNodes(root);
    cout << "Total Node Count: " << total << endl;

    return 0;
}
