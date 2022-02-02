/*
 Rvalue references

Rvalue references can be used to extend the lifetimes of temporary objects 
(note, lvalue references to const can extend the lifetimes of temporary objects too, but they are not modifiable through them): 
*/

#include <iostream>
#include <string>
 
/* int main() {
    std::string s1 = "Test";
//  std::string&& r1 = s1;           // error: can't bind to lvalue
 
    const std::string& r2 = s1 + s1; // okay: lvalue reference to const extends lifetime
//  r2 += "Test";                    // error: can't modify through reference to const
 
    std::string&& r3 = s1 + s1;      // okay: rvalue reference extends lifetime
    r3 += "Test";                    // okay: can modify through reference to non-const
    std::cout << r3 << '\n';
}
 */

/*
More importantly, when a function has both rvalue reference and lvalue reference overloads, 
the rvalue reference overload binds to rvalues (including both prvalues and xvalues), 
while the lvalue reference overload binds to lvalues: 
*/


#include <utility>
 
void f(int& x) {
    std::cout << "lvalue reference overload f(" << x << ")\n";
}
 
void f(const int& x) {
    std::cout << "lvalue reference to const overload f(" << x << ")\n";
}
 
void f(int&& x) {
    std::cout << "rvalue reference overload f(" << x << ")\n";
} 
 
int main() {
    int i = 1;
    const int ci = 2;
    f(i);  // calls f(int&)
    f(ci); // calls f(const int&)
    f(3);  // calls f(int&&)
           // would call f(const int&) if f(int&&) overload wasn't provided
    f(std::move(i)); // calls f(int&&)
 
    // rvalue reference variables are lvalues when used in expressions
    int&& x = 1;
    f(x);            // calls f(int& x)
    f(std::move(x)); // calls f(int&& x)
}