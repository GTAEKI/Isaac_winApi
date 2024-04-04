#pragma once

#include "../Ref.h"
#include "../Object/Obj.h"

class CCollider :
    public CRef
{
protected:
	CCollider();
	CCollider(const CCollider& coll);
    virtual ~CCollider() = 0;

	friend class CObj;

	COLLIDER_TYPE m_eCollType;
	class CObj* m_pObj;
	list<CCollider*> m_CollisionList;
	list<function<void(CCollider*, CCollider*, float)>> m_FuncList[CS_END];

	bool CollisionRectToRect(const RECTANGLE& src, const RECTANGLE& dest); // Rect와 Rect 충돌처리

public:
	void AddCollisionFunction(COLLISION_STATE eState, void(*pFunc)(CCollider*, CCollider*, float))
	{
		function<void(CCollider*, CCollider*, float)> func;

		func = bind(pFunc, placeholders::_1, placeholders::_2, placeholders::_3);

		m_FuncList[eState].push_back(func);
	}

	template <typename T>
	void AddCollisionFunction(COLLISION_STATE eState, T* pObj, void(T::*pFunc)(CCollider*, CCollider*, float))
	{
		function<void(CCollider*, CCollider*, float)> func;

		func = bind(pFunc, pObj, placeholders::_1, placeholders::_2, placeholders::_3);

		m_FuncList[eState].push_back(func);
	}

	void CallFunction(COLLISION_STATE eState, CCollider* pDest, float fDeltaTime)
	{
		list<function<void(CCollider*, CCollider*, float)>> ::iterator iter;
		list<function<void(CCollider*, CCollider*, float)>> ::iterator iterEnd = m_FuncList[eState].end();

		for (iter = m_FuncList[eState].begin(); iter != iterEnd; ++iter) 
		{
			(*iter)(this, pDest, fDeltaTime);
		}

	}

	void AddCollider(CCollider* pCollider) 
	{
		m_CollisionList.push_back(pCollider);
	}

	bool CheckCollisionList(CCollider* pCollider)
	{
		list<CCollider*>::iterator iter;
		list<CCollider*>::iterator iterEnd = m_CollisionList.end();

		for (iter = m_CollisionList.begin(); iter != iterEnd; ++iter) 
		{

			if (*iter == pCollider) 
			{
				return true;
			}
		}
		return false;
	}

	void EraseCollisionList(CCollider* pCollider) 
	{
		list<CCollider*>::iterator iter;
		list<CCollider*>::iterator iterEnd = m_CollisionList.end();

		for (iter = m_CollisionList.begin(); iter != iterEnd; ++iter)
		{
			if (*iter == pCollider)
			{
				m_CollisionList.erase(iter);
				break;
			}
		}
	}

	COLLIDER_TYPE GetColliderType() const 
	{
		return m_eCollType;
	}

	class CObj* GetObj() const 
	{
		return m_pObj;
	}

	void SetObj(class CObj* pObj)
	{
		m_pObj = pObj;
	}


public:
	virtual bool Init() = 0;
	virtual void Input(float fDeltaTime);
	virtual int Update(float fDeltaTime);
	virtual int LateUpdate(float fDeltaTime);
	virtual bool Collision(CCollider* pDest); // 상대 대상 충돌체가 들어오는 함수
	virtual void Render(HDC hdc, float fDeltaTime);
	virtual CCollider* Clone() = 0;
};

