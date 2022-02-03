#include <iostream>
using namespace std;

template <class T, int i>
void fun(T t) {
    // i = 20;
    cout << i << "--" << t << std::endl;
}

int main() {
    fun<int, 10>(5);
    return 0;
}