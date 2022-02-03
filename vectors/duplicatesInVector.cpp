/*

*/

#include <bits/stdc++.h>
using namespace std;

/*
 * Generic function to find duplicates elements in vector.
 * It adds the duplicate elements and their duplication count in given map countMap
 */
template <typename T>
void findDuplicates(std::vector<T>& vecOfElements, std::map<T, int>& countMap) {
    // Iterate over the vector and store the frequency of each element in map
    for (auto& elem : vecOfElements) {
        auto result = countMap.insert(std::pair<T, int>(elem, 1));
        if (result.second == false)
            result.first->second++;
    }
    // Remove the elements from Map which has 1 frequency count
    for (auto it = countMap.begin(); it != countMap.end();) {
        if (it->second == 1)
            it = countMap.erase(it);
        else
            it++;
    }
}

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


    /// implemented using templates 

    std::map<std::string, int> duplicateElements;
    // Get the duplicate elements in vector
    findDuplicates(vecOfStings, duplicateElements);
    std::cout << "Duplicate elements and their duplication count " << std::endl;
    for (auto& elem : duplicateElements)
        std::cout << elem.first << " :: " << elem.second << std::endl;

    return 0;
}