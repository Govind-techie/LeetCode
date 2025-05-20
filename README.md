# LeetCode Solutions

This repository includes all the LeetCode problems I solved throughout my DSA journey.

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

---

### 🚀 Special Problems (Hard)

- **Book Allocation Problem**  
  This problem involves allocating books to students in a way that minimizes the maximum number of pages assigned to any student. Solved using **binary search** on the answer range and a greedy feasibility check. Time complexity is **O(n log m)** where n is the number of books and m is the max page number.

- **Split Array Largest Sum**  
  Given an array, split it into m subarrays such that the largest sum among these subarrays is minimized. Solved with **binary search** over the answer space combined with a greedy check.

- **Aggressive Cows**  
  Given positions of stalls and number of cows, find the largest minimum distance between cows placed in stalls. Solved using **binary search** over distance and a greedy check for feasibility.

---