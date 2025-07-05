# LeetCode Solutions

This repository includes all the LeetCode problems I solved throughout my DSA journey.

## 📈 Progress

- ✅ Easy: 37 problems  
- 🔥 Medium: 30 problems  
- 🚀 Hard: 6 problems  

---

## 🎯 LeetCode Problems

### ✅ Easy Problems

- **Problem 136: Single Number**  
  *Find the single number in an array where every element appears twice except for one.*

- **Problem 1: Two Sum**  
  *Find two numbers in an array that add up to a specific target value.*

- **Problem 169: Majority Element**  
  *Find the majority element in an array that appears more than **n / 2** times.*

- **Problem 121: Best Time to Buy and Sell Stock**  
  *Find the maximum profit you can make from buying and selling a stock once, given an array of prices where each element represents the price of the stock on a given day.*

- **Problem 26: Remove Duplicates from Sorted Array**  
  *Remove duplicates from a sorted array in-place such that each unique element appears only once, achieving an **O(n) time complexity** with **O(1) extra space**.*

- **Problem 374: Guess Number Higher or Lower**  
  *Guess the picked number using **binary search**, reducing the search space efficiently to achieve an **O(log n) time complexity**.*

- **Problem 704: Binary Search**  
  *Implement **binary search** on a sorted array to find a target element, achieving an **O(log n) time complexity**.*

- **Problem 35: Search Insert Position**  
  *Find the index where a target value should be inserted in a sorted array using **binary search**, achieving an **O(log n) time complexity**.*

- **Problem 278: First Bad Version**  
  *Find the first bad version in a sequence using **binary search**, optimizing the search process to **O(log n) time complexity**.*

- **Problem 88: Merge Two Sorted Arrays**  
  *Merge two sorted arrays into one sorted array in place. The problem is solved efficiently by starting from the end of the arrays and filling the result in a backward direction. The time complexity is **O(m + n)**.*

- **Problem 905: Sort Array By Parity**  
  *Sort an array such that all even numbers appear before all odd numbers while maintaining relative order. This problem is efficiently solved using a **two-pointer approach**, achieving **O(n) time complexity** with **O(1) space complexity**.*

- **Problem 167: Two Sum II - Input Array Is Sorted**  
  *Given a sorted array, find two numbers such that they add up to a specific target. Solved using the two-pointer approach in O(n) time.*

- **Problem 242: Valid Anagram**  
  *Check if two strings are anagrams of each other. Solved using character frequency counting with O(n) time complexity.*

- **Problem 2022: Convert 1D Array Into 2D Array**  
  *Convert a 1D array into a 2D array with specified dimensions. Solved using simple slicing and traversal, with O(n) time complexity.*

- **Problem 217: Contains Duplicate**  
  *Check if any value appears at least twice in an array. Solved using hashing (unordered_set) in O(n) time and space.*

- **Problem 231: Power of Two**  
  *Check whether a number is a power of 2 using recursion. Solved by dividing the number by 2 repeatedly and checking if it reduces to 1.*

- **Problem 326: Power of Three**  
  *Check whether a number is a power of 3 using recursion. Divide the number by 3 repeatedly and return true if it becomes 1.*

- **Problem 342: Power of Four**  
  *Check whether a number is a power of 4 using recursion. Divide by 4 until the number becomes 1, returning true if successful.*

- **Problem 344: Reverse String**  
  *Reverse a given character array in-place using the two-pointer approach. This solution is implemented using recursion where the first and last characters are swapped and the function is called recursively on the remaining substring. The algorithm efficiently reverses the string with **O(n) time complexity** and **O(n) space complexity** (due to recursion stack).*

- **Problem 20: Valid Parentheses**  
  *Check if a string containing just the characters '(', ')', '{', '}', '[' and ']' is valid. A valid string requires every opening bracket to be closed by the same type of bracket in the correct order. Solved using a stack to track opening brackets and matching with closing brackets efficiently.*

- **Problem 234: Palindrome Linked List**  
  *Check whether a singly linked list is a palindrome. Solved by finding the middle of the linked list, reversing the second half, and then comparing both halves. The solution achieves **O(n) time complexity** and **O(1) space complexity**.*

