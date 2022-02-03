// std__memory__shared_ptr_reset.cpp
// compile with: /EHsc
#include <iostream>
#include <memory>

struct deleter {
    void operator()(int *p) {
        delete p;
    }
};

int main() {
    std::shared_ptr<int> sp(new int(5));

    std::cout << "*sp == " << std::boolalpha
              << *sp << std::endl;

    sp.reset();
    std::cout << "(bool)sp == " << std::boolalpha
              << (bool)sp << std::endl;

    sp.reset(new int(10));
    std::cout << "*sp == " << std::boolalpha
              << *sp << std::endl;

    sp.reset(new int(15), deleter());
    std::cout << "*sp == " << std::boolalpha
              << *sp << std::endl;

    return (0);
}
