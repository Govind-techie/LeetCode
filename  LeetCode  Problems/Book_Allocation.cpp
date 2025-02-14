// Problem : Book Alocation.
// Difficulty : Hard.
// Time Complexity : O(logn)
// Algorithm Used : Binary Search


// DESCRIPTION : Book Allocation Problem

// There are N books, each ith book has A[i] number of pages.

// You have to allocate books to M number of students so that the maximum no. of pages alloted to a student is minimum

// • Each book should be allocated to a student.
// • Each student must be allocated at least one book.
// • The allocation of books should be in contiguous order.

// Calculate and return the minimum possible number.

// Return -1 if a valid allotment is not possible.


// Example 1
// Input: N = 4, A = [12, 34, 67, 90], M = 2
// Output: 113
// Explanation: 
// The optimal way to allocate books is:
//   - Student 1: [12, 34, 67] → Total pages = 113
//   - Student 2: [90] → Total pages = 90
// Among all possible allocations, the maximum pages assigned to a student is minimized to 113.

// Edge Case:
// Input: N = 3, A = [10, 20, 30], M = 4
// Output: -1
// Explanation: Allocation is not possible since M > N.


// Note : Array of pages is not Sorted.

#include <iostream>
#include <vector>
using namespace std;

// Function to check if a given max pages limit (mid) is a valid allocation
bool isValid(vector<int> arr, int n, int m, int mid) {
    int student = 1; // Start with the first student
    int pages = 0;   // Track the number of pages allocated to the current student

    for (int i = 0; i < n; i++) { // Books must be allocated in contiguous order

        // Edge Case: If any single book has more pages than mid, allocation is impossible
        if (arr[i] > mid) return false;

        // If adding this book doesn't exceed max allowed pages, assign it to the current student
        if (pages + arr[i] <= mid) {
            pages += arr[i];
        } else {
            // Allocate this book to the next student
            student++;
            pages = arr[i]; // Start fresh allocation for the new student

            // If students required exceed available students (m), allocation is invalid
            if (student > m) return false;
        }
    }

    return true; // Allocation is valid within given constraints
}

// Function to find the minimum of the maximum pages allocated using Binary Search
int minMaxPages(vector<int> arr, int n, int m) {

    if (m > n) return -1; // Edge Case;

    // Edge Case: If students are more than books, allocation is not possible
    if (m > n) return -1;

    int start = 0;
    int end = 0;
    int ans = -1;

    // Find the sum of all pages (upper bound for binary search)
    for (int num : arr) {
        end += num;
    }

    // Apply Binary Search on the possible max pages range
    while (start <= end) {
        int mid = start + (end - start) / 2; // Mid represents a potential max page allocation

        // Check if mid is a valid max page allocation
        if (isValid(arr, n, m, mid)) {
            ans = mid;   // Store the potential answer
            end = mid - 1; // Try to find a smaller valid max allocation
        } else {
            start = mid + 1; // Increase mid to allow larger allocations
        }
    }

    return ans;
}


int main() {
    vector<int> arr = {12, 34, 67, 90}; // Number of pages in each book
    int n = arr.size(); // Number of books
    int m = 2; // Number of students

    int result = minMaxPages(arr, n, m); // Find the minimum max pages allocation

    cout << "Minimum possible maximum pages allocated: " << result << endl;
    
    return 0;
}