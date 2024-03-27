#include "Scene.h"
#include "Layer.h"
#include "../Object/Obj.h"

unordered_map<string, CObj*> CScene:: m_mapPrototype;


CScene::CScene()
{
	CLayer* pLayer = CreateLayer("UI", INT_MAX);
	pLayer = CreateLayer("Default");

}

CScene::~CScene()
{
	ErasePrototype();
	Safe_Delete_VecList(m_LayerList);
}



bool CScene::Init()
{
	return true;
}

void CScene::Input(float fDeltaTime)
{
	list<CLayer*>::iterator iter;
	list<CLayer*>::iterator iterEnd = m_LayerList.end();

	for (iter = m_LayerList.begin(); iter != iterEnd;) 
	{
		if (!(*iter)->GetEnable()) 
		{
			++iter;
			continue;
		}
		
		(*iter)->Input(fDeltaTime);
		
		if (!(*iter)->GetLive()) 
		{
			SAFE_DELETE((*iter));
			iter = m_LayerList.erase(iter);
			iterEnd = m_LayerList.end();
		}
		else 
		{
			++iter;
		}
	}
}

int CScene::Update(float fDeltaTime)
{
	list<CLayer*>::iterator iter;
	list<CLayer*>::iterator iterEnd = m_LayerList.end();

	for (iter = m_LayerList.begin(); iter != iterEnd;)
	{
		if (!(*iter)->GetEnable())
		{
			++iter;
			continue;
		}

		(*iter)->Update(fDeltaTime);

		if (!(*iter)->GetLive())
		{
			SAFE_DELETE((*iter));
			iter = m_LayerList.erase(iter);
			iterEnd = m_LayerList.end();
		}
		else
		{
			++iter;
		}
	}
	return 0;
}

int CScene::LateUpdate(float fDeltaTime)
{
	list<CLayer*>::iterator iter;
	list<CLayer*>::iterator iterEnd = m_LayerList.end();

	for (iter = m_LayerList.begin(); iter != iterEnd;)
	{
		if (!(*iter)->GetEnable())
		{
			++iter;
			continue;
		}

		(*iter)->LateUpdate(fDeltaTime);

		if (!(*iter)->GetLive())
		{
			SAFE_DELETE((*iter));
			iter = m_LayerList.erase(iter);
			iterEnd = m_LayerList.end();
		}
		else
		{
			++iter;
		}
	}
	return 0;
}

void CScene::Collision(float fDeltaTime)
{
	list<CLayer*>::iterator iter;
	list<CLayer*>::iterator iterEnd = m_LayerList.end();

	for (iter = m_LayerList.begin(); iter != iterEnd;)
	{
		if (!(*iter)->GetEnable())
		{
			++iter;
			continue;
		}

		(*iter)->Collision(fDeltaTime);

		if (!(*iter)->GetLive())
		{
			SAFE_DELETE((*iter));
			iter = m_LayerList.erase(iter);
			iterEnd = m_LayerList.end();
		}
		else
		{
			++iter;
		}
	}
}

void CScene::Render(HDC hdc, float fDeltaTime)
{
	list<CLayer*>::iterator iter;
	list<CLayer*>::iterator iterEnd = m_LayerList.end();

	for (iter = m_LayerList.begin(); iter != iterEnd;)
	{
		if (!(*iter)->GetEnable())
		{
			++iter;
			continue;
		}

		(*iter)->Render(hdc,fDeltaTime);

		if (!(*iter)->GetLive())
		{
			SAFE_DELETE((*iter));
			iter = m_LayerList.erase(iter);
			iterEnd = m_LayerList.end();
		}
		else
		{
			++iter;
		}
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


void CScene::ErasePrototype()
{
	Safe_Release_Map(m_mapPrototype);
}

void CScene::ErasePrototype(const string& strTag)
{
	unordered_map<string, CObj*>::iterator iter = m_mapPrototype.find(strTag);

	if (!iter->second) return;

	SAFE_RELEASE(iter->second);
	m_mapPrototype.erase(iter);
}

CObj* CScene::FindPrototype(const string& strKey)
{
	unordered_map<string, CObj*>::iterator iter = m_mapPrototype.find(strKey);

	if (iter == m_mapPrototype.end()) return NULL;

	return iter->second;
}
