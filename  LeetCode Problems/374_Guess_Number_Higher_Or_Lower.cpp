// LeetCode Problem (374) : Guess Higher or Lower
// Time Complexity : O(logn)
// Difficulty : Easy

// DESCRIPTION :

// We are playing the Guess Game. The game is as follows:

// I pick a number from 1 to n. You have to guess which number I picked.

// Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

// You call a pre-defined API int guess(int num), which returns three possible results:

// -1: Your guess is higher than the number I picked (i.e. num > pick).
// 1: Your guess is lower than the number I picked (i.e. num < pick).
// 0: your guess is equal to the number I picked (i.e. num == pick).

// Return the number that I picked.


// Example 1:

// Input: n = 10, pick = 6
// Output: 6
// Example 2:

// Input: n = 1, pick = 1
// Output: 1
// Example 3:

// Input: n = 2, pick = 1
// Output: 1
 

// Constraints:

// 1 <= n <= 231 - 1
// 1 <= pick <= n



#include <iostream>
using namespace std;

// Mock `guess` function (since it's not available in VS Code)
int pick = 6; // Example picked number

int guess(int num) {
    if (num > pick) return -1;
    if (num < pick) return 1;
    return 0;
}

int guessNumber(int n) {
    int left = 1;
    int right = n;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int result = guess(mid);

        if (result == 0) {
            return mid;  // Found the correct number
        } else if (result == -1) {
            right = mid - 1;  // Move left
        } else {
            left = mid + 1;  // Move right
        }
    }

    return -1;  // Not found (shouldn't happen)
}

int main() {
    int n = 10; // Example range (1 to 10)
    cout << "Picked number is: " << guessNumber(n) << endl;
    return 0;
}