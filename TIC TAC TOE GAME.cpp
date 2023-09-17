#include <iostream>
#include <vector>

using namespace std;

void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " | ";
        }
        cout << "\n";
        cout << "---------\n";
    }
}

bool checkWin(const vector<vector<char>>& board, char player) {
    for (const auto& row : board) {
        if (row[0] == player && row[1] == player && row[2] == player)
            return true;
    }

    for (int col = 0; col < 3; ++col) {
        if (board[0][col] == player && board[1][col] == player && board[2][col] == player)
            return true;
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ')
                return false;
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char players[] = {'X', 'O'};
    int currentPlayerIdx = 0;
    bool gameOver = false;

    while (!gameOver) {
        char currentPlayer = players[currentPlayerIdx];

        printBoard(board);
        int row, col;
        cout << "Player " << currentPlayer << ", enter row (0-2): ";
        cin >> row;
        cout << "Player " << currentPlayer << ", enter column (0-2): ";
        cin >> col;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            if (checkWin(board, currentPlayer)) {
                printBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameOver = true;
            } else if (checkDraw(board)) {
                printBoard(board);
                cout << "It's a draw!" << endl;
                gameOver = true;
            } else {
                currentPlayerIdx = (currentPlayerIdx + 1) % 2;
            }
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }

    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;

    if (playAgain == 'y' || playAgain == 'Y') {
        main();
    } else {
        cout << "Thanks for playing!" << endl;
    }

    return 0;
}
