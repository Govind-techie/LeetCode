/*
LeetCode Problem: 572. Subtree of Another Tree
Difficulty: Easy
Algorithm: Depth-First Search (DFS)
Time Complexity: O(n), where n is the number of nodes in the tree
Space Complexity: O(h), where h is the height of the tree (due to recursion stack)

Description:

Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

 

Example 1:


Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true
Example 2:


Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false
 

Constraints:

The number of nodes in the root tree is in the range [1, 2000].
The number of nodes in the subRoot tree is in the range [1, 1000].
-104 <= root.val <= 104
-104 <= subRoot.val <= 104
*/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int i = -1;  // Global index for buildTree

TreeNode* buildTree(const vector<int>& nodes) {
    i++;
    if (i >= (int)nodes.size() || nodes[i] == -1) return NULL;
    TreeNode* root = new TreeNode(nodes[i]);
    root->left = buildTree(nodes);
    root->right = buildTree(nodes);
    return root;
}

bool sameTree(TreeNode* root, TreeNode* subRoot) {
    if (root == NULL && subRoot == NULL) return true;

    if (root != NULL && subRoot != NULL) {
        if (root->val == subRoot->val) {
            return sameTree(root->left, subRoot->left) && sameTree(root->right, subRoot->right);
        }
    }
    return false;
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (subRoot == NULL) return true;
    if (root == NULL) return false;

    if (sameTree(root, subRoot)) return true;

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main() {
    vector<int> rootNodes = {3, 4, 1, -1, -1, 2, -1, -1, 5, -1, -1};
    vector<int> subRootNodes = {4, 1, -1, -1, 2, -1, -1};

    i = -1;
    TreeNode* root = buildTree(rootNodes);

    i = -1;
    TreeNode* subRoot = buildTree(subRootNodes);

    cout << (isSubtree(root, subRoot) ? "subRoot is a subtree of root\n" : "subRoot is NOT a subtree of root\n");

    return 0;
}
