/*
LeetCode Problem: 1305 - All Elements in Two Binary Search Trees
Difficulty: Medium
Algorithm: In-order Traversal, Merge Two Sorted Arrays
Time Complexity: O(m + n), where m and n are the number of nodes in the two BSTs
Space Complexity: O(m + n), for storing the elements of both trees

Description:

Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.

 

Example 1:


Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]
Example 2:


Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]
 

Constraints:

The number of nodes in each tree is in the range [0, 5000].
-105 <= Node.val <= 105
*/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

void inorderHelper(TreeNode* root, vector<int>& nodes) {
    if (root == nullptr) return;
    inorderHelper(root->left, nodes);
    nodes.push_back(root->val);
    inorderHelper(root->right, nodes);
}

void mergeVectors(const vector<int>& nodes1, const vector<int>& nodes2, vector<int>& mergedNodes) {
    int i = 0, j = 0;
    while (i < (int)nodes1.size() && j < (int)nodes2.size()) {
        if (nodes1[i] <= nodes2[j]) {
            mergedNodes.push_back(nodes1[i++]);
        } else {
            mergedNodes.push_back(nodes2[j++]);
        }
    }
    while (i < (int)nodes1.size()) {
        mergedNodes.push_back(nodes1[i++]);
    }
    while (j < (int)nodes2.size()) {
        mergedNodes.push_back(nodes2[j++]);
    }
}

TreeNode* insertNode(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insertNode(root->left, val);
    else
        root->right = insertNode(root->right, val);
    return root;
}

int main() {
    // Build first BST
    TreeNode* root1 = nullptr;
    root1 = insertNode(root1, 2);
    root1 = insertNode(root1, 1);
    root1 = insertNode(root1, 4);

    // Build second BST
    TreeNode* root2 = nullptr;
    root2 = insertNode(root2, 1);
    root2 = insertNode(root2, 0);
    root2 = insertNode(root2, 3);

    vector<int> nodes1, nodes2, mergedNodes;

    inorderHelper(root1, nodes1);
    inorderHelper(root2, nodes2);

    mergeVectors(nodes1, nodes2, mergedNodes);

    cout << "Merged elements: ";
    for (int val : mergedNodes) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}