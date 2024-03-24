#pragma once
#include "Obj.h"
class StaticObj :
    public Obj
{
public :
	virtual bool Init()=0;
	virtual void Input(float fDeltaTime);
	virtual int Update(float fDeltaTime);
	virtual int LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hdc, float fDeltaTime);

protected:
    StaticObj();
	StaticObj(const StaticObj& staticObj);
    virtual ~StaticObj();
};

