/*
LeetCode Problem: 100. Same Tree
Difficulty: Easy
Algorithm: Depth-First Search (DFS)
Time Complexity: O(n), where n is the number of nodes in the tree
Space Complexity: O(h), where h is the height of the tree (due to recursion stack)

Description:

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 

Example 1:


Input: p = [1,2,3], q = [1,2,3]
Output: true
Example 2:


Input: p = [1,2], q = [1,null,2]
Output: false
Example 3:


Input: p = [1,2,1], q = [1,1,2]
Output: false
 

Constraints:

The number of nodes in both trees is in the range [0, 100].
-104 <= Node.val <= 104
*/

#include <iostream>
#include <vector>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Global index for buildTree recursion
int i = -1;

// buildTree from preorder vector, -1 means NULL
TreeNode* buildTree(const vector<int>& nodes) {
    i++;
    if (i >= (int)nodes.size() || nodes[i] == -1) return NULL;
    TreeNode* root = new TreeNode(nodes[i]);
    root->left = buildTree(nodes);
    root->right = buildTree(nodes);
    return root;
}

// isSameTree standalone function (LeetCode style)
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == NULL && q == NULL) return true;

    if (p != NULL && q != NULL) {
        if (p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
    return false;
}

int main() {
    vector<int> tree1 = {1, 2, -1, -1, 3, -1, -1};
    vector<int> tree2 = {1, 2, -1, -1, 3, -1, -1};
    vector<int> tree3 = {1, 2, -1, -1, 4, -1, -1};

    i = -1;
    TreeNode* root1 = buildTree(tree1);

    i = -1;
    TreeNode* root2 = buildTree(tree2);

    i = -1;
    TreeNode* root3 = buildTree(tree3);

    cout << (isSameTree(root1, root2) ? "tree1 and tree2 are same\n" : "tree1 and tree2 are different\n");
    cout << (isSameTree(root1, root3) ? "tree1 and tree3 are same\n" : "tree1 and tree3 are different\n");

    return 0;
}