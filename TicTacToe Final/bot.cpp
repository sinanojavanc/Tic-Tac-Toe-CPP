#include "bot.h"
#include "logic.h"
#include "ui.h"
#include <windows.h>

int difficulty = 0;

void bot_handler() {
    if (!isXturn && winner == 0) {
        int pos;
        switch (difficulty) {
        case 0:
            pos = easy_thinker();
            break;
        case 1:
            pos = medium_thinker();
            if (pos == -1)
                pos = easy_thinker();
            break;
        case 2:
            pos = medium_thinker();
            if (pos == -1)
                pos = hard_thinker();
            break;
        default:
            pos = 8;// for test
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
    int emptyCount = 0;
    int playerCount = 0;
    int botCount = 0;

    int winable = -1;
    int blockable = -1;
    int pos = -1;
    //   check Rows
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            if (block[x][y] == 1)
                playerCount++;

            if (block[x][y] == 2)
                botCount++;

            if (block[x][y] == 0) {
                emptyCount++;
                pos = x + y * 3;
            }
        }
        if (pos != -1) {
            if (botCount == 2 && emptyCount == 1)
                return pos;
            
            if (playerCount == 2 && emptyCount == 1)
                blockable = pos;
        }
        pos = -1;
        emptyCount = 0;
        playerCount = 0;
        botCount = 0;
    }
    pos = -1;
    emptyCount = 0;
    playerCount = 0;
    botCount = 0;

    //   check cols
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (block[x][y] == 1)
                playerCount++;

            if (block[x][y] == 2)
                botCount++;

            if (block[x][y] == 0) {
                emptyCount++;
                pos = x + y * 3;
            }
        }
        if (pos != -1) {
            if (botCount == 2 && emptyCount == 1) 
                return pos;
            
            if (playerCount == 2 && emptyCount == 1)
                blockable = pos;
        }
        pos = -1;
        emptyCount = 0;
        playerCount = 0;
        botCount = 0;
    }

    pos = -1;
    emptyCount = 0;
    playerCount = 0;
    botCount = 0;
    //	check Qatars
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (x == y) {
                if (block[x][y] == 1)
                    playerCount++;

                if (block[x][y] == 2)
                    botCount++;

                if (block[x][y] == 0) {
                    emptyCount++;
                    pos = x + y * 3;
                }
            }
        }
    }
    if (pos != -1) {
        if (botCount == 2 && emptyCount == 1)
            return pos;
        
        if (playerCount == 2 && emptyCount == 1)
            blockable = pos;
    }
    pos = -1;
    emptyCount = 0;
    playerCount = 0;
    botCount = 0;
    for (int x = 2; x >= 0; x--) {
        for (int y = 0; y < 3; y++) {
            if (x + y == 2) {
                if (block[x][y] == 1)
                    playerCount++;

                if (block[x][y] == 2)
                    botCount++;

                if (block[x][y] == 0) {
                    emptyCount++;
                    pos = x + y * 3;
                }
            }
        }
    }
    if (pos != -1) {
        if (botCount == 2 && emptyCount == 1)
            return pos;
     
        if (playerCount == 2 && emptyCount == 1)
            blockable = pos;
    }
    pos = -1;
    emptyCount = 0;
    playerCount = 0;
    botCount = 0;
    
    if (blockable >= 0)
        return blockable;

    pos = -1;
    emptyCount = 0;
    playerCount = 0;
    botCount = 0;
    // else random target?
    return -1;
    
}

int hard_thinker() {
    // اولویت بندی کردن خونه ها برای ردیف کردن دوتا
    // اگه نبود اولویت بندی کردن برای تک خونه گرفتن
    // تک خونه اول گوشه بعد وسط
    return 7;// for test
}