- **Problem 222: Count Complete Tree Nodes**  
  *Count the number of nodes in a complete binary tree efficiently using depth comparison. The solution uses a recursive approach achieving **O(log² n) time complexity**.*

- **Problem 104: Maximum Depth of Binary Tree**  
  *Calculate the maximum depth (or height) of a binary tree using DFS traversal. Solved recursively with **O(n) time complexity**.*

- **Problem 145: Binary Tree Postorder Traversal**  
  *Traverse a binary tree in postorder (left-right-root) using recursion or stack. The solution achieves **O(n) time complexity**.*

- **Problem 94: Binary Tree Inorder Traversal**  
  *Traverse a binary tree in inorder (left-root-right) using recursion or a stack. Time complexity is **O(n)**.*

- **Problem 144: Binary Tree Preorder Traversal**  
  *Traverse a binary tree in preorder (root-left-right) using recursion or a stack. Time complexity is **O(n)**.*

- **Problem 543: Diameter of Binary Tree**  
  *Compute the diameter (longest path between any two nodes) of a binary tree. Solved using postorder DFS traversal in **O(n)** time.*

- **Problem 100: Same Tree**  
  *Given two binary trees, check whether they are the same tree. Two trees are the same if they are structurally identical and the nodes have the same value. Solved using recursion in **O(n)** time.*

- **Problem 572: Subtree of Another Tree**  
  *Check whether one binary tree is a subtree of another. Solved using recursion and the helper function to check tree equality. Time complexity is **O(m * n)** in the worst case.*

- **Problem 112: Path Sum**  
  *Given a binary tree and a target sum, determine if the tree has a root-to-leaf path such that the sum of the node values equals the target. Solved using DFS with recursive subtraction of node values from the target sum.*

- **Problem 938: Range Sum of BST**  
  *Given a Binary Search Tree and a range \[low, high\], return the sum of all node values within that range. The problem is solved using **DFS traversal**, where we leverage the **BST property** to skip unnecessary branches. If the current node value is less than `low`, we only explore the right subtree; if it's greater than `high`, we explore only the left subtree. This approach improves efficiency over a brute-force traversal. The time complexity is **O(n)** in the worst case (unbalanced tree) and **O(log n)** on average for a balanced BST.*

- **Problem 98: Validate Binary Search Tree**  
  *Determine if a binary tree is a valid binary search tree (BST).  
  A valid BST requires that for every node, all nodes in the left subtree are strictly less than the node’s value, and all nodes in the right subtree are strictly greater than the node’s value (no duplicates allowed).  
  The solution uses recursion with min and max constraints passed down to validate each subtree, ensuring strict inequality.  
  Time complexity: **O(n)**, where n is the number of nodes in the tree.*

- **Problem 108: Convert Sorted Array to Binary Search Tree**  
  *Given a sorted array, convert it to a height-balanced binary search tree (BST).  
  The solution uses the middle element of the array as the root to ensure balance, then recursively builds left and right subtrees from the left and right halves of the array respectively. This approach achieves O(n) time complexity.*

- **Problem 1337: The K Weakest Rows in a Matrix**  
  *Given a binary matrix where each row consists of soldiers (1s) followed by civilians (0s), return the indices of the **k weakest rows** in the matrix in order from weakest to strongest.*  
  A row is weaker if it has fewer soldiers, or the same number of soldiers but a smaller index.  
  The solution uses a **min-heap (priority queue)** or sorting based on soldier count (using binary search per row) along with row index to determine the weakest rows.  
  Time complexity is **O(m × log n + m log m)** where *m* is the number of rows and *n* is the number of columns.

- **Problem 1207: Unique Number of Occurrences**  
  *Given an array of integers, determine if the number of occurrences of each value is unique.  
  The solution uses a hash map to count the frequency of each element, then checks if all frequencies are unique by inserting them into a hash set.  
  If any frequency repeats, return false; otherwise, return true.  
  Time complexity is **O(n)** for counting and checking uniqueness, where n is the length of the array.*

- **Problem 349: Intersection of Two Arrays**  
  *Given two arrays, find their intersection (unique elements present in both arrays).  
  The solution uses hash sets to store elements from the first array and checks for common elements in the second array, ensuring uniqueness in the result.  
  Time complexity is **O(n + m)**, where n and m are the lengths of the two arrays.*
  
