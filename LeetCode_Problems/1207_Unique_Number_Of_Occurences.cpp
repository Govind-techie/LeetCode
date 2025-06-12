/*
LeetCode Problem 1207: Unique Number of Occurrences
Difficulty: Easy
Time Complexity: O(n)
Space Complexity: O(n)
Algorithm: Use a hash map to count occurrences and a set to check uniqueness.

Dsecription:
Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

 

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
 

Constraints:

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Function to check if the occurrences of each element are unique
bool uniqueOccurrences(vector<int>& arr) {
    if (arr.size() == 0) return true;

    unordered_map<int, int> m;
    unordered_set<int> s;

    for (int i : arr) m[i]++;

    for (auto& p : m) {
        if (s.count(p.second) != 0) return false;
        s.insert(p.second);
    }

    return true;
}

int main() {
    vector<int> arr1 = {1, 2, 2, 1, 1, 3};
    vector<int> arr2 = {1, 2};
    vector<int> arr3 = {};
    
    cout << "Test Case 1: " << (uniqueOccurrences(arr1) ? "True" : "False") << endl;
    cout << "Test Case 2: " << (uniqueOccurrences(arr2) ? "True" : "False") << endl;
    cout << "Test Case 3 (Empty): " << (uniqueOccurrences(arr3) ? "True" : "False") << endl;

    return 0;
}