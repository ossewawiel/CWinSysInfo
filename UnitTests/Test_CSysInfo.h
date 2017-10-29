#pragma once
#include "stdafx.h"
#include "TUtils.h"

class Test_CSysInfo :
	public ::testing::Test
{
public:
	CComPtr<ICSysInfo> mpSysInfo;

	void SetUp()
	{
		HRESULT hr = mpSysInfo.CoCreateInstance(CLSID_CSysInfo);
		ASSERT_FALSE(hr) << TUtils::GetLastErrorAsString(hr);
	}

	void TearDown()
	{
		mpSysInfo.Release();
	}
};

