# LeetCode Solutions

This repository includes all the LeetCode problems I solved throughout my DSA journey.

## 🎯 LeetCode Problems

### ✅ Easy Problems
- **Problem 136: Single Number**  
  Find the single number in an array where every element appears twice except for one.

- **Problem 1: Two Sum**  
  Find two numbers in an array that add up to a specific target value.

- **Problem 169: Majority Element**  
  Find the majority element in an array that appears more than **n / 2** times.

- **Problem 121: Best Time to Buy and Sell Stock**  
  Find the maximum profit you can make from buying and selling a stock once, given an array of prices where each element represents the price of the stock on a given day.

- **Problem 26: Remove Duplicates from Sorted Array**  
  Remove duplicates from a sorted array in-place such that each unique element appears only once, achieving an **O(n) time complexity** with **O(1) extra space**.

- **Problem 374: Guess Number Higher or Lower**  
  Guess the picked number using **binary search**, reducing the search space efficiently to achieve an **O(log n) time complexity**.

- **Problem 704: Binary Search**  
  Implement **binary search** on a sorted array to find a target element, achieving an **O(log n) time complexity**.

- **Problem 35: Search Insert Position**  
  Find the index where a target value should be inserted in a sorted array using **binary search**, achieving an **O(log n) time complexity**.

- **Problem 278: First Bad Version**  
  Find the first bad version in a sequence using **binary search**, optimizing the search process to **O(log n) time complexity**.

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

---

### 🚀 Special Problems (Hard)

- **Book Allocation Problem**  
  This problem involves allocating books to students in a way that minimizes the maximum number of pages assigned to any student. It requires **binary search on answer** and **greedy allocation** to efficiently distribute the books. The key constraints are:
  - Each book must be assigned to exactly one student.
  - Each student must get at least one book.
  - The books must be allocated in **contiguous order**.
  
  This problem is not on LeetCode but is an important **hard-level** problem often asked in interviews.

- **Painter’s Partition Problem**  
  This problem involves partitioning a set of boards among painters such that the maximum time taken by any painter is minimized. It is solved using **binary search on answer** along with **greedy allocation** to ensure an efficient partitioning strategy. The key constraints are:
  - Each painter must paint at least one board.
  - A painter can only paint **contiguous** boards.
  - The goal is to minimize the **maximum time** taken by any painter.
  
  This problem is another **hard-level** problem, commonly asked in coding interviews.

- **Aggressive Cows Problem**  
  This problem involves placing cows in stalls such that the minimum distance between any two cows is maximized. It is solved using **binary search on answer** and **greedy placement** to efficiently determine the optimal placement strategy. The key constraints are:
  - The stalls are given in an unordered list and must be sorted before applying the approach.
  - The goal is to find the largest minimum distance possible between cows.
  
  This problem is a popular **hard-level** problem often asked in competitive programming contests and technical interviews.
