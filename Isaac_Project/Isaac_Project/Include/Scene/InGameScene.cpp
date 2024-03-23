#include "InGameScene.h"

bool CInGameScene::Init()
{
	// 부모 Scene 클래스의 초기화 함수를 호출해준다.
	if (!CScene::Init()) 
	{
		return false;
	}

	return true;
}

//void CInGameScene::Input(float fDeltaTime)
//{
//}
//
//int CInGameScene::Update(float fDeltaTime)
//{
//	return 0;
//}
//
//int CInGameScene::LateUpdate(float fDeltaTime)
//{
//	return 0;
//}
//
//void CInGameScene::Collision(float fDeltaTime)
//{
//}
//
//void CInGameScene::Render(HDC hdc, float fDeltaTime)
//{
//}

CInGameScene::CInGameScene()
{
}

CInGameScene::~CInGameScene()
{
}
