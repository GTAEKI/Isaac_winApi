#pragma once
class CRef
{
public:
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

protected:
	CRef();
	virtual ~CRef() = 0;

	int m_iRef;

};

