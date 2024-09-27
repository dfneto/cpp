#include <iostream>

//recebo o objeto (na realidade vc passa o endereço)
void byReference(int &ref) {
    ref = 20;  
}

//recebo o endereço
void byPointer(int *ptr) {
    *ptr = 20;  // Dereference to modify the original object
}

//recebo uma cópia do objeto
void byValue(int val) {
    val = val + 30; // Only modifies the copy
}

int main() {
    int x = 10;
    byReference(x);                 //passo x como se fosse um objeto e não seu endereço como no ponteiro
    std::cout << x << std::endl;  // Output: 20 (x was modified)
    byValue(x);
    std::cout << x << std::endl;  // Output: 20 (x was NOT modified)
    byPointer(&x); // Passing the address of x
    return 0;
}
