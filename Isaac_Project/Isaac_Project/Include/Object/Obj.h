#pragma once

#include "../Game.h"
#include "../Ref.h"

class Obj :
	public Ref
{
public:
	virtual bool Init() = 0;
	virtual void Input(float fDeltaTime);
	virtual int Update(float fDeltaTime);
	virtual int LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hdc, float fDeltaTime);

	string GetTag() const
	{
		return m_strTag;
	}

	POSITION GetPos()
	{
		return m_tPos;
	}

	_SIZE GetSize()
	{
		return m_tSize;
	}

	void SetTag(const string& strTag)
	{
		m_strTag = strTag;
	}

	void SetPos(const POSITION& tPos)
	{
		m_tPos = tPos;
	}

	void SetPos(const POINT& tPt)
	{
		m_tPos = tPt;
	}

	void SetPos(float x, float y)
	{
		m_tPos.x = x;
		m_tPos.y = y;
	}

	void SetSize(const _SIZE& tSize)
	{
		m_tSize = tSize;
	}

	void SetSize(float x, float y)
	{
		m_tSize.x = x;
		m_tSize.y = y;
	}

	void SetScene(class CScene* pScene) 
	{
		m_pScene = pScene;
	}
	void SetLayer(class Layer* pLayer) 
	{
		m_pLayer = pLayer;
	}

	class CScene* GetScene() const 
	{
		return m_pScene;
	}

	class Layer* GetLayer() const 
	{
		return m_pLayer;
	}

	template<typename T>
	static T* CreateObj(const string& strTag, class Layer* pLayer = NULL) 
	{
		T* pObj = new T;

		if (!pObj->Init()) 
		{
			SAFE_RELEASE(pObj);
			return NULL;
		}

		if (pLayer) 
		{
			pLayer->AddObject(pObj);
		}
		return pObj;
	}

protected:
	Obj();
	Obj(const Obj& obj);
	virtual ~Obj();

	string m_strTag;
	POSITION m_tPos;
	_SIZE m_tSize;
	POSITION m_tPivot;

	class CScene* m_pScene;
	class Layer* m_pLayer;
};

