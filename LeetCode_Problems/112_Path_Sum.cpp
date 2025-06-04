/*
LeetCode Problem: 112. Path Sum
Difficulty: Easy
Algorithm: Depth-First Search (DFS)
Time Complexity: O(N), where N is the number of nodes in the tree.
Space Complexity: O(H), where H is the height of the tree (due to recursion stack).

Description:
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

Example 1:


Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.
Example 2:


Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There are two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.
Example 3:

Input: root = [], targetSum = 0
Output: false
Explanation: Since the tree is empty, there are no root-to-leaf paths.
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000
*/

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Checks if the binary tree has a root-to-leaf path such that the sum of the node values equals targetSum.
bool hasPathSum(TreeNode* root, int targetSum) {
    // If the current node is null, there is no path, so return false.
    if (root == NULL) return false;

    // If the current node is a leaf (no left or right child),
    // check if the value of this node equals the remaining targetSum.
    if (root->left == NULL && root->right == NULL){
        return root->val == targetSum;
    }

    // Recursively check the left and right subtrees with the updated targetSum.
    // Subtract the current node's value from targetSum for the next call.
    return hasPathSum(root->left, targetSum - root->val) || 
           hasPathSum(root->right, targetSum - root->val);
}


int main() {

    // Constructing the binary tree for the example:
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;

    cout << (hasPathSum(root, targetSum) ? "True" : "False") << endl;

    return 0;
}