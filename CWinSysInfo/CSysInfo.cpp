// CSysInfo.cpp : Implementation of CCSysInfo

#include "stdafx.h"
#include "CSysInfo.h"
#include "Utils.h"
#include "CHwProfileInfo.h"
#include "CSystemInfo.h"
// CCSysInfo



STDMETHODIMP CCSysInfo::get_CeipIsOptedIn(SHORT* pVal)
{
	if (!mbLoadedCeipIsOptedIn)
	{
		mshCeipIsOptedIn = (::CeipIsOptedIn()) ? 1 : 0;
		mbLoadedCeipIsOptedIn = true;
	}
	*pVal = mshCeipIsOptedIn;
	return S_OK;
}


STDMETHODIMP CCSysInfo::GetComputerNameEx(eComputerNameFormat nameFormat, BSTR* pbsComputerName)
{
	COMPUTER_NAME_FORMAT cnf(Utils::ToComputerNameFormat(nameFormat));
	TCHAR buffer[256] = L"";
	DWORD dwSize(sizeof(buffer));
	BOOL bResult(::GetComputerNameEx(cnf, buffer, &dwSize));
	if (!bResult) return ::GetLastError();
	*pbsComputerName = _bstr_t(buffer).copy();
	return S_OK;
}


STDMETHODIMP CCSysInfo::DnsHostnameToComputerName(BSTR bsHostName, BSTR* pbsComputerName)
{
	_bstr_t hostName(bsHostName);
	TCHAR buffer[256] = L"";
	DWORD dwSize(sizeof(buffer));
	BOOL bResult(::DnsHostnameToComputerName((LPCTSTR)hostName, buffer, &dwSize));
	if (!bResult) return ::GetLastError();
	*pbsComputerName = _bstr_t(buffer).copy();
	return S_OK;
}


STDMETHODIMP CCSysInfo::GetComputerName(BSTR* pbsComputerName)
{
	TCHAR buffer[256] = L"";
	DWORD dwSize(sizeof(buffer));
	BOOL bResult(::GetComputerName(buffer, &dwSize));
	if (!bResult) return ::GetLastError();
	*pbsComputerName = _bstr_t(buffer).copy();
	return S_OK;
}


STDMETHODIMP CCSysInfo::GetComputerObjectName(eExtendedNameFormat nameFormat, BSTR* pbsComputerName)
{
	EXTENDED_NAME_FORMAT enf(Utils::ToExtendedNameFormat(nameFormat));
	TCHAR buffer[256] = L"";
	DWORD dwSize(sizeof(buffer));
	BOOL bResult(::GetComputerObjectName(enf, buffer, &dwSize));
	if (!bResult) return ::GetLastError();
	*pbsComputerName = _bstr_t(buffer).copy();
	return S_OK;
}


STDMETHODIMP CCSysInfo::GetCurrentHwProfile(ICHwProfileInfo** ppHwProfileInfo)
{
	HRESULT hr(CCHwProfileInfo::CreateInstance(ppHwProfileInfo));
	if (hr) return hr;
	HW_PROFILE_INFO hwProfileInfo;
	if(!::GetCurrentHwProfile(&hwProfileInfo)) return ::GetLastError();
	if (hr = (*ppHwProfileInfo)->Initialise(
		  hwProfileInfo.dwDockInfo
		, _bstr_t(hwProfileInfo.szHwProfileGuid)
		, _bstr_t(hwProfileInfo.szHwProfileName)
	)) return hr;
	return S_OK;
}


STDMETHODIMP CCSysInfo::GetSystemInfo(ICSystemInfo** ppSystemInfo)
{
	HRESULT hr(CCSystemInfo::CreateInstance(ppSystemInfo));
	if (hr) return hr;
	SYSTEM_INFO siSysInfo;
	::GetSystemInfo(&siSysInfo);
	if (hr = (*ppSystemInfo)->Initialise(
		siSysInfo.dwOemId
		, siSysInfo.wProcessorArchitecture
		, siSysInfo.dwPageSize
		, (DWORD)siSysInfo.lpMinimumApplicationAddress
		, (DWORD)siSysInfo.lpMaximumApplicationAddress
		, siSysInfo.dwActiveProcessorMask
		, siSysInfo.dwNumberOfProcessors
		, siSysInfo.dwProcessorType
		, siSysInfo.dwAllocationGranularity
		, siSysInfo.wProcessorLevel
		, siSysInfo.wProcessorRevision
	)) return hr;
	return S_OK;
}
