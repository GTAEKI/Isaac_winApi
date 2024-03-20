﻿#pragma once

// 전체적인 헤더파일을 관리할 용도
#include <Windows.h>
#include <list>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

#include "Macro.h"
#include "Types.h"
#include "Flag.h"

template <typename T>
void Safe_Delete_VecList(T& p) 
{
	typename T::iterator iter;
	typename T::iterator iterEnd = p.end();

	for (iter = p.begin(); iter != iterEnd; ++iter) 
	{
		SAFE_DELETE((*iter));
	}

	p.clear();
}