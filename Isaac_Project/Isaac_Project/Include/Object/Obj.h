#pragma once

#include "../Game.h"
#include "../Ref.h"
#include "../Scene/Layer.h"

class CObj :
	public CRef
{
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

	class CScene* GetScene() const 
	{
		return m_pScene;
	}

	class CLayer* GetLayer() const
	{
		return m_pLayer;
	}

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


	static CObj* CreateCloneObj(const string& strPrototypeKey, const string& strTag, class CLayer* pLayer = NULL);

	static void AddObj(CObj* pObj);
	static CObj* FindObject(const string& strTag);
	static void EraseObj(CObj* pObj);
	static void EraseObj(const string& strTag);
	static void EraseObj();

	static void AddObj(CObj* pObj);
	static CObj* FindObject(const string& strTag);
	static void EraseObj(CObj* pObj);
	static void EraseObj(const string& strTag);
	static void EraseObj();
	static void ErasePrototype();
	static void ErasePrototype(const string& strTag);

private:
	// 프로토타입 찾는 기능은 외부에서 필요가 없음. 객체 생성시에만 필요
	static CObj* FindPrototype(const string& strKey);


protected:
	CObj();
	CObj(const CObj& obj);
	virtual ~CObj();

	string m_strTag;
	POSITION m_tPos;
	_SIZE m_tSize;
	POSITION m_tPivot;

	class CScene* m_pScene;
	class CLayer* m_pLayer;

private:
	static list<CObj*> m_ObjList;
	static unordered_map<string, CObj*> m_mapPrototype;
};

