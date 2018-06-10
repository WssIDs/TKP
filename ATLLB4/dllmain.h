// dllmain.h : Declaration of module class.

class CATLLB4Module : public ATL::CAtlDllModuleT< CATLLB4Module >
{
public :
	DECLARE_LIBID(LIBID_ATLLB4Lib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATLLB4, "{8BFE8757-6267-453C-999B-F52186D1EFFF}")
};

extern class CATLLB4Module _AtlModule;