- **Problem 2215: Find the Difference of Two Arrays**  
  *Given two integer arrays, return a list of two lists:  
  1. Elements present in the first array but not in the second,  
  2. Elements present in the second array but not in the first.  
  The solution uses hash sets to efficiently compute the unique differences between the arrays.  
  Time complexity is **O(n + m)**, where n and m are the lengths of the two arrays.*

- **Problem 1971: Find if Path Exists in Graph**  
  *Given an undirected graph with n nodes and a list of edges, determine if there is a valid path between two given nodes (source and destination).  
  The solution builds an adjacency list and uses Depth-First Search (DFS) or Breadth-First Search (BFS) to check if the destination node is reachable from the source node.  
  Time complexity is **O(V + E)**, where V is the number of vertices and E is the number of edges.*

---

### 🔥 Medium Problems

- **Problem 53: Maximum Subarray Sum**  
  Find the maximum sum of a contiguous subarray using the brute-force approach.

- **Problem 50: Pow(x, n)**  
  Calculate **x** raised to the power **n** (x^n), implementing an efficient approach using binary exponentiation to reduce the time complexity.

- **Problem 11: Container With Most Water**  
  Find the maximum area of water that can be contained by two vertical lines, given their positions and heights. The problem is solved using the **two-pointer approach** to optimize the solution and reduce time complexity to **O(n)**.

- **Problem 238: Product of Array Except Self**  
  Compute an array where each element is the product of all other elements except itself, without using division. The problem is solved using a **prefix and suffix multiplication approach**, achieving an optimal **O(n) time complexity** with **O(1) extra space** (excluding the output array).

- **Problem 33: Search in Rotated Sorted Array**  
  Search a target value in a **rotated sorted array** using **binary search**, achieving an efficient **O(log n) time complexity**.

- **Problem 852: Peak Index in a Mountain Array**  
  Find the peak index in a **mountain array** using **binary search**, optimizing the search process to **O(log n) time complexity**.

- **Problem 153: Find Minimum in Rotated Sorted Array**  
  Find the minimum element in a **rotated sorted array** using **binary search**, achieving an efficient **O(log n) time complexity**.

- **Problem 540: Single Element in a Sorted Array**  
  Find the single non-duplicate element in a sorted array where every other element appears twice. The problem is solved efficiently using **binary search**, achieving an **O(log n) time complexity**.

- **Problem 75: Sort Colors**  
  Sort an array of colors (represented by 0, 1, and 2) in place using the **Dutch National Flag Algorithm**. This problem is solved with a **one-pass** solution to achieve **O(n) time complexity** and **O(1) space complexity**.

- **Problem 31: Next Permutations**  
  Find the next lexicographically greater permutation of numbers in an array. The problem is solved using **three steps**: finding the pivot, swapping elements, and reversing the right part of the array, all in **O(n)** time complexity.

- **Problem 152: Maximum Product Subarray**  
  *Find the contiguous subarray that has the largest product. Solved using a variation of Kadane’s Algorithm keeping track of max and min products, with O(n) time complexity.*

- **Problem 46: Permutations**  
  *Given a collection of distinct integers, return all possible permutations.*  
  This problem is solved using **backtracking**, where we build the permutations one element at a time by swapping elements and recursively generating the next permutation. The algorithm achieves an **O(n!) time complexity** and **O(n)** space complexity, where n is the number of elements in the input array.

- **Online Stock Span Problem**  
  *Calculate the stock span for each day given daily stock prices. The problem is solved using a stack to maintain indices of days with greater stock prices, achieving an efficient **O(n)** time complexity.*

- **Problem 496: Next Greater Element I**  
  *Given two arrays, find the next greater element for each element in the first array relative to the second array. Solved using a stack to efficiently find the next greater elements and hash mapping to answer queries in O(n) time.*

- **Problem 102: Binary Tree Level Order Traversal**  
  *Traverse a binary tree level by level using BFS. Solved using a queue and visited each node once for a **O(n)** time complexity solution.*

