#include "Cliente.h"

// Constructor
Cliente::Cliente(int dni, const char* name, const Fecha& fecha) : dni(dni), fechaAlta(fecha) {
    nombre = new char[strlen(name) + 1];
    strcpy(nombre, name);
}

// Constructor por copia
Cliente::Cliente(const Cliente& other) : dni(other.dni), fechaAlta(other.fechaAlta) {
    nombre = new char[strlen(other.nombre) + 1];
    strcpy(nombre, other.nombre);
}

// Destructor
Cliente::~Cliente() {
    delete[] nombre;
}

// Setter para el nombre
void Cliente::setNombre(const char* name) {
    delete[] nombre;
    nombre = new char[strlen(name) + 1];
    strcpy(nombre, name);
}

// Operador de igualdad
bool Cliente::operator==(const Cliente& c) const {
    return dni == c.dni;
}

// Operador de asignación
Cliente& Cliente::operator=(const Cliente& c) {
    if (this != &c) {
        dni = c.dni;
        fechaAlta = c.fechaAlta;

        delete[] nombre;
        nombre = new char[strlen(c.nombre) + 1];
        strcpy(nombre, c.nombre);
    }
    return *this;
}

// Sobrecarga del operador de inserción para imprimir la información del cliente
std::ostream& operator<<(std::ostream& os, const Cliente& c) {
    const char* meses[] = { "ene", "feb", "mar", "abr", "may", "jun", "jul", "ago", "sep", "oct", "nov", "dic" };
    os << c.getNombre() << " (" << c.getDni() << " - " << (c.getFecha().getDia() < 10 ? "0" : "") << c.getFecha().getDia() << " " << meses[c.getFecha().getMes() - 1] << " " << c.getFecha().getAnio();

    return os;
}



Fecha Cliente::getFecha() const {
    return fechaAlta; // Devuelve el objeto Fecha en lugar de una cadena de caracteres
}