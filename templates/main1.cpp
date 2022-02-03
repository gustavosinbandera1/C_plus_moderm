#include <iostream>
/*
According to the C++17 standard, what is the output of this program?
*/
template <class T>
void f(T &i) { std::cout << 1; }

template <>
void f(const int &i) { std::cout << 2; }

template <class T>
void f(T &&i) { std::cout << 3; }

int main() {
    int i = 42;
    const int j = 5;
    f(i);             // 1
    f(12);            // 3
    f(std::move(i));  // 3
    f(j);             // 2
}

/*
For the call f(i), since the type of i is int, template argument deduction deduces T = int.

The explicit specialization template <> void f(const int &i) has T = const int, which is not the same type as int, so it doesn't match.

Instead, template <class T> void f(T &i) with T = int is used to create the implicit instantiation void f<int>(int&).
*/