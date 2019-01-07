//Dynamisk allokeret hukommelse 
//Eksempel p� metode der f�rst skal slette type_, og derefter allokkere hukommelse til ny type_
void Lokale::setType(char *type)
{
	if (type_ != nullptr)
	{
		delete[] type_;
	}
	type_ = new char[strlen(type_) + 1];
	strcpy(type_, type);
}

//I constructoren er type_ initialiseret s�ledes
type_ = nullptr;

// Dynamisk alokation af klasse i list objekt
// 
Kontor * l3 = new Kontor(areal, antalBorde);
lokaler_.push_back(l3);
// skrevet simplere
lokaler_.push_back(new Kontor(areal, antalBorde));


// Eksempel p� objekter der skal dynamisk allokeres
// Et array med 2 pointere til basisklassen oprettes
VaerdiPapir * arr[2];

//Laver objekter dynamisk allokeret og ligger dem p� pladser i arrayet.
arr[0] = new Aktie("B&O", 101.5, 50.0);
arr[1] = new Obligation("RD 16. serie 2047", 99.5, 2.0);

//genneml�ber arrayet og kalder beregn... p� begge objekter i arrayet.
for (int i = 0; i < 2; i++)
{
	cout << arr[i]->beregnHandelsVaerdi(1000) << endl;
}

