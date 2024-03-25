﻿#include "InGameScene.h"
#include "../Object/Player.h"
#include "../Object/Minion.h"
#include "Layer.h"

bool CInGameScene::Init()
{
	// 부모 Scene 클래스의 초기화 함수를 호출해준다.
	if (!CScene::Init()) 
	{
		return false;
	}

	CLayer* pLayer = FindLayer("Default");

	CPlayer* pPlayer = CObj::CreateObj<CPlayer>("Player",pLayer);

	SAFE_RELEASE(pPlayer);

	CMinion* pMinion = CObj::CreateObj<CMinion>("Minion", pLayer);

	SAFE_RELEASE(pMinion);

	return true;
}

CInGameScene::CInGameScene()
{
}

CInGameScene::~CInGameScene()
{
}
