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
		//inds�tter p� pladse l�ngst "til h�jre"
		dataPtr_[size_ - 1] = data;
	}
	return *this;
}

//Laver integer array  
dataPtr_ = new int[size_];
//l�ber dem alle igennem
for (int i = 0; i < size_; i++)
{
	// s�tter dem alle 0
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


// erkl�rer et dynamisk allokeret objekt af klassen CarInsurance
// Pointeren til objektet er af typen Insurance. udskriver objektets data ved at kalde metoden print() vha. pointeren.
int main()
{
	Insurance * myPtr = new CarInsurance("AB-10123456", 5000.00, 2500, 20000);
	myPtr->print();
	return 0;
}

//Metoden inds�tter data bagerst i sekvensen. Returnerer pointer til objektet selv, s� den kan kaskadekaldes.
//De nuv�rende v�rdier skal bevares og der skal skaffes plads til den nye v�rdi, der inds�ttes p� pladsen med det h�jeste index
Sekvens & Sekvens::push_back(int data)
{
	//temp f�r dataPtr_ lagt i sig
	int * temp = dataPtr_;
	//Der bliver lavet nyt int array med en ekstra plads
	dataPtr_ = new int[length_ + 1];
	for (int i = 0; i < length_; i++)
	{
		//dataPtr f�r temp's v�rdier
		dataPtr_[i] = temp[i];
	}
	//dataPtr f�r det nye data i sig
	dataPtr_[length_] = data;
	//sletter temp, da den har tjent sit form�l
	delete temp;
	//L�ngden er blevet en l�ngere
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
}//Print metode til array hvor de enkelte v�rdier skal printes hver for sig.for (int i = 0; i < length_; ++i)
{
	cout << dataPtr_[i] << " ";
}