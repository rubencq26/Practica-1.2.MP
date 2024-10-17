#ifndef FECHA_H
#define FECHA_H
#include <iostream>
using namespace std;

class Fecha {
private:
    int dia;
    int mes;
    int anio;

public:
    // Constructores
    Fecha(const int day, const int month, const int year);
    Fecha();

    // Getters y Setters
    int getDia() const { return dia; }
    int getMes() const { return mes; }
    int getAnio() const { return anio; }
    void setDia(const int day) { dia = day; }
    void setMes(const int month) { mes = month; }
    void setAnio(const int year) { anio = year; }
    void setFecha(const int day, const int month, const int year);

    // M�todos
    void ver() const;
    bool bisiesto() const;

    // Sobrecarga de operadores
    Fecha& operator=(const Fecha& f);
    Fecha& operator++();      // Pre-incremento
    Fecha operator++(int);    // Post-incremento
    friend ostream& operator<<(ostream& os, const Fecha& f);
    friend const Fecha operator+(const Fecha& f, int dias);
    friend const Fecha operator+(int dias, const Fecha& f);
};
#endif