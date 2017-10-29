// UnitTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	CoInitializeEx(NULL, COINIT_MULTITHREADED);
	int iRet = RUN_ALL_TESTS();
	CoUninitialize();
	system("pause");
	return iRet;
}

