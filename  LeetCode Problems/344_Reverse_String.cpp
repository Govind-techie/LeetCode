/*
LeetCode Problem 344: Reverse String
Difficulty: Easy
Time Complexity: O(n)
Algorithm: Recursion

Description:

Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

Constraints:

1 <= s.length <= 105
s[i] is a printable ascii character.
*/

#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<char>& arr, int st, int en) {
    if (st >= en) return;
    swap(arr[st], arr[en]);
    reverse(arr, ++st, --en);
}

void reverseString(vector<char>& s) {
    reverse(s, 0, s.size() - 1);
}

int main() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    cout << "Original string: ";
    for (char c : s) {
        cout << c;
    }
    cout << endl;

    reverseString(s);

    cout << "Reversed string: ";
    for (char c : s) {
        cout << c;
    }
    cout << endl;

    return 0;
}

