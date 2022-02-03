// C++ program to find the index
// of an element in a vector
#include <bits/stdc++.h>
using namespace std;

// Function to print the
// index of an element

template <typename T, typename U>
void getIndexx(const T& vecOfElements, const U& k) {
    std::cout << "LVALUE here ..................." << std::endl;
    auto it = find(vecOfElements.begin(), vecOfElements.end(), k);
    if (it != vecOfElements.end()) {
        // calculating the index
        // of K
        int index = it - vecOfElements.begin();
        cout << index << endl;
    } else {
        // If the element is not
        // present in the vector
        cout << "-1" << endl;
    }
}

template <typename T, typename U>
void getIndexx(const T&& vecOfElements, const U&& k) {
    std::cout << "RVALUE here ..................." << std::endl;
    auto it = find(vecOfElements.begin(), vecOfElements.end(), k);
    if (it != vecOfElements.end()) {
        // calculating the index
        // of K
        int index = it - vecOfElements.begin();
        cout << index << endl;
    } else {
        // If the element is not
        // present in the vector
        cout << "-1" << endl;
    }
}

void getIndex(vector<int> v, int K) {
    auto it = find(v.begin(), v.end(), K);

    // If element was found
    if (it != v.end()) {
        // calculating the index
        // of K
        int index = it - v.begin();
        cout << index << endl;
    } else {
        // If the element is not
        // present in the vector
        cout << "-1" << endl;
    }
}

template <typename T>
void print(T&& vecOfElements, std::string delimeter = "  ") {
    for (auto elem : vecOfElements)
        std::cout << elem << delimeter;
    std::cout << std::endl;

    for (auto it = vecOfElements.begin(); it != vecOfElements.end(); ++it)
        std::cout << *it << delimeter;

    std::cout << '\n';
}
// Driver Code
int main() {
    // Vector
    vector<int> v = {1, 45, 54, 71, 76, 17};
    vector<double> f = {1.34, 45.3, 54.3, 71.2, 76.4, 17.1};
    vector<string> s = {"hola", "mundo", "cruel", "como", "estas"};
    // Value whose index
    // needs to be found
    int ints = 54;
    double dbl = 17.1;
    getIndexx(v, 54);
    getIndexx(f, 17.1);
    getIndexx(s, move("cruel"));

    auto vv = {1, 45, 54, 71, 76, 17};
    getIndexx(move(vv), 54);
    getIndexx(move(f), 17.1);
    getIndexx(move(s), move("cruel"));

    return 0;
}