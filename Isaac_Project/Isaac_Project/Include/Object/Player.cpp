#include "Player.h"

bool CPlayer::Init()
{
	SetPos(100.f, 100.f);
	SetSize(25.f, 25.f);
	SetSpeed(400.f);

	SetTexture("Player", L"lost_contact_tears.bmp");

	return true;
}

void CPlayer::Input(float fDeltaTime)
{
	CMoveObj::Input(fDeltaTime);

	if (GetAsyncKeyState('W') & 0x8000) 
	{
		MoveYFromSpeed(fDeltaTime, MD_BACK);
	}
	
	if (GetAsyncKeyState('S') & 0x8000)
	{
		MoveYFromSpeed(fDeltaTime, MD_FRONT);
	}

	if (GetAsyncKeyState('A') & 0x8000)
	{
		MoveXFromSpeed(fDeltaTime, MD_BACK);
	}

	if (GetAsyncKeyState('D') & 0x8000)
	{
		MoveXFromSpeed(fDeltaTime, MD_FRONT);
	}

	if (GetAsyncKeyState(VK_SPACE) & 0x8000) 
	{
		Fire();
	}
}

int CPlayer::Update(float fDeltaTime)
{
	CMoveObj::Update(fDeltaTime);
	return 0;
}

int CPlayer::LateUpdate(float fDeltaTime)
{
	CMoveObj::LateUpdate(fDeltaTime);
	return 0;
}

void CPlayer::Collision(float fDeltaTime)
{
	CMoveObj::Collision(fDeltaTime);
}

void CPlayer::Render(HDC hdc, float fDeltaTime)
{
	CMoveObj::Render(hdc, fDeltaTime);
	//Rectangle(hdc, m_tPos.x, m_tPos.y, m_tPos.x + m_tSize.x, m_tPos.y + m_tSize.y);
}

CPlayer* CPlayer::Clone()
{
	return new CPlayer(*this);
}

CPlayer::CPlayer()
{
}

CPlayer::CPlayer(const CPlayer& player)
	: CMoveObj(player)
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::Fire()
{
	CObj* pBullet = CObj::CreateCloneObj("Bullet", "PlayerBullet", m_pLayer);

	//pBullet->SetSize(50.f, 50.f);
	pBullet->SetPos(m_tPos.x + m_tSize.x, 
		((m_tPos.y + m_tPos.y + m_tSize.y) / 2.f) - (pBullet->GetSize().y / 2.f));

	SAFE_RELEASE(pBullet);
}
