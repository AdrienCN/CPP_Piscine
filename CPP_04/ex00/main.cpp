#include "Animal.hpp"

int main(void)
{
	Animal typeless;

	typeless.makeSound();
	std::cout << typeless.getType() << std::endl;
	typeless.setType("BullFrog");
	std::cout << typeless.getType() << std::endl;
	return (0);
}
