#pragma once

#include "Game.h"

class CPathManager
{
	DECLARE_SINGLE(CPathManager)

private:
	// wstring : 유니코드, 2바이트 string
	unordered_map<string, wstring> m_mapPath;

public:
	bool Init();
	bool CreatePath(const string& strKey, const wchar_t* pPath, const string& strBaseKey = ROOT_PATH);
	const wchar_t* FindPath(const string& strKey);

};

