//Rent virtuelle klasser kan ikke instantieres.
//Kig i .cpp filen. Implementationen(manglen p� dette) afsl�rer om det er virtual/pure virtual.
//Eksempel p� rent virtuel metode i .h filen. INGEN .cpp implementation.
public:
virtual double beregnVolumen() const = 0;

//Metoder der implementeres i afledte klasser, skal laves virtuelle.
//Nedarvning kr�ver typisk virtual deconstructor  i grundklassen.
//Eksempel p� en hel .h fil til en (pure) virtual klasse med virtuelle og pure virtual metoder.
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


//I constructoren for en klasse der arver, skal der kaldes p� hovedklassens constructor s�ledes. 
Rectangle::Rectangle(int x, int y, int vert, int hori)
	: Shape(x, y)//Et andet eksempel p� constructoren der skal arve.OvenRecipe::OvenRecipe(string name, int workTime, int temp, int ovenTime)
	:
	SimpleRecipe(name, workTime), temperature_(temp), ovenTime_(ovenTime)
{
}
//Husk at include .h filer der arves fra.
//En afledt klasse kunne se s�ledes ud. Bem�rk "class Kasse :public Beholder"
//Kasse arver i eksemplet fra beholder. lav ogs� funktioner der er virtual i baseclassen
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





