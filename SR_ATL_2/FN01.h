// FN01.h : Declaration of the CFN01

#pragma once
#include "resource.h"       // main symbols



#include "SRATL2_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CFN01

class ATL_NO_VTABLE CFN01 :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFN01, &CLSID_CoFN01>,
	public IDispatchImpl<IFN01, &IID_IFN01, &LIBID_SRATL2Lib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CFN01()
	{
	}

DECLARE_REGISTRY_RESOURCEID(106)


BEGIN_COM_MAP(CFN01)
	COM_INTERFACE_ENTRY(IFN01)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

	STDMETHOD(Fun11)(int a, int b, int* pResult);
	STDMETHOD(Fun12)(int a, int b, int c, float* pResult);
	STDMETHOD(Fun13)(double inValue, double* pResult);

};

OBJECT_ENTRY_AUTO(__uuidof(CoFN01), CFN01)
