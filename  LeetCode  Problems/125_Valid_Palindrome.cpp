/*
// LeetCode Problem (125) : Valid Palindrome

// Difficulty : Easy

// Time Complexity : O(n)

//DESCRIPTION:

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/

#include<iostream>
#include<string>
using namespace std;

// Function to check if a string is a valid palindrome
bool isPalindrome(string s) {
    int st = 0;
    int end = s.length() - 1;

    while (st < end) {
        // Skip non-alphanumeric characters from the start
        while (st < end && !isalnum(s[st])) 
            st++;
        
        // Skip non-alphanumeric characters from the end
        while (st < end && !isalnum(s[end])) 
            end--;

        // Compare characters after converting both to lowercase
        if (tolower(s[st++]) != tolower(s[end--])) {
            return false; // Not a palindrome
        }
    }

    return true; // It is a palindrome
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str); // Use getline to read spaces too

    if (isPalindrome(str)) {
        cout << "Valid Palindrome" << endl;
    } else {
        cout << "Not a Palindrome" << endl;
    }

    return 0;
}