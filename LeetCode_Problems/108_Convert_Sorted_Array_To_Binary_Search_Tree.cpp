/*
LeetCode Problem: 108 - Convert Sorted Array to Binary Search Tree
Difficulty: Easy
Algorithm: Divide and Conquer
Time Complexity: O(n)
Space Complexity: O(log n) for the recursion stack

Description:

Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

 

Example 1:


Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:


Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in a strictly increasing order.
*/

#include <iostream>
#include <vector>
using namespace std;

// Definition of a TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function to convert sorted array to BST
TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int st, int en) {
    if (st > en) return NULL;

    int mid = st + (en - st) / 2;
    TreeNode* root = new TreeNode(nums[mid]);

    root->left = sortedArrayToBSTHelper(nums, st, mid - 1);
    root->right = sortedArrayToBSTHelper(nums, mid + 1, en);

    return root;
}

// Main function to call helper
TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
}

// Utility function to print inorder traversal of BST
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode* root = sortedArrayToBST(nums);

    cout << "Inorder traversal of the BST: ";
    inorder(root);
    cout << endl;

    return 0;
}