- **Problem 236: Lowest Common Ancestor of a Binary Tree**  
  *Given a binary tree, find the lowest common ancestor (LCA) of two given nodes. The LCA of two nodes is the deepest node that has both nodes as descendants (a node can be a descendant of itself). Solved using a recursive post-order traversal. If both left and right recursive calls return non-null, the current node is the LCA. Otherwise, we return whichever side is non-null. Time complexity is **O(n)** where n is the number of nodes in the tree.*

- **Problem 1382: Balance a Binary Search Tree**  
  *Given a binary search tree (BST), return a balanced BST with the same node values.*  
  The solution involves performing an inorder traversal to collect the nodes in sorted order, then recursively building a balanced BST from the sorted list by choosing the middle element as the root at each step.  
  This approach guarantees a balanced tree and runs in **O(n)** time and space, where n is the number of nodes.

- **Problem 973: K Closest Points to Origin**  
  *Find the k points closest to the origin (0, 0) using a max-heap (priority queue).*  
  *Time complexity: O(n log k), Space complexity: O(k).*

- **Problem 215: Kth Largest Element in an Array**  
  *Find the kᵗʰ largest element using a max heap (priority queue). Push all elements into the max heap (inverted min heap in most languages), then pop k times to get the answer. Time: O(n log n), Space: O(n).*

- **Problem 229: Majority Element II**  
  *Find all elements in an array that appear more than ⌊n/3⌋ times.*  
  Solved using a **hash map to count frequencies** and a **set to avoid duplicates**:  
  1. Iterate through the array and count each element’s frequency using an unordered_map.  
  2. If the count exceeds ⌊n/3⌋ and hasn’t been added to the result yet (tracked using unordered_set), add it to the answer.  
  Time complexity: **O(n)**, Space complexity: **O(n)**.

- **Problem 560: Subarray Sum Equals K**  
  *Given an array of integers and an integer k, find the total number of continuous subarrays whose sum equals k.  
  The solution uses a hash map to store the cumulative sum frequencies while iterating through the array.  
  For each element, it checks if (current sum - k) exists in the map, which indicates a subarray summing to k ends at the current index.  
  This approach achieves **O(n) time complexity** and **O(n) space complexity**.*

- **Problem 974: Subarray Sums Divisible by K**  
  *Given an integer array and an integer k, return the number of non-empty subarrays whose sum is divisible by k.  
  The solution uses a hash map to track the frequency of prefix sum remainders modulo k while iterating through the array.  
  For each prefix sum, it checks how many times the same remainder has occurred before, which indicates a subarray sum divisible by k.  
  Handles negative numbers by normalizing the modulo result.  
  Time complexity is **O(n)** and space complexity is **O(n)**.*

- **Problem 720: Longest Word in Dictionary**  
  *Given a list of words, find the longest word in the dictionary that can be built one character at a time by other words in the list.  
  The solution sorts the words and uses a hash set to keep track of valid prefixes. For each word, it checks if all prefixes exist in the set before adding the word itself.  
  If multiple answers exist, the lexicographically smallest is returned.  
  Time complexity is **O(n log n + n * k)**, where n is the number of words and k is the

- **Problem 684: Redundant Connection**  
  *Given a connected undirected graph with one extra edge added to a tree, find the edge that can be removed so the resulting graph is a tree.  
  The solution incrementally adds edges and uses Depth-First Search (DFS) to detect cycles. When a cycle is detected upon adding an edge, that edge is the redundant connection.  
  Time complexity is **O(V + E)** per edge, where V is the number of vertices and E is the number of edges.*


- **Problem 785: Is Graph Bipartite?**  
  *Given an undirected graph, determine if it is bipartite (i.e., its nodes can be colored with two colors such that no two adjacent nodes share the same color).  
  The solution uses Breadth-First Search (BFS) to attempt coloring the graph and checks for conflicts. If a conflict is found, the graph is not bipartite.  
  Time complexity is **O(V + E)**, where V is the number of vertices and E is the number of edges.*

- **Problem 797: All Paths From Source to Target**  
  *Given a directed acyclic graph (DAG), find all possible paths from node 0 to node n - 1.  
  The solution uses Depth-First Search (DFS) with backtracking to explore all paths from the source to the target node, storing each valid path.  
  Time complexity is **O(2^(V + E))** in the worst case, where V is the number of vertices and E is the number of edges, as all possible paths are explored.*

