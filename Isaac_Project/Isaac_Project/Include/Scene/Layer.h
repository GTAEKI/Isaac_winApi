#pragma once

#include "../Game.h"

class CLayer
{
public :
	void Input(float fDeltaTime);
	int Update(float fDeltaTime);
	int LateUpdate(float fDeltaTime);
	void Collision(float fDeltaTime);
	void Render(HDC hdc, float fDeltaTime);

public:
	void SetTag(const string& strTag) 
	{
		m_strTag = strTag;
	}

	void SetZOrder(int iZOrder) 
	{
		m_iZOrder = iZOrder;
	}

	void SetScene(class CScene* pScene) 
	{
		m_pScene = pScene;
	}

	int GetZOrder() const 
	{
		return m_iZOrder;
	}

	string GetTag() const 
	{
		return m_strTag;
	}

	CScene* GetScene() const 
	{
		return m_pScene;
	}

	void AddObject(class CObj* pObj);

	~CLayer();

private:
	// 씬 통해서만 생성하게 할 것이다.
	friend class CScene;

	CLayer();

	class CScene* m_pScene;
	string m_strTag;//태그
	int m_iZOrder; // 레이어 순서
	list<class CObj*> m_ObjList;

};

