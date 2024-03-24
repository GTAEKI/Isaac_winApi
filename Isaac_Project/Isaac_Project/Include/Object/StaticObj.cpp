#include "StaticObj.h"

void StaticObj::Input(float fDeltaTime)
{
}

int StaticObj::Update(float fDeltaTime)
{
	return 0;
}

int StaticObj::LateUpdate(float fDeltaTime)
{
	return 0;
}

void StaticObj::Collision(float fDeltaTime)
{
}

void StaticObj::Render(HDC hdc, float fDeltaTime)
{
}

StaticObj::StaticObj()
{
}

StaticObj::StaticObj(const StaticObj& staticObj)
	: Obj(staticObj)
{

}

StaticObj::~StaticObj()
{
}
