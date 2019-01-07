//Dynamisk allokeret hukommelse 
//Eksempel på metode der først skal slette type_, og derefter allokkere hukommelse til ny type_
void Lokale::setType(char *type)
{
	if (type_ != nullptr)
	{
		delete[] type_;
	}
	type_ = new char[strlen(type_) + 1];
	strcpy(type_, type);
}

//I constructoren er type_ initialiseret således
type_ = nullptr;

// Dynamisk alokation af klasse i list objekt
// 
Kontor * l3 = new Kontor(areal, antalBorde);
lokaler_.push_back(l3);
// skrevet simplere
lokaler_.push_back(new Kontor(areal, antalBorde));


// Eksempel på objekter der skal dynamisk allokeres
// Et array med 2 pointere til basisklassen oprettes
VaerdiPapir * arr[2];

//Laver objekter dynamisk allokeret og ligger dem på pladser i arrayet.
arr[0] = new Aktie("B&O", 101.5, 50.0);
arr[1] = new Obligation("RD 16. serie 2047", 99.5, 2.0);

//gennemløber arrayet og kalder beregn... på begge objekter i arrayet.
for (int i = 0; i < 2; i++)
{
	cout << arr[i]->beregnHandelsVaerdi(1000) << endl;
}




//Constructor der allokerer dynamisk hukommelse
Bog::Bog(const char * titel, int antalSider)
{
	// antalSider initialiseres as pr. usual
	antalSider_ = (antalSider > 0 ? antalSider : 0);
	// titel_ initialiseres med dynamisk hukommelse!
	titel_ = new char[strlen(titel) + 1];
	// titel ligges i titel_   Vigtigt!
	strcpy(titel_, titel);
}
//Constructor Objekter af klassen skal kan indeholde en række(0 og 1)'ere. 
// Disse opbevares i et array allokeret dynamisk via pointeren numberPtr_.
BinaryCache::BinaryCache(int capacity)
{
	capacity_ = (capacity > 1 ? capacity : 1);
	size_ = 0;
	numberPtr_ = new int[capacity_];
}
//metode til indsættelse af 1/0. Ligges ind bagerst i arrayet, hvis der er plads.
void BinaryCache::addNumber(int number)
{
	if (number == 0 || number == 1) {
		//Hvis alt plads er optaget
		if (capacity_ == size_) {
			int *temp = numberPtr_;
			//fordobbel capacity
			capacity_ *= 2;
			//lav nyt array med dobbelt capacity
			numberPtr_ = new int[capacity_];

			for (int i = 0; i < size_; i++)
				numberPtr_[i] = temp[i];
			//sletter temp igen
			delete[] temp;
		}
		//pejer på den plads tallet skal ligges ind i
		numberPtr_[size_++] = number;
	}
}






//eksempel på metode der skal sætte alle pladser i et int array til 0.
BitSet::BitSet(int size)
{
	size_ = size > 0 ? size : 32;
	//Laver int array 
	dataPtr_ = new int[size_];
	//løber igennem arrayet med for loop
	for (int i = 0; i < size_; i++)
	{
		//Sætter alle pladserne til 0
		dataPtr_[i] = 0;
	}
}