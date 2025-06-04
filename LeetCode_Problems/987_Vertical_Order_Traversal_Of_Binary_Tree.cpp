/*
LeetCode Problem: 987 - Vertical Order Traversal of a Binary Tree
Difficulty: Hard
Algorithm: BFS

Time Complexity: O(N log N), where N is the number of nodes in the tree.
- Each node is inserted into a map and a multiset, which take O(log N) time per insert in the worst case.
- No explicit sorting is done, but ordered containers (map, multiset) maintain sorted order internally.

Space Complexity: O(N), where N is the number of nodes in the tree.
- Extra space is used for the queue during BFS and the map structure to store node values by horizontal and vertical levels.

Description:

Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Column -1: Only node 9 is in this column.
Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only node 20 is in this column.
Column 2: Only node 7 is in this column.
Example 2:


Input: root = [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
Column -2: Only node 4 is in this column.
Column -1: Only node 2 is in this column.
Column 0: Nodes 1, 5, and 6 are in this column.
          1 is at the top, so it comes first.
          5 and 6 are at the same position (2, 0), so we order them by their value, 5 before 6.
Column 1: Only node 3 is in this column.
Column 2: Only node 7 is in this column.
Example 3:


Input: root = [1,2,3,4,6,5,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
This case is the exact same as example 2, but with nodes 5 and 6 swapped.
Note that the solution remains the same since 5 and 6 are in the same location and should be ordered by their values.
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
0 <= Node.val <= 1000
*/
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

// Node class for the binary tree
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

// Static index used by buildTree (preorder input)
static int i = -1;

// Function to build binary tree from a vector using preorder traversal
// -1 in input indicates NULL nodes
Node* buildTree(const vector<int>& nodes) {
    i++;
    if (i >= nodes.size() || nodes[i] == -1) return NULL;

    Node* currNode = new Node(nodes[i]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

// Function to perform vertical order traversal of the binary tree
vector<vector<int>> verticalTraversal(Node* root) {
    vector<vector<int>> res;

    // Queue stores: (Node*, (horizontal distance, level))
    queue<pair<Node*, pair<int, int>>> q;
    q.push({root, {0, 0}});  // root starts at hd = 0, level = 0

    // Nested map structure:
    // map<HD, map<Level, multiset<node values>>> 
    // Helps group nodes by their vertical and level positions, with sorted values
    map<int, map<int, multiset<int>>> m;

    while (!q.empty()) {
        auto [currNode, pos] = q.front();
        q.pop();

        int hd = pos.first;     // horizontal distance
        int level = pos.second; // depth/level in tree

        // Insert current node value into the appropriate HD and level group
        m[hd][level].insert(currNode->val);

        // Enqueue left child with HD - 1 and level + 1
        if (currNode->left != NULL) {
            q.push({currNode->left, {hd - 1, level + 1}});
        }

        // Enqueue right child with HD + 1 and level + 1
        if (currNode->right != NULL) {
            q.push({currNode->right, {hd + 1, level + 1}});
        }
    }

    // Extract values from the nested map structure into the result vector
    for (auto& [hd, levelMap] : m) {
        vector<int> col;
        for (auto& [level, values] : levelMap) {
            // Insert all sorted node values at this (hd, level)
            col.insert(col.end(), values.begin(), values.end());
        }
        res.push_back(col);
    }

    return res;
}

// Driver code
int main() {
    // Preorder input: -1 represents NULL
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    // Perform vertical traversal
    vector<vector<int>> result = verticalTraversal(root);

    // Output each vertical column
    for (const auto& col : result) {
        for (int val : col) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}