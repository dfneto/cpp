#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename F> void iter(T *array, int lenght, F func) { 
    for (int i = 0; i < lenght; i++)
        func(array[i]);
}

#endif
