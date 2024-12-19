#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T> class Array {
    private:
        T *elements;
        unsigned int size; //criamos size pq assim sabemos o tamanho do array (veja a utilidade no caso do construtor por cópia)
    public:
        Array() : elements(NULL), size(0) {}

        Array(unsigned int n) : size(n) {
            this->elements = new T[size]; //TODO: pq new? 
            // The new keyword is used to dynamically allocate memory for an array of T objects
            // int arr[10]; // stack allocation
            // int* arr = new int[10]; // Dynamically allocate an array of size 10
            int intArray[] = {1, 2, 3, 4, 5};
            for (unsigned int i = 0; i < size; i++) {
                elements[i] = T(); //TODO: pq T()? eu estou chamando o construtor de T, mas e se T for um int ou double?
            }
        }
        Array(const Array &ref) {
            elements = new Array(ref.size); //TODO: pq ele usar new T[_size];?
            for (unsigned int i = 0; i < size; i++) {
                elements[i] = ref.elements[i];
            }
        }
        &operator=(const Array &ref) {
            // if (this != &ref)
                // *this = ref;
            return (*this);
        }
};

#endif
