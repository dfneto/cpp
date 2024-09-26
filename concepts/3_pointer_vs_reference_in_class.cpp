#include <iostream>

class Sample {
    public:
        void printPointer(int *other) {
            std::cout << other << std::endl;
        }
        void printReference(Sample &other) {
            std::cout << other << std::endl; //NÃO POSSO FAZER ISSO!!!
        }
};

int main() {
    int x = 10;
    int *ptr = &x;  // ptr is a pointer to the memory address of x
    Sample s;
    s.printPointer(ptr);
}
