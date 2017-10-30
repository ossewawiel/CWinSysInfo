// CHwProfileInfo.h : Declaration of the CCHwProfileInfo

#pragma once
#include "resource.h"       // main symbols



#include "CWinSysInfo_i.h"
#include "comutil.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CCHwProfileInfo

class ATL_NO_VTABLE CCHwProfileInfo :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CCHwProfileInfo, &CLSID_CHwProfileInfo>,
	public IDispatchImpl<ICHwProfileInfo, &IID_ICHwProfileInfo, &LIBID_CWinSysInfoLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CCHwProfileInfo()
		: mulDockInfo(0)
	{
		m_pUnkMarshaler = NULL;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_CHWPROFILEINFO)


BEGIN_COM_MAP(CCHwProfileInfo)
	COM_INTERFACE_ENTRY(ICHwProfileInfo)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY_AGGREGATE(IID_IMarshal, m_pUnkMarshaler.p)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()
	DECLARE_GET_CONTROLLING_UNKNOWN()

	HRESULT FinalConstruct()
	{
		return CoCreateFreeThreadedMarshaler(
			GetControllingUnknown(), &m_pUnkMarshaler.p);
	}

	void FinalRelease()
	{
		m_pUnkMarshaler.Release();
	}

	CComPtr<IUnknown> m_pUnkMarshaler;

public:



	STDMETHOD(get_DockInfo)(ULONG* pVal);
	STDMETHOD(get_HwProfileGuid)(BSTR* pVal);
	STDMETHOD(get_HwProfileName)(BSTR* pVal);
	STDMETHOD(Initialise)(ULONG ulDockInfo, BSTR bsHwProfileGuid, BSTR bsHwProfileName);
private:
	unsigned long mulDockInfo;
	_bstr_t mbsHwProfileGuid;
	_bstr_t mbsHwProfileName;
};

OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO(__uuidof(CHwProfileInfo), CCHwProfileInfo)
