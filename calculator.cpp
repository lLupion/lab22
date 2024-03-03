#include<windows.h>
#include <stdio.h>
#define Plus_button 1
#define Minus_button 2
#define Multiply_button 3
#define Divide_button 4

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
wchar_t num1[30], num2[30], ans[30];
float result;

void AddControls(HWND);

HWND hNum1, hNum2, hAsn;
HMENU hMenu;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
	WNDCLASSW wc = { 0 };
	wc.hbrBackground = CreateSolidBrush(RGB(255, 100, 100));
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hInstance = hInst;
	wc.lpszClassName = L"myWindowClass";
	wc.lpfnWndProc = WindowProcedure;

	if (!RegisterClassW(&wc))
		return -1;

	HWND hWnd = CreateWindowW(L"myWindowClass", L"My Calculator",WS_OVERLAPPEDWINDOW | WS_VISIBLE, 550, 375, 250, 200, NULL, NULL, NULL,NULL);


	MSG msg = { 0 };

	while (GetMessage(&msg, NULL, NULL, NULL)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg) {
	case WM_COMMAND:
		switch (LOWORD(wp)) {
		case Plus_button:
			GetWindowText(hNum1, num1, sizeof(num1) / sizeof(num1[0]));
			GetWindowText(hNum2, num2, sizeof(num2) / sizeof(num2[0]));
			result = _wtof(num1) + _wtof(num2);
			swprintf(ans, 30, L"%f", result);
			SetWindowTextW(hAsn, ans);
			MessageBox(hWnd, ans, L"Result", MB_OK);
			break;
		case Minus_button:
			GetWindowText(hNum1, num1, sizeof(num1) / sizeof(num1[0]));
			GetWindowText(hNum2, num2, sizeof(num2) / sizeof(num2[0]));
			result = _wtof(num1) - _wtof(num2);
			swprintf(ans, 30, L"%f", result);
			SetWindowTextW(hAsn, ans);
			MessageBox(hWnd, ans, L"Result", MB_OK);
			break;
		case Multiply_button:
			GetWindowText(hNum1, num1, sizeof(num1) / sizeof(num1[0]));
			GetWindowText(hNum2, num2, sizeof(num2) / sizeof(num2[0]));
			result = _wtof(num1) * _wtof(num2);
			swprintf(ans, 30, L"%f", result);
			SetWindowTextW(hAsn, ans);
			MessageBox(hWnd, ans, L"Result", MB_OK);
			break;
		case Divide_button:
			GetWindowText(hNum1, num1, sizeof(num1) / sizeof(num1[0]));
			GetWindowText(hNum2, num2, sizeof(num2) / sizeof(num2[0]));
			result = _wtof(num1) / _wtof(num2);
			swprintf(ans, 30, L"%f", result);
			SetWindowTextW(hAsn, ans);
			MessageBox(hWnd, ans, L"Result", MB_OK);
			break;
		}

		break;
	case WM_CREATE:
		AddControls(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProcW(hWnd, msg, wp, lp);
	}
}

void AddControls(HWND hWnd) {
	CreateWindowW(L"Static", L"Please input two numbers", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER , 30, 10, 170, 20, hWnd, NULL, NULL, NULL);
	CreateWindowW(L"Button", L"+", WS_VISIBLE | WS_CHILD, 25, 100, 30, 30, hWnd, (HMENU)1, NULL, NULL);
	CreateWindowW(L"Button", L"-", WS_VISIBLE | WS_CHILD, 75, 100, 30, 30, hWnd, (HMENU)2, NULL, NULL);
	CreateWindowW(L"Button", L"*", WS_VISIBLE | WS_CHILD, 125, 100, 30, 30, hWnd, (HMENU)3, NULL, NULL);
	CreateWindowW(L"Button", L"/", WS_VISIBLE | WS_CHILD, 175, 100, 30, 30, hWnd, (HMENU)4, NULL, NULL);

	CreateWindowW(L"Static", L"Number 1", WS_VISIBLE | WS_CHILD , 30, 40, 65, 20, hWnd, NULL, NULL, NULL);
	hNum1 = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 100, 40, 100, 20, hWnd, NULL, NULL, NULL);

	CreateWindowW(L"Static", L"Number 2", WS_VISIBLE | WS_CHILD , 30, 70, 65, 20, hWnd, NULL, NULL, NULL);
	hNum2 = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER , 100, 70, 100, 20, hWnd, NULL, NULL, NULL);

}