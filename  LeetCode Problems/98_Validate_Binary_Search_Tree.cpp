/*
LeetCode Problem: 98. Validate Binary Search Tree
Difficulty: Medium
Algorithm: DFS, Recursion
Time Complexity: O(n)
Space Complexity: O(h), where h is the height of the tree

Description:

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
*/

#include <iostream>
using namespace std;

// Basic tree node structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

// Helper function to validate BST by keeping track of allowed min and max nodes
bool validateBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
    if (root == NULL) return true;

    // If current node's value is not strictly greater than minNode's value, return false
    if (minNode != NULL && root->val <= minNode->val) return false;

    // If current node's value is not strictly less than maxNode's value, return false
    if (maxNode != NULL && root->val >= maxNode->val) return false;

    // Recursively check left subtree and right subtree with updated constraints
    return validateBST(root->left, minNode, root) && validateBST(root->right, root, maxNode);
}

// Wrapper function to call validateBST with no initial min or max constraints
bool isValidBST(TreeNode* root) {
    return validateBST(root, NULL, NULL);
}


TreeNode* createSampleBST() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(20);
    return root;
}

int main() {
    // Create a sample BST
    TreeNode* root = createSampleBST();

    // Check if the tree is a valid BST
    if (isValidBST(root)) {
        cout << "The tree is a valid BST." << endl;
    } else {
        cout << "The tree is NOT a valid BST." << endl;
    }

    return 0;
}