#pragma once

#include "../Game.h"

class Layer
{
public:
	void SetTag(const string& strTag) 
	{
		m_strTag = strTag;
	}

	void SetZOrder(int iZOrder) 
	{
		m_iZOrder = iZOrder;
	}

	int GetZOrder() const 
	{
		return m_iZOrder;
	}

	string GetTag() const 
	{
		return m_strTag;
	}

	~Layer();

private:
	// 씬 통해서만 생성하게 할 것이다.
	friend class CScene;

	Layer();

	string m_strTag;//태그
	int m_iZOrder; // 레이어 순서



};

