#pragma once
#include "MoveObj.h"
class CMinion :
    public CMoveObj
{

private:
	friend class CObj;
	friend class CScene;

	CMinion();
	CMinion(const CMinion& minion);
	~CMinion();

	MOVE_DIR m_eDir;
	float m_fFireTime;
	float m_fFireLimitTime;

	void Fire();

public:
	virtual bool Init();
	virtual int Update(float fDeltaTime);
	virtual int LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hdc, float fDeltaTime);
	virtual CMinion* Clone();

};

