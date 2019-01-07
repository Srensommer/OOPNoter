// magic keyword som indsættes før klassen påbegyndes men efter headers
template <class T>

//Når du laver en template klasse så skal der ikke være en tilhørende .cpp fil. 
//Implementering foregår altså i .h filen.
// Eksempel på en template klasse i .h.
template <class T>
class Plade
{
public:
	Plade(T laengde, T bredde, string unit);
	void setLaengde(T laengde);
	T getLaengde() const;
	void setBredde(T bredde);
	T getBredde() const;
	void print() const;
private:
	T laengde_;
	T bredde_;
	string unit_;
};

//Et eksempel på en af metoderne i .h filen der bruger template datatypen

template <class T>
T Plade<T>::getLaengde() const
{
	return laengde_;
}


// Eksempel på nogle templates.
int main()
{
	CircularBuffer<int> buffer1(5);
	buffer1.print();
	CircularBuffer<Point> buffer2(20);
	buffer2.print();
	CircularBuffer<double> buffer3;
	buffer3.print();
	return 0;
}


// en funktion der bruger templates laves
template <typename T>
void isInRange(const T &min, const T &max, const T &value)
{
	cout << value << " er" << (value >= min && value <= max ? " " : " ikke ");
	cout << "mellem " << min << " og " << max << "." << endl;
}
// tester funktionen og at den kan håndterer int, double og char. 
//bemærk at man ikke behøver skrive type!
int main()
{
	isInRange(0, 10, 5);
	isInRange<double>(0.0, 10.0, 13.5);
	isInRange('a', 'z', 'c');
}