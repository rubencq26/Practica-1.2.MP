#ifndef CONTRATOTP_H
#define CONTRATOTP_H

#include <iostream> //cin, cout
#include "Fecha.h"
#include "Contrato.h"

using namespace std;

class ContratoTP : public Contrato {
	static int minutosTP;
	static float precioTP;
	int minutosHablados;
	static const float precioExcesoMinutos;

public:
	ContratoTP(long int dni, Fecha f, int m);
	//virtual ~ContratoTP(); //¿es necesario? pensar y reflexionad
	//ContratoTP(const ContratoTP& other);//¿es necesario? pensar y reflexionad
	//ContratoTP& operator=(const ContratoTP& c); //¿es necesario? pensar y reflexionad

	static int getLimiteMinutos() { return ContratoTP::minutosTP; }
	static float getPrecio() { return ContratoTP::precioTP; }
	int getMinutosHablados() const{ return minutosHablados; }
	const float getPrecioExcesoMinutos() const { return precioExcesoMinutos; }
	static void setTarifaPlana(int m, float p); //el el .cpp se pone la cabecera sin la palabra static
	float factura() const;
	void setMinutosHablados(int m);
	void ver() const;
	//A RELLENAR POR EL ALUMNO...

};

ostream& operator<<(ostream& s, const ContratoTP& c);

#endif // CONTRATOTP_H
