// ConcurrentFileCopy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ConcurrentFileCopy.h"

TCHAR* szTitle = _T("Concurrent file copy");
TCHAR* szWindowClass = _T("__CFC_WND_CLASS__");

DWORD dwReadBytes = 0;
DWORD dwWriteBytes = 0;

DWORD dwBlockSize = 0;
DWORD dwFileSize = 0; 

HLOCAL pMemory = NULL;

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPTSTR
	szCmdLine, int iCmdShow)
{
	UNREFERENCED_PARAMETER(hPrev);
	UNREFERENCED_PARAMETER(szCmdLine);

	RegisterWndClass(hInstance);

	HWND hWnd = NULL;
	HWND hWndPB = NULL;
	if (!(hWnd = InitializeInstances(hInstance, iCmdShow, hWndPB)))
		return 1;

	MSG msg = { 0 };
	TCHAR szReadFile[MAX_PATH];
	TCHAR szWriteFile[MAX_PATH];

	if (FileDialog(hWnd, szReadFile, FILE_OPEN) && FileDialog(hWnd,
		szWriteFile, FILE_SAVE))
	{
		COPYDETAILS copyDetails = { hInstance, hWndPB, szReadFile,
			szWriteFile };

		HANDLE hMutex = CreateMutex(NULL, FALSE, MUTEX_NAME);
		HANDLE hReadThread = CreateThread(NULL, 0,
			(LPTHREAD_START_ROUTINE)ReadRoutine, &copyDetails, 0, NULL);

		while (GetMessage(&msg, NULL, 0, 0))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		CloseHandle(hReadThread);
		CloseHandle(hMutex);
	}
	else
		MessageBox(hWnd, _T("Cannot open file!"),
		_T("Error!"), MB_OK);

	LocalFree(pMemory);
	UnregisterClass(szWindowClass, hInstance);

	return (int)msg.wParam;
}

ATOM
RegisterWndClass(HINSTANCE hInstance)
{
	WNDCLASSEX wndEx;

	wndEx.cbSize = sizeof(WNDCLASSEX);
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

