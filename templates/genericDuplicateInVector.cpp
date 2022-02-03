#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <vector>
// Print the contents of vector
template <typename T>
void print(T& vecOfElements, std::string delimeter = " , ") {
    for (auto elem : vecOfElements)
        std::cout << elem << delimeter;
    std::cout << std::endl;
}
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

    std::vector<int> vecOfInts{1, 2, 3, 4, 5, 5, 4, 3, 2, 1, 8, 8, 7, 6, 4, 4, 4, 6, 1, 2};
    std::vector<int> vec{1, 2, 3, 4, 5};  // to check if repeated elements using std::unique
    print(vecOfStings);
    // Create a map to store the frequency of each element in vector
    std::map<std::string, int> countMap;
    // Iterate over the vector and store the frequency of each element in map
    for (auto& elem : vecOfStings) {
        auto result = countMap.insert(std::pair<std::string, int>(elem, 1));
        if (result.second == false)
            result.first->second++;
    }
    std::cout << "Duplicate elements and their duplication count " << std::endl;
    // Iterate over the map
    for (auto& elem : countMap) {
        // If frequency count is greater than 1 then its a duplicate element
        if (elem.second > 1) {
            std::cout << elem.first << " :: " << elem.second << std::endl;
        }
    }
    /*
     * Finding duplicates in vector using generic function
     */
    std::map<std::string, int> duplicateElements;
    // Get the duplicate elements in vector
    findDuplicates(vecOfStings, duplicateElements);
    std::cout << "Duplicate elements and their duplication count " << std::endl;
    for (auto& elem : duplicateElements)
        std::cout << elem.first << " :: " << elem.second << std::endl;

    /*
     * Finding duplicates in vector using generic function
     */
    std::map<int, int> duplicateIntElements;
    // Get the duplicate elements in vector
    findDuplicates(vecOfInts, duplicateIntElements);
    std::cout << "Duplicate elements and their duplication count " << std::endl;
    for (auto& elem : duplicateIntElements)
        std::cout << elem.first << " :: " << elem.second << std::endl;

    std::cout << "*********************************" << std::endl;
    auto it = std::unique(vec.begin(), vec.end());
    bool wasUnique = (it == vec.end());
    std::cout << "********************************* was unique: " << wasUnique << std::endl;
    return 0;
}




// this is just if anyone force to create own algorithm

/*
bool hasDuplicates(const std::vector<int>& arr) {
    for (std::size_t i = 0; i < arr.size(); ++i) {
        for (std::size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[i] == arr[j])
                return true;
        }
    }
    return false;
}

*/