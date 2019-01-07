// copyconstructor
// Husk at der må være flere constructorer!
//For klassen lokale f.eks. i .h
public:
	Lokale(const Lokale &copyMe);
// i .cpp
Lokale::Lokale(const Lokale & copyMe)
{
	areal_ = copyMe.areal_;
	type_ = new char[strlen(copyMe.type_) + 1];
	strcpy(type_, copyMe.type_);
}

Sekvens(const Sekvens &);
Sekvens::Sekvens(const Sekvens & copyMe)
{
	length_ = copyMe.length_;
	dataPtr_ = new int[length_];
	for (int i = 0; i < length_; i++)
	{
		dataPtr_[i] = copyMe.dataPtr_[i];
	}
}

// destructor
// .h Lav virtuel hvis der er nedarvning fra denne klasse.
public:
	~Lokale();
// .cpp sletter her dynamisk allokeret memory, det skal den!
Lokale::~Lokale()
{
	delete[] type_;
}



// Overload assignment /copy assignment operator
// i .h filen
public:
	const Lokale & operator=(const Lokale &copyMe);
// Copy assignment operator
const Sekvens& operator=(const Sekvens &);

// .cpp filen Denne har en lenght attribut!
const Sekvens & Sekvens::operator=(const Sekvens & copyMe)
{
	if (this != &copyMe)
	{
		if (length_ != copyMe.length_)
		{
			delete dataPtr_;
			length_ = copyMe.length_;
			dataPtr_ = new int[length_];
		}
		for (int i = 0; i < length_; i++)
		{
			dataPtr_[i] = copyMe.dataPtr_[i];
		}
	}
	return *this;
}

// i .cpp filen
const Lokale & Lokale::operator=(const Lokale & copyMe)
{
	if (this != &copyMe)
	{
		// initialiserer også attributen areal_, den er ganske almindelig
		areal_ = copyMe.areal_;
		if (strlen(type_) != strlen(copyMe.type_))
		{
			//indmaden her skal typisk ændres lidt. Indeholder næsten altid delete[]
			delete[] type_;
			type_ = new char[strlen(copyMe.type_) + 1];
		}
		// ligger den kopierede i type_
		strcpy(type_, copyMe.type_);
	}
	return *this;
}

const BitSet & BitSet::operator=(const BitSet & copyMe)
{
	// Test for self assignment meget vigtig
	if (this != &copyMe)
	{
		// At teste størrelsen for at undgå reallokering er ekstra flot, men ikke obligatorisk
			if (size_ != copyMe.size_)
			{
				delete[] dataPtr_;
				size_ = copyMe.size_;
				dataPtr_ = new int[size_];
			}
		for (int i = 0; i < size_; i++)
		{
			//indsætter data i alle dataPtr's pladser
			dataPtr_[i] = copyMe.dataPtr_[i];
		}
	}
	return *this;
}

//bog manglede destructor, overload assignment og copy constructor// .h filen//copy constructorBog(const Bog &copy);
//destructor
~Bog();
//overload assignment
Bog & operator=(const Bog &right);//destructor as per usualBog::~Bog()
{
	delete[] titel_;
}// copyconstructorBog::Bog(const Bog & copy)
{
	titel_ = new char[strlen(copy.titel_) + 1];
	strcpy(titel_, copy.titel_);
	antalSider_ = copy.antalSider_;
}
// Overload assignment operator 
Bog & Bog::operator=(const Bog & right)
{
	if (this != &right)
	{
		if (strlen(titel_) != strlen(right.titel_))
		{
			delete[] titel_;
			titel_ = new char[strlen(right.titel_) + 1];
		}
		strcpy(titel_, right.titel_);
		antalSider_ = right.antalSider_;
	}
	return *this;
}