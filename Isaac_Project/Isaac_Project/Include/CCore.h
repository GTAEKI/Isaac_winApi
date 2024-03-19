#pragma once

#include "Game.h"

class CCore
{
public:
	static CCore* GetInst() 
	{
		if (!m_pInst)
		{
			m_pInst = new CCore;
		}

		return m_pInst;
	}

	static void DestroyInst() 
	{
		SAFE_DELETE(m_pInst);
		//delete m_pInst;
		//m_pInst = NULL;
	}

	bool Init(HINSTANCE hInst);
	int Run();

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT messageType, WPARAM wParam, LPARAM lParam);

private:
	WNDCLASS windowClass;
	
	static CCore* m_pInst;
	static bool m_bLoop;
	
	HINSTANCE m_hInst;
	HWND m_hWnd;
	RESOLUTION m_tRS;

	CCore();
	~CCore();
	
	ATOM MyRegisterClass();
	BOOL Create();
};

