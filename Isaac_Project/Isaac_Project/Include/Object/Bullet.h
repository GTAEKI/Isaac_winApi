#pragma once
#include "MoveObj.h"
class CBullet :
    public CMoveObj
{
public:
	virtual bool Init();
	virtual int Update(float fDeltaTime);
	virtual int LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hdc, float fDeltaTime);
	virtual CBullet* Clone();

	void SetBulletDistance(float fDist) 
	{
		m_fLimitDist = fDist;
	}

private:
	friend class CObj;
	friend class CScene;

	CBullet();
	CBullet(const CBullet& bullet);
	~CBullet();

	float m_fLimitDist;
	float m_fDist;
};

