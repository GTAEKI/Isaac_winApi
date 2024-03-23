#pragma once
#include "Scene.h"

class CInGameScene :
    public CScene
{

public:
    virtual bool Init();
    /*virtual void Input(float fDeltaTime);
    virtual int Update(float fDeltaTime);
    virtual int LateUpdate(float fDeltaTime);
    virtual void Collision(float fDeltaTime);
    virtual void Render(HDC hdc, float fDeltaTime);*/


private:
    friend class CSceneManager;

    CInGameScene();
    ~CInGameScene();
};

