/*
LeetCode Problem: 144. Binary Tree Postorder Traversal
Difficulty: Easy
Algorithm: Depth-First Search (DFS)
Time Complexity: O(n), where n is the number of nodes in the tree
Space Complexity: O(h), where h is the height of the tree (due to recursion stack)

Description:

Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [3,2,1]

Explanation:



Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [4,6,7,5,2,9,8,3,1]

Explanation:



Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]

 

Constraints:

The number of the nodes in the tree is in the range [0, 100].
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

// Global index to track position in preorder vector during tree build
int i = -1;

// Build tree from preorder vector, where -1 indicates NULL node
Node* buildTree(const vector<int>& nodes) {
    i++;
    if (i >= nodes.size() || nodes[i] == -1) return NULL;

    Node* root = new Node(nodes[i]);
    root->left = buildTree(nodes);
    root->right = buildTree(nodes);
    return root;
}

// Postorder traversal helper
void postorderHelper(Node* root, vector<int>& postorder) {
    if (root == NULL) return;

    postorderHelper(root->left, postorder);
    postorderHelper(root->right, postorder);
    postorder.push_back(root->data);
}

// Postorder traversal function
vector<int> postorderTraversal(Node* root) {
    vector<int> postorder;
    postorderHelper(root, postorder);
    return postorder;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};  // example input preorder with -1 as NULL
    Node* root = buildTree(nodes);

    vector<int> result = postorderTraversal(root);

    cout << "Postorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
