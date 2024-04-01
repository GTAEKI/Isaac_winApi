#pragma once

#include "Game.h"

typedef struct _tagKeyInfo 
{
	string strName;
	vector<DWORD> vecKey; // unsigned long 타입으로 키정보, 조합키를 만들기 위함
	bool bDown;
	bool bPress;
	bool bUp;

	_tagKeyInfo()
		:bDown(false)
		, bPress(false)
		, bUp(false) 
	{
	}
}KEYINFO, *PKEYINFO;



class CInput
{
	DECLARE_SINGLE(CInput)

private:
	HWND m_hWnd;
	unordered_map<string, PKEYINFO> m_mapKey;
	PKEYINFO m_pCreateKey; // 재귀함수때문에 만듬
	PKEYINFO FindKey(const string& strKey) const;

public:
	bool Init(HWND hWnd);
	void Update(float fDeltaTime);
	bool KeyDown(const string& strKey) const;
	bool KeyPress(const string& strKey) const;
	bool KeyUp(const string& strKey) const;

	template<typename T>
	bool AddKey(const T& data) // 마지막 함수가 호출되면 여기가 호출되며 끝이난다.
	{
		const char* pTType = typeid(T).name(); //typeid -> 타입의 식별번호가 들어온다. // .name()은 나온값이 문자열로 나온다.
		if (strcmp(pTType, "char") == 0 || strcmp(pTType, "int") == 0)
		{
			m_pCreateKey->vecKey.push_back((DWORD) data);
		}
		else
		{
			m_pCreateKey->strName = data;
			m_mapKey.insert(make_pair(m_pCreateKey->strName, m_pCreateKey));
		}

		return true;
	}

	template<typename T, typename ... Types>
	bool AddKey(const T& data, const Types& ... arg) 
	{
		if (!m_pCreateKey) // 가변템플릿에 의해 재귀로 호출되더라도 한번만 할당됨
		{
			m_pCreateKey = new KEYINFO;
		}

		const char* pTType = typeid(T).name(); //typeid -> 타입의 식별번호가 들어온다. // .name()은 나온값이 문자열로 나온다.
		if (strcmp(pTType, "char") == 0 || strcmp(pTType, "int") == 0) 
		{
			m_pCreateKey->vecKey.push_back((DWORD)data);
		}
		else 
		{
			m_pCreateKey->strName = data;
			m_mapKey.insert(make_pair(m_pCreateKey->strName, m_pCreateKey));
		}

		AddKey(arg...);

		if (m_pCreateKey) 
		{
			m_pCreateKey = NULL;
		}

		return true;
	}
};

