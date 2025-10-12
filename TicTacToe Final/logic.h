#pragma once
#include <windows.h>

extern int block[3][3];
extern bool isXturn;
extern int winner;
void BlockChanger(HWND hBtn, HWND hText, int row, int col, bool& xTurn);

void ResetBoard();
bool CheckDraw();
int CheckWinner();