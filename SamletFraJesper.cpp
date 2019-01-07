

//Ostream
//Fra .h fil
ostream& operator<<(ostream& out, const ComplexNumber& number);

//Fra .cpp fil
ostream & operator<<(ostream & out, const ComplexNumber & number)
{
	number.print();

	return out;
}

/////////////// EN ANDEN MULIGHED ///////////////////
ostream & operator<<(ostream & out, const ComplexNumber & number)
{
	out << number.getTekst() << " (" << number.getKategori() << ") " << number.getBeloeb();
	return out;
}



///////////////////////////////////////// Istream ///////////////////////
//Fra .h filen
istream & operator>>(istream& in, StraightLine & line);

//Fra .cpp filen
istream & operator>>(istream & in, StraightLine & line)
{
	int a, b;

	in >> a >> b;

	line.setSlope(a);
	line.setYCross(b);

	return in;
}

///////////////////////////////////    MEDLEM    ///////////////////////////////////
///////////////////////////////////  EQUAL FUNKTON  ////////////////////////////////////////

//Overload af == operator
//Er inde i klassen under public
bool operator==(const StraightLine & rightLine);

//Fra .cpp filen
bool StraightLine::operator==(const StraightLine & rightLine)
{
	return (slope_ == rightLine.slope_ && yCross_ == rightLine.yCross_);
}


///////////////////////////////////// MEDLEM ///////////////////////
////////////////////////////////// += OPERATOR  / PLUS LIG MED ////////////////////////////////// 
// skrives i klassen
Kaede & operator+=(const Kaede &right);

//skrives i .cpp filen.
Kaede Kaede::operator+=(const Kaede & left)
{
	antalLed_ += left.antalLed_;
	return *this;
}


///////////////////////////////////////////Overload af + operator ///////
////////////////////////////////////////////////// FRI GlOBAL 


// Skal være i .h filen 
ComplexNumber operator+(const ComplexNumber& left, const ComplexNumber& right);

//Fra .cpp filen
ComplexNumber operator+(const ComplexNumber & left, const ComplexNumber & right)
{
	return ComplexNumber(left.getRealPart() + right.getRealPart(),
		left.getImaginaryPart() + right.getImaginaryPart());
}


/////////////////////// HVIS DER KUN ER EN ATTRIBUT DER SKAL ADDERES ////////////////////

// Skal være i .h filen 
ComplexNumber operator+(const ComplexNumber& left, const ComplexNumber& right);

