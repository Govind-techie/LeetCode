/*
LeetCode Problem: 1382 - Balance a Binary Search Tree
Difficulty: Medium
Algorithm: Tree Traversal, inorder traversal
Time Complexity: O(n)
Space Complexity: O(n)

Description:
Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

 

Example 1:


Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
Example 2:


Input: root = [2,1,3]
Output: [2,1,3]
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
1 <= Node.val <= 105
*/

#include <iostream>
#include <vector>
using namespace std;

// Define TreeNode structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void nodes(TreeNode* root, vector<int>& balancedBSTNodes){
        if (root == NULL) return;

        nodes(root->left, balancedBSTNodes);
        balancedBSTNodes.push_back(root->val);
        nodes(root->right, balancedBSTNodes);
    }

    TreeNode* helper(const vector<int>& balancedBSTNodes, int st, int en){
        if (st > en) return NULL;
        int mid = st + (en - st) / 2;

        TreeNode* root = new TreeNode(balancedBSTNodes[mid]);
        root->left = helper(balancedBSTNodes, st, mid - 1);
        root->right = helper(balancedBSTNodes, mid + 1, en);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> balancedBSTNodes;
        nodes(root, balancedBSTNodes);
        return helper(balancedBSTNodes, 0, (int)balancedBSTNodes.size() - 1);
    }
};

// Utility function to insert nodes into a normal BST
TreeNode* insertNode(TreeNode* root, int val) {
    if (root == NULL) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insertNode(root->left, val);
    } else {
        root->right = insertNode(root->right, val);
    }
    return root;
}

// Utility function to print inorder traversal of the tree
void printInorder(TreeNode* root) {
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    // Create a normal BST with unbalanced nodes
    vector<int> nodes = {10, 5, 1, 7, 40, 50};
    TreeNode* root = NULL;
    for (int val : nodes) {
        root = insertNode(root, val);
    }

    cout << "Inorder traversal of original BST: ";
    printInorder(root);
    cout << endl;

    Solution sol;
    TreeNode* balancedRoot = sol.balanceBST(root);

    cout << "Inorder traversal of balanced BST: ";
    printInorder(balancedRoot);
    cout << endl;

    return 0;
}