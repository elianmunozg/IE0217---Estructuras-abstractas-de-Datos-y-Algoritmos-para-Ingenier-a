#include <iostream>
using namespace std;

enum suit {
    club = 0,
    diamonds = 10,
    hearts = 20,
    spades = 3
};

int main() {
    suit card = club;
    
    cout << "Size of enum variable: " << sizeof(card) << " bytes." << endl;

    return 0;
}