//Fra .cpp filen
ComplexNumber operator+(const ComplexNumber & left, const ComplexNumber & right)
{
	return ComplexNumber(left.getRealPart() + right.getRealPart();
}


//////////////////////////Overload af < operator / MINDRE END //
//////////////////////////// FRI GlOBAL 
// Skal være i .h filen 
bool operator <(const BudgetPost &, const BudgetPost &);


// Skal være i .cpp filen
bool operator<(const Budgetpost & l, const Budgetpost & r)
{
	return l.getKategori() < r.getKategori();
}


////////////////////////////////// SAMMENLIGNING AF OBJEKTER ///////////////////////////////
////////////////////////////////// STØRRE END > ( FRI GLOBAL) ////////////////////


// FRA .h fil
bool operator>(const Stang& left, const Stang& right);


// Fra .cpp fil 

bool operator>(const Stang & left, const Stang & right)
{
	return left.getLaengde() > right.getLaengde();
}



///////////////////////////////////     RULE OF THREE      /////////////////////////////////////////

//Destructor
//Fra .h filen
~BinaryCache();

//Fra .cpp filen
//Det er pointeren som skal deletes
BinaryCache::~BinaryCache()
{
	delete[] numberPtr_;
}

///////////////////////////////// COPY CONSTRUCTOR ////////////////////
/////////////////////////////////	 CHAR	 ///////////////////////////

//Copy Constructor
// Fra .h filen
Lokale(const Lokale &copyMe);

//Fra .cpp filen
Lokale::Lokale(const Lokale & copyMe)
{
	// DETTE ER IKKE CHAR ATTRIBUTTEN!!! 
	// HVIS DER ER FLERE ATTRIBUTTER; DER SKAL KOPIRES TILFØJES DE HER.
	areal_ = copyMe.areal_;

	// CHAR ATTRIBUTTEN DER SKAL KOPIERES
	type_ = new char[strlen(copyMe.type_) + 1];
	strcpy(type_, copyMe.type_);
}


///////////////////////////////// ASSIGNMENT OPERATOR ////////////////////
//////////////////////////////////	 CHAR	///////////////////////////
//Assignment operator
// Fra .h filen
const Lokale & operator=(const Lokale &copyMe);

//Fra .cpp filen
const Lokale & Lokale::operator=(const Lokale & copyMe)
{
	if (this != &copyMe)
	{
		if (strlen(type_) != strlen(copyMe.type_))
		{
			delete[] type_;
			type_ = new char[strlen(copyMe.type_) + 1];
		}
		strcpy(type_, copyMe.type_);

		// HVIS DER ER FLERE ATTRIBUTTER DER SKAL KOPIRES KAN DET GØRES HER
		areal_ = copyMe.areal_;
	}
	return *this;
}

///////////////////////////////// COPY CONSTRUCTOR ////////////////////
///////////////////////////////////// HVIS INT ///////////////////////////////////

//Copy Constructor
// Fra .h filen
BitSet(const BitSet &copyMe);



// Fra .cpp filen
BitSet::BitSet(const BitSet & copyMe) : size_(copyMe.size_)
{
	// Denne assignment er også tilladt i stedet for memberinitializer
	size_ = copyMe.size_;
	dataPtr_ = new int[size_];
	for (int i = 0; i < size_; i++)
	{
		dataPtr_[i] = copyMe.dataPtr_[i];
	}
}

///////////////////////////////// ASSIGNMENT OPERATOR ////////////////////
/////////////////////////////////////// HVIS INT / DOUBLE //////////////

//Assignment operator
// Fra .h filen
const BitSet & operator=(const BitSet &copyMe);  /// MÅSKE IKKE CONST

//Fra .cpp filen
const BitSet & BitSet::operator=(const BitSet & copyMe)
{
	// Test for self assignment meget vigtig
	if (this != &copyMe)
	{
		// // TJEK OM DET ER DE KORREKTE ATTRIBUTTER. ER DER EN CAPACITY SÅ SKAL DENNE BENYTTES.
		if (capacity_ != copyMe.capacity_)
		{
			delete[] numberPtr_;
			size_ = copyMe.size_;
			capacity_ = copyMe.capacity_;

			numberPtr_ = new int[capacity_];
		}



		for (int i = 0; i < size_; i++)
		{
			dataPtr_[i] = copyMe.dataPtr_[i];
		}
	}
	return *this;
}







////////////////////////////// Template class ///////////////////////////////////////
#pragma once
#include <iostream>
#include <String>
using namespace std;
class Plade
{
public:
	Plade(int laengde, int bredde, string unit);
	void setLaengde(int laengde);
	int getLaengde() const;
	void setBredde(int bredde);
	int getBredde() const;
	void print() const;
private:
	int laengde_;
	int bredde_;
	string unit_;
};

////  TIL  ////

#pragma once
#include <iostream>
#include <String>
using namespace std;

template<class T>

class Plade
{
public:
	Plade(T laengde, T bredde, string unit);
	void setLaengde(T laengde);
	T getLaengde() const;
	void setBredde(T bredde);
	T getBredde() const;
	void print() const;
private:
	T laengde_;
	T bredde_;
	string unit_;
};

//// fra .cpp filen bliver det lavet til en template som ligger i .h filen

Plade::Plade(int laengde, int bredde, string unit)
{
	setLaengde(laengde);
	setBredde(bredde);
	unit_ = (unit == "m" || unit == "cm" || unit == "mm" ? unit :
		"units");
}
//// står i .h filen i stedet for .cpp filen 
template<class T>
Plade<T>::Plade(T laengde, T bredde, string unit)
{
	setLaengde(laengde);
	setBredde(bredde);
	unit_ = (unit == "m" || unit == "cm" || unit == "mm" ? unit : "units");
}

/*	
	Alt koden står i .h filen og der er ikke en .cpp fil ved en template class
	alt der er int, double osv bliver lavet til T
	string bliver ikke lavet om (char gør måske heller ikke)	
*/

//// Oprette objekt i main for template class////
Plade<int> p1(90, 21, "cm");
Plade<double> p2(0.90, 0.21, "m");

///////////////////////////////// TEMPLATE  FUNKTION //////////////////////////

template <typename MyType>
void isInRange(const MyType &min, const MyType &max, const MyType &value)
{
	// Fx. denne måde, men opdeling i mindre kodebidder og brug af variable er også
	tilladt
		cout << value << " er" << (min <= value && value <= max ? "" : " ikke") << "
		mellem " << min << " og " << max;
}
// I MAIN

//Der behøves ingen særlig type angivelse, template funktionen bliver automatisk valgt ud fra værdierne
int main()
{
	isInRange(0, 10, 5);
	cout << endl;
	isInRange(0.0, 10.0, 13.5);
	cout << endl;
	isInRange('a', 'z', 'c');
	cout << endl;
}





//////////////////////////////// VIRTUAL OG PURE VIRTUAL /////////////////////////////////// 

//////////////////// BASE KLASSE .h ///////////////////////////////////

#pragma once
using namespace std;

class Beholder
{
public:
	Beholder();
	virtual ~Beholder();                          ///////////// ALTID
	virtual double beregnVolumen() const = 0;	// DENNE ER REN VIRTUAL
	virtual void print() const;					// DENNE ER VIRTUAL

protected:
	double volumen_;
};


////////////////////////////////// EN ARVE KLASSE ////////////////////////////// 

#pragma once
#include "Beholder.h"

class Kasse : public Beholder
{
public:
	Kasse(double, double, double);
	virtual ~Kasse();
	virtual double beregnVolumen() const;
	virtual	void print() const;

private:
	double hoejde_;
	double bredde_;
	double dybde_;

};


//////////////// ARV -  ANDET   ///////////

Rectangle::Rectangle(int x, int y, int vert, int hori)
	: Shape(x, y)										// VÆRDIERNE HENTES FRA BASE KLASSEN
{
	setSides(vert, hori);
}

//////////////////////////////////////// LIST / VECTOR / DEQUE ///////////////////////////
///////////////SKRIVES I MAIN - DENNE ER UDEN POINTER!!!!!!

vector<StraightLine> myVector;
myVector.push_back(line1);
myVector.push_back(line2);
myVector.push_back(line3);

vector<StraightLine>::iterator myIter;
for (myIter = myVector.begin(); myIter != myVector.end(); ++myIter)
{
	myIter->print();
}

	// OPGAVE TEKST
//Metoden tilfoejKontor(int areal, int antalBorde) skal tilføje et dynamisk allokeret Kontor objekt til listen lokaler_.

//Tilføje et dynamisk allokeret objekt til en list / DEQUE / VECTOR
lokale_.push_back(new Kontor(areal, antalBorde));


//////////////////////// UDSKRIVNING MED ITERATOR VHA LIST / VECTOR / DEQUE - MED POINTER*!!!!  ///////////////////////

///////////////////////////////Eksempel hvor alt laves i main() filen /////////////////////////////
Kasse K1(2, 3, 4);
Toende T1(4, 4, "Vingummi");

K1.print();
T1.print();

// Oprettelse af liste med pointer 
list<Beholder*>  mylist;

// Objekter bliver lagt ind i listen
////// MAIN FIL ///////
mylist.push_back(&K1);
mylist.push_back(&T);


//////////////////////////////////////////// HVIS DET GØRES I .CPP FIL ///////


// Objekter bliver lagt ind i listen
actorPtrs_.push_back(actorPtr);


// Iteratoren initieres
list<BASEKLASSE*>::iterator i; // const_iterator kan være nødvendig

//Der køres en for løkke
for (i = mylist.begin(); i != mylist.end(); i++)
(*i)->print();

//// ALTERNATIVT SKRIVES 

for (auto i = lokale_.begin(); i != lokale_.end(); ++i)
{
	(*i)->print();
}




//////////////////////////////////Eksempel hvor det laves i .h og .cpp filen  ////////////////////////////////

//Oprettelse af liste med pointer i .h filens attribut 
list<Lokale *> lokale_;





// Iteratoren initieres i .cpp filen 
list<Lokale *>::const_iterator listIter;

//Der køres en forløkke i .cpp filen
for (listIter = lokale_.cbegin(); listIter != lokale_.cend(); ++listIter)
(*listIter)->print();

///// ALTERNATIVT SKRIVES 

for (auto i = lokale_.begin(); i != lokale_.end(); ++i)
{
	(*i)->print();
}

// I opgavens main fil benyttes

MoviePerson d("Dustin Hoffman");
MoviePerson l("Lana Wachowski");
MoviePerson s("Sandra Bullock")


d.print();
l.print();
s.print();

// PROTOTYPEN SER SÅLEDES UD:
//Movie::Movie(string title, MoviePerson * directorPtr)

Movie m("Matrix Revisited", &l); // HUSK & for reference

m.hireActor(&d);  // Det samme gælder en reference til actorPtr;
m.hireActor(&s);

m.print();

//////////////////////// VECTOR  / DEQUE / LIST POINTER MED OPRETTELSE AF OBJEKT ///////

/*Opret en std::vector med plads til pointere til basisklassen Shape.I første
omgang skal den være tom.Indsæt nu pointere til 3 forskellige Rectangle objekter.
Lav til sidst en løkke, der med iteratorer udskriver de 3 objekter ved at kalde draw()
for hver af dem, for at demonstrere polymorfi.*/

// Opgave 2D - fokus vector med Shape *, iteratorer

vector<Shape *> shapeVec;

shapeVec.push_back(new Rectangle(2, 3, 4, 5));
shapeVec.push_back(new Rectangle(10, 11, 14, 15));
shapeVec.push_back(new Rectangle(22, 23, 24, 25));
for (vector<Shape *>::iterator i = shapeVec.begin(); i != shapeVec.end(); i++)
{
	(*i)->draw();
}
// Med auto og en anden dereference
for (auto i = shapeVec.begin(); i != shapeVec.end(); i++)
{
	(**i).draw();
}



////////////////////////////// VECTOR ///////////////////////////////////////


for (vector<BudgetPost> ::const_iterator it = poster_.begin; it != poster_.end; it++)
{
	if (it->getKategori() == kategori)
	{
		cout << *it << endl;
		sum += it->getBeloeb();
	}
}
cout << endl << "Ialt udgifter for " << sum << " for kategori " << k << endl;
}




