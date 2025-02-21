#include "Serializer.hpp"

int main() {
	Data a;
	a.id = 42;
	a.name = "Pepo";

	std::cout << "Pointer before serialization: " << &a << std::endl;

	uintptr_t uptr = Serializer::serialize(&a);
	std::cout << "uintptr_t of the serialized pointer: " << uptr << std::endl;

	Data *b = Serializer::deserialize(uptr);
	std::cout <<  "Pointer after serialization: " << b << std::endl;
    std::cout << b->id << " - " << b->name << std::endl;
    
	int myInt = 42;
	uintptr_t ptrValue = reinterpret_cast<uintptr_t>(&myInt);
    std::cout << "Dirección de memoria de myInt: " << ptrValue << std::endl;

    // También puedes convertirlo de nuevo a un puntero
    int* ptrToInt = reinterpret_cast<int*>(ptrValue);
    std::cout << "Valor a través del puntero: " << *ptrToInt << std::endl;

    return 0;
}
