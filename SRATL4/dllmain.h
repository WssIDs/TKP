// dllmain.h : Declaration of module class.

class CSRATL4Module : public ATL::CAtlDllModuleT< CSRATL4Module >
{
public :
	DECLARE_LIBID(LIBID_SRATL4Lib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_SRATL4, "{52BB77FF-E687-4532-97A0-DA016163ED27}")
};

extern class CSRATL4Module _AtlModule;
