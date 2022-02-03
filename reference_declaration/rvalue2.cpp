#include<iostream>

using namespace std;
int x = 5;

int &f() {
	return x;
}
int main() {
    f() = 10;
   cout<<x;
}