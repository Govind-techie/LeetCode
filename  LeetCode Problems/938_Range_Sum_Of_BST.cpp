/*
LeetCode Problem: 938 - Range Sum of BST
Algorithm: Depth-First Search (DFS) with Range Check
Difficulty: Easy
Time Complexity: O(N), where N is the number of nodes in the BST
Space Complexity: O(H), where H is the height of the tree (due to recursion stack)

Description:

Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

 

Example 1:


Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.
Example 2:


Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
Output: 23
Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 = 23.
 

Constraints:

The number of nodes in the tree is in the range [1, 2 * 104].
1 <= Node.val <= 105
1 <= low <= high <= 105
All Node.val are unique.
*/

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Global variable to store the sum
int sum = 0;

// Function to compute the range sum
int rangeSumBST(TreeNode* root, int low, int high) {
    if (root == NULL) return 0;

    if (low <= root->val && root->val <= high) {
        sum += root->val;
        rangeSumBST(root->left, low, high);
        rangeSumBST(root->right, low, high);
    } else if (root->val < low) {
        rangeSumBST(root->right, low, high);
    } else if (root->val > high) {
        rangeSumBST(root->left, low, high);
    }

    return sum;
}

// Helper function to free memory (optional)
void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}


int main() {
  
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(17);

    int low = 6, high = 15;
    int result = rangeSumBST(root, low, high);
    cout << "Range Sum of BST from " << low << " to " << high << " is: " << result << endl;

    deleteTree(root);  // Clean up memory
    return 0;
}
