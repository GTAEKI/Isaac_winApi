#include "MoveObj.h"

void MoveObj::Input(float fDeltaTime)
{
}

int MoveObj::Update(float fDeltaTime)
{
	return 0;
}

int MoveObj::LateUpdate(float fDeltaTime)
{
	return 0;
}

void MoveObj::Collision(float fDeltaTime)
{
}

void MoveObj::Render(HDC hdc, float fDeltaTime)
{
}

MoveObj::MoveObj()
{
}

MoveObj::MoveObj(const MoveObj& obj) 
	:Obj(obj)
{
}

MoveObj::~MoveObj()
{
}
