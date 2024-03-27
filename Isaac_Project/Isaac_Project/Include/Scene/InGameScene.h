#pragma once
#include "Scene.h"

class CInGameScene :
    public CScene
{

public:
    virtual bool Init();


private:
    friend class CSceneManager;

    CInGameScene();
    ~CInGameScene();
};

