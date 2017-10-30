// CHwProfileInfo.cpp : Implementation of CCHwProfileInfo

#include "stdafx.h"
#include "CHwProfileInfo.h"


// CCHwProfileInfo



STDMETHODIMP CCHwProfileInfo::get_DockInfo(ULONG* pVal)
{
	*pVal = mulDockInfo;
	return S_OK;
}


STDMETHODIMP CCHwProfileInfo::get_HwProfileGuid(BSTR* pVal)
{
	*pVal = mbsHwProfileGuid.copy();
	return S_OK;
}


STDMETHODIMP CCHwProfileInfo::get_HwProfileName(BSTR* pVal)
{
	*pVal = mbsHwProfileName.copy();
	return S_OK;
}


STDMETHODIMP CCHwProfileInfo::Initialise(ULONG ulDockInfo, BSTR bsHwProfileGuid, BSTR bsHwProfileName)
{
	mulDockInfo = ulDockInfo;
	mbsHwProfileGuid.Assign(bsHwProfileGuid);
	mbsHwProfileName.Assign(bsHwProfileName);
	return S_OK;
}
