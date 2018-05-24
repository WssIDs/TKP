// dllmain.h : Declaration of module class.

class CSRATL2Module : public ATL::CAtlDllModuleT< CSRATL2Module >
{
public :
	DECLARE_LIBID(LIBID_SRATL2Lib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_SRATL2, "{7b73966c-6b25-4129-a381-010b6a4dec84}")
};

extern class CSRATL2Module _AtlModule;
