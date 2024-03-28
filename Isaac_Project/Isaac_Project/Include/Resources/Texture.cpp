#include "Texture.h"
#include "../PathManager.h"


bool CTexture::LoadTexture(HINSTANCE hInst, HDC hdc, const string& strKey, const wchar_t* pFileName, const string& strPathKey)
{
	//메모리 DC를 만들어준다.
	m_hMemDC = CreateCompatibleDC(hdc); // 삽입한 화면 DC용 메모리 DC가 만들어진다.

	// 전체 경로를 만들어준다.
	const wchar_t* pPath = GET_SINGLE(CPathManager)->FindPath(strPathKey);

	wstring strPath;
	if (pPath) 
	{
		strPath = pPath;
	}

	strPath += pFileName;

	m_hBitmap = (HBITMAP)LoadImage(hInst, strPath.c_str(), IMAGE_BITMAP, 0,0, LR_LOADFROMFILE);  //0,0 은 원본이미지

	// 위에서 만들어준 비트맵 도구를 DC에 지정한다.
	// 지정할때 반환되는 값은 DC에 기본으로 지정되어있던 도구가 반환된다.
	m_hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBitmap);

	GetObject(m_hBitmap, sizeof(m_tInfo), &m_tInfo); // 가로세로크기, 이미지 크기를 손쉽게 값으로 갖게 된다.

	return true;
}

CTexture::CTexture()
	:m_hMemDC(NULL)
{
}

CTexture::~CTexture()
{
	// 기존에 지정되어있던 도구를 다시 지정
	SelectObject(m_hMemDC, m_hOldBitmap);

	// Bitmap을 지워준다.
	DeleteObject(m_hBitmap);

	// DC를 지워준다.
	DeleteDC(m_hMemDC);
}
