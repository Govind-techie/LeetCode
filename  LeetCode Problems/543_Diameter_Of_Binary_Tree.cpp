/*
LeetCode Problem: 543. Diameter of Binary Tree
Difficulty: Easy
Algorithm: Depth-First Search (DFS)
Time Complexity: O(n), where n is the number of nodes in the tree
Space Complexity: O(h), where h is the height of the tree (due to recursion stack)

Description:

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

 

Example 1:


Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:

Input: root = [1,2]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-100 <= Node.val <= 100
*/

#include <iostream>
#include <vector>
#include <algorithm>
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
    if (nodes[i] == -1) return NULL;

    // Create current node with value nodes[i]
    Node* currNode = new Node(nodes[i]);
    
    // Recursively build left subtree
    currNode->left = buildTree(nodes);
    // Recursively build right subtree
    currNode->right = buildTree(nodes);

    // Return current node (root of subtree)
    return currNode;
}

// Global variable to track max diameter
int maxDiameter = 0;

// Function to get height of tree and update maxDiameter for diameter
int getDiameter(Node* root) {
    if (root == NULL) return 0;

    int leftHeight = getDiameter(root->left);
    int rightHeight = getDiameter(root->right);

    int currDiameter = leftHeight + rightHeight;  // diameter in edges
    maxDiameter = max(maxDiameter, currDiameter);

    return max(leftHeight, rightHeight) + 1;
}

int diameterOfBinaryTree(Node* root) {
    maxDiameter = 0;        // reset before calculation
    getDiameter(root);
    return maxDiameter;
}

int main() {
    // Preorder vector representation of tree where -1 means NULL node
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};

    i = -1; // reset static index before building tree
    Node* root = buildTree(nodes);

    int diameter = diameterOfBinaryTree(root);
    cout << "Diameter of the tree (in edges) = " << diameter << endl;

    return 0;
}