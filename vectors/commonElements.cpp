/*
Approach: Common elements b/w 2 arrays  can be found with the help of set_intersection() function provided in STL.

Syntax:

set_intersection (InputIterator1 first1, InputIterator1 last1,
           InputIterator2 first2, InputIterator2 last2,
           OutputIterator result);

// C++ program to find common elements
// between two Vectors using STL
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Get the vector
    vector<int> vector1 = {1, 45, 54, 71, 76, 12};
    vector<int> vector2 = {1, 7, 5, 4, 6, 12};

    // Sort the vector
    sort(vector1.begin(), vector1.end());
    sort(vector2.begin(), vector2.end());

    // Print the vector
    cout << "First Vector: ";
    for (int i = 0; i < vector1.size(); i++)
        cout << vector1[i] << " ";
    cout << endl;

    cout << "Second Vector: ";
    for (int i = 0; i < vector2.size(); i++)
        cout << vector2[i] << " ";
    cout << endl;

    // Initialise a vector
    // to store the common values
    // and an iterator
    // to traverse this vector
    vector<int> v(vector1.size() + vector2.size());
    vector<int>::iterator it, st;

    it = set_intersection(vector1.begin(),
                          vector1.end(),
                          vector2.begin(),
                          vector2.end(),
                          v.begin());

    cout << "\nCommon elements:\n";
    for (st = v.begin(); st != it; ++st)
        cout << *st << ", ";
    cout << '\n';

    return 0;
}