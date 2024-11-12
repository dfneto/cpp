#include <iostream>

int main() {
    //using pointer
    int x = 10;
    int *ptr = &x;  // ptr is a pointer to the memory address of x
    std::cout << "ptr addr: " << ptr << std::endl;
    std::cout << "ptr value: " << *ptr << std::endl;
    x++;
    std::cout << "new ptr value: " << *ptr << std::endl;
    // ptr = NULL; posso fazer o ponteiro apontar para nulo
    // std::cout << *ptr << std::endl; segfault

    //using reference (alias)
    int y = 10;
    // int &ref = NULL; não posso fazer a referência apontar para nulo
    //int &ref; tbm não posso fazer isso
    int &ref = y;  // ref is a reference (alias) to x
    std::cout << "ref addr: " << &ref << std::endl;
    std::cout << "y: " << y << ", ref: " << ref << std::endl;
    std::cout << "alterando ref ... " << std::endl;  
    ref = 12;
    std::cout << "y: " << y << ", ref: " << ref << std::endl;
    std::cout << "alterando y ... " << std::endl;  
    y = 10;
    std::cout << "y: " << y << ", ref: " << ref << std::endl;

    
    int z = 14;
    ref = z; //assim estou alterando o valor de y
    // &ref = z; - NÃO POSSO
    // *ref = z; - NÃO POSSO
    std::cout << "y: " << y << ", ref: " << ref << std::endl;
}
