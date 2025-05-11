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

---

### 🚀 Hard Problems

- **Problem 42: Trapping Rain Water**  
  *Calculate how much water can be trapped after raining, given the elevation map. Solved using the two-pointer approach to reduce space and achieve O(n) time complexity.*

---

### 🚀 Special Problems (Hard)

- **Book Allocation Problem**  
  This problem involves allocating books to students in a way that minimizes the maximum number of pages assigned to any student. It requires **binary search on answer** and **greedy allocation** to efficiently distribute the books. The key constraints are:
  - Each book must be assigned to exactly one student.
  - Each student must get at least one book.
  - The books must be allocated in **contiguous order**.

- **Painter’s Partition Problem**  
  This problem involves partitioning a set of boards among painters such that the maximum time taken by any painter is minimized. It is solved using **binary search on answer** along with **greedy allocation** to ensure an efficient partitioning strategy. The key constraints are:
  - Each painter must paint at least one board.
  - A painter can only paint **contiguous** boards.
  - The goal is to minimize the **maximum time** taken by any painter.

- **Aggressive Cows Problem**  
  This problem involves placing cows in stalls such that the minimum distance between any two cows is maximized. It is solved using **binary search on answer** and **greedy placement** to efficiently determine the optimal placement strategy. The key constraints are:
  - The stalls are given in an unordered list and must be sorted before applying the approach.
  - The goal is to find the largest minimum distance possible between cows.