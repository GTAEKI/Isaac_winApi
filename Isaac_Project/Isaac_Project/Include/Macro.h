#pragma once

#define SAFE_DELETE(p) if(p) {delete p; p = NULL;}
#define SAFE_DELETE_ARRAY(p) if(p) {delete[] p; p = NULL;}
#define SAFE_RELEASE(p) if(p) {p->Release(); p=NULL;}

// 싱글톤 클래스를 만들어주는 매크로
// 변수가 들어올 수도있고 타입이 들어올 수도 있음 \를 통해 줄을 나눠줄 수 있다.
// 매크로는 디버깅이 안된다. 싱글톤은 정형화되어있으니 매크로로 사용하였다.
#define DECLARE_SINGLE(Type) \
	private:\
		static Type* m_pInst;\
	public:\
		static Type* GetInst()\
			{\
				if(!m_pInst)\
				{\
					m_pInst = new Type;\
				}\
				return m_pInst;\
			}\
		static void DestroyInst()\
		{\
			SAFE_DELETE(m_pInst);\
		}\
	private:\
		Type();\
		~Type();

#define DEFINITION_SINGLE(Type) Type* Type::m_pInst = NULL;
#define GET_SINGLE(Type) Type::GetInst()
#define DESTROY_SINGLE(Type) Type::DestroyInst()
