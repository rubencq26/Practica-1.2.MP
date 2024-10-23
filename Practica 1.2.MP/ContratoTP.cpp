#include "ContratoTP.h"

int ContratoTP::minutosTP = 300;
float ContratoTP::precioTP = 10;
const float ContratoTP::precioExcesoMinutos = 0.15;

ContratoTP::ContratoTP(long int dni, Fecha f, int m) : Contrato(dni, f) {
	minutosHablados = m;
	Contrato::setFechaContrato(f);
}



void ContratoTP::setTarifaPlana(int m, float p) {
	minutosTP = m;
	precioTP = p;
}

ostream& operator<<(ostream& s, const ContratoTP& c) {
	const char* meses[] = { "ene", "feb", "mar", "abr", "may", "jun", "jul", "ago", "sep", "oct", "nov", "dic" };
	int excesoMin = c.getLimiteMinutos() - c.getMinutosHablados();
	if (excesoMin > 0) {
		excesoMin = 0;
	}
	else {
		excesoMin = abs(excesoMin) * c.getPrecioExcesoMinutos();
	}
	s << c.getDniContrato() << " (" << c.getIdContrato() << " - "<<(c.getFechaContrato().getDia() < 10 ? "0" : "\0") << c.getFechaContrato().getDia() << " "<< (c.getFechaContrato().getMes() < 10 ? "0" : "\0") << meses[c.getFechaContrato().getMes() - 1] << " " << c.getFechaContrato().getAnio() << ") " << c.getMinutosHablados() << "m, " << c.getLimiteMinutos() << "(" << c.getPrecio() << ") - " << c.getPrecio() + excesoMin << "€";

	return s;
}

float ContratoTP::factura() const {
	float excesoMin = minutosTP - minutosHablados;
	if (excesoMin > 0) {
		excesoMin = 0;
	}
	else {
		excesoMin = abs(excesoMin) * precioExcesoMinutos;
	}

	return (precioTP + (excesoMin));
}

void ContratoTP::setMinutosHablados(int m) {
	minutosHablados = m;
}

void ContratoTP::ver() const {
	Contrato::ver();
	cout << minutosHablados << "m, " << minutosTP << " (" << precioTP<<")";
}
