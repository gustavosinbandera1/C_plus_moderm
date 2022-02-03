#include <algorithm>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <vector>

std::string removeCharacters(std::string s, char c) {
    s.erase(remove(s.begin(), s.end(), c), s.end());
    return s;
}

template <typename T>
std::string vectorToString(const T&& vec) {
    std::ostringstream os;
    for (auto item : vec) {
        os << item;
    }
    return os.str();
}
template <>
std::string vectorToString(const std::vector<double>&& vec) {
    std::ostringstream os;
    for (auto item : vec) {
        os << item;
    }
    std::string str = os.str();
    str = removeCharacters(str, '.');
    std::cout << "Float output : " << str << std::endl;
    return os.str();
}

void print_each_digit(int x) {
    if (x >= 10) {
        print_each_digit(x / 10);
    }
    int digit = x % 10;
    std::cout << digit << '\n';
}

int main() {
    print_each_digit(1234);

    std::vector<int> vecInt = {18, 2, 3, 4, 11, 22, 33, 44, 5, 6, 6, 7, 6, 8888888};
    std::vector<double> vecDouble = {18.5, 1.2, 1.5, 1.7};
    std::string digitsInt = vectorToString(std::move(vecInt));
    std::string digitsDouble = vectorToString(std::move(vecDouble));
    int counter[10];
    int counter2[10];

    for (int i = 0; i < 10; i++) {
        size_t n = std::count(digitsInt.begin(), digitsInt.end(), '0' + i);
        counter[i] = n;
        std::cout << "number : [" << i << "] = " << n << std::endl;
    }

    for (int i = 0; i < 10; i++) {
        size_t m = std::count(digitsDouble.begin(), digitsDouble.end(), '0' + i);
        counter2[i] = m;
        std::cout << "number float [" << i
                  << "] = " << m << std::endl;
    }
}