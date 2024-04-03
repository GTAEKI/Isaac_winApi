#pragma once

// 전체적인 헤더파일을 관리할 용도
#include <Windows.h>
#include <list>
#include <vector>
#include <unordered_map>
#include <string>
#include <crtdbg.h> // 메모리 누수를 체크할 수 있는 기능을 제공
#include <typeInfo>
#include <functional> // functional 함수포인터

using namespace std;

#include "Macro.h"
#include "Types.h"
#include "Flag.h"

// 텍스처를 사용할때 필요한 라이브러리 <- 기본적으로 윈도우에서 제공해주는 정적 라이브러리
#pragma comment(lib, "msimg32") // 아래는 코드로 링크를 거는 방법이다.

#define PI 3.141592f

// Path Key
#define ROOT_PATH "RootPath"
#define TEXTURE_PATH "TexturePath"

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