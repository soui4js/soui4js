#pragma once
namespace qjsbind {
	template<class T>
	class JsProxy
	{
	public:
		JsProxy(T* _pObj, bool _bOwner = false) : bOwner(_bOwner) {
			pObj = _pObj;
		}

		~JsProxy() {
			if (bOwner) delete pObj;
		}

		T* GetObj() {
			return pObj;
		}
		bool IsOwner() const {
			return bOwner;
		}
	private:
		T* pObj;
		bool bOwner;
	};
}