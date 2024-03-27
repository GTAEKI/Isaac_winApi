#pragma once

// 전체적인 헤더파일을 관리할 용도
#include <Windows.h>
#include <list>
#include <vector>
#include <unordered_map>
#include <string>
#include <crtdbg.h> // 메모리 누수를 체크할 수 있는 기능을 제공

using namespace std;

#include "Macro.h"
#include "Types.h"
#include "Flag.h"

#define PI 3.141592f

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

template <typename T>
void Safe_Release_VecList(T& p)
{
	typename T::iterator iter;
	typename T::iterator iterEnd = p.end();

	for (iter = p.begin(); iter != iterEnd; ++iter)
	{
		SAFE_RELEASE((*iter));
	}

	p.clear();
}

template <typename T>
void Safe_Release_Map(T& p)
{
	typename T::iterator iter;
	typename T::iterator iterEnd = p.end();

	for (iter = p.begin(); iter != iterEnd; ++iter)
	{
		SAFE_RELEASE(iter->second);
	}

	p.clear();
}


template <typename T>
void Safe_Delete_Map(T& p)
{
	typename T::iterator iter;
	typename T::iterator iterEnd = p.end();

	for (iter = p.begin(); iter != iterEnd; ++iter)
	{
		SAFE_DELETE(iter->second);
	}

	p.clear();
}