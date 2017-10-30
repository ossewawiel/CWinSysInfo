#include "stdafx.h"
#include "Test_CSysInfo.h"


TEST_F(Test_CSysInfo, if_get_ceipisoptedin_called_then_expect_zero_or_one)
{
	short shReturned(0);
	HRESULT hr = mpSysInfo->get_CeipIsOptedIn(&shReturned);
	ASSERT_FALSE(hr) << TUtils::GetLastErrorAsString(hr);
	ASSERT_TRUE(shReturned == 0 || shReturned == 1);
}

TEST_F(Test_CSysInfo, if_getcomputernameex_called_with_valid_name_format_then_expect_valid_computer_name)
{
	_bstr_t retVal(L"");
	HRESULT hr = mpSysInfo->GetComputerNameEx(eComputerNameFormat::cnfNetBIOS, retVal.GetAddress());
	ASSERT_FALSE(hr) << TUtils::GetLastErrorAsString(hr);
	ASSERT_TRUE(retVal.length() > 0);
}

TEST_F(Test_CSysInfo, if_dnshostnametocomputername_called_with_valid_names_then_expect_valid_computer_name)
{
	_bstr_t bsDns(L"");
	HRESULT hr = mpSysInfo->GetComputerNameEx(eComputerNameFormat::cnfDnsFullyQualified, bsDns.GetAddress());
	ASSERT_FALSE(hr) << TUtils::GetLastErrorAsString(hr);
	ASSERT_TRUE(bsDns.length() > 0);

	_bstr_t retVal(L"");
	hr = mpSysInfo->DnsHostnameToComputerName(bsDns, retVal.GetAddress());
	ASSERT_FALSE(hr) << TUtils::GetLastErrorAsString(hr);
	ASSERT_TRUE(retVal.length() > 0);
}

TEST_F(Test_CSysInfo, if_getcomputername_called_with_valid_name_format_then_expect_valid_computer_name)
{
	_bstr_t retVal(L"");
	HRESULT hr = mpSysInfo->GetComputerName(retVal.GetAddress());
	ASSERT_FALSE(hr) << TUtils::GetLastErrorAsString(hr);
	ASSERT_TRUE(retVal.length() > 0);
}

TEST_F(Test_CSysInfo, if_getcomputerobjectname_called_with_valid_name_format_then_expect_valid_computer_name)
{
	_bstr_t retVal(L"");
	HRESULT hr = mpSysInfo->GetComputerObjectName(eExtendedNameFormat::enfDisplay, retVal.GetAddress());
	ASSERT_FALSE(hr) << TUtils::GetLastErrorAsString(hr);
	ASSERT_TRUE(retVal.length() > 0);
}

TEST_F(Test_CSysInfo, if_getcurrenthwprofile_called_then_expect_valid_hwprofileinfo)
{
	CComPtr<ICHwProfileInfo> pHwProfileInfo;
	HRESULT hr = mpSysInfo->GetCurrentHwProfile(&pHwProfileInfo);
	ASSERT_FALSE(hr) << TUtils::GetLastErrorAsString(hr);
	ASSERT_TRUE(pHwProfileInfo != NULL) << L"pHwProfileInfo = NULL";

	DWORD dwDocInfo(0);
	hr = pHwProfileInfo->get_DockInfo(&dwDocInfo);
	ASSERT_FALSE(hr) << TUtils::GetLastErrorAsString(hr);
	ASSERT_TRUE(dwDocInfo != 0) << L"pHwProfileInfo: dwDocInfo = 0";

	_bstr_t bsHwProfileGuid(L"");
	hr = pHwProfileInfo->get_HwProfileGuid(bsHwProfileGuid.GetAddress());
	ASSERT_FALSE(hr) << TUtils::GetLastErrorAsString(hr);
	ASSERT_TRUE(bsHwProfileGuid.length() != 0) << L"pHwProfileInfo: bsHwProfileGuid.length() = 0";

	_bstr_t bsHwProfileName(L"");
	hr = pHwProfileInfo->get_HwProfileName(bsHwProfileName.GetAddress());
	ASSERT_FALSE(hr) << TUtils::GetLastErrorAsString(hr);
	ASSERT_TRUE(bsHwProfileName.length() != 0) << L"pHwProfileInfo: bsHwProfileName.length() = 0";
}

