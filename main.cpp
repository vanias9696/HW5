#include "vintage_port.h"

int main(void)
{
	Port pfirst("Gallo", "tawny", 20);

	std::cout << "Port:\n";
	pfirst.Show();
	VintagePort vfirst("Andresen", 2, "Andresen Vintage", 1999);
	std::cout << "\nVintage:\n";
	vfirst.Show();

	pfirst -= 3;
	vfirst += 3;
	std::cout << "\nSubtracted from Port 3. Added to Vintage 3.\n";
	std::cout << "Port: " << pfirst << std::endl;
	std::cout << "Vintage: "<< vfirst << std::endl;
	return 0;
}