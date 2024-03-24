#pragma once

#include "MoveObj.h"

class Player :
    public MoveObj
{
public :
	virtual bool Init();
	virtual void Input(float fDeltaTime);
	virtual int Update(float fDeltaTime);
	virtual int LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hdc, float fDeltaTime);

private:
    Player();
	Player(const Player& player);
    ~Player();
};

