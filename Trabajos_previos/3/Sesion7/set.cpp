#include <iostream>
#include <set>

using namespace std;

int main() {
    // inicializa un set de int type
    set<int> numbers = {1, 100, 10, 70, 100};

    // print the set
    cout << "Numbers are: ";
    for(auto &num: numbers) {
        cout << num << ", ";
    }

    return 0;
}
