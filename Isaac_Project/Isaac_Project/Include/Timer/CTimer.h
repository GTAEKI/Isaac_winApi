#pragma once

#include "../Game.h"

class CTimer
{
public:
	bool init();
	bool Update();

	float GetDeltaTime() const 
	{
		return m_fDeltaTime;
	}

	float GetFPS() const 
	{
		return m_fFPS;
	}

private:
	LARGE_INTEGER m_tSecond;
	LARGE_INTEGER m_tTime;
	float m_fDeltaTime;
	float m_fFPS;
	float m_fFPSTime;
	int m_iFrameMax;
	int m_iFrame;

	DECLARE_SINGLE(CTimer);
};

