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

	static void ErasePrototype();
	static void ErasePrototype(const string& strTag);

	// 프로토타입 생성
	template<typename T>
	static T* CreatePrototype(const string& strTag)
	{
		T* pObj = new T;

		pObj->SetTag(strTag);

		if (!pObj->Init())
		{
			SAFE_RELEASE(pObj);
			return NULL;
		}

		pObj->AddRef();
		m_mapPrototype.insert(make_pair(strTag, pObj));

		return pObj;
	}

	static class CObj* FindPrototype(const string& strKey);


protected:
	friend class CSceneManager;

	list<class CLayer*> m_LayerList;

	CScene();
	virtual ~CScene() = 0;

private:
	static unordered_map<string,class CObj*> m_mapPrototype;
};

