// Problem : AGGRESSIVE COWS 

// PROBLEM STATEMENT
// 	•	Given N stalls (distinct positions) and C cows, place cows in stalls such that the minimum distance between any two cows is maximized.
// 	•	Return the largest minimum distance possible.


/*

EXAMPLE 1
Input: N = 5, C = 3, stalls = [1, 2, 8, 4, 9] 
Output: 3
Explanation: Cows placed at 1, 4, 8 → Min distance = 3


EXAMPLE 2
Input: N = 5, C = 2, stalls = [1, 2, 8, 4, 9]
Output: 8
Explanation: Cows placed at 1, 9 → Min distance = 8


CONSTRAINTS
	•	2 ≤ N ≤ 10⁵, 2 ≤ C ≤ N
	•	1 ≤ stalls[i] ≤ 10⁹ (Distinct positions)

*/

#include<iostream>
#include<vector>
using namespace std;

// Function to check if cows can be placed with a minimum distance of 'mid' between them
bool isValid(vector<int> arr, int n, int c, int mid) {

    int cow = 1; // Placing the first cow at the first stall
    int lastStallPos = arr[0]; // Store the position of the last placed cow

    // Try placing the remaining cows
    for (int i = 1; i < n; i++) {
        // If the gap between current stall and last placed cow is at least 'mid', place a new cow
        if (arr[i] - lastStallPos >= mid) {
            cow++; 
            lastStallPos = arr[i]; // Update last placed cow position
        }
        // If all cows are placed successfully, return true
        if (cow == c) return true;
    }
    return false; // Not possible to place all cows with the given minimum distance
}

// Function to find the largest minimum distance possible
int minLargestDistance(vector<int> arr, int n, int c) {
    // Sorting is already done inside isValid(), so start and end need correct initialization
    sort(arr.begin(), arr.end()); // Ensure the array is sorted before searching

    int start = 1; // The minimum possible distance (1 unit)
    int end = arr[n - 1] - arr[0]; // The maximum possible distance (largest stall - smallest stall)
    int minLargestDist = 0; // Store the maximum of minimum distances found

    // Apply binary search to find the optimal distance
    while (start <= end) {
        int mid = start + (end - start) / 2; // Find the middle distance

        // Check if cows can be placed with at least 'mid' distance apart
        if (isValid(arr, n, c, mid)) {
            minLargestDist = mid; // Update the answer with the valid distance
            start = mid + 1; // Try for a larger minimum distance
        } else {
            end = mid - 1; // Reduce search space if not possible
        }
    }

    return minLargestDist; // Return the maximum possible minimum distance
}

int main() {
    int n = 5; // Number of stalls
    int c = 3; // Number of cows
    vector<int> arr = {1, 2, 8, 4, 9}; // Stall positions (unsorted)

    int result = minLargestDistance(arr, n, c);
    
    cout << "Largest Minimum Distance: " << result << endl; 
    
    return 0;
}