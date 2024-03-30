#pragma once

#include "../Game.h"

class CLayer
{

private:
	// 씬 통해서만 생성하게 할 것이다.
	friend class CScene;

	CLayer();

	class CScene* m_pScene;
	string m_strTag;//태그
	int m_iZOrder; // 레이어 순서
	list<class CObj*> m_ObjList;
	bool m_bEnable;
	bool m_bLife;


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


	void SetEnable(bool bEnable)
	{
		m_bEnable = bEnable;
	}

	void Die()
	{
		m_bLife = false;
	}

	bool GetEnable() const
	{
		return m_bEnable;
	}

	bool GetLive() const
	{
		return m_bLife;
	}

	~CLayer();


};

