﻿#include "InGameScene.h"

bool CInGameScene::Init()
{
	// 부모 Scene 클래스의 초기화 함수를 호출해준다.
	if (!CScene::Init()) 
	{
		return false;
	}

	return true;
}

CInGameScene::CInGameScene()
{
}

CInGameScene::~CInGameScene()
{
}
