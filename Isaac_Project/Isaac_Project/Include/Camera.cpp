#include "Camera.h"
#include "Object/Obj.h"

DEFINITION_SINGLE(CCamera)

CCamera::CCamera()
	:m_pTarget(NULL)
{
}

CCamera::~CCamera()
{
	SAFE_RELEASE(m_pTarget);
}

bool CCamera::Init(const POSITION& tPos, const RESOLUTION& tRS, const RESOLUTION& tWorldRS)
{


	return true;
}

void CCamera::Input(float fDeltaTime)
{
}

void CCamera::Update(float fDeltaTime)
{
}

void CCamera::SetTarget(CObj* pObj)
{
	SAFE_RELEASE(m_pTarget)
	m_pTarget = pObj;
}
