// Function that takes a value as a parameter
void func1(int numVal) {
    // Code
}

// Function that takes a reference as a parameter
// Notice the & before the parameter
void func2(int &numRef) {
    // Code
}

int main() {
    int num = 5;

    // Pass by value
    func1(num);

    // Pass by reference
    func2(num);

    return 0;
}
