#include "StaticObj.h"

void CStaticObj::Input(float fDeltaTime)
{
}

int CStaticObj::Update(float fDeltaTime)
{
	return 0;
}

int CStaticObj::LateUpdate(float fDeltaTime)
{
	return 0;
}

void CStaticObj::Collision(float fDeltaTime)
{
}

void CStaticObj::Render(HDC hdc, float fDeltaTime)
{
}

CStaticObj::CStaticObj()
{
}

CStaticObj::CStaticObj(const CStaticObj& staticObj)
	: CObj(staticObj)
{

}

CStaticObj::~CStaticObj()
{
}
