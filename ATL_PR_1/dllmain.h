// dllmain.h : Declaration of module class.

class CATLPR1Module : public ATL::CAtlDllModuleT< CATLPR1Module >
{
public :
	DECLARE_LIBID(LIBID_ATLPR1Lib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATLPR1, "{d3c8bde6-0546-456b-9fd1-4b29f96b9133}")
};

extern class CATLPR1Module _AtlModule;
