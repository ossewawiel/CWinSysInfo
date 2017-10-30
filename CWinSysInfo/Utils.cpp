#include "stdafx.h"
#include "Utils.h"

_COMPUTER_NAME_FORMAT Utils::ToComputerNameFormat(const eComputerNameFormat nameFormat)
{
	switch (nameFormat)
	{
	case eComputerNameFormat::cnfDnsDomain:
		return _COMPUTER_NAME_FORMAT::ComputerNameDnsDomain;
		break;
	case eComputerNameFormat::cnfDnsFullyQualified:
		return _COMPUTER_NAME_FORMAT::ComputerNameDnsFullyQualified;
		break;
	case eComputerNameFormat::cnfDnsHostname:
		return _COMPUTER_NAME_FORMAT::ComputerNameDnsHostname;
		break;
	case eComputerNameFormat::cnfMax:
		return _COMPUTER_NAME_FORMAT::ComputerNameMax;
		break;
	case eComputerNameFormat::cnfNetBIOS:
		return _COMPUTER_NAME_FORMAT::ComputerNameNetBIOS;
		break;
	case eComputerNameFormat::cnfPhysicalDnsDomain:
		return _COMPUTER_NAME_FORMAT::ComputerNamePhysicalDnsDomain;
		break;
	case eComputerNameFormat::cnfPhysicalDnsFullyQualified:
		return _COMPUTER_NAME_FORMAT::ComputerNamePhysicalDnsFullyQualified;
		break;
	case eComputerNameFormat::cnfPhysicalDnsHostname:
		return _COMPUTER_NAME_FORMAT::ComputerNamePhysicalDnsHostname;
		break;
	case eComputerNameFormat::cnfPhysicalNetBIOS:
		return _COMPUTER_NAME_FORMAT::ComputerNamePhysicalNetBIOS;
		break;
	default:
		return _COMPUTER_NAME_FORMAT();
	}
	return _COMPUTER_NAME_FORMAT();
}

EXTENDED_NAME_FORMAT Utils::ToExtendedNameFormat(const eExtendedNameFormat nameFormat)
{
	switch (nameFormat)
	{
	case eExtendedNameFormat::enfCanonical:
		return EXTENDED_NAME_FORMAT::NameCanonical;
		break;
	case eExtendedNameFormat::enfCanonicalEx:
		return EXTENDED_NAME_FORMAT::NameCanonicalEx;
		break;
	case eExtendedNameFormat::enfDisplay:
		return EXTENDED_NAME_FORMAT::NameDisplay;
		break;
	case eExtendedNameFormat::enfDnsDomain:
		return EXTENDED_NAME_FORMAT::NameDnsDomain;
		break;
	case eExtendedNameFormat::enfFullyQualifiedDN:
		return EXTENDED_NAME_FORMAT::NameFullyQualifiedDN;
		break;
	case eExtendedNameFormat::enfSamCompatible:
		return EXTENDED_NAME_FORMAT::NameSamCompatible;
		break;
	case eExtendedNameFormat::enfServicePrincipal:
		return EXTENDED_NAME_FORMAT::NameServicePrincipal;
		break;
	case eExtendedNameFormat::enfUniqueId:
		return EXTENDED_NAME_FORMAT::NameUniqueId;
		break;
	default:
		return EXTENDED_NAME_FORMAT();
	}
	return EXTENDED_NAME_FORMAT();
}

