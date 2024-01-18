int main() {
    int result1;
    double result2;

    // Llamando a una función genérica con parámetros enteros
    result1 = add<int>(2, 3);
    cout << result1 << endl;

    // Llamando a una función genérica con parámetros de tipo double
    result2 = add<double>(2.2, 3.3);
    cout << result2 << endl;

    return 0;
}