TEST_F(Test_CSysInfo, if_getsysteminfo_called_then_expect_valid_systeminfo)
{
	CComPtr<ICSystemInfo> pSystemInfo;
	HRESULT hr = mpSysInfo->GetSystemInfo(&pSystemInfo);
	ASSERT_FALSE(hr) << TUtils::GetLastErrorAsString(hr);
	ASSERT_TRUE(pSystemInfo != NULL) << L"pSystemInfo = NULL";

	ULONG ulOemId(0);
	hr = pSystemInfo->get_OemId(&ulOemId);
	ASSERT_FALSE(hr) << TUtils::GetLastErrorAsString(hr);
	ASSERT_TRUE(ulOemId >= 0) << L"pSystemInfo: ulOemId < 0";
	
	USHORT usProcArchitecture(0);
	hr = pSystemInfo->get_ProcessorArchitecture(&usProcArchitecture);
	ASSERT_FALSE(hr) << TUtils::GetLastErrorAsString(hr);
	ASSERT_TRUE(usProcArchitecture >= 0) << L"pSystemInfo: usProcArchitecture < 0";

	ULONG ulPageSize(0);
	hr = pSystemInfo->get_PageSize(&ulPageSize);
	ASSERT_FALSE(hr) << TUtils::GetLastErrorAsString(hr);
	ASSERT_TRUE(ulPageSize != 0) << L"pSystemInfo: ulPageSize = 0";

	ULONG ulMinAppAddress(0);
	hr = pSystemInfo->get_MinimumApplicationAddress(&ulMinAppAddress);
	ASSERT_FALSE(hr) << TUtils::GetLastErrorAsString(hr);
	ASSERT_TRUE(ulMinAppAddress != 0) << L"pSystemInfo: ulMinAppAddress = 0";

	ULONG ulMaxAppAddress(0);
	hr = pSystemInfo->get_MaximumApplicationAddress(&ulMaxAppAddress);
	ASSERT_FALSE(hr) << TUtils::GetLastErrorAsString(hr);
	ASSERT_TRUE(ulMaxAppAddress != 0) << L"pSystemInfo: ulMaxAppAddress = 0";

	ULONG ulActProcMask(0);
	hr = pSystemInfo->get_ActiveProcessorMask(&ulActProcMask);
	ASSERT_FALSE(hr) << TUtils::GetLastErrorAsString(hr);
	ASSERT_TRUE(ulActProcMask != 0) << L"pSystemInfo: ulActProcMask = 0";

	ULONG ulNumProcs(0);
	hr = pSystemInfo->get_NumberOfProcessors(&ulNumProcs);
	ASSERT_FALSE(hr) << TUtils::GetLastErrorAsString(hr);
	ASSERT_TRUE(ulNumProcs != 0) << L"pSystemInfo: ulNumProcs = 0";

	ULONG ulProcType(0);
	hr = pSystemInfo->get_ProcessorType(&ulProcType);
	ASSERT_FALSE(hr) << TUtils::GetLastErrorAsString(hr);
	ASSERT_TRUE(ulProcType != 0) << L"pSystemInfo: ulProcType = 0";

	ULONG ulAllocGranularity(0);
	hr = pSystemInfo->get_AllocationGranularity(&ulAllocGranularity);
	ASSERT_FALSE(hr) << TUtils::GetLastErrorAsString(hr);
	ASSERT_TRUE(ulAllocGranularity != 0) << L"pSystemInfo: ulAllocGranularity = 0";

	USHORT usProcLevel(0);
	hr = pSystemInfo->get_ProcessorLevel(&usProcLevel);
	ASSERT_FALSE(hr) << TUtils::GetLastErrorAsString(hr);
	ASSERT_TRUE(usProcLevel != 0) << L"pSystemInfo: usProcLevel = 0";

	USHORT usProcRevision(0);
	hr = pSystemInfo->get_ProcessorRevision(&usProcRevision);
	ASSERT_FALSE(hr) << TUtils::GetLastErrorAsString(hr);
	ASSERT_TRUE(usProcRevision != 0) << L"pSystemInfo: usProcRevision = 0";
}


