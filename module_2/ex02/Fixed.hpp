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
		Fixed	&operator++(); 		//++a
		Fixed	operator++(int);	//a++
		//b = ++c: incrementa-se c e repois atribui-se o resultado a b
		//Ex: 
		//	c = 1
		//	b = ++c
		//	agora b = 2 e c = 2
		// b = c++: atribui-se o resultado a b e depois incrementa-se c
		//Ex: 
		//	c = 1
		//	b = c++
		//	agora b = 1 e c = 2
		Fixed	&operator--();		//--a
		Fixed	operator--(int);	//a--

		//Max min functions
		static Fixed &min(Fixed &a, Fixed &b); //Fixed::min(a, b) = Fixed(42);  // Allowed because the return value is non-const
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed); //devolvo um objeto do tipo ostream e assim posso fazer chaining

#endif