- **Problem 207: Course Schedule**  
  *Given the total number of courses and a list of prerequisite pairs, determine if it is possible to finish all courses.  
  The solution models the problem as a directed graph and uses Depth-First Search (DFS) to detect cycles. If a cycle is detected, it means there is a circular dependency and not all courses can be completed.  
  Time complexity is **O(V + E)**, where V is the number of courses and E is the number of prerequisite pairs.*
  
- **Problem 210: Course Schedule II**  
  *Given the total number of courses and a list of prerequisite pairs, return an ordering of courses you should take to finish all courses.  
  The solution models the problem as a directed graph and uses topological sorting (DFS-based) to find a valid course order. If a cycle is detected (i.e., not all courses can be completed), it returns an empty array.  
  Time complexity is **O(V + E)**, where V is the number of courses and E is the number of prerequisite pairs.*

- **Problem 743: Network Delay Time**  
  *Given a network of n nodes and a list of travel times as directed edges, determine the minimum time required for a signal sent from a starting node to reach all nodes. If it is impossible, return -1.  
  The solution builds an adjacency list and uses Dijkstra's algorithm to find the shortest path from the source to all nodes, tracking the maximum delay.  
  Time complexity is **O((V + E) log V)**, where V is the number of nodes and E is the number of edges.*

---

### 🚀 Hard Problems

- **Problem 42: Trapping Rain Water**  
  *Calculate how much water can be trapped after raining, given the elevation map. Solved using the two-pointer approach to reduce space and achieve O(n) time complexity.*

- **Problem 51: N-Queens**  
  *Solve the N-Queens problem where the task is to place N queens on an N×N chessboard such that no two queens threaten each other. The problem is solved using **backtracking** and checking for safety at each position on the board.*

- **Problem 37: Sudoku Solver**  
  *Solve a 9x9 Sudoku puzzle by filling empty cells so that each row, column, and 3×3 subgrid contains all digits from 1 to 9 exactly once. Solved using **backtracking**, where we try placing each digit in empty cells, validate the placement with safety checks, and backtrack when necessary. The time complexity is exponential in the worst case, but optimized with early pruning.*

- **Problem 84: Largest Rectangle in Histogram**  
  *Given a histogram (an array of heights), find the area of the largest rectangle that can be formed. Solved using a stack-based approach to track indices and compute the maximum area efficiently in **O(n)** time.*

- **Problem 987: Vertical Order Traversal of a Binary Tree**  
  *Given a binary tree, return the vertical order traversal of its nodes' values. Nodes with the same position should be reported in order from top to bottom, and from left to right when positions are the same. This is solved using BFS with a map to store nodes by their vertical and level indices, achieving **O(n log n)** time complexity.*

- **Problem 1305: All Elements in Two Binary Search Trees**  
  *Given two binary search trees, return a sorted list containing all the elements from both trees. Solved using inorder traversal on both trees to get sorted lists, then merging these two sorted lists efficiently with O(n + m) time complexity.*

- **Problem 239: Sliding Window Maximum**  
  *Given an array of integers and a sliding window size `k`, return the maximum value in each sliding window.*  
  The problem is solved using a **deque (double-ended queue)** to maintain the indices of potential maximum elements for the current window.  
  At each step, we remove indices from the back of the deque if the current element is greater than the elements at those indices. We also remove the front element if it is outside the current window.  
  This results in an efficient **O(n) time complexity** where n is the number of elements in the input array.

---

### 🚀 Special Problems (Hard)

- **Book Allocation Problem**  
  This problem involves allocating books to students in a way that minimizes the maximum number of pages assigned to any student. Solved using **binary search** on the answer range and a greedy feasibility check. Time complexity is **O(n log m)** where n is the number of books and m is the max page number.

- **Split Array Largest Sum**  
  Given an array, split it into m subarrays such that the largest sum among these subarrays is minimized. Solved with **binary search** over the answer space combined with a greedy check.

- **Aggressive Cows**  
  Given positions of stalls and number of cows, find the largest minimum distance between cows placed in stalls. Solved using **binary search** over distance and a greedy check for feasibility. 