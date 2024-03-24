#pragma once
class Ref
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
	Ref();
	virtual ~Ref() = 0;

	int m_iRef;

};

