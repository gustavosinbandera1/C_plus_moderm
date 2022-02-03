// C++ program to demonstrate working of
// functors.

#include <iostream>
using namespace std;

class Line {
    double a;  // slope
    double b;  // y-intercept

   public:
    Line(double slope = 1, double yintercept = 1) : a(slope), b(yintercept) {}
    double operator()(double x) const {
        return a * x + b;
    }
};

int main() {
    // Line fa;             // y = 1*x + 1
    Line fb(3.0, 1.0);  // y = 3*x + 1

    // double y1 = fa(20.0);  // y1 = 20*(1) + 1
    double y2 = fb(1);  // y2 = 5*3 + 10

    /* cout << "y1 = " << y1 << " y2 = " << y2 << endl; */
    cout << " y2 = " << y2 << endl;
    return 0;
}