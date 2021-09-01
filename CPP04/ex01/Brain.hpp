#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#define BRAIN "\U0001F9E0"

class Brain 
{
	public:
		Brain();
		Brain(Brain const & src);
		Brain & operator=(Brain const & src);
		~Brain();

	private:
		std::string _ideas[100];

	protected:

};
#endif
