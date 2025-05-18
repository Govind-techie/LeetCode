/*
LeetCode Problem: 20. Valid Parentheses
Difficulty: Easy
Algorithm: Stack
Time Complexity: O(n)
Space Complexity: O(n)

Description:

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if a string has valid parentheses
bool isValid(string s) {
    stack<char> st;

    for (int i = 0; i < s.size(); i++) {
        if ((s[i] == '(') || (s[i] == '[') || (s[i] == '{')) {
            st.push(s[i]);
        } else {
            if (st.empty()) {
                return false;
            } else {
                if ((st.top() == '(' && s[i] == ')') || 
                    (st.top() == '{' && s[i] == '}') || 
                    (st.top() == '[' && s[i] == ']')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
    }

    return st.empty();
}

int main() {
    // Test cases
    string test1 = "()";
    string test2 = "()[]{}";
    string test3 = "(]";
    string test4 = "({[]})";
    string test5 = "([)]";

    cout << "Test 1: " << (isValid(test1) ? "Valid" : "Invalid") << endl;
    cout << "Test 2: " << (isValid(test2) ? "Valid" : "Invalid") << endl;
    cout << "Test 3: " << (isValid(test3) ? "Valid" : "Invalid") << endl;
    cout << "Test 4: " << (isValid(test4) ? "Valid" : "Invalid") << endl;
    cout << "Test 5: " << (isValid(test5) ? "Valid" : "Invalid") << endl;

    return 0;
}