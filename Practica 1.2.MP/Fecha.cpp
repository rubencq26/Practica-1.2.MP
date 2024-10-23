#include "Fecha.h"

// Constructor con parámetros
Fecha::Fecha(const int day, const int month, const int year) {
    this->setFecha(day, month, year); //el cogido es el mismo que el del metodo setFecha
}

// Constructor por defecto
Fecha::Fecha() {
    dia = 1;
    mes = 1;
    anio = 1900;
}

// Método para mostrar la fecha
void Fecha::ver() const {

    cout << (dia < 10 ? "0" : "") << dia << "/" << (mes < 10 ? "0" : "") << mes << "/" << anio;
    //Asi se añade un 0 delante para que siempre tenga el fomato DD/MM/YYYY
}

// Método para comprobar si el año es bisiesto
bool Fecha::bisiesto() const {
    if (anio % 4 == 0) {
        if (anio % 100 != 0 || anio % 400 == 0) {
            return true;
        }
    }
    return false;
}

// Método para establecer la fecha
void Fecha::setFecha(const int day, const int month, const int year) {
    int dmax, diaMes[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };// array del numero de dias de cada mes

    this->anio = year; //VIP debo asignar año para que al llamar a bisiesto() tenga el año bien

    if (this->bisiesto()) {
        diaMes[2] = 29; //febrero tiene 29 dias si es bisiesto
    }

    /// MES
    if (month < 1) {
        this->mes = 1; // Si el mes es menor que 1, ponemos enero
    }
    else if (month > 12) {
        this->mes = 12; // Si el mes es mayor que 12, será diciembre
    }
    else {
        this->mes = month;
    }

    dmax = diaMes[this->mes]; //miramos el dia maximo que tiene ese mes

    /// DIA
    if (day > dmax) {
        this->dia = dmax;// Si el dia es mayor que el que se el máximo, se le asigna el máximo
    }
    else if (day < 1) {
        this->dia = 1; //si es menor que 1, se pone a 1
    }
    else {
        this->dia = dia;
    }
}

// Operador de asignación
Fecha& Fecha::operator=(const Fecha& f) {
    if (this != &f) {
        dia = f.dia;
        mes = f.mes;
        anio = f.anio;
    }
    return *this;
}

// Operador de pre-incremento (avanza un día)
Fecha& Fecha::operator++() {
    int diasEnMes[] = { 31, (bisiesto() ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    dia++; // Incrementa el día
    if (dia > diasEnMes[mes - 1]) { // Si se pasa del límite del mes
        dia = 1; // Reinicia el día
        mes++;   // Incrementa el mes
        if (mes > 12) { // Si se pasa del límite del año
            mes = 1;   // Reinicia el mes
            anio++;    // Incrementa el año
        }
    }
    return *this;
}

// Operador de post-incremento (avanza un día y devuelve el estado anterior)
Fecha Fecha::operator++(int) {
    Fecha temp = *this; // Almacena el estado actual
    ++(*this);          // Utiliza el operador pre-incremento para avanzar un día
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
    return f + dias; // Reutiliza la lógica de Fecha + int
}

// Sobrecarga del operador << para la clase Fecha
ostream& operator<<(ostream& os, const Fecha& f) {
    os << f.dia << "/" << f.mes << "/" << f.anio;
    return os;
}