#include "logic.h"
#include "ui.h"
#include <windows.h>
#include <thread>
#include <ctime>

int block[3][3] = { 0 }; // 0: empty, 1: X, 2: O
bool isXturn = true;
int winner = 0;

void bot_handler() {
    while (true) {
        if (!isXturn) {
            static bool seeded = false;
            if (!seeded) {
                srand(time(0));
                seeded = true;
            }

            int pos;
            do {
                pos = std::rand() % 9; // generate random number 0 - 9
                int x = pos % 3;
                int y = pos / 3;
                if (block[x][y] == 0) {
                    
                }
            } while (true);
        }
    }

}

void BlockChanger(HWND hBtn, HWND hText, int row, int col, bool& xTurn) {
    if (block[row][col] == 0   &&   winner == 0) {
        if (xTurn) {
            const wchar_t* turnCh = xTurn ? L"X" : L"O";
            SetWindowTextW(hBtn, turnCh);

            block[row][col] = xTurn ? 1 : 2;

            xTurn = !xTurn;

            winner = CheckWinner();
            if (winner != 0) {
                if (winner == 1)
                    SetWindowTextW(hText, L".!The X player Wins!.");
                else
                    SetWindowTextW(hText, L".!The O player Wins!.");
            }
            else if (CheckDraw()) {
                SetWindowTextW(hText, L".!The game is Drawn!.");
            }
            else {
                SetWindowTextW(hText, xTurn ? L"Turn : X" : L"Turn : O");
            }
        } else {
            SetWindowTextW(hText, L"is Not your turn wait a second..");
        }

        
    }
}

void ResetBoard() {
    for (int x = 0 ; x < 3 ; x++) 
        for (int y = 0 ; y < 3 ; y++) 
            block[x][y] = 0;

    SetWindowText(hButton1, L"");
    SetWindowText(hButton2, L"");
    SetWindowText(hButton3, L"");
    SetWindowText(hButton4, L"");
    SetWindowText(hButton5, L"");
    SetWindowText(hButton6, L"");
    SetWindowText(hButton7, L"");
    SetWindowText(hButton8, L"");
    SetWindowText(hButton9, L"");

    SetWindowText(hTurn, L"Turn : X");
    isXturn = true; 
    winner = 0;
}

bool CheckDraw() {
    for (int x = 0; x < 3; x++) 
        for (int y = 0; y < 3; y++) 
            if (block[x][y] == 0)
                return 0;
    return 1;
}

int CheckWinner() {
    //   check Rows
    for (int y = 0; y < 3; y++)
        if (block[0][y] == block[1][y] &&
            block[1][y] == block[2][y] &&
            block[0][y] != 0)
            return block[0][y];

    //	check Columns
    for (int x = 0; x < 3; x++)
        if (block[x][0] == block[x][1] &&
            block[x][1] == block[x][2] &&
            block[x][0] != 0)
            return block[x][0];

    //	check Qatars
    if (block[0][0] == block[1][1] &&
        block[1][1] == block[2][2] &&
        block[0][0] != 0)
        return block[0][0];
    if (block[2][0] == block[1][1] &&
        block[1][1] == block[0][2] &&
        block[1][1] != 0)
        return block[1][1];

    return 0;
}