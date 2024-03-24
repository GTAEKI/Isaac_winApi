#pragma once
#include "Obj.h"
class MoveObj :
    public Obj
{
public:
	virtual bool Init() = 0;
	virtual void Input(float fDeltaTime);
	virtual int Update(float fDeltaTime);
	virtual int LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hdc, float fDeltaTime);

protected:
    MoveObj();
	MoveObj(const MoveObj& obj);
    virtual ~MoveObj();
};

