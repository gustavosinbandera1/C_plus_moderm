/*
https://en.cppreference.com/w/cpp/language/reference#Rvalue_references

Because references are not objects, there are no arrays of references, no pointers to references, and no references to references: 
int& a[3]; // error
int&* p;   // error
int& &r;   // error

1) Lvalue reference declarator: the declaration S& D; declares D as an lvalue reference to the type determined by decl-specifier-seq S.
2) Rvalue reference declarator: the declaration S&& D; declares D as an rvalue reference to the type determined by decl-specifier-seq S.


 Reference collapsing

It is permitted to form references to references through type manipulations in templates or typedefs, in which case the reference collapsing rules apply: rvalue reference to rvalue reference collapses to rvalue reference, all other combinations form lvalue reference:

typedef int&  lref;
typedef int&& rref;
int n;
lref&  r1 = n; // type of r1 is int&
lref&& r2 = n; // type of r2 is int&
rref&  r3 = n; // type of r3 is int&
rref&& r4 = 1; // type of r4 is int&&

*/
//lvalue  refreneces
/* #include <iostream>
#include <string>
 
int main() {
    std::string s = "Ex";
    std::string& r1 = s;
    const std::string& r2 = s;
 
    r1 += "ample";           // modifies s
//  r2 += "!";               // error: cannot modify through reference to const
    std::cout << r2 << '\n'; // prints s, which now holds "Example"
} */


#include <iostream>
#include <string>
 
char& char_number(std::string& s, std::size_t n) {
    return s.at(n); // string::at() returns a reference to char
}
 
int main() {
    std::string str = "Test";
    char_number(str, 1) = 'a'; // the function call is lvalue, can be assigned to
    std::cout << str << '\n';
}