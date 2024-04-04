#include "Bullet.h"
#include "../Collider/ColliderRect.h"


bool CBullet::Init()
{
	SetPos(0, 0);
	SetSize(25.f, 25.f);
	SetSpeed(500.f);
	SetPivot(0.5f, 0.5f);

	SetTexture("Bullet", L"lost_contact_tears.bmp");

	CColliderRect* pRC = AddCollider<CColliderRect>("Bullet");

	pRC->SetRect(-12.5f, -12.5f, 12.5f, 12.5f);

	SAFE_RELEASE(pRC);

	return true;
}

int CBullet::Update(float fDeltaTime)
{
	CMoveObj::Update(fDeltaTime);

	MoveAngle(fDeltaTime);

	m_fDist += GetSpeed() * fDeltaTime;

	if (m_fDist >= m_fLimitDist) 
	{
		Die();
	}

	return 0;
}

int CBullet::LateUpdate(float fDeltaTime)
{
	CMoveObj::LateUpdate(fDeltaTime);

	return 0;
}

void CBullet::Collision(float fDeltaTime)
{
	CMoveObj::Collision(fDeltaTime);
}

void CBullet::Render(HDC hdc, float fDeltaTime)
{
	CMoveObj::Render(hdc, fDeltaTime);
	//Ellipse(hdc, m_tPos.x, m_tPos.y, m_tPos.x + m_tSize.x, m_tPos.y + m_tSize.y);
}

CBullet* CBullet::Clone()
{
	return new CBullet(*this);
}

void CBullet::Hit(CCollider* pSrc, CCollider* pDest, float fDeltaTime)
{
	
}

CBullet::CBullet(const CBullet& bullet)
	:CMoveObj(bullet)
{
	m_fLimitDist = bullet.m_fLimitDist;
	m_fDist = bullet.m_fDist;
	m_tSize = bullet.m_tSize;
}

CBullet::CBullet()
	:m_fDist(0.f)
	, m_fLimitDist(500.f)
{
}

CBullet::~CBullet()
{
}
