/*

LeetCode Problem (242) : Valid Anagram
Difficulty : Easy

Time Complexity : O(n)
Space Complexity : O(n)

DESCRIPTION:

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

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Function to check if two strings are anagrams
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;

    unordered_map<char, int> m1;
    unordered_map<char, int> m2;

    for (char ch : s) m1[ch]++;
    for (char ch : t) m2[ch]++;

    return m1 == m2; // compare the two entire maps
}

int main() {
    string s = "anagram";
    string t = "nagaram";

    if (isAnagram(s, t)) {
        cout << s << " and " << t << " are anagrams." << endl;
    } else {
        cout << s << " and " << t << " are not anagrams." << endl;
    }

    return 0;
}