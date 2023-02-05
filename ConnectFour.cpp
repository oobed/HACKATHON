//
// Created by slopp on 2/4/2023.
//
const int ROWS = 6;
const int COLUMNS = 7;
#include "ConnectFour.h"
#include <vector>
#include <iostream>
ConnectFour::ConnectFour() {
        // Initialize the board to be empty
        board = vector<vector<int>>(ROWS, vector<int>(COLUMNS, 0));
    }
void ConnectFour::displayBoard() {
    // Print out the current state of the board
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLUMNS; col++) {
            cout << board[row][col] << " ";
        }
        cout << endl;
    }
}

bool ConnectFour::makeMove(int column, int player) {
    // Check if the column is full
    if (board[0][column] != 0) {
        return false;
    }

    // Find the next available row in the given column
    int row = ROWS - 1;
    while (row >= 0 && board[row][column] != 0) {
        row--;
    }

    // Place the piece for the current player
    board[row][column] = player;
    return true;
}

bool ConnectFour::checkForWin(int row, int col) {
    // Check the horizontal direction
    int count = 0;
    for (int i = col; i < COLUMNS && board[row][i] == board[row][col]; i++) {
        count++;
    }
    for (int i = col - 1; i >= 0 && board[row][i] == board[row][col]; i--) {
        count++;
    }
    if (count >= 4) {
        return true;
    }

    // Check the vertical direction
    count = 0;
    for (int i = row; i < ROWS && board[i][col] == board[row][col]; i++) {
        count++;
    }
    if (count >= 4) {
        return true;
    }

    // Check the diagonal direction (top-left to bottom-right)
    count = 0;
    for (int i = row, j = col; i < ROWS && j < COLUMNS && board[i][j] == board[row][col]; i++, j++) {
        count++;
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0 && board[i][j] == board[row][col]; i--, j--) {
        count++;
    }
    if (count >= 4) {
        return true;
    }

    // Check the diagonal direction (bottom-left to top-right)
    count = 0;
    for (int i = row, j = col; i >= 0 && j < COLUMNS && board[i][j] == board[row][col]; i--, j++) {
        count++;
    }
    for (int i = row + 1, j = col - 1; i < ROWS && j >= 0 && board[i][j] == board[row][col]; i++, j--) {
        count++;
    }
    if (count >= 4) {
        return true;
    }

    return false;
}
