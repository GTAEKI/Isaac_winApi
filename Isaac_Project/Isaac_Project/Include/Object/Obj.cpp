#include "Obj.h"

// 초기화
list<CObj*> CObj::m_ObjList;
unordered_map<string, CObj*> CObj::m_mapPrototype;


void CObj::Input(float fDeltaTime)
{
}

int CObj::Update(float fDeltaTime)
{
	return 0;
}

int CObj::LateUpdate(float fDeltaTime)
{
	return 0;
}

void CObj::Collision(float fDeltaTime)
{
}

void CObj::Render(HDC hdc, float fDeltaTime)
{
}

void CObj::AddObj(CObj* pObj)
{
	pObj->AddRef();
	m_ObjList.push_back(pObj);
}

CObj* CObj::FindObject(const string& strTag)
{
	list<CObj*> ::iterator iter;
	list<CObj*> ::iterator iterEnd = m_ObjList.end();

	for (iter = m_ObjList.begin(); iter != iterEnd; ++iter) 
	{
		if ((*iter)->GetTag() == strTag) 
		{
			(*iter)->AddRef();
			return *iter;
		}
	}

	return NULL;
}

void CObj::EraseObj(CObj* pObj)
{
	list<CObj*> ::iterator iter;
	list<CObj*> ::iterator iterEnd = m_ObjList.end();

	for (iter = m_ObjList.begin(); iter != iterEnd; ++iter)
	{
		if (*iter == pObj)
		{
			SAFE_RELEASE((*iter));
			iter = m_ObjList.erase(iter);
			return;
		}
	}
}

void CObj::EraseObj(const string& strTag)
{
	list<CObj*> ::iterator iter;
	list<CObj*> ::iterator iterEnd = m_ObjList.end();

	for (iter = m_ObjList.begin(); iter != iterEnd; ++iter)
	{
		if ((*iter)->GetTag() == strTag)
		{
			SAFE_RELEASE((*iter));
			iter = m_ObjList.erase(iter);
			return;
		}
	}
}

void CObj::EraseObj()
{
	Safe_Release_VecList(m_ObjList);
}

CObj::CObj()
{
}

CObj::CObj(const CObj& obj)
{

}

CObj::~CObj()
{
}
