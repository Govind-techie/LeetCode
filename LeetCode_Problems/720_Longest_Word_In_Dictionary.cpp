/*
LeetCode Problem 720: Longest Word in Dictionary
Difficulty: Medium
Algorithm: Trie, Backtracking
Time Complexity: O(N * L), where N is the number of words and L is the average length of the words.
Space Complexity: O(N * L), for storing the Trie.

Description:

Given an array of strings words representing an English Dictionary, return the longest word in words that can be built one character at a time by other words in words.

If there is more than one possible answer, return the longest word with the smallest lexicographical order. If there is no answer, return the empty string.

Note that the word should be built from left to right with each additional character being added to the end of a previous word. 

 

Example 1:

Input: words = ["w","wo","wor","worl","world"]
Output: "world"
Explanation: The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
Example 2:

Input: words = ["a","banana","app","appl","ap","apply","apple"]
Output: "apple"
Explanation: Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".
 

Constraints:

1 <= words.length <= 1000
1 <= words[i].length <= 30
words[i] consists of lowercase English letters.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> child;
    bool endOfWord;

    Node() {
        endOfWord = false;
    }
};

class Trie {
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* curr = root;
        for (char ch : word) {
            if (!curr->child[ch]) {
                curr->child[ch] = new Node();
            }
            curr = curr->child[ch];
        }
        curr->endOfWord = true;
    }

    Node* getRoot() {
        return root;
    }
};

void helper(Node* root, string& ans, string temp) {
    for (auto p : root->child) {
        temp += p.first;
        if (p.second->endOfWord) {
            if (temp.size() > ans.size() || (temp.size() == ans.size() && temp < ans)) {
                ans = temp;
            }
            helper(p.second, ans, temp);
        }
        temp.pop_back();
    }
}

string longestWord(vector<string>& words) {
    Trie t;
    for (string s : words) t.insert(s);

    string ans = "";
    helper(t.getRoot(), ans, "");
    return ans;
}

int main() {
    vector<string> words = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    cout << longestWord(words) << endl;  // Output: apple
    return 0;
}