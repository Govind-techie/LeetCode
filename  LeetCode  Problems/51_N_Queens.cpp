/*
Leetcode Problem 51: N-Queens
Difficulty: Hard
Algorithm: Backtracking
Time Complexity: O(N!)
Space Complexity: O(N)

Description:

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

. Q . .    → Row 0
. . . Q    → Row 1
Q . . .    → Row 2
. . Q .    → Row 3


. . Q .    → Row 0
Q . . .    → Row 1
. . . Q    → Row 2
. Q . .    → Row 3


Example 1:


Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
 

Constraints:

1 <= n <= 9
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to check if placing a queen at (row, col) is safe
bool isSafe(const vector<string>& board, int row, int col) {
    int n = board.size();
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 'Q') return false; // Horizontal check
    }

    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return false; // Vertical check
    }

    for (int r = row, c = col; r >= 0 && c >= 0; r--, c--) {
        if (board[r][c] == 'Q') return false; // Left diagonal check
    }

    for (int r = row, c = col; r >= 0 && c < n; r--, c++) {
        if (board[r][c] == 'Q') return false; // Right diagonal check
    }

    return true; // Safe position if all checks pass
}

// Function to solve N-Queens problem using backtracking
void NQueens(vector<string>& board, int rows, vector<vector<string>>& result) {
    int n = board.size();
    if (rows == n) {
        result.push_back(board); // Found a valid solution
        return;
    }

    for (int j = 0; j < n; j++) {
        if (isSafe(board, rows, j)) { // Check if it's safe to place the queen
            board[rows][j] = 'Q'; // Place the queen
            NQueens(board, rows + 1, result); // Recursively place queens on the next row
            board[rows][j] = '.'; // Backtrack and remove the queen
        }
    }
}

// Function to solve the N-Queens problem and return all solutions
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result; // Store the solutions
    vector<string> board(n, string(n, '.')); // Initialize the board with '.' (empty cells)
    NQueens(board, 0, result); // Start solving from row 0
    return result; // Return the list of solutions
}

// Main function for test cases
int main() {
    int n = 4; // Example test case for 4x4 board
    vector<vector<string>> solutions = solveNQueens(n); // Get all solutions for n=4

    cout << "Test case: n = " << n << endl;

    // Output all the solutions
    if (solutions.empty()) {
        cout << "No solution found!" << endl;
    } else {
        cout << "Found " << solutions.size() << " solution(s):" << endl;
        for (const auto& solution : solutions) {
            for (const auto& row : solution) {
                cout << row << endl;
            }
            cout << "--------------------" << endl; // Separator between solutions
        }
    }

    // Additional test case for n = 8 (Optional)
    n = 8;
    solutions = solveNQueens(n); // Get all solutions for n=8
    cout << "Test case: n = " << n << endl;

    if (solutions.empty()) {
        cout << "No solution found!" << endl;
    } else {
        cout << "Found " << solutions.size() << " solution(s):" << endl;
        for (const auto& solution : solutions) {
            for (const auto& row : solution) {
                cout << row << endl;
            }
            cout << "--------------------" << endl; // Separator between solutions
        }
    }

    return 0;
}