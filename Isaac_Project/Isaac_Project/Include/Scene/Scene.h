#pragma once

#include "../Game.h"

class CScene
{
public:
	virtual bool Init();
	virtual void Input(float fDeltaTime);
	virtual int Update(float fDeltaTime);
	virtual int LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hdc, float fDeltaTime);

	class CLayer* CreateLayer(const string& strTag, int iZOrder = 0);
	class CLayer* FindLayer(const string& strTag);

	static bool LayerSort(CLayer* pL1, CLayer* pL2);

protected:
	friend class CSceneManager;

	list<class CLayer*> m_LayerList;

	CScene();
	virtual ~CScene() = 0;

	
};

