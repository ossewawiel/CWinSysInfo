// CSysInfo.cpp : Implementation of CCSysInfo

#include "stdafx.h"
#include "CSysInfo.h"
#include "Utils.h"

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
