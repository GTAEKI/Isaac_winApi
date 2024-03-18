#include <Windows.h>

HINSTANCE g_hinstance;

//LRESULT CALLBACK WndProc(HWND hWnd, UINT messageType, WPARAM wParam, LPARAM lParam)
//{
//
//	switch (messageType)
//	{
//	case WM_CREATE:
//	case WM_KEYDOWN:
//	case WM_PAINT:
//	case WM_DESTROY:
//	}
//	return DefWindowProc(hWnd, messageType, wParam, lParam);
//}


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	return 0;

	//g_hinstance = hInstance;
	//WNDCLASS windowClass;

	//windowClass.lpszClassName = TEXT("Second Project");
	//windowClass.lpszMenuName = NULL;

	//windowClass.lpfnWndProc = WndProc;
	//windowClass.hInstance = hInstance;

	//windowClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	//windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	//windowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	//windowClass.style = CS_VREDRAW | CS_HREDRAW | CS_DBLCLKS;

	//windowClass.cbClsExtra = 0;
	//windowClass.cbWndExtra = 0;
	//RegisterClass(&windowClass);

	//HWND hWND = CreateWindow(windowClass.lpszClassName, windowClass.lpszClassName, WS_OVERLAPPEDWINDOW,
	//	CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
	//	NULL, NULL, hInstance, NULL);

	//ShowWindow(hWND, nCmdShow);

	//MSG msg;

	//while (TRUE)
	//{
	//	if (GetMessage(&msg, NULL, 0, 0) == FALSE)
	//	{
	//		break;
	//	}

	//	TranslateMessage(&msg);
	//	DispatchMessage(&msg);
	//}

	//return msg.wParam;
}