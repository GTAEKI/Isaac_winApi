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
	HDC m_hDC;
	RESOLUTION m_tRS;

	CCore();
	~CCore();
	
	ATOM MyRegisterClass();
	BOOL Create();
	void Logic();
	void Input(float fDeltaTime);
	int Update(float fDeltaTime);
	int LateUpdate(float fDeltaTime); // 후처리 해야하는 경우
	void Collision(float fDeltaTime);
	void Render(float fDeltaTime);
};

