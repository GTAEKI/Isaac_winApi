#pragma once

#include "../Game.h"

class CScene
{
public:
	virtual bool Init();

protected:
	friend class CSceneManager;

	CScene();
	virtual ~CScene() = 0;
};

