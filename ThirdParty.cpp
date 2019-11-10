#pragma once
#include "ThirdParty.h"

ThirdParty::ThirdParty()
{
	ID = 0;
	name = "INVALID NAME";
	serviceType = "INVALID TYPE";
}

ThirdParty::ThirdParty(int id, string Name, string servicetype)
{
	ID = id;
	name = Name;
	serviceType = servicetype;
}

int ThirdParty::getID()
{
	return ID;
}
string ThirdParty::getName()
{
	return name;
}
string ThirdParty::getService()
{
	return serviceType;
}