#include "Obj.h"

bool Obj::Init()
{
	return true;
}

void Obj::Input(float fDeltaTime)
{
}

int Obj::Update(float fDeltaTime)
{
	return 0;
}

int Obj::LateUpdate(float fDeltaTime)
{
	return 0;
}

void Obj::Collision(float fDeltaTime)
{
}

void Obj::Render(HDC hdc, float fDeltaTime)
{
}

Obj::Obj()
	: m_iRef(1)
{
}

Obj::~Obj()
{
}
