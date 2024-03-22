#pragma once

#include "../Game.h"

class Obj
{
public:
	virtual bool Init();
	virtual void Input(float fDeltaTime);
	virtual int Update(float fDeltaTime);
	virtual int LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hdc, float fDeltaTime);

	void AddRef() 
	{
		++m_iRef;
	}

	int Release() 
	{
		--m_iRef;
		if (m_iRef == 0) 
		{
			delete this;
			return 0;
		}

		return m_iRef;
	}

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


protected:
	Obj();
	virtual ~Obj();

	string m_strTag;
	POSITION m_tPos;
	_SIZE m_tSize;

	int m_iRef;
};

