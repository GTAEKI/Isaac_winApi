#include "Player.h"

bool CPlayer::Init()
{
	SetPos(50, 50);
	SetSize(30.f, 35.f);
	SetSpeed(400.f);
	SetPivot(0.9f, 0.8);

	SetTexture("Player", L"Character1.bmp");

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

	// 오른쪽 가운데를 구한다.
	POSITION tPos;
	tPos.x = m_tPos.x + (1.f - m_tPivot.x) * m_tSize.x;
	tPos.y = m_tPos.y + (0.5f - m_tPivot.y) * m_tSize.y;

	//pBullet->SetSize(50.f, 50.f);
	pBullet->SetPos(tPos.x, tPos.y - (pBullet->GetSize().y / 2.f));

	SAFE_RELEASE(pBullet);
}
