#include <iostream>
using namespace std;

char board[3][3];

void initializeBoard() {
    char num = '1';

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = num++;
        }
    }
}

void displayBoard() {
    cout << "\n";

    for(int i = 0; i < 3; i++) {
        cout << " ";

        for(int j = 0; j < 3; j++) {
            cout << board[i][j];

            if(j < 2)
                cout << " | ";
        }

        cout << endl;

        if(i < 2)
            cout << "---|---|---" << endl;
    }

    cout << "\n";
}

bool makeMove(int choice, char player) {

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if(choice < 1 || choice > 9)
        return false;

    if(board[row][col] == 'X' || board[row][col] == 'O')
        return false;

    board[row][col] = player;

    return true;
}

bool checkWin(char player) {

    for(int i = 0; i < 3; i++) {

        if(board[i][0] == player &&
           board[i][1] == player &&
           board[i][2] == player)
            return true;

        if(board[0][i] == player &&
           board[1][i] == player &&
           board[2][i] == player)
            return true;
    }

    if(board[0][0] == player &&
       board[1][1] == player &&
       board[2][2] == player)
        return true;

    if(board[0][2] == player &&
       board[1][1] == player &&
       board[2][0] == player)
        return true;

    return false;
}

bool checkDraw() {

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {

            if(board[i][j] != 'X' &&
               board[i][j] != 'O')
                return false;
        }
    }

    return true;
}

int main() {

    char playAgain;

    do {

        initializeBoard();

        char player = 'X';
        int move;

        while(true) {

            displayBoard();

            cout << "Player "
                 << player
                 << " Enter position (1-9): ";

            cin >> move;

            if(!makeMove(move, player)) {

                cout << "Invalid move! Try again.\n";

                continue;
            }

            if(checkWin(player)) {

                displayBoard();

                cout << "Player "
                     << player
                     << " Wins!\n";

                break;
            }

            if(checkDraw()) {

                displayBoard();

                cout << "Game Draw!\n";

                break;
            }

            player = (player == 'X')
                    ? 'O'
                    : 'X';
        }

        cout << "\nPlay Again? (Y/N): ";
        cin >> playAgain;

    } while(playAgain == 'Y' || playAgain == 'y');

    cout << "Thanks for playing!\n";

    return 0;
}