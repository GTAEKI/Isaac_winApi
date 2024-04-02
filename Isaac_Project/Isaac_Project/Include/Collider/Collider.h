#pragma once

#include "../Ref.h"
#include "../Object/Obj.h"

class CCollider :
    public CRef
{
protected:
	CCollider();
	CCollider(const CCollider& coll);
    virtual ~CCollider() = 0;

	friend class CObj;

	COLLIDER_TYPE m_eCollType;
public:
	COLLIDER_TYPE GetColliderType() const 
	{
		return m_eCollType;
	}

public:
	virtual bool Init() = 0;
	virtual void Input(float fDeltaTime);
	virtual int Update(float fDeltaTime);
	virtual int LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hdc, float fDeltaTime);
	virtual CCollider* Clone() = 0;
};

