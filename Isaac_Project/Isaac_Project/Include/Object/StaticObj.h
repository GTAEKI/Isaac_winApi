#pragma once
#include "Obj.h"
class CStaticObj :
    public CObj
{
public :
	virtual bool Init()=0;
	virtual void Input(float fDeltaTime);
	virtual int Update(float fDeltaTime);
	virtual int LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hdc, float fDeltaTime);

protected:
	CStaticObj();
	CStaticObj(const CStaticObj& staticObj);
    virtual ~CStaticObj();
};

