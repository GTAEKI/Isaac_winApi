#include "Scene.h"
#include "Layer.h"

bool CScene::Init()
{
	return true;
}

void CScene::Input(float fDeltaTime)
{
	list<CLayer*>::iterator iter;
	list<CLayer*>::iterator iterEnd = m_LayerList.end();

	for (iter = m_LayerList.begin(); iter != iterEnd; ++iter) 
	{
		(*iter)->Input(fDeltaTime);
	}
}

int CScene::Update(float fDeltaTime)
{
	list<CLayer*>::iterator iter;
	list<CLayer*>::iterator iterEnd = m_LayerList.end();

	for (iter = m_LayerList.begin(); iter != iterEnd; ++iter)
	{
		(*iter)->Update(fDeltaTime);
	}
	return 0;
}

int CScene::LateUpdate(float fDeltaTime)
{
	list<CLayer*>::iterator iter;
	list<CLayer*>::iterator iterEnd = m_LayerList.end();

	for (iter = m_LayerList.begin(); iter != iterEnd; ++iter)
	{
		(*iter)->LateUpdate(fDeltaTime);
	}
	return 0;
}

void CScene::Collision(float fDeltaTime)
{
	list<CLayer*>::iterator iter;
	list<CLayer*>::iterator iterEnd = m_LayerList.end();

	for (iter = m_LayerList.begin(); iter != iterEnd; ++iter)
	{
		(*iter)->Collision(fDeltaTime);
	}
}

void CScene::Render(HDC hdc, float fDeltaTime)
{
	list<CLayer*>::iterator iter;
	list<CLayer*>::iterator iterEnd = m_LayerList.end();

	for (iter = m_LayerList.begin(); iter != iterEnd; ++iter)
	{
		(*iter)->Render(hdc, fDeltaTime);
	}
}

bool CScene::LayerSort(CLayer* pL1, CLayer* pL2)
{
	return pL1->GetZOrder() < pL2->GetZOrder();
}

CLayer* CScene::CreateLayer(const string& strTag, int iZOrder)
{
	CLayer* pLayer = new CLayer;

	pLayer->SetTag(strTag);
	pLayer->SetZOrder(iZOrder);
	pLayer->SetScene(this); // 이 씬에 속할 레이어를 만드는것, 이 함수를 호출한 씬이 이 레이어를 가지도록

	m_LayerList.push_back(pLayer);

	if (m_LayerList.size() >= 2) 
	{
		// zOrder값에 따라 오름차순, 작은게 앞, 큰게 뒤
		m_LayerList.sort(CScene::LayerSort);
	}

	return pLayer;
}

CLayer* CScene::FindLayer(const string& strTag)
{
	list<CLayer*>::iterator iter;
	list<CLayer*>::iterator iterEnd = m_LayerList.end();

	for (iter = m_LayerList.begin(); iter != iterEnd; ++iter)
	{
		if((*iter)->GetTag() == strTag) return *iter;
	}

	return NULL;
}

CScene::CScene()
{
	CLayer* pLayer = CreateLayer("UI", INT_MAX); 
	pLayer = CreateLayer("Default");
	
}

CScene::~CScene()
{
	Safe_Delete_VecList(m_LayerList);
}
