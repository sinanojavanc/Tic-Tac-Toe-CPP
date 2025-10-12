#include <windows.h>
#include "ui.h"
#include "logic.h"
using namespace std;

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
	WNDCLASSW wc = { 0 };
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hInstance = hInst;
	wc.lpszClassName = L"myWindowClass";
	wc.lpfnWndProc = WindowProcedure;
	
	if (!RegisterClassW(&wc))
		return -1;

	CreateWindowW(L"myWindowClass", L"tic tac toe",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		500, 400, 360, 430,
		NULL, NULL, hInst, NULL);

	MSG msg = { 0 };
	while (GetMessage(&msg, NULL, NULL, NULL)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg)
	{
	case WM_CREATE:
		AddMenus(hWnd);
		AddControls(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_COMMAND:
		switch (wp)
		{
		case RESTART:
			ResetBoard();
			break;
		case BLOCK1:
			BlockChanger(hButton1, hTurn, 0, 0, isXturn);
			break;
		case BLOCK2:
			BlockChanger(hButton2, hTurn, 1, 0, isXturn);
			break;
		case BLOCK3:
			BlockChanger(hButton3, hTurn, 2, 0, isXturn);
			break;
		case BLOCK4:
			BlockChanger(hButton4, hTurn, 0, 1, isXturn);
			break;
		case BLOCK5:
			BlockChanger(hButton5, hTurn, 1, 1, isXturn);
			break;
		case BLOCK6:
			BlockChanger(hButton6, hTurn, 2, 1, isXturn);
			break;
		case BLOCK7:
			BlockChanger(hButton7, hTurn, 0, 2, isXturn);
			break;
		case BLOCK8:
			BlockChanger(hButton8, hTurn, 1, 2, isXturn);
			break;
		case BLOCK9:
			BlockChanger(hButton9, hTurn, 2, 2, isXturn);
			break;
		default:
			break;
		}
		break;
	default:
		return DefWindowProc(hWnd, msg, wp, lp);
	}
	return 0;
}
