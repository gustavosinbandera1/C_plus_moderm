/*

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Vector of strings
    std::vector<std::string> vecOfStings{"at", "hello", "hi", "there", "where", "now", "is",
                                         "that", "hi", "where", "at", "no", "yes", "at"};

    // Create a map to store the frequency of each element in vector
    std::map<std::string, int> countMap;

    // Iterate over the vector and store the frequency of each element in map
    for (auto& elem : vecOfStings) {
        auto result = countMap.insert(std::pair<std::string, int>(elem, 1));
        if (result.second == false)  // equivalent key exist
            result.first->second++;
    }

    // Iterate over the map
    for (auto& elem : countMap) {
        // If frequency count is greater than 1 then its a duplicate element
        if (elem.second > 1) {
            std::cout << elem.first << " :: " << elem.second << std::endl;
        }
    }

    return 0;
}