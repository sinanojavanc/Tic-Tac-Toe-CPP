#include <windows.h>
#include "ui.h"
#include "bot.h"


HMENU hMenu;

HWND hButton1, hButton2, hButton3;
HWND hButton4, hButton5, hButton6;
HWND hButton7, hButton8, hButton9;
HWND hTurn;

void AddMenus(HWND hWnd) {
	hMenu = CreateMenu();
	HMENU hDifficultyMenu = CreatePopupMenu();

	AppendMenu(hMenu, MF_STRING, RESTART, L"Play Again");

	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hDifficultyMenu, L"Change Difficulty");

	AppendMenu(hDifficultyMenu, MF_STRING, EASY_D, L"Easy");
	AppendMenu(hDifficultyMenu, MF_STRING, MEDIUM_D, L"Medium");
	AppendMenu(hDifficultyMenu, MF_STRING, HARD_D, L"Hard");
	AppendMenu(hDifficultyMenu, MF_STRING, VETERAN_D, L"Veteran");
	AppendMenu(hDifficultyMenu, MF_SEPARATOR, 0, NULL);
	AppendMenu(hDifficultyMenu, MF_STRING, AI_D, L"AI");

	SetMenu(hWnd, hMenu);
}

void AddControls(HWND hWnd) 
{
	hTurn = CreateWindowW(L"Edit", L"Turn : X",
		WS_VISIBLE | WS_CHILD | SS_CENTER,
		17, 17, 300, 25,
		hWnd, NULL, NULL, NULL);

	hButton1 = CreateWindowW(L"Button", L"",
		WS_VISIBLE | WS_CHILD,
		10, 50, 100, 100,
		hWnd, (HMENU)BLOCK1, NULL, NULL);

	hButton2 = CreateWindowW(L"Button", L"",
		WS_VISIBLE | WS_CHILD,
		120, 50, 100, 100,
		hWnd, (HMENU)BLOCK2, NULL, NULL);

	hButton3 = CreateWindowW(L"Button", L"",
		WS_VISIBLE | WS_CHILD,
		230, 50, 100, 100,
		hWnd, (HMENU)BLOCK3, NULL, NULL);

	hButton4 = CreateWindowW(L"Button", L"",
		WS_VISIBLE | WS_CHILD,
		10, 160, 100, 100,
		hWnd, (HMENU)BLOCK4, NULL, NULL);

	hButton5 = CreateWindowW(L"Button", L"",
		WS_VISIBLE | WS_CHILD,
		120, 160, 100, 100,
		hWnd, (HMENU)BLOCK5, NULL, NULL);

	hButton6 = CreateWindowW(L"Button", L"",
		WS_VISIBLE | WS_CHILD,
		230, 160, 100, 100,
		hWnd, (HMENU)BLOCK6, NULL, NULL);

	hButton7 = CreateWindowW(L"Button", L"",
		WS_VISIBLE | WS_CHILD,
		10, 270, 100, 100,
		hWnd, (HMENU)BLOCK7, NULL, NULL);

	hButton8 = CreateWindowW(L"Button", L"",
		WS_VISIBLE | WS_CHILD,
		120, 270, 100, 100,
		hWnd, (HMENU)BLOCK8, NULL, NULL);

	hButton9 = CreateWindowW(L"Button", L"",
		WS_VISIBLE | WS_CHILD,
		230, 270, 100, 100,
		hWnd, (HMENU)BLOCK9, NULL, NULL);
}
