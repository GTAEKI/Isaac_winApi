#pragma once

#include "../Game.h"

class CResourcesManager
{
	DECLARE_SINGLE(CResourcesManager)
public:
	class CTexture* CLoadTexture(const string& strKey, const wchar_t* pFileName, const string& strPathKey);
private:
	unordered_map<string, class CTexture*> m_mapTexture;
};

