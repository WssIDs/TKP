// dllmain.h : Declaration of module class.

class CLABATL4Module : public ATL::CAtlDllModuleT< CLABATL4Module >
{
public :
	DECLARE_LIBID(LIBID_LABATL4Lib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_LABATL4, "{a21469b2-1c01-4562-ae6f-ba0f8305eb82}")
};

extern class CLABATL4Module _AtlModule;
