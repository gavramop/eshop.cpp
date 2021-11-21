#include "Owner.h"

std::vector<std::string> Owner::getOwnerData()
{
	return ownernameData;
}
void Owner::LoadOwnernameData(std::vector<std::string> _ownernameData)
{
	ownernameData = _ownernameData;
}
void Owner::SetOwnername(std::string n)
{
	oname = n;
}
std::string Owner::getOwnername()
{
	return oname;
}
void Owner::SetoEmail(std::string o)
{
	oemail = o;
}
std::string Owner::GetoEmail()
{
	return oemail;
}
