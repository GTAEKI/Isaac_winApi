#include "Scene.h"
#include "Layer.h"

bool CScene::Init()
{
	return true;
}

bool CScene::LayerSort(Layer* pL1, Layer* pL2)
{
	return pL1->GetZOrder() < pL2->GetZOrder();
}

Layer* CScene::CreateLayer(const string& strTag, int iZOrder)
{
	Layer* pLayer = new Layer;

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

CScene::CScene()
{
	Layer* pLayer = CreateLayer("UI", INT_MAX); 
	pLayer = CreateLayer("Default");
	
}

CScene::~CScene()
{
	Safe_Delete_VecList(m_LayerList);
}
