#include "InGameScene.h"
#include "../Object/Player.h"
#include "Layer.h"

bool CInGameScene::Init()
{
	// 부모 Scene 클래스의 초기화 함수를 호출해준다.
	if (!CScene::Init()) 
	{
		return false;
	}

	Layer* pLayer = FindLayer("Default");

	Player* pPlayer = Obj::CreateObj<Player>("Player", pLayer);

	SAFE_RELEASE(pPlayer);

	return true;
}

CInGameScene::CInGameScene()
{
}

CInGameScene::~CInGameScene()
{
}
