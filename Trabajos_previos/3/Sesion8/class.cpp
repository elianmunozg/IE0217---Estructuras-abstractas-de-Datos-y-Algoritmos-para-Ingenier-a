
// Plantilla de clase
template <class T>
class Number {
private:
    // Variable de tipo T
    T num;

public:
    // Constructor
    Number(T n) : num(n) {}

    // Función para obtener el valor de num
    T getNum() {
        return num;
    }
};

int main() {
    // Crea un objeto con tipo int
    Number<int> numberInt(7);

    // Crea un objeto con tipo double
    Number<double> numberDouble(7.7);

    // Imprime el valor almacenado en numberInt
    cout << "int Number = " << numberInt.getNum() << endl;

    // Imprime el valor almacenado en numberDouble
    cout << "double Number = " << numberDouble.getNum() << endl;

    return 0;
}