// C++ Program to display the address of each element of an array
#include <iostream>
using namespace std;

int main() {
    float arr[3];
    // declare pointer variable
    float *ptr;
    
    cout << "Displaying address using arrays:" << endl;
    // use a for loop to print addresses of all array elements
    for (int i = 0; i < 3; ++i) {
        cout << "&arr[" << i << "] = " << &arr[i] << endl;
    }

    // ptr = &arr[0]
    ptr = arr;

    cout << "\nDisplaying address using pointers:" << endl;
    // use a for loop to print addresses of all array elements
    // using pointer notation
    for (int i = 0; i < 3; ++i) {
        cout << "ptr + " << i << " = " << ptr + i << endl;
    }

    return 0;
}
