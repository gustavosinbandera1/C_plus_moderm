// vector::back
#include <iostream>
#include <vector>

template <typename T>
void print(T&& vecOfElements, std::string delimeter = "  ") {
    for (auto elem : vecOfElements)
        std::cout << elem << delimeter;
    std::cout << std::endl;

    for (auto it = vecOfElements.begin(); it != vecOfElements.end(); ++it)
        std::cout << *it << delimeter;

    std::cout << '\n';
}

int main() {
    std::vector<int> myVector;
    myVector.push_back(10);
    while (myVector.back() != 0) {
        myVector.push_back(myVector.back() - 1);
    }
    print(myVector);
}