#include <algorithm>
#include <iostream>
#include <vector>

#include "test.h"

using namespace std;

int main() {
    typedef pair<int, int> TPair;

    vector<TPair> data(10);

    data[0] = make_pair(7, 1);
    data[1] = make_pair(3, 2);
    data[2] = make_pair(8, 0);
    data[3] = make_pair(5, 1);
    data[4] = make_pair(3, 1);
    data[5] = make_pair(2, 0);
    data[6] = make_pair(7, 0);
    data[7] = make_pair(6, 4);
    data[8] = make_pair(5, 2);
    data[9] = make_pair(3, 1);

    stable_sort(data.begin(), data.end(), comp());

    for (unsigned int i = 0; i < 10; ++i) {
        cout << data[i].first << "\t" << data[i].second << endl;
    }

    return 0;
}