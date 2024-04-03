#pragma once
#include "Collider.h"
class CColliderRect :
    public CCollider
{
private:
	RECTANGLE m_tInfo;
	RECTANGLE m_tWorldInfo;

protected:
	CColliderRect();
	CColliderRect(const CColliderRect& coll);
	virtual ~CColliderRect();

	friend class CObj;

public:
	virtual bool Init();
	virtual void Input(float fDeltaTime);
	virtual int Update(float fDeltaTime);
	virtual int LateUpdate(float fDeltaTime);
	virtual bool Collision(CCollider* pDest);
	virtual void Render(HDC hdc, float fDeltaTime);
	virtual CColliderRect* Clone();

	void SetRect(float l, float t, float r, float b);

	RECTANGLE GetInfo() const 
	{
		return m_tInfo;
	}

	RECTANGLE GetWorldInfo() const 
	{
		return m_tWorldInfo;
	}
};

