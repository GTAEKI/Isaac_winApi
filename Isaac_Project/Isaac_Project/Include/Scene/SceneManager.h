#pragma once

#include "../Game.h"

class CSceneManager
{
	DECLARE_SINGLE(CSceneManager);

public:
	bool Init();

	//class CScene* CreateScene(SCENE_TYPE eType);
	template<typename T>
	T* CreateScene(SCENE_CREATE sc) 
	{
		T* pScene = new T;

		if (!pScene->Init()) 
		{
			SAFE_DELETE(pScene);
			return NULL;
		}

		switch (sc) 
		{
		case SC_CURRENT:
			SAFE_DELETE(m_pScene);
			m_pScene = pScene;
			break;
		case SC_NEXT:
			SAFE_DELETE(m_pScene);
			m_pNextScene = pScene;
			break;
		}

		return pScene;
	}


private:
	class CScene* m_pScene;
	class CScene* m_pNextScene;
};

