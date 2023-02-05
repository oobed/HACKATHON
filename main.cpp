#include <iostream>
#include <vector>

const int ROWS = 6;
const int COLUMNS = 7;

// Represent the state of the game
class Game {
public:
    std::vector<std::vector<int>> board;
    Game() {
        board = std::vector<std::vector<int>>(ROWS, std::vector<int>(COLUMNS, 0));
    }

    void displayBoard() {
        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLUMNS; col++) {
                std::cout << board[row][col] << " ";
            }
            std::cout << std::endl;
        }
    }

    bool makeMove(int column, int player) {
        if (board[0][column] != 0) {
            return false;
        }
        int row = ROWS - 1;
        while (row >= 0 && board[row][column] != 0) {
            row--;
        }

        board[row][column] = player;
        return true;
    }

    bool checkWin(int row, int col) {
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

        count = 0;
        for (int i = row; i < ROWS && board[i][col] == board[row][col]; i++) {
            count++;
        }
        if (count >= 4) {
            return true;
        }

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
};

int main() {
    Game game;
    int currentPlayer = 1;

    while (true) {
        std::cout << "Player " << currentPlayer << "'s turn:" << std::endl;
        game.displayBoard();
        int column;
        std::cout << "Enter the column number to drop your piece (1-7): ";
        std::cin >> column;
        column--;

        if (!game.makeMove(column, currentPlayer)) {
            std::cout << "This column is full. Try again." << std::endl;
            continue;
        }

        int row = 0;
        for (int i = 0; i < ROWS; i++) {
            if (game.board[i][column] != 0) {
                row = i;
                break;
            }
        }

        if (game.checkWin(row, column)) {
            std::cout << "Player " << currentPlayer << " wins!" << std::endl;
            break;
        }

        currentPlayer = currentPlayer == 1 ? 2 : 1;
    }

    return 0;
}



