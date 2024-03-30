#pragma once

#include "../Ref.h"
#include "../Game.h"

class CTexture :
    public CRef
{
private:
    friend class CResourcesManager;

    HDC m_hMemDC; // 화면 DC를 활용해서 Pixel정보를 담아두는 DC
    HBITMAP m_hBitmap; // 비트맵 컨트롤위한 핸들
    HBITMAP m_hOldBitmap; // 추후 되돌려주기 위한 비트맵
    BITMAP m_tInfo;

    CTexture();
    ~CTexture();

public:
    bool LoadTexture(HINSTANCE hInst, HDC hdc, const string& strKey, const wchar_t* pFileName, const string& strPathKey = TEXTURE_PATH);
    HDC GetDC() const 
    {
        return m_hMemDC;
    }
};

