#include "stdafx.h"
#include "Utils.h"

_COMPUTER_NAME_FORMAT Utils::ToComputerNameFormat(const eComputerNameFormat nameFormat)
{
	switch (nameFormat)
	{
	case eComputerNameFormat::DnsDomain:
		return _COMPUTER_NAME_FORMAT::ComputerNameDnsDomain;
		break;
	case eComputerNameFormat::DnsFullyQualified:
		return _COMPUTER_NAME_FORMAT::ComputerNameDnsFullyQualified;
		break;
	case eComputerNameFormat::DnsHostname:
		return _COMPUTER_NAME_FORMAT::ComputerNameDnsHostname;
		break;
	case eComputerNameFormat::Max:
		return _COMPUTER_NAME_FORMAT::ComputerNameMax;
		break;
	case eComputerNameFormat::NetBIOS:
		return _COMPUTER_NAME_FORMAT::ComputerNameNetBIOS;
		break;
	case eComputerNameFormat::PhysicalDnsDomain:
		return _COMPUTER_NAME_FORMAT::ComputerNamePhysicalDnsDomain;
		break;
	case eComputerNameFormat::PhysicalDnsFullyQualified:
		return _COMPUTER_NAME_FORMAT::ComputerNamePhysicalDnsFullyQualified;
		break;
	case eComputerNameFormat::PhysicalDnsHostname:
		return _COMPUTER_NAME_FORMAT::ComputerNamePhysicalDnsHostname;
		break;
	case eComputerNameFormat::PhysicalNetBIOS:
		return _COMPUTER_NAME_FORMAT::ComputerNamePhysicalNetBIOS;
		break;
	default:
		return _COMPUTER_NAME_FORMAT();
	}
	return _COMPUTER_NAME_FORMAT();
}
