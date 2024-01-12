#ifndef VEHICULO_HPP
#define VEHICULO_HPP

class Vehiculo {
public:
    Vehiculo(int param_velocidad);
    void acelerar();
    void frenar();

private:
    int velocidad;
};

#endif // VEHICULO_HPP
