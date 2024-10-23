#include "ContratoMovil.h"


ContratoMovil::ContratoMovil(long int dni, Fecha f, float p, int m,const char* nac) : Contrato(dni, f) {
	precioMinuto = p;
	minutosHablados = m;
	nacionalidad = new char[strlen(nac) + 1];
	strcpy(nacionalidad, nac);
}

ContratoMovil::ContratoMovil(const ContratoMovil& c)
	: Contrato(c.getDniContrato(), c.getFechaContrato()),  // Llamada al constructor de Contrato
	precioMinuto(c.getPrecioMinuto()),
	minutosHablados(c.getMinutosHablados())
{
	// Copia profunda del puntero nacionalidad
	nacionalidad = new char[strlen(c.getNacionalidad()) + 1];
	strcpy(nacionalidad, c.getNacionalidad());
}

ContratoMovil::~ContratoMovil() {
	if (nacionalidad) {
		delete[] nacionalidad;
		nacionalidad = nullptr;  // Opcional, para evitar futuros problemas
	}

}

void ContratoMovil::setNacionalidad(const char* nac) {
	if (nacionalidad) {
		delete[] nacionalidad;  // Solo liberar si el puntero no es nulo
	}

	nacionalidad = new char[strlen(nac) + 1];
	strcpy(nacionalidad, nac);
}

void ContratoMovil::ver() const{
	Contrato::ver();
	cout << minutosHablados << "m, " << nacionalidad << " " << precioMinuto;

}

float ContratoMovil::factura() const {

	return minutosHablados * precioMinuto;
}

ostream& operator<<(ostream& s, const ContratoMovil& c) {
	const char* meses[] = { "ene", "feb", "mar", "abr", "may", "jun", "jul", "ago", "sep", "oct", "nov", "dic" };

	s << c.getDniContrato() << " (" << c.getIdContrato() << " - "<< (c.getFechaContrato().getDia() < 10 ? "0" : "\0") << c.getFechaContrato().getDia() << " "<< (c.getFechaContrato().getMes() < 10 ? "0" : "\0") << meses[c.getFechaContrato().getMes() - 1] << " " << c.getFechaContrato().getAnio() << ") " << c.getMinutosHablados() << "m, " << c.getNacionalidad() << " " << c.getPrecioMinuto() << " - " << c.factura() << "$";

	return s;
}