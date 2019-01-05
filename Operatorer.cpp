// Operatorer


// Stream - operatoren << udskriver her data for objekt af klassen ComplexNumber ligesom metoden print().
// .h filen
ostream& operator<<(ostream& out, const ComplexNumber& number);
// .cpp filen
ostream& operator<<(ostream& out, const ComplexNumber& number)
{
	number.print();
	return out;
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


