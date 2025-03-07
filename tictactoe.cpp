#include <iostream>
using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char currentMarker;
int currentPlayer;

void drawBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;
    
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    } else {
        return false;
    }
}

int checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return currentPlayer;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return currentPlayer;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return currentPlayer;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return currentPlayer;
    return 0;
}

void swapPlayer() {
    if (currentMarker == 'X') {
        currentMarker = 'O';
        currentPlayer = 2;
    } else {
        currentMarker = 'X';
        currentPlayer = 1;
    }
}

void startGame() {
    cout << "Player 1, choose your marker (X or O): ";
    cin >> currentMarker;
    currentPlayer = 1;
    
    drawBoard();
    
    for (int i = 0; i < 9; i++) {
        int slot;
        cout << "Player " << currentPlayer << "'s turn. Enter position: ";
        cin >> slot;
        
        if (slot < 1 || slot > 9 || !placeMarker(slot)) {
            cout << "Invalid move! Try again.\n";
            i--;
            continue;
        }
        
        drawBoard();
        
        if (checkWin() != 0) {
            cout << "Player " << currentPlayer << " wins!\n";
            return;
        }
        
        swapPlayer();
    }
    
    cout << "It's a draw!\n";
}

int main() {
    char playAgain;
    do {
        startGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        
        if (playAgain == 'y' || playAgain == 'Y') {
            board[0][0] = '1'; board[0][1] = '2'; board[0][2] = '3';
            board[1][0] = '4'; board[1][1] = '5'; board[1][2] = '6';
            board[2][0] = '7'; board[2][1] = '8'; board[2][2] = '9';
        }
        
    } while (playAgain == 'y' || playAgain == 'Y');
    
    return 0;
}
