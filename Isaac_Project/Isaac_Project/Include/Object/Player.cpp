#include "Player.h"
#include "../Input.h"
#include <WinUser.h>

bool CPlayer::Init()
{
	SetPos(65, 70);
	SetSize(65.f, 70.f);
	SetSpeed(400.f);
	SetPivot(1, 1);

	SetTexture("Player", L"Character1.bmp");

	return true;
}

void CPlayer::Input(float fDeltaTime)
{
	CMoveObj::Input(fDeltaTime);

	//if (GetAsyncKeyState('W') & 0x8000) 
	if(KEYPRESS("MoveFront"))
	{
		MoveYFromSpeed(fDeltaTime, MD_BACK);
	}
	
	//if (GetAsyncKeyState('S') & 0x8000)
	if(KEYPRESS("MoveBack"))
	{
		MoveYFromSpeed(fDeltaTime, MD_FRONT);
	}

	//if (GetAsyncKeyState('A') & 0x8000)
	if(KEYPRESS("MoveLeft"))
	{
		MoveXFromSpeed(fDeltaTime, MD_BACK);
	}

	//if (GetAsyncKeyState('D') & 0x8000)
	if(KEYPRESS("MoveRight"))
	{
		MoveXFromSpeed(fDeltaTime, MD_FRONT);
	}

	//if (GetAsyncKeyState(VK_SPACE) & 0x8000) 
	if(KEYDOWN("Fire"))
	{
		Fire();
	}

	if (KEYDOWN("Skill1")) 
	{
		MessageBox(NULL, L"Skill1", L"Skill1", MB_OK);
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
	//pBullet->SetSize(25.f, 25.f);
	// 오른쪽 가운데를 구한다.
	POSITION tPos;
	tPos.x = GetRight() + pBullet->GetSize().x * pBullet->GetPivot().x;
	tPos.y = GetCenter().y;
	
 	pBullet->SetPos(tPos);
	//pBullet->SetSize(50.f, 50.f);
	//pBullet->SetPos(tPos.x, tPos.y - (pBullet->GetSize().y / 2.f));

	SAFE_RELEASE(pBullet);
}
