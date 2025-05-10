
/*
LeetCode Problem: 342. Power of Four
Difficulty: Easy
Time Complexity: O(log n)
Algorithm: Recursion


DESCRIPTION:
Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x.

 

Example 1:

Input: n = 16
Output: true
Example 2:

Input: n = 5
Output: false
Example 3:

Input: n = 1
Output: true
 

Constraints:

-231 <= n <= 231 - 1
*/


#include <iostream>
using namespace std;

bool isPowerOfFour(int n) {
    if (n <= 0) return false;
    if (n == 1) return true;
    if (n % 4 != 0) return false;
    return isPowerOfFour(n / 4);
}

int main() {
    int test1 = 16; // Example input
    int test2 = 5;  // Example input
    int test3 = 1;  // Example input

    cout << "Is " << test1 << " a power of four? " << (isPowerOfFour(test1) ? "Yes" : "No") << endl;
    cout << "Is " << test2 << " a power of four? " << (isPowerOfFour(test2) ? "Yes" : "No") << endl;
    cout << "Is " << test3 << " a power of four? " << (isPowerOfFour(test3) ? "Yes" : "No") << endl;

    return 0;
}