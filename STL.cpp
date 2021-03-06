// Vector med navn shapeVec oprettes med plads til pointere til basisklassen Shape.
vector<Shape *> shapeVec;
// Pointere til 3 rectangle objekter inds�ttes i shapeVec
shapeVec.push_back(new Rectangle(2, 3, 4, 5));
shapeVec.push_back(new Rectangle(10, 11, 14, 15));
shapeVec.push_back(new Rectangle(22, 23, 24, 25));
//Laver en forl�kke med iterator, der udskriver alle objekter ved at kalde metoden draw() for dem hver is�r. 
for (vector<Shape *>::iterator i = shapeVec.begin(); i != shapeVec.end(); i++)
{
	(*i)->draw();
}


//Erkl�ring af et objekt af STL klassen list.Derefter ligges 3 objekter af klassen ComplexNumber deri.
//Dette udskrives derefter med STL algoritmen copy.
{
	list<ComplexNumber> myList;
	ostream_iterator<ComplexNumber> myOutput(cout, "\n");
	myList.push_back(ComplexNumber(-2, 4));
	myList.push_back(ComplexNumber(6, -8));
	myList.push_back(ComplexNumber(10, 12));
	copy(myList.begin(), myList.end(), myOutput);
}
//Erkl�ring af et objekt af STL klassen vector.
//Ligges 3 objekter af klassen StraightLine I vector - objektet.
//Til sidst for-l�kke der bruger en iterator til at genneml�be vector-objektet og 
//udskrive dataen for alle StraightLine-objektor I vectoren.
vector<StraightLine> myVector;
myVector.push_back(line1);
myVector.push_back(line2);
myVector.push_back(line3);
vector<StraightLine>::iterator myIter;
for (myIter = myVector.begin(); myIter != myVector.end(); ++myIter)
{
	myIter->print();
}

//En klasse der har en metode der ligger poster i en vector.
//Metoden returnerer en reference til Budget objektet, s� der kan laves kaskadekald med indsaetPost.
// .h filen
private:
	vector<BudgetPost> poster_;
// .cpp filen
Budget & Budget::indsaetPost(const BudgetPost &p)
{
	poster_.push_back(p);
	return *this;
}
// Anden metode der g�r brug af den samme attribut og en iterator
void Budget::printKategori(string k) const
{
	double sum = 0;
	//     Laver iterator	           iterator navn            vector metoder brugt til at tjekke om vi er f�rdige             
	for (vector<BudgetPost>::const_iterator it = poster_.cbegin(); it != poster_.cend();
		it++)
	{
					// Hvis den katagori iteratoren er n�et til er katagori
		if (it->getKategori() == k)
		{
			// print nuv�rende iterator indhold
			cout << *it << endl;
			// og lig v�rdien fra det objekt iteratoren er ved til sum
			sum += it->getBeloeb();
		}
	}
	cout << endl << "Ialt udgifter for " << sum << " for kategori " << k << endl;
}


//en metode skulle kunne printe poster i kategoriers alfabetiske r�kkef�lge.
void Budget::print() const
{
	vector<BudgetPost> temp(poster_);
	// #include <algorithm> sort sorterer fra parameter 1 til parameter 2.
	sort(temp.begin(), temp.end());
	cout << "budgettet har" << temp.size() << "poster" << endl;
	//laver iterator og bruger den til at udskrive de sorterede poster.
	for (vector<BudgetPost>::const_iterator it = temp.cbegin(); it != temp.cend(); it++)
	{
		cout << *it << endl;
	}
}





//deque eksempel
{
public:
 void addToQueue(Document *);
 void printNextDocument();
 void showQueue() const;
private:
	//Her som en attribut
 deque<Document *> printerQueue_;
};
// Printer.cpp
#include "Printer.h"
#include <iostream>
using namespace std;
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
void Printer::printNextDocument()
{
	if (printerQueue_.empty())
	{
		cout << "Print queue is empty\n\n";
	}
	else
	{
		//Sender det "forreste" til print
		printerQueue_.front()->print();
		//Fjerner det forreste
		printerQueue_.pop_front();
	}
}//List eksempel med iterator, bem�rk at iteratoren kan erkl�res inden i for-statementlist<Beholder *> liste;
liste.push_back(&k);
liste.push_back(&t);
list<Beholder *>::iterator i;
for (i = liste.begin(); i != liste.end(); i++)
(*i)->print();




//Vector eksempel i constructor
// .h
private:
	std::vector<string> instrumenter_;
// .cpp

Musiker::Musiker(string navn, string inst1, string inst2, string inst3, string inst4)
{
	//navn skulle initialiseres normalt
	navn_ = navn;
	instrumenter_.push_back(inst1);
	if (inst2 != "")
		instrumenter_.push_back(inst2);
	if (inst3 != "")
		instrumenter_.push_back(inst3);
	if (inst4 != "")
		instrumenter_.push_back(inst4);
}


//I en anden klasse hvor musiker er en attribut
// .h
public:
	void tilfoejMusiker(Musiker * m);
private:
	std::list<Musiker*> musikere_;

// .cpp 
	void Band::tilfoejMusiker(Musiker * m)
	{
		musikere_.push_back(m);
	}

// en anden metode der bruger samme list som attribut
	void Band::print() const
	{
		std::cout << navn_ << std::endl;
		std::list<Musiker*>::const_iterator i;
		for (i = musikere_.begin(); i != musikere_.end(); i++)
			(*i)->print();
	}