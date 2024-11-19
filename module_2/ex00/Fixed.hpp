#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
    int fixed;
    static const int fractionalBits; //TODO: pq static?

    public:
        Fixed();
        Fixed(const Fixed &src);
        Fixed & operator=(const Fixed &rhs);
        ~Fixed();
        int getRawBits() const;
        void setRawBits(int const raw);
};

#endif
