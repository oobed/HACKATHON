//
// Created by slopp on 2/4/2023.
//

#ifndef UNTITLED1_CONNECTFOUR_H
#define UNTITLED1_CONNECTFOUR_H
#include <vector>

using namespace std;
class ConnectFour {
public:
    ConnectFour();
    vector<vector<int>> board;
    void displayBoard();
    bool makeMove(int column, int player);
    bool checkForWin(int row, int col);


    };


#endif //UNTITLED1_CONNECTFOUR_H
