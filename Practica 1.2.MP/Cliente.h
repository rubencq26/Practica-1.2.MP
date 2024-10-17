#ifndef CLIENTE_H
#define CLIENTE_H
#define _CRT_SECURE_NO_WARNINGS //Permite que pueda usar la libreria cstring en visual studio
#include "Fecha.h" // Para utilizar la clase Fecha
#include <iostream>
#include <cstring> // Para usar funciones de manejo de cadenas como strcpy

class Cliente {
private:
    int dni;
    char* nombre;
    Fecha fechaAlta;

public:
    // Constructor
    Cliente(int dni, const char* name, const Fecha& fecha);

    // Constructor por copia
    Cliente(const Cliente& other);

    // Destructor
    ~Cliente();

    // Getters
    int getDni() const { return dni; }
    const char* getNombre() const { return nombre; }
    Fecha getFecha() const;

    // Setters
    void setNombre(const char* name);
    void setFecha(const Fecha& fecha) { fechaAlta = fecha; }

    // Operadores
    bool operator==(const Cliente& c) const;
    Cliente& operator=(const Cliente& c);

    // Sobrecarga del operador de inserción
    friend std::ostream& operator<<(std::ostream& os, const Cliente& c);
};
#endif

