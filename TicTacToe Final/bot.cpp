#include "bot.h"
#include "logic.h"
#include "ui.h"
#include <windows.h>

int difficulty = 0;

void bot_handler() {
    if (!isXturn && winner == 0) {
        switch (difficulty) {
        case 0:
            int pos = easy_thinker();
            break;
        case 1:
            int pos = easy_thinker();
            break;
        default:
            int pos = easy_thinker();
            break;
        }
        int x = pos % 3;
        int y = pos / 3;
        BotAction(pos, x, y);
    }
}

void BotAction(int pos, int row, int col) {
    const wchar_t* turnCh = L"O";
    SetWindowTextW(hTurn, L"Turn : O");
    block[row][col] = 2;
    isXturn = !isXturn;
    ChangeTurn();
    switch (pos) {
    case 0:
        SetWindowTextW(hButton1, turnCh);
        break;
    case 1:
        SetWindowTextW(hButton2, turnCh);
        break;
    case 2:
        SetWindowTextW(hButton3, turnCh);
        break;
    case 3:
        SetWindowTextW(hButton4, turnCh);
        break;
    case 4:
        SetWindowTextW(hButton5, turnCh);
        break;
    case 5:
        SetWindowTextW(hButton6, turnCh);
        break;
    case 6:
        SetWindowTextW(hButton7, turnCh);
        break;
    case 7:
        SetWindowTextW(hButton8, turnCh);
        break;
    case 8:
        SetWindowTextW(hButton9, turnCh);
        break;
    default:
        SetWindowTextW(hTurn, L"Error Bot Action");
        break;
    }
}

int easy_thinker() {
    int pos;
    do {
        pos = rand() % 9;
    } while (block[pos % 3][pos / 3] != 0); // تا زمانی که خانه خالی پیدا شود
    return pos;
}


int medium_thinker() {
    bool freeBlock = false;
    int pos = -1;
    //   check Rows
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            if (block[x][y] == 0) {
                if (freeBlock) {
                    freeBlock = false;
                    pos = -1;
                    break;
                }
                else {
                    freeBlock = true;
                    pos = x + y * 3;
                }
            }
            return pos;
        }
    }

    int pos;
    bool oneClearBlock = false;
    //   check Rows if he can win
    for (int x = 0; x < 3; x++) {
        if (block[x][0] == 0) {
            if (!oneClearBlock) {
                oneClearBlock = true;
                pos = x;
            } else {
                oneClearBlock = false;
                pos = -1;
            }
        }
        if (pos )
    }

    //	check Columns if he can win
    for (int x = 0; x < 3; x++)
        if (block[x][0] == block[x][1] &&
            block[x][1] == block[x][2] &&
            block[x][0] != 0)
            return block[x][0];
    //	check Qatars if he can win
    if (block[0][0] == block[1][1] &&
        block[1][1] == block[2][2] &&
        block[0][0] != 0)
        return block[0][0];
    if (block[2][0] == block[1][1] &&
        block[1][1] == block[0][2] &&
        block[1][1] != 0)
        return block[1][1];
}