////////////////////////////// DYNAMISK ALLOKERET OBJEKT /////////////////
/*

BESKRIVELSE AF OPGAVEN
Skriv et testprogram (main) hvori du erklærer et dynamisk allokeret objekt af klassen
CarInsurance. Policenummer skal være ”AB-10123456”, grundpris skal være
5000.00, selvrisiko skal være 2500 og km pr. år skal være 20000. Pointeren til
objektet skal være af typen Insurance

*/

Insurance * myPtr = new CarInsurance("AB-10123456", 5000.00, 2500, 20000);
myPtr->print();


///////////////////////////////// DYNAMISK ALLOKERET HUKOMMELSE ////////////////////////////////
//////////////////////////////////////     CHAR    ////////////////////////////////// 

//Constructoren skal desuden allokere dynamisk hukommelse til attributten titel_ og initialisere denne vha.parameteren titel.

Bog::Bog(const char * titel, int antalSider)
{
	titel_ = new char[strlen(titel) + 1];
	strcpy(titel_, titel);


	// ANDEN ATTRIBUT - SE BORT FRA
	antalSider_ = antalSider > 0 ? antalSider : 0;
}

//////////////////////// SET FUNKTION FOR DYNAMISK ALLOKERET /////////////////////////

void Ejer::setNavn(char *nytNavn)
{
	delete[] navnPtr_;
	navnPtr_ = new char[strlen(nytNavn) + 1];
	strcpy(navnPtr_, nytNavn);
}

