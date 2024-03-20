#pragma once

#include "../Game.h"

class CScene
{
public:
	virtual bool Init();

	class Layer* CreateLayer(const string& strTag, int iZOrder = 0);

	static bool LayerSort(Layer* pL1, Layer* pL2);

protected:
	friend class CSceneManager;

	list<class Layer*> m_LayerList;

	CScene();
	virtual ~CScene() = 0;
};

