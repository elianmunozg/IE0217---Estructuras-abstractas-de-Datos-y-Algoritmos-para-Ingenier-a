#include <iostream>
#include <vector>

using namespace std;

int main() {
    // inicializa un vector de int type
    vector<int> numbers = {1, 100, 10, 70, 100};

    // print the vector
    cout << "Numbers are: ";
    for(auto &num: numbers) {
        cout << num << ", ";
    }

    return 0;
}