// ET ALTERNATIV

void Txt::setText(char * newText)
{
	if (strlen(text_) != strlen(newText))
	{
		delete[] text_;
		text_ = new char[strlen(newText) + 1];
	}
	strcpy(text_, newText);
}


////////////////////////////////// FRIEND ///////////////////////////////

// Fra .h filen
class Person
{
	friend bool operator==(const Person &, const Person &);
public:
	Person(string = "Unknown", int = 0);
	string getName() const;
	int getAge() const;
	void print() const;
private:
	int age_;
	string name_;
};

bool operator==(const Person &, const Person &);


//// FRA .CPP
//// GANSKE ALM. 

bool operator==(const Person &pRef1, const Person &pRef2)
{
	if (pRef1.name_ == pRef2.name_ && pRef1.age_ == pRef2.age_)
		return true;
	else
		return false;
}



/////////////////////////////////////DYNAMISK ALLOKERET ARRAY ////////////////


////////////////// DYNAMISK ARRAY POINTER ///////////////////

// OPGAVE TEKST
/*
Lav et testprogram, der tester at dit arvehierarki fungerer korrekt ved at oprette et
array med 2 pointere til basisklassen VaerdiPapir. Indsæt et Aktie objekt og et
Obligation objekt oprettet ved dynamisk memory allokering. Lav en forløkke, der
gennemløber arrayet og kalder metoden beregnHandelsVaerdi() på begge
objekter for antallet 1000 og udskriver resultatet. Du skal bruge nedenstående
testdata.*/

