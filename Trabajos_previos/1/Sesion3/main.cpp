#include <iostream>
#include "sum.hpp"

using namespace std;

int main() {
    int num1 = 5;
    int num2 = 3;
    int result = sum(num1, num2);

    cout << "El resultado de " << num1 << " + " << num2 << " es igual: " << result << endl;

    return 0;
}
