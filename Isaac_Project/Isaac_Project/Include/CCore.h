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

private:
	static CCore* m_pInst;

	CCore();
	~CCore();
};

