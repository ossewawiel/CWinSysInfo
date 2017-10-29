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
	HRESULT hr = mpSysInfo->GetComputerNameEx(eComputerNameFormat::NetBIOS, retVal.GetAddress());
	ASSERT_FALSE(hr) << TUtils::GetLastErrorAsString(hr);
	ASSERT_TRUE(retVal.length() > 0);
}

TEST_F(Test_CSysInfo, if_dnshostnametocomputername_called_with_valid_names_then_expect_valid_computer_name)
{
	_bstr_t bsDns(L"");
	HRESULT hr = mpSysInfo->GetComputerNameEx(eComputerNameFormat::DnsFullyQualified, bsDns.GetAddress());
	ASSERT_FALSE(hr) << TUtils::GetLastErrorAsString(hr);
	ASSERT_TRUE(bsDns.length() > 0);

	_bstr_t retVal(L"");
	hr = mpSysInfo->DnsHostnameToComputerName(bsDns, retVal.GetAddress());
	ASSERT_FALSE(hr) << TUtils::GetLastErrorAsString(hr);
	ASSERT_TRUE(retVal.length() > 0);
}
