#include "stdafx.h"

#define BUTTON_CLOSE 100
#define PHILOSOPHER_COUNT 5
#define WM_INVALIDATE	WM_USER + 1

typedef struct _tagCOMMUNICATIONOBJECT
{
	HWND hWnd;
	bool bExitApplication;
	int iPhilosopherArray[PHILOSOPHER_COUNT];
};