#include "CCore.h"


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	if (!CCore::GetInst()->Init(hInstance)) 
	{
		CCore::DestroyInst();
		return 0;
	}
	
	int iRev = CCore::GetInst()->Run();

	CCore::DestroyInst();

	return iRev; 
}