#pragma once

#include "../Game.h"
#include "../Ref.h"
#include "../Scene/Layer.h"

class CObj :
	public CRef
{
private:
	static list<CObj*> m_ObjList;

protected:
	friend class CScene;

	CObj();
	CObj(const CObj& obj);
	virtual ~CObj();

	string m_strTag;
	POSITION m_tPos;
	_SIZE m_tSize;
	POSITION m_tPivot;

	class CScene* m_pScene;
	class CLayer* m_pLayer;
	class CTexture* m_pTexture;

public:
	virtual bool Init() = 0;
	virtual void Input(float fDeltaTime);
	virtual int Update(float fDeltaTime);
	virtual int LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hdc, float fDeltaTime);
	virtual CObj* Clone() = 0;

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
	void SetLayer(class CLayer* pLayer)
	{
		m_pLayer = pLayer;
	}

	void SetPivot(const _SIZE& tPivot)
	{
		m_tPivot = tPivot;
	}


	void SetPivot(float x, float y)
	{
		m_tPivot.x = x;
		m_tPivot.y = y;
	}

	class CScene* GetScene() const 
	{
		return m_pScene;
	}

	class CLayer* GetLayer() const
	{
		return m_pLayer;
	}

	POSITION GetPivot() const 
	{
		return m_tPivot;
	}

	void SetTexture(class CTexture* pTexture);
	void SetTexture(const string& strKey, const wchar_t* pFileName = NULL, const string& strPathKey = TEXTURE_PATH);

	// 오브젝트 생성
	template<typename T>
	static T* CreateObj(const string& strTag, class CLayer* pLayer = NULL)
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

		AddObj(pObj);

		return pObj;
	}

	static CObj* CreateCloneObj(const string& strPrototypeKey, const string& strTag, class CLayer* pLayer = NULL);

	static void AddObj(CObj* pObj);
	static CObj* FindObject(const string& strTag);
	static void EraseObj(CObj* pObj);
	static void EraseObj(const string& strTag);
	static void EraseObj();

};

