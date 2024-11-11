#include <iostream>
using namespace std;

#define N 4

// Function to print the board
void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    // Check the column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    // Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Check upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

// Backtracking function to solve the N Queen problem
bool solveNQueens(int board[N][N], int row) {
    if (row >= N)
        return true; // All queens are placed

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1; // Place queen

            if (solveNQueens(board, row + 1))
                return true;

            board[row][col] = 0; // Backtrack
        }
    }

    return false; // If no place is found
}

int main() {
    int board[N][N] = {0}; // Initialize the board with 0s (no queens placed)

    if (solveNQueens(board, 0)) {
        printSolution(board); // If solution exists, print the board
    } else {
        cout << "Solution does not exist." << endl;
    }

    return 0;
}
