#include "Player.h"

bool CPlayer::Init()
{
	return true;
}

void CPlayer::Input(float fDeltaTime)
{
}

int CPlayer::Update(float fDeltaTime)
{
	return 0;
}

int CPlayer::LateUpdate(float fDeltaTime)
{
	return 0;
}

void CPlayer::Collision(float fDeltaTime)
{
}

void CPlayer::Render(HDC hdc, float fDeltaTime)
{
	Rectangle(hdc, m_tPos.x, m_tPos.y, m_tPos.x + m_tSize.x, m_tPos.y + m_tSize.y);
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
