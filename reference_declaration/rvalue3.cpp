#include <utility>
#include<iostream>

void printReference (const int& element)
{
     std::cout << "is_lvalue" << std::is_lvalue_reference<decltype(element)>::value << std::endl;
        std::cout <<"lvalue: " << element << std::endl;;
}

void printReference (int&& element)
{

    std::cout <<"is_rvalue " <<std::is_rvalue_reference<decltype(element)>::value << std::endl;
    std::cout << "rvalue: " << element << std::endl;
}
 
int main() {
    int i = 5;
    const int ci = 2;
    printReference(std::move(i));  // calls f(int&)
    printReference(ci); 
   
}