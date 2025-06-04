/*
LeetCode Problem: 94. Binary Tree Inorder Traversal
Difficulty: Easy
Algorithm: Depth-First Search (DFS)
Time Complexity: O(n), where n is the number of nodes in the tree
Space Complexity: O(h), where h is the height of the tree (due to recursion stack)

Description:

Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [1,3,2]

Explanation:



Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [4,2,6,5,7,1,3,9,8]

Explanation:



Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]

 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/

#include <iostream>
#include <vector>
using namespace std;

// Node class for binary tree
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

// Global index for building tree from preorder vector
int i = -1;

// Build tree from preorder vector, -1 represents NULL
Node* buildTree(const vector<int>& nodes) {
    i++;
    if (i >= nodes.size() || nodes[i] == -1) return NULL;

    Node* root = new Node(nodes[i]);
    root->left = buildTree(nodes);
    root->right = buildTree(nodes);
    return root;
}

// Inorder traversal helper
void inorderHelper(Node* root, vector<int>& inorder) {
    if (root == NULL) return;

    inorderHelper(root->left, inorder);
    inorder.push_back(root->data);
    inorderHelper(root->right, inorder);
}

// Inorder traversal function
vector<int> inorderTraversal(Node* root) {
    vector<int> inorder;
    inorderHelper(root, inorder);
    return inorder;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};  // example input preorder with -1 as NULL
    Node* root = buildTree(nodes);

    vector<int> result = inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}