int main()
{
	VaerdiPapir * arr[2];
	arr[0] = new Aktie("B&O", 101.5, 50.0);
	arr[1] = new Obligation("RD 16. serie 2047", 99.5, 2.0);
	for (int i = 0; i < 2; i++)
	{
		cout << arr[i]->beregnHandelsVaerdi(1000) << endl;
	}
	return 0;
}





/*
BitSet(int size)
Parameter: size Angiver antal pladser til bits, et per heltalsplads.
	Attributter :
	size_ : int Angiver antal pladser.Skal være større end 0, ellers sættes den til
	defaultværdien 32.
	dataPtr_ : int * Pointer til dynamisk allokeret array af heltal, der hver
	repræsenterer 1 bit, dvs lovlige værdier er 0 eller 1. Alle pladser initialiseres til 0.

	*/
size_ = (size > 0 ? size : 32);

dataPtr_ = new int[size_];

for (int i = 0; i < size_; i++)
{
	dataPtr_[i] = 0;			// initialiserer alle pladser til 0
}

/// TILFØJ TAL TIL DYNAMISK ARRAY/////////////////
// CONSTRUCTOREN HVOR DER INITIALISERES ET NY DYNAMISK ARRAY /
BinaryCache::BinaryCache(int capacity)
{
	capacity_ = (capacity > 1 ? capacity : 1);
	size_ = 0;
	numberPtr_ = new int[capacity_];
}

//// ÆNDRE ARRAY STØRRELSE VED DYNAMISK ALLOKERET ARRAY
void BinaryCache::addNumber(int number)
{
	if (number == 0 || number == 1) {
		if (capacity_ == size_) {
			int *temp = numberPtr_;
			capacity_ *= 2;
			numberPtr_ = new int[capacity_];
			for (int i = 0; i < size_; i++)
				numberPtr_[i] = temp[i];
			delete[] temp;
		}
		numberPtr_[size_++] = number;
	}
}



//////////////////////////// SHIFT IN ////////////// 


if (data == 0 || data == 1)
{
	for (int i = 0; i < size_ - 1; ++i)
	{
		dataPtr_[i] = dataPtr_[i + 1];
	}
	dataPtr_[size_ - 1] = data;
}
return *this;
}

///////////////// PUSH BACK /////////////////////
Sekvens & Sekvens::push_back(int data)
{
	int * temp = dataPtr_;
	dataPtr_ = new int[length_ + 1];
	for (int i = 0; i < length_; i++)
	{
		dataPtr_[i] = temp[i];
	}
	dataPtr_[length_] = data;
	delete temp;
	length_++;
	return *this;
}

//////////////////////////// GET BY INDEX

int Sekvens::getByIndex(int index) const
{
	if (0 <= index && index < length_)
	{
		return dataPtr_[index];
	}
	else
	{
		return 0;
	}
}

////////////////////////////// STATIC ///////////////

// Som den fremgår i klassen
private:
	int antalLed_;
	int kaedeNummer_;
	static int antalKaeder_;
};


// SKAL SKRIVES I .CPP FILEN I TOPPEN OVER CONSTRUCTOREN

#include "Kaede.h
#include <iostream>
int Kaede::antalKaeder_ = 0;

/////////////////////////// KASKADE ////////////////////

MoviePerson& MoviePerson::addOscar()
{
	numberOfOscars_++;
	return *this;
}



////////////////////////// PUSH TO BACK  / PUSH TO FRONT  / PRIORITET

void Printer::addToQueue(Document * d)
{
	if (d->getPriority())
	{
		// High priority, put in front
		printerQueue_.push_front(d);
	}
	else
	{
		printerQueue_.push_back(d);
	}
}

/////////////////// NULLPTR / NULL

//Attributten type_ skal ikke pege på noget men den skal initialiseres.

Lokale::Lokale(int areal)
{
	areal_ = (areal > 0 ? areal : 0);
	type_ = nullptr;
}

