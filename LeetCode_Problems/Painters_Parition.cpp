// Problem : Painter's Partition (Hard)

// DESCRIPTION : 

// Given are (n) boards of length each given in form of array, and (m) painters such that each painter take 1 unit of time to paint 1 unit 
// of board.

// The task is to find the minimum time to paint all boards under the constraints that any painter will only paint continuous sections of boards.

/*
Constraints:
1 ≤ n ≤ 10^5  
1 ≤ m ≤ n  
1 ≤ boards[i] ≤ 10^9  
*/

// Example 1
// Input: n = 4, m = 2, boards = [10, 20, 30, 40]
// Output: 60
// Explanation: Painter 1 -> [10, 20, 30] (60), Painter 2 -> [40] (40), Max time = 60

// Example 2
// Input: n = 3, m = 3, boards = [5, 10, 15]
// Output: 15
// Explanation: Painter 1 -> [5] (5), Painter 2 -> [10] (10), Painter 3 -> [15] (15), Max time = 15

// Note: The boards array is not necessarily sorted and can contain elements in any order.


#include <iostream>
#include <vector>
using namespace std;

// Function to check if it's possible to paint all boards within 'mid' time
// while ensuring no painter paints non-continuous sections.
bool isValid(vector<int> len, int n, int m, int mid) {
    int painter = 1;  // Start with one painter
    int time = 0;      // Current time spent by the painter

    for (int i = 0; i < n; i++) {
        // If a single board length is greater than mid, it's impossible to paint it
        if (len[i] > mid) return false;

        // If adding the current board doesn't exceed the mid-time, assign it to the same painter
        if (time + len[i] <= mid) {
            time += len[i];
        } 
        // Otherwise, assign the board to a new painter
        else {
            painter++;   // Increase the painter count
            time = len[i]; // Start a new painter with the current board
        }

        // If the number of painters exceeds the available m painters, return false
        if (painter > m) return false;
    }
    return true;
}

// Function to find the minimum time required to paint all boards
int maxTime(vector<int> len, int n, int m) {
    int start = len[0];  // Minimum time possible
    int end = 0;    // Maximum time possible (sum of all boards)
    int time = 0;   // Variable to store the result

    // Calculate the sum of all board lengths (upper bound for binary search)
    for (int nums : len) {
        end += nums;
    }

    // Apply binary search on the minimum and maximum possible time
    while (start <= end) {
        int mid = start + (end - start) / 2;  // Find the middle value of the range

        // If it's possible to paint all boards within 'mid' time
        if (isValid(len, n, m, mid)) {
            time = mid;  // Store the potential answer
            end = mid - 1; // Try for a better (lower) minimum time
        } else {
            start = mid + 1; // Increase the minimum time limit
        }
    }
    return time; // Return the minimum possible maximum time required
}

int main() {
    // Test case: Given boards and painters
    vector<int> boards = {10, 20, 30, 40}; // Lengths of boards
    int n = boards.size(); // Number of boards
    int m = 2; // Number of painters

    // Output the minimum time required to paint all boards
    cout << "Minimum time to paint all boards: " << maxTime(boards, n, m) << endl;
    return 0;
}
