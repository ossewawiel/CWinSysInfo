// dllmain.h : Declaration of module class.

class CCWinSysInfoModule : public ATL::CAtlDllModuleT< CCWinSysInfoModule >
{
public :
	DECLARE_LIBID(LIBID_CWinSysInfoLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_CWINSYSINFO, "{F385BFAE-75E1-4675-B4B6-947C6799B036}")
};

extern class CCWinSysInfoModule _AtlModule;
