#include "Brain.hpp"

Brain::Brain()
{
	std::cout << BRAIN << "(Default) Brain constructor" << BRAIN << std::endl;
}

Brain::Brain(Brain const & src)
{
	std::cout << BRAIN << "(Copy) Brain constructor"<< BRAIN << std::endl;
	*this = src;
}

Brain & Brain::operator=(Brain const & src)
{
	int i;

	std::cout << BRAIN << "Assignation brain called" << BRAIN << std::endl;
	if (&src == this)
	{
		std::cout << "trying to clone yourself ?" << std::endl;
		return *this;
	}
	std::cout << "\tCloning ideas processing..." << std::endl;
	for (i = 0; i < 100; i++)
		this->_ideas[i] = src._ideas[i];
	return *this;
}

Brain::~Brain()
{
	std::cout << BRAIN << "Brain is destroyed" << BRAIN << std::endl;
}
