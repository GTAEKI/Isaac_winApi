#pragma once

#include "Game.h"

class CCamera
{
	DECLARE_SINGLE(CCamera)

private:
	POSITION m_tPos;
	RESOLUTION m_tClientRS;
	RESOLUTION m_tWorldRS;
	class CObj* m_pTarget;

public:
	bool Init(const POSITION& tPos, const RESOLUTION& tRS, const RESOLUTION& tWorldRS);
	void Input(float fDeltaTime);
	void Update(float fDeltaTime);

	void SetPos(const POSITION& tPos) 
	{
		m_tPos = tPos;
	}

	void SetPos(float x, float y) 
	{
		m_tPos.x = x;
		m_tPos.y = y;
	}

	void SetClientResolution(const RESOLUTION& tRS)
	{
		m_tClientRS = tRS;
	}

	void SetClientResolution(float x, float y)
	{
		m_tClientRS = RESOLUTION(x, y);
	}

	void SetWorldResolution(const RESOLUTION& tRS)
	{
		m_tWorldRS = tRS;
	}

	void SetWorldResolution(float x, float y)
	{
		m_tWorldRS = RESOLUTION(x,y);
	}

	void SetTarget(class CObj* pObj);

};

