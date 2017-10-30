// CSystemInfo.cpp : Implementation of CCSystemInfo

#include "stdafx.h"
#include "CSystemInfo.h"


// CCSystemInfo



STDMETHODIMP CCSystemInfo::Initialise(ULONG ulOemId, USHORT usProcessorArchitecture, ULONG ulPageSize, ULONG ulMinimumApplicationAddress, ULONG ulMaximumApplicationAddress, ULONG ulActiveProcessorMask, ULONG ulNumberOfProcessors, ULONG ulProcessorType, ULONG ulAllocationGranularity, USHORT usProcessorLevel, USHORT usProcessorRevision)
{
	mulOemId = ulOemId;
	mucProcessorArchitecture = usProcessorArchitecture;
	mulPageSize = ulPageSize;
	mulMinimumApplicationAddress = ulMinimumApplicationAddress;
	mulMaximumApplicationAddress = ulMaximumApplicationAddress;
	mulActiveProcessorMask = ulActiveProcessorMask;
	mulNumberOfProcessors = ulNumberOfProcessors;
	mulProcessorType = ulProcessorType;
	mulAllocationGranularity = ulAllocationGranularity;
	mucProcessorLevel = usProcessorLevel;
	mucProcessorRevision = usProcessorRevision;
	return S_OK;
}


STDMETHODIMP CCSystemInfo::get_OemId(ULONG* pVal)
{
	*pVal = mulOemId;
	return S_OK;
}


STDMETHODIMP CCSystemInfo::get_ProcessorArchitecture(USHORT* pVal)
{
	*pVal = mucProcessorArchitecture;
	return S_OK;
}


STDMETHODIMP CCSystemInfo::get_PageSize(ULONG* pVal)
{
	*pVal = mulPageSize;
	return S_OK;
}


STDMETHODIMP CCSystemInfo::get_MinimumApplicationAddress(ULONG* pVal)
{
	*pVal = mulMinimumApplicationAddress;
	return S_OK;
}


STDMETHODIMP CCSystemInfo::get_MaximumApplicationAddress(ULONG* pVal)
{
	*pVal = mulMaximumApplicationAddress;
	return S_OK;
}


STDMETHODIMP CCSystemInfo::get_ActiveProcessorMask(ULONG* pVal)
{
	*pVal = mulActiveProcessorMask;
	return S_OK;
}


STDMETHODIMP CCSystemInfo::get_NumberOfProcessors(ULONG* pVal)
{
	*pVal = mulNumberOfProcessors;
	return S_OK;
}


STDMETHODIMP CCSystemInfo::get_ProcessorType(ULONG* pVal)
{
	*pVal = mulProcessorType;
	return S_OK;
}


STDMETHODIMP CCSystemInfo::get_AllocationGranularity(ULONG* pVal)
{
	*pVal = mulAllocationGranularity;
	return S_OK;
}


STDMETHODIMP CCSystemInfo::get_ProcessorLevel(USHORT* pVal)
{
	*pVal = mucProcessorLevel;
	return S_OK;
}


STDMETHODIMP CCSystemInfo::get_ProcessorRevision(USHORT* pVal)
{
	*pVal = mucProcessorRevision;
	return S_OK;
}
