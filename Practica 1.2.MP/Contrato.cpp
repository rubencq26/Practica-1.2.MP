#include "Contrato.h"

int Contrato::contador = 1;


Contrato::Contrato(long int dni, Fecha f) : idContrato(contador), fechaContrato(f){
	//idContrato es constante por eso debemos inicializarlo en la zona de inicializadores
	contador++;
	this->dniContrato = dni;
	//fechaContrato al no ser un tipo primitivo de dato tambien debe inicializarse en la zona de inicializadores
}

Contrato::~Contrato() {

}

void Contrato::ver() const {
	cout << dniContrato << " (" << idContrato << " - "; fechaContrato.ver(); cout << ")";
}

ostream& operator<<(ostream& o,const Contrato& c) {
	const char* meses[] = { "ene", "feb", "mar", "abr", "may", "jun", "jul", "ago", "sep", "oct", "nov", "dic" };

	o << c.getDniContrato() << " (" << c.getIdContrato() << " - "<< (c.getFechaContrato().getDia() < 10 ? "0" : "\0") << c.getFechaContrato().getDia() << " "
		<< (c.getFechaContrato().getMes() < 10 ? "0" : "\0") << meses[c.getFechaContrato().getMes() - 1] << " " << c.getFechaContrato().getAnio() << ")";

	return o;
}
