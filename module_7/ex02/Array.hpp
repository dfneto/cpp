#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T> class Array {
    private:
        T *elements;
        unsigned int size; //criamos size pq assim sabemos o tamanho do array (veja a utilidade no caso do construtor por cópia)
    public:
        Array() : elements(NULL), size(0) {}

        ~Array() {
            if (elements) {
                delete[] elements;
            }
        }

        Array(unsigned int n) : size(n) {
            this->elements = new T[size]; // pq new? 
            // The new keyword is used to dynamically allocate memory for an array of T objects
            // int arr[10]; // stack allocation
            // int* arr = new int[10]; // Dynamically allocate an array of size 10
            for (unsigned int i = 0; i < size; i++) {
                elements[i] = T(); 
                //For primitive types like int, float, etc., T() initializes them to their default value (0)
                //For class types, T() calls the default constructor of the class.
                //For pointers, T() initializes them to nullptr if the type is a pointer.
            }
        }

        //Constructor's purpose is to create a new object, not to "assign" to an existing one (operator=).
        //Por isso não faz sentido checar *this != ref
        Array(const Array &ref) : size(ref.size) {
            this->elements = new T[size]; //elements é um ponteiro para um array do tipo T. 
            //Antes eu tinha erroneamente feito elements = new Array(ref.size), mas elements assim seria um ponteiro
            //para um objeto do tipo Array que tem elements e size.
            for (unsigned int i = 0; i < size; i++) {
                elements[i] = ref.elements[i];
            }
        }

        Array& operator=(const Array &ref) {
            if (this != &ref) {
                if (elements) {
                    delete[] elements; //Free the memory allocated of the old array
                }
                size = ref.size;
                elements = new T[size];
                for (unsigned int i = 0; i < size; i++) {
                    elements[i] = ref.elements[i];
                }
            }
            return (*this);
        }

        T& operator[](unsigned int index) {
            if (index >= size) {
                throw std::out_of_range("Index out of range, my friend");
            }
            return elements[index];
        }

        //The first const ensures the return value itself cannot be modified.
        //The second const is to prevent alterations to the object. 
        const T& operator[](unsigned int index) const {
            if (index >= size) {
                throw std::out_of_range("Index out of range, my friend");
            }
            return elements[index];
        }
        
        unsigned int getSize() const {
            return (size);
        }
};

#endif
