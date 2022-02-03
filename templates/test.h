#include <vector>

#pragma once

using namespace std;

struct comp {
    template <typename T, typename U>
    bool operator()(pair<T, U> const& a, pair<T, U> const& b) const {
        std::cout << "*****************1" << std::endl;
        return a.first < b.first;
    }

    template <typename TPair>
    bool operator()(TPair const& a, TPair const& b) {
        std::cout << "*****************2" << std::endl;
        return a.first < b.first;
    } 

    bool operator()(pair<int, int> const& a, pair<int, int> const& b) {
        std::cout << "*****************3" << std::endl;
        return a.first < b.first;
    }
};


