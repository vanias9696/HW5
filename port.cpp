#include "port.h"

Port::Port(const char* br, const char* st, int b)
{
	if (br == NULL || st == NULL)
		throw std::invalid_argument("Brand or Style is empty!");
	memset (style, '\0', 20);
	strcpy(style, st);
	bottles = b;
	char *bd = new char[strlen(br) + 1];
	bd[strlen(br)] = '\0';
	bd = strcpy(bd, br);
	brand = bd;
}

Port::Port(const Port& p)
{
	memset (style, '\0', 20);
	strcpy(style, p.style);
	bottles = p.bottles;
	char *bd = new char[strlen(p.brand) + 1];
	bd[strlen(p.brand)] = '\0';
	bd = strcpy(bd, p.brand);
	brand = bd;
}

Port& Port::operator= (const Port & p)
{
	bottles = p.bottles;
	if (brand != p.brand)
	{
		delete [] brand;
		char *bd = new char[strlen(p.brand) + 1];
		bd[strlen(p.brand)] = '\0';
		bd = strcpy(bd, p.brand);
		brand = bd;
	}
	if (style != p.style)
	{
		memset(style, '\0', 20);
		strcpy(style, p.style);
	}
	return (*this);
}

Port& Port::operator+= (int b)
{
	bottles += b;
	return (*this);
}

Port& Port::operator-= (int b)
{
	bottles = bottles < b ? 0 : bottles - b;
	return (*this);
}

void Port::Show() const
{
	std::cout << "Brand: " << brand << "\nKind: " << style << "\nBottles: " << bottles << std::endl;
}

std::ostream& operator<< (std::ostream& os, const Port& p)
{
	os << p.brand << ", " << p.style << ", " << p.bottles;
	return (os);
}
