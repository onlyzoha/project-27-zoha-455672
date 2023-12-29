#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int BOARD_SIZE = 9;
const int MIN_MOVE = 1;
const int MAX_MOVE = 9;
void displayBoard(char board[]) {
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "-----------" << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
}
bool checkWin(char board[], char player) {
    for (int i = 0; i < 3; i++) {
        if ((board[i] == player && board[i + 3] == player && board[i + 6] == player) ||
            (board[i * 3] == player && board[i * 3 + 1] == player && board[i * 3 + 2] == player))
            return true;
    }
    if ((board[0] == player && board[4] == player && board[8] == player) ||
        (board[2] == player && board[4] == player && board[6] == player))
        return true;
    return false;
}
bool checkDraw(char board[]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i] == ' ')
            return false; 
    }
    return true; 
}
void computerMove(char board[]) {
    int move;
    do {
        move = rand() % BOARD_SIZE + 1; 
    } while (board[move - 1] != ' '); 
    cout << "Computer chooses position " << move << endl;
    board[move - 1] = 'O';
}
int main() {
    char board[BOARD_SIZE] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
    char currentPlayer;
    int gameMode;
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    cout << "Select Game Mode:" << endl;
    cout << "1. Two Players" << endl;
    cout << "2. One Player vs Computer" << endl;
    cout << "Enter 1 or 2: ";
    cin >> gameMode;
    string player1Name, player2Name;
    if (gameMode == 1) {
        currentPlayer = 'X'; 
        cout << "Enter Player 1's name: ";
        cin >> player1Name;
        cout << "Enter Player 2's name: ";
        cin >> player2Name;
    } else if (gameMode == 2) {
        currentPlayer = 'X'; 
        cout << "Enter your name: ";
        cin >> player1Name;
        player2Name = "Computer";
    } else {
        cout << "Invalid choice. Exiting the game." << endl;
        return 0;
    }
    do {
        displayBoard(board);
        if (currentPlayer == 'X') {
            int move;
            cout << player1Name << ", enter your move (" << MIN_MOVE << "-" << MAX_MOVE << "): ";
            cin >> move;
            if (move < MIN_MOVE || move > MAX_MOVE || board[move - 1] != ' ') {
                cout << "Invalid move! Please choose an empty position (" << MIN_MOVE << "-" << MAX_MOVE << ")." << endl;
                continue;
            }
            board[move - 1] = 'X';
        } else {
            if (gameMode == 1) {
                int move;
                cout << player2Name << ", enter your move (" << MIN_MOVE << "-" << MAX_MOVE << "): ";
                cin >> move;
                if (move < MIN_MOVE || move > MAX_MOVE || board[move - 1] != ' ') {
                    cout << "Invalid move! Please choose an empty position (" << MIN_MOVE << "-" << MAX_MOVE << ")." << endl;
                    continue;
                }
                board[move - 1] = 'O';
            } else {
                computerMove(board);
            }
        }
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            if (currentPlayer == 'X')
                cout << player1Name << " wins!" << endl;
            else
                cout << player2Name << " wins!" << endl;
            break;
        }
        if (checkDraw(board)) {
            displayBoard(board);
            cout << "It's a draw!" << endl;
            break;
        }
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    } while (true);
    return 0;
}   
