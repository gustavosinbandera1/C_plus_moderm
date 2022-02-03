/*
Please note that the title is Functors (Not Functions)!!

Consider a function that takes only one argument. However, while calling this function we have a lot more
information that we would like to pass to this function, but we cannot as it accepts only one parameter.
What can be done?

One obvious answer might be global variables. However, good coding practices do not advocate the use of global
variables and say they must be used only when there is no other alternative.

Functors are objects that can be treated as though they are a function or function pointer.
Functors are most commonly used along with STLs in a scenario like following:
*/

// A C++ program uses transform() in STL to add
// 1 to all elements of arr[]
#include <bits/stdc++.h>
using namespace std;

int increment(int x) { return (x + 1); }

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Apply increment to all elements of
    // arr[] and store the modified elements
    // back in arr[]
    std::transform(arr, arr + n, arr, increment);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}