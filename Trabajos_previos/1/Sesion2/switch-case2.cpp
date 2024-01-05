#include <iostream>

int main() {
    std::cout << "Hola Mundo, estudiantes de IE0237!\n";

    int var = 1;
    int var2 = 2;
    int var3 = 3;

    switch (var) {
        case 1:
            std::cout << "Case 1!\n";
            break;
        case 2:
        case 3:
            std::cout << "Case Final!\n";
            break;
        
        
        default:
            std::cout << "Default Case!\n";
            break;
    }

    return 0;
}
