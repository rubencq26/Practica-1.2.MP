#include "Fecha.h"

// Constructor con par�metros
Fecha::Fecha(const int day, const int month, const int year) {
    int diasEnMes[] = { 31, (bisiesto() ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month > 0 && month < 13) {
        mes = month;
    }
    else if (month < 1) {
        mes = 1;
    }
    else {
        mes = 12;
    }

    if (day > 0 && day < diasEnMes[mes - 1] + 1) {
        dia = day;
    }
    else if (day < 1) {
        dia = 1;
    }
    else {
        dia = diasEnMes[mes - 1];
    }
    anio = year;
}

// Constructor por defecto
Fecha::Fecha() {
    dia = 1;
    mes = 1;
    anio = 1900;
}

// M�todo para mostrar la fecha
void Fecha::ver() const {

    cout << (dia < 10 ? "0" : "") << dia << "/" << (mes < 10 ? "0" : "") << mes << "/" << anio;
    //Asi se a�ade un 0 delante para que siempre tenga el fomato DD/MM/YYYY
}

// M�todo para comprobar si el a�o es bisiesto
bool Fecha::bisiesto() const {
    if (anio % 4 == 0) {
        if (anio % 100 != 0 || anio % 400 == 0) {
            return true;
        }
    }
    return false;
}

// M�todo para establecer la fecha
void Fecha::setFecha(const int day, const int month, const int year) {
    int diasEnMes[] = { 31, (bisiesto() ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month > 0 && month < 13) {
        mes = month;
    }
    else if (month < 1) {
        mes = 1;
    }
    else {
        mes = 12;
    }

    if (day > 0 && day < diasEnMes[mes - 1] + 1) {
        dia = day;
    }
    else if (day < 1) {
        dia = 1;
    }
    else {
        dia = diasEnMes[mes - 1];
    }
    anio = year;
}

// Operador de asignaci�n
Fecha& Fecha::operator=(const Fecha& f) {
    if (this != &f) {
        dia = f.dia;
        mes = f.mes;
        anio = f.anio;
    }
    return *this;
}

// Operador de pre-incremento (avanza un d�a)
Fecha& Fecha::operator++() {
    int diasEnMes[] = { 31, (bisiesto() ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    dia++; // Incrementa el d�a
    if (dia > diasEnMes[mes - 1]) { // Si se pasa del l�mite del mes
        dia = 1; // Reinicia el d�a
        mes++;   // Incrementa el mes
        if (mes > 12) { // Si se pasa del l�mite del a�o
            mes = 1;   // Reinicia el mes
            anio++;    // Incrementa el a�o
        }
    }
    return *this;
}

// Operador de post-incremento (avanza un d�a y devuelve el estado anterior)
Fecha Fecha::operator++(int) {
    Fecha temp = *this; // Almacena el estado actual
    ++(*this);          // Utiliza el operador pre-incremento para avanzar un d�a
    return temp;        // Devuelve la fecha original (estado anterior)
}

// Sobrecarga global del operador + para Fecha +  int
const Fecha operator+(const Fecha& f, int dias) {
    Fecha result = f;
    for (int i = 0; i < dias; ++i) {
        ++result; // Usa el operador de incremento
    }
    return result;
}

// Sobrecarga global del operador + para int + Fecha
const Fecha operator+(int dias, const Fecha& f) {
    return f + dias; // Reutiliza la l�gica de Fecha + int
}

// Sobrecarga del operador << para la clase Fecha
ostream& operator<<(ostream& os, const Fecha& f) {
    os << f.dia << "/" << f.mes << "/" << f.anio;
    return os;
}