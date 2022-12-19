#pragma once
namespace qjsbind {
	template<class T>
	class JsProxy
	{
	public:
		JsProxy(T* _pObj, bool _bOwner = false) :nRef(1), bOwner(_bOwner) {
			pObj = _pObj;
		}

		~JsProxy() {
			if (bOwner) delete pObj;
		}

		T* GetObj() {
			return pObj;
		}

		long AddRef() {
			return InterlockedIncrement(&nRef);
		}
		long Release() {
			int nRet = InterlockedDecrement(&nRef);
			if (nRet == 0) {
				delete this;
			}
			return nRet;
		}
	private:
		T* pObj;
		bool bOwner;
		volatile long nRef;
	};
}