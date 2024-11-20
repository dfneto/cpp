#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	int fixed;
	static const int fractionalBits;

	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &src);
		Fixed & operator=(const Fixed &rhs);
		~Fixed();

		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;

		//Arithmetic operators
		Fixed	operator+(const Fixed &rhs) const;
		Fixed	operator-(const Fixed &rhs) const;
		Fixed	operator*(const Fixed &rhs) const;
		Fixed	operator/(const Fixed &rhs) const;

		//Comparison operators
		bool	operator>(const Fixed& rhs) const;
		bool	operator>=(const Fixed& rhs) const;
		bool	operator<(const Fixed& rhs) const;
		bool	operator<=(const Fixed& rhs) const;
		bool	operator==(const Fixed& rhs) const;
		bool	operator!=(const Fixed& rhs) const;

		//Increment/decremente operators
		Fixed	&operator++(); 	//a++
		Fixed	&operator++(int);	//++a
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed); //TODO: pq &?

#endif
