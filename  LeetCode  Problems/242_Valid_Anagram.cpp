/*

// LeetCode Problem (242) : Valid Anagram

// Difficulty : Easy

// Time Complexity : O(n)

//DESCRIPTION:

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false

 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
*/

#include<iostream>
#include<string>
using namespace std;

// Function to check if two strings are anagrams
bool isAnagram(string s, string t) {
    // If lengths are different, they can't be anagrams
    if (s.length() != t.length()) 
        return false;

    int count[26] = {0}; // Array to count frequency of each character (assuming only lowercase letters)

    // Count characters from first string
    for (int i = 0; i < s.length(); i++) {
        count[s[i] - 'a']++;
    }

    // Decrease count based on second string
    for (int i = 0; i < t.length(); i++) {
        if (count[t[i] - 'a'] == 0) {
            return false; // If character not found or overused
        }
        count[t[i] - 'a']--;
    }

    return true; // All counts matched, so they are anagrams
}

int main() {
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    if (isAnagram(str1, str2)) {
        cout << "Valid Anagram" << endl;
    } else {
        cout << "Not an Anagram" << endl;
    }

    return 0;
}