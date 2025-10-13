#pragma once

#define BLOCK1 101
#define BLOCK2 102
#define BLOCK3 103
#define BLOCK4 104
#define BLOCK5 105
#define BLOCK6 106
#define BLOCK7 107
#define BLOCK8 108
#define BLOCK9 109

#define RESTART 201
#define EASY_D 301
#define MEDIUM_D 302
#define HARD_D 303
#define VETERAN_D 304
#define AI_D 305


void AddControls(HWND hWnd);
void AddMenus(HWND hWnd);

extern HMENU hMenu;
extern HWND hButton1, hButton2, hButton3;
extern HWND hButton4, hButton5, hButton6;
extern HWND hButton7, hButton8, hButton9;
extern HWND hTurn;