// Operatorer
// overloading foregår i .h filen efter klassen.


// Stream - operatoren << udskriver her data for objekt af klassen ComplexNumber ligesom metoden print().
// .h filen
ostream& operator<<(ostream& out, const ComplexNumber& number);
// .cpp filen
ostream& operator<<(ostream& out, const ComplexNumber& number)
{
	number.print();
	return out;
}
// endnu et eksempel på <<, denne gang så den giver et specifikt output basseret på objekter
// .h filen
ostream& operator<<(ostream&, const BudgetPost&);
// .cpp filen 
ostream & operator<<(ostream & returDetHer, const BudgetPost & xd)
{
	returDetHer << xd.getTekst() << " (" << xd.getKategori() << ") " << xd.getBeloeb();
	return returDetHer;
}
//Måtte ikke bruge print();
// .h filen
ostream & operator<<(ostream &os, const Txt &);
// .cpp filen
ostream & operator<<(ostream & os, const Txt & t)
{
	os << endl << (t.getPriority() == 1 ? "High: " : "Low: ");
	os << t.getName() << endl << endl;
	os << t.getText() << endl << endl;
	return os;
}









//+operatoren adderer to objekter af klassen ComplexNumber.Operatoren er her I en fri(global) udgave.
// .h filen
ComplexNumber operator+(const ComplexNumber& left, const ComplexNumber& right);
// .cpp filen
ComplexNumber operator+(const ComplexNumber& left, const ComplexNumber& right)
{
	return ComplexNumber(left.getRealPart() + right.getRealPart(),
		left.getImaginaryPart() + right.getImaginaryPart());
}
// Andet eksempel på en fri implementation af +operatoren. 
// .h filen
const Lokale operator+(const Lokale &lokale1, const Lokale &lokale2);
// .cpp filen
const Lokale operator+(const Lokale &lokale1, const Lokale &lokale2)
{
	return Lokale(lokale1.getAreal() + lokale2.getAreal());
}




//Input - operatoren >> som her indlæser data I et objekt af klassen StraightLine.
// h.fil
istream & operator>>(istream& in, StraightLine & line);
// .cpp fil
istream & operator>>(istream & in, StraightLine & line)
{
	int a, b;
	in >> a >> b;
	line.setSlope(a);
	line.setYCross(b);
	return in;
}
//Indlæs data til line3 objektet vha. >> operatoren
cin >> line3;



//Equality - operatoren == som her undersøger om to objekter af klassen StraightLine er ens.Operatoren er her medlem af klassen StraightLine.
// h.fil
bool StraightLine::operator==(const StraightLine & rightLine);
// .cpp fil
bool StraightLine::operator==(const StraightLine & rightLine)
{
	return (slope_ == rightLine.slope_ && yCross_ == rightLine.yCross_);
}



// += operatoren. Returnerer en reference til den første af de 
// to objekter af klassen kaede der ligges sammen.
// h.fil
Kaede & operator+=(const kaede1 &right);
// .cpp fil
Kaede & Kaede::operator+=(const Kaede &right)
{
	antalLed_ += right.antalLed_;
	return *this;
}


// > operatoren. Som en fri operator. Sammenligner to objekter og returnerer ja/nej.
// .h fil 
bool operator>(const Stang & left, const Stang & right);
// .ccp fil
bool operator>(const Stang & left, const Stang & right)
{
	return left.getLaengde() > right.getLaengde();
}


