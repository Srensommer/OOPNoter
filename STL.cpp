//Erklæring af et objekt af STL klassen list.Derefter ligges 3 objekter af klassen ComplexNumber deri.
//Dette udskrives derefter med STL algoritmen copy.
{
	list<ComplexNumber> myList;
	ostream_iterator<ComplexNumber> myOutput(cout, "\n");
	myList.push_back(ComplexNumber(-2, 4));
	myList.push_back(ComplexNumber(6, -8));
	myList.push_back(ComplexNumber(10, 12));
	copy(myList.begin(), myList.end(), myOutput);
}
//Erklæring af et objekt af STL klassen vector.
//Ligges 3 objekter af klassen StraightLine I vector - objektet.
//Til sidst for-løkke der bruger en iterator til at gennemløbe vector-objektet og 
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
//Metoden returnerer en reference til Budget objektet, så der kan laves kaskadekald med indsaetPost.
// .h filen
private:
	vector<BudgetPost> poster_;
// .cpp filen
Budget & Budget::indsaetPost(const BudgetPost &p)
{
	poster_.push_back(p);
	return *this;
}
// Anden metode der gør brug af den samme attribut og en iterator
void Budget::printKategori(string k) const
{
	double sum = 0;
	//     Laver iterator	           iterator navn            vector metoder brugt til at tjekke om vi er færdige             
	for (vector<BudgetPost>::const_iterator it = poster_.cbegin(); it != poster_.cend();
		it++)
	{
					// Hvis den katagori iteratoren er nået til er katagori
		if (it->getKategori() == k)
		{
			// print nuværende iterator indhold
			cout << *it << endl;
			// og lig værdien fra det objekt iteratoren er ved til sum
			sum += it->getBeloeb();
		}
	}
	cout << endl << "Ialt udgifter for " << sum << " for kategori " << k << endl;
}


//en metode skulle kunne printe poster i kategoriers alfabetiske rækkefølge.
void Budget::print() const
{
	vector<BudgetPost> temp(poster_);
	// #include <algorithm>
	sort(temp.begin(), temp.end());
	cout << "budgettet har" << temp.size() << "poster" << endl;
	for (vector<BudgetPost>::const_iterator it = temp.cbegin(); it != temp.cend(); it++)
	{
		cout << *it << endl;
	}
}
