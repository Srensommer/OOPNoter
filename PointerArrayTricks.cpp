BitSet & BitSet::shiftIn(int data)
{
	// validerer hvis det er et "bit"
	if (data == 0 || data == 1)
	{
		// da der er en plads 0, skal size_ -1.
		for (int i = 0; i < size_ - 1; ++i)
		{
			// incrementer dataPtr_[]
			dataPtr_[i] = dataPtr_[i + 1];
		}
		//indsætter på pladse længst "til højre"
		dataPtr_[size_ - 1] = data;
	}
	return *this;
}

//Laver integer array  
dataPtr_ = new int[size_];
//løber dem alle igennem
for (int i = 0; i < size_; i++)
{
	// sætter dem alle 0
	dataPtr_[i] = 0;
}


Txt::Txt(string name, bool priority) : Document(name + ".txt", priority)
{
	//Attributten text_ er en pointer til et dynamisk allokeret array, som skal indeholde
	//dokumentets tekst.
	text_ = new char[1]{ '\0' };
	*text_ = '\0';
	text_[0] = '\0';
}


// erklærer et dynamisk allokeret objekt af klassen CarInsurance
// Pointeren til objektet er af typen Insurance. udskriver objektets data ved at kalde metoden print() vha. pointeren.
int main()
{
	Insurance * myPtr = new CarInsurance("AB-10123456", 5000.00, 2500, 20000);
	myPtr->print();
	return 0;
}

//Metoden indsætter data bagerst i sekvensen. Returnerer pointer til objektet selv, så den kan kaskadekaldes.
//De nuværende værdier skal bevares og der skal skaffes plads til den nye værdi, der indsættes på pladsen med det højeste index
Sekvens & Sekvens::push_back(int data)
{
	//temp får dataPtr_ lagt i sig
	int * temp = dataPtr_;
	//Der bliver lavet nyt int array med en ekstra plads
	dataPtr_ = new int[length_ + 1];
	for (int i = 0; i < length_; i++)
	{
		//dataPtr får temp's værdier
		dataPtr_[i] = temp[i];
	}
	//dataPtr får det nye data i sig
	dataPtr_[length_] = data;
	//sletter temp, da den har tjent sit formål
	delete temp;
	//Længden er blevet en længere
	length_++;
	return *this;
}//Tjekker om index er okif (0 <= index && index < length_)
{	
	//returnerer dataPtr_ for det givne index hvis ok
	return dataPtr_[index];
}
else
{
	return 0;
}//Print metode til array hvor de enkelte værdier skal printes hver for sig.for (int i = 0; i < length_; ++i)
{
	cout << dataPtr_[i] << " ";
}