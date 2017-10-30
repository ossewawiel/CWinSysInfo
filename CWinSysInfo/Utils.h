#pragma once
#include "CWinSysInfo_i.h"

namespace Utils
{
	_COMPUTER_NAME_FORMAT ToComputerNameFormat(const eComputerNameFormat nameFormat);
	EXTENDED_NAME_FORMAT ToExtendedNameFormat(const eExtendedNameFormat nameFormat);
}