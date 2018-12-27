#include "vintage_port.h"

VintagePort::VintagePort()
{
	VintagePort("none", 0, "none", 0);
}

VintagePort::VintagePort(const char* br, int b, const char* nn, int y) : Port(br, "vintage", b)
{
	if (nn == NULL)
		throw std::invalid_argument("Nickname is empty!");
	char *nnm = new char[strlen(nn) + 1];
	nnm[strlen(nn)] = '\0';
	nnm = strcpy(nnm, nn);
	nickname = nnm;
	year = y;
}

VintagePort::VintagePort(const VintagePort& vp) : Port(static_cast<Port>(vp))
{
	char *nnm = new char[strlen(vp.nickname) + 1];
	nnm[strlen(vp.nickname)] = '\0';
	nnm = strcpy(nnm, vp.nickname);
	nickname = nnm;
	year = vp.year;
}

VintagePort& VintagePort::operator= (const VintagePort & vp)
{
	Port::operator=(static_cast<Port>(vp));
	year = vp.year;
	if (nickname != vp.nickname)
	{
		char *nnm = new char[strlen(vp.nickname) + 1];
		nnm[strlen(vp.nickname)] = '\0';
		nnm = strcpy(nnm, vp.nickname);
		nickname = nnm;
	}
	return (*this);
}

void VintagePort::Show() const
{
	Port::Show();
	std::cout << "Name: " << nickname << "\nYear: " << year << std::endl;
}

std::ostream& operator<<(std::ostream& os, const VintagePort& vp)
{
	Port tmp(vp);
	os << tmp << ", " << vp.nickname << ", " << vp.year;
	return (os);
}