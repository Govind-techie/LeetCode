/*
LeetCode Problem 231: Power of Two
Difficulty: Easy
Time Complexity: O(log n)
Algorithm: Recursion

DESCRIPTION:


Topics
Companies
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

 

Example 1:

Input: n = 1
Output: true
Explanation: 20 = 1
Example 2:

Input: n = 16
Output: true
Explanation: 24 = 16
Example 3:

Input: n = 3
Output: false
 

Constraints:

-231 <= n <= 231 - 1
*/

#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    if (n == 1) return true;
    if (n % 2 != 0) return false;
    return isPowerOfTwo(n / 2);
}

int main() {
    int test1 = 1;  // Example input
    int test2 = 16; // Example input
    int test3 = 3;  // Example input

    cout << "Is " << test1 << " a power of two? " << (isPowerOfTwo(test1) ? "Yes" : "No") << endl;
    cout << "Is " << test2 << " a power of two? " << (isPowerOfTwo(test2) ? "Yes" : "No") << endl;
    cout << "Is " << test3 << " a power of two? " << (isPowerOfTwo(test3) ? "Yes" : "No") << endl;

    return 0;
}