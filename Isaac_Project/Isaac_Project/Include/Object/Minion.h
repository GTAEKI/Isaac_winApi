#pragma once
#include "MoveObj.h"
class CMinion :
    public CMoveObj
{
public:
	virtual bool Init();
	virtual int Update(float fDeltaTime);
	virtual int LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hdc, float fDeltaTime);

private:
	friend class CObj;

	CMinion();
	CMinion(const CMinion& minion);
	~CMinion();

	MOVE_DIR m_eDir;
};

