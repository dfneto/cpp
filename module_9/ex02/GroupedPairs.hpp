#ifndef GROUPED_PAIRS_HPP
#define GROUPED_PAIRS_HPP

#include <iostream>
#include <vector>

typedef std::vector<std::vector<int> > GroupedPairs;

// Inline function to avoid multiple definitions
inline std::ostream& operator<<(std::ostream& os, const GroupedPairs& pairs) {
    os << "[";
    for (std::vector<std::vector<int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
        os << " [";
        for (std::vector<int>::const_iterator vit = it->begin(); vit != it->end(); ++vit) {
            os << *vit;
            if (vit + 1 != it->end()) os << ", "; // Avoid trailing comma
        }
        os << "]";
    }
    os << " ]";
    return os;
}

#endif // GROUPED_PAIRS_HPP
