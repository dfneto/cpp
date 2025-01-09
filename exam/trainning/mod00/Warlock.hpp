#pragma once

#include <iostream>

class Warlock {
	private:
		std::string name;
		std::string title;

		Warlock();
		Warlock(const Warlock &);
		Warlock & operator=(const Warlock &);

	public:
		Warlock(std::string name, std::string title);
		~Warlock();

		const std::string&	getName() const;	
		const std::string&	getTitle() const;	
		void				setTitle(const std::string &);
		void				introduce() const;

};
