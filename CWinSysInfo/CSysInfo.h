// CSysInfo.h : Declaration of the CCSysInfo

#pragma once
#include "resource.h"       // main symbols



#include "CWinSysInfo_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CCSysInfo

class ATL_NO_VTABLE CCSysInfo :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CCSysInfo, &CLSID_CSysInfo>,
	public IDispatchImpl<ICSysInfo, &IID_ICSysInfo, &LIBID_CWinSysInfoLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CCSysInfo()
		: mshCeipIsOptedIn(0)
		, mbLoadedCeipIsOptedIn(false)
	{
		m_pUnkMarshaler = NULL;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_CSYSINFO)


BEGIN_COM_MAP(CCSysInfo)
	COM_INTERFACE_ENTRY(ICSysInfo)
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



	STDMETHOD(get_CeipIsOptedIn)(SHORT* pVal);
private:
	short mshCeipIsOptedIn;
	bool mbLoadedCeipIsOptedIn;
public:
	STDMETHOD(GetComputerNameEx)(eComputerNameFormat nameFormat, BSTR* pbsComputerName);
	STDMETHOD(DnsHostnameToComputerName)(BSTR bsHostName, BSTR* pbsComputerName);
};

OBJECT_ENTRY_AUTO(__uuidof(CSysInfo), CCSysInfo)
