#include "Player.h"

bool Player::Init()
{
	return true;
}

void Player::Input(float fDeltaTime)
{
}

int Player::Update(float fDeltaTime)
{
	return 0;
}

int Player::LateUpdate(float fDeltaTime)
{
	return 0;
}

void Player::Collision(float fDeltaTime)
{
}

void Player::Render(HDC hdc, float fDeltaTime)
{
	Rectangle(hdc, m_tPos.x, m_tPos.y, m_tPos.x + m_tSize.x, m_tPos.y + m_tSize.y);
}

Player::Player()
{
}

Player::Player(const Player& player)
	: MoveObj(player)
{
}

Player::~Player()
{
}
