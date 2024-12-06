#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
// private: //TODO: ides deve ser private
public:
	std::string	ideas[100];

	Brain();
	Brain(const Brain& ref);
	~Brain();

	Brain&	operator=(const Brain& ref);
};

#endif