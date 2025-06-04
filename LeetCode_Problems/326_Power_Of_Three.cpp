/*
LeetCode Problem 326: Power of Three
Difficulty: Easy
Time Complexity: O(log n)
Algorithm: Recursion

DESCRIPTION:
Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.

 

Example 1:

Input: n = 27
Output: true
Explanation: 27 = 33
Example 2:

Input: n = 0
Output: false
Explanation: There is no x where 3x = 0.
Example 3:

Input: n = -1
Output: false
Explanation: There is no x where 3x = (-1).
 

Constraints:

-231 <= n <= 231 - 1
*/

#include <iostream>
using namespace std;

bool isPowerOfThree(int n) {
    if (n <= 0) return false;
    if (n == 1) return true;
    if (n % 3 != 0) return false;
    return isPowerOfThree(n / 3);
}

int main() {
    int test1 = 27; // Example input
    int test2 = 0;  // Example input
    int test3 = -1; // Example input

    cout << "Is " << test1 << " a power of three? " << (isPowerOfThree(test1) ? "Yes" : "No") << endl;
    cout << "Is " << test2 << " a power of three? " << (isPowerOfThree(test2) ? "Yes" : "No") << endl;
    cout << "Is " << test3 << " a power of three? " << (isPowerOfThree(test3) ? "Yes" : "No") << endl;

    return 0;
}