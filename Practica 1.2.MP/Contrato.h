#ifndef CONTRATO_H
#define CONTRATO_H
#include <iostream>
#include "Fecha.h"


class Contrato
{
	static int contador;
	const int idContrato;
	long int dniContrato;
	Fecha fechaContrato;

public:
	Contrato(long int, Fecha); //constructor clase padre
	virtual ~Contrato();//Destructor clase padre
	

	//Getters
	int getIdContrato() const{ return idContrato; }
	long int getDniContrato() const{ return dniContrato; }
	Fecha getFechaContrato() const{ return fechaContrato; }

	//Setters
	void setFechaContrato(Fecha f) { fechaContrato = f; }
	void setDniContrato(long int dni) { dniContrato = dni; }
	virtual void ver() const;

};

ostream& operator<<(ostream& o, const Contrato& c);

#endif