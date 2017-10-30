// CSystemInfo.h : Declaration of the CCSystemInfo

#pragma once
#include "resource.h"       // main symbols



#include "CWinSysInfo_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CCSystemInfo

class ATL_NO_VTABLE CCSystemInfo :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CCSystemInfo, &CLSID_CSystemInfo>,
	public IDispatchImpl<ICSystemInfo, &IID_ICSystemInfo, &LIBID_CWinSysInfoLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CCSystemInfo()
		: mulOemId(0)
		, mucProcessorArchitecture(0)
		, mulPageSize(0)
		, mulMinimumApplicationAddress(0)
		, mulMaximumApplicationAddress(0)
		, mulActiveProcessorMask(0)
		, mulNumberOfProcessors(0)
		, mulProcessorType(0)
		, mulAllocationGranularity(0)
		, mucProcessorLevel(0)
		, mucProcessorRevision(0)
	{
		m_pUnkMarshaler = NULL;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_CSYSTEMINFO)


BEGIN_COM_MAP(CCSystemInfo)
	COM_INTERFACE_ENTRY(ICSystemInfo)
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



	STDMETHOD(Initialise)(ULONG ulOemId, USHORT usProcessorArchitecture, ULONG ulPageSize, ULONG ulMinimumApplicationAddress, ULONG ulMaximumApplicationAddress, ULONG ulActiveProcessorMask, ULONG ulNumberOfProcessors, ULONG ulProcessorType, ULONG ulAllocationGranularity, USHORT usProcessorLevel, USHORT usProcessorRevision);
	STDMETHOD(get_OemId)(ULONG* pVal);
	STDMETHOD(get_ProcessorArchitecture)(USHORT* pVal);
	STDMETHOD(get_PageSize)(ULONG* pVal);
	STDMETHOD(get_MinimumApplicationAddress)(ULONG* pVal);
	STDMETHOD(get_MaximumApplicationAddress)(ULONG* pVal);
	STDMETHOD(get_ActiveProcessorMask)(ULONG* pVal);
	STDMETHOD(get_NumberOfProcessors)(ULONG* pVal);
	STDMETHOD(get_ProcessorType)(ULONG* pVal);
	STDMETHOD(get_AllocationGranularity)(ULONG* pVal);
	STDMETHOD(get_ProcessorLevel)(USHORT* pVal);
	STDMETHOD(get_ProcessorRevision)(USHORT* pVal);
private:
	unsigned long mulOemId;
	unsigned char mucProcessorArchitecture;
	unsigned long mulPageSize;
	unsigned long mulMinimumApplicationAddress;
	unsigned long mulMaximumApplicationAddress;
	unsigned long mulActiveProcessorMask;
	unsigned long mulNumberOfProcessors;
	unsigned long mulProcessorType;
	unsigned long mulAllocationGranularity;
	unsigned char mucProcessorLevel;
	unsigned char mucProcessorRevision;
};

OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO(__uuidof(CSystemInfo), CCSystemInfo)
