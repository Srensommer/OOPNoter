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

// destructor
// .h Lav virtuel hvis der er nedarvning fra denne klasse.
public:
	~Lokale();


// .cpp sletter her dynamisk allokeret memory, det skal den!
Lokale::~Lokale()
{
	delete[] type_;
}



// Overload assignment
// i .h filen
public:
	const Lokale & operator=(const Lokale &copyMe);


// i .cpp filen
const Lokale & Lokale::operator=(const Lokale & copyMe)
{
	if (this != &copyMe)
	{
		areal_ = copyMe.areal_;
		if (strlen(type_) != strlen(copyMe.type_))
		{
			delete[] type_;
			type_ = new char[strlen(copyMe.type_) + 1];
		}
		strcpy(type_, copyMe.type_);
	}
	return *this;
}