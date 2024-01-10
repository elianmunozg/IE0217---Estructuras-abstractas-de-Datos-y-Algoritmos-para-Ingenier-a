#include <iostream>
using namespace std;

class A {};

class B : public A {};

class C : public B {};

int main() {
    C obj;
    return 0;
}
