#include "CollisionManager.h"
#include "../Object/Obj.h"
#include "../Collider/Collider.h"

DEFINITION_SINGLE(CCollisionManager)

CCollisionManager::CCollisionManager()
{
}

CCollisionManager::~CCollisionManager()
{
}

void CCollisionManager::AddObject(CObj* pObj)
{
	if (pObj->CheckCollider())  // 충돌체를 갖고있다면
	{
		m_CollisionList.push_back(pObj);
	}
	else  //충돌체를 갖고있지 않다면
	{
		
	}
}

void CCollisionManager::Collision(float fDeltaTime)
{
	if (m_CollisionList.size() < 2) // 1개 이하라면. 부딪힐 이유가 없음
	{
		m_CollisionList.clear();
		return;
	}

	// 제일 단순한 완전탐색을 해보자. 이중포문으로 전체 충돌처리 검사
	list<CObj*>::iterator iter;
	list<CObj*>::iterator iterEnd = m_CollisionList.end();
	
	for (iter = m_CollisionList.begin(); iter != prev(iterEnd); ++iter) 
	{
		list<CObj*>::iterator innerIter = next(iter);
		for (; innerIter != iterEnd; ++innerIter) 
		{
			Collision(*iter, *innerIter, fDeltaTime);
		}
	}

	m_CollisionList.clear();
}

bool CCollisionManager::Collision(CObj* pSrc, CObj* pDest, float fDeltaTime)
{
	const list<CCollider*>* pSrcList = pSrc->GetColliderList();
	const list<CCollider*>* pDestList = pDest->GetColliderList();

	list<CCollider*>::const_iterator iterSrc;
	list<CCollider*>::const_iterator iterSrcEnd = pSrcList->end();

	list<CCollider*>::const_iterator iterDest;
	list<CCollider*>::const_iterator iterDestEnd = pDestList->end();

	bool bCollision = false;

	for (iterSrc = pSrcList->begin(); iterSrc != iterSrcEnd; ++iterSrc) 
	{
		for (iterDest = pDestList->begin(); iterDest != iterDestEnd; ++iterDest)
		{
			if ((*iterSrc)->Collision(*iterDest)) 
			{
				bCollision = true;

				// 충돌목록에서 이전에 충돌된적이 없다면 처음 막 충돌되었다는 의미이다.
				if ((*iterSrc)->CheckCollisionList(*iterDest)) 
				{
					//서로 상대방을 충돌 목골으로 추가한다.
					(*iterSrc)->AddCollider(*iterDest);
					(*iterDest)->AddCollider(*iterSrc);

					(*iterSrc)->CallFunction(CS_ENTER, *iterDest, fDeltaTime);
					(*iterDest)->CallFunction(CS_ENTER, *iterSrc, fDeltaTime);
				}
				// 기존 충돌된 적이 있다면 계속 충돌상태인 것
				else 
				{
					(*iterSrc)->CallFunction(CS_STAY, *iterDest, fDeltaTime);
					(*iterDest)->CallFunction(CS_STAY, *iterSrc, fDeltaTime);
				}
			}
			// 이전에 충돌이 되고있었다면 이제 막 충돌이 떨어진 것
			else if((*iterSrc)->CheckCollisionList(*iterDest))
			{
				// 서로 충돌이 안되므로 충돌목록에서 지워줌
				(*iterSrc)->EraseCollisionList(*iterDest);
				(*iterDest)->EraseCollisionList(*iterSrc);

				(*iterSrc)->CallFunction(CS_LEAVE, *iterDest, fDeltaTime);
				(*iterDest)->CallFunction(CS_LEAVE, *iterSrc, fDeltaTime);

			}
		}
	}

	return bCollision;
}
