#pragma once

#include "MoveObj.h"

class CPlayer :
    public CMoveObj
{
public :
	virtual bool Init();
	virtual void Input(float fDeltaTime);
	virtual int Update(float fDeltaTime);
	virtual int LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hdc, float fDeltaTime);

private:
	friend class CObj;

	CPlayer();
	CPlayer(const CPlayer& player);
    ~CPlayer();
};

