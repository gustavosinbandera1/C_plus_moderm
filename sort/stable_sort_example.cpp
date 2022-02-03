// stable_sort example
#include <algorithm>  // std::stable_sort
#include <iostream>   // std::cout
#include <vector>     // std::vector

bool compare_as_ints(double i, double j) {
    return (int(i) < int(j));
}

bool compare_as_double(double i, double j) {
    return (i < j);
}

template <typename T>
void printVector(const T& vecOfElements, const std::string delimiter = " , ") {
    /*     for(auto element : vecOfElements)
            std::cout << element << delimiter;
        std::cout << std::endl; */
    for (auto it = vecOfElements.begin(); it != vecOfElements.end(); ++it)
        if (it != vecOfElements.end()) {
            std::cout << ' ' << *it << delimiter;
        }
    std::cout << '\n';
}

int main() {
    double mydoubles[] = {3.14, 1.41, 2.72, 4.67, 1.73, 1.32, 1.62, 2.58};

    std::vector<double> myvector;

    myvector.assign(&mydoubles[0], mydoubles + 8);

    std::cout << "using default comparison:";
    std::stable_sort(myvector.begin(), myvector.end());
    for (std::vector<double>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    myvector.assign(mydoubles, mydoubles + 8);

    std::cout << "using 'compare_as_ints' :";
    std::stable_sort(myvector.begin(), myvector.end(), compare_as_ints);
    printVector(myvector);

    std::cout << "using 'compare_as_double':";
    std::stable_sort(myvector.begin(), myvector.end(), compare_as_double);
    printVector(myvector);

    int ints[]{8, 7, 6, 5, 9, 3, 2, 1, 4, 10};
    std::vector<int> myints;
    myints.assign(ints, ints + 10);
    std::stable_sort(myints.begin(), myints.end());
    printVector(myints);
    /* for (std::vector<int>::iterator it = myints.begin(); it != myints.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n'; */

    return 0;
}