//Rent virtuelle klasser kan ikke instantieres.
//Kig i .cpp filen. Implementationen(manglen på dette) afslører om det er virtual/pure virtual.
//Eksempel på rent virtuel metode i .h filen. INGEN .cpp implementation.
public:
virtual double beregnVolumen() const = 0;

//Metoder der implementeres i afledte klasser, skal laves virtuelle.
//Nedarvning kræver typisk virtual deconstructor  i grundklassen.
//Eksempel på en hel .h fil til en (pure) virtual klasse med virtuelle og pure virtual metoder.
#pragma once
class Beholder
{
protected:
	double volumen_;

public:
	Beholder();
	virtual ~Beholder();
	virtual double beregnVolumen() const = 0; //pure virtual
	virtual void print();
};


//Husk at include .h filer der arves fra.
//En afledt klasse kunne se således ud. Bemærk "class Kasse :public Beholder"
//Kasse arver i eksemplet fra beholder. lav også funktioner der er virtual i baseclassen
//virtual i den afledte klasse
#pragma once
#include "Beholder.h"
class Kasse :public Beholder
{
public:
	Kasse(double hoejde, double bredde, double dybde);
	virtual ~Kasse();
	virtual double beregnVolumen() const;
	virtual void print() const;
private:
	double hoejde_, bredde_, dybde_;
};





