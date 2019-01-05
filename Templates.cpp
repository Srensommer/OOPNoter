// magic keyword som inds�ttes f�r klassen p�begyndes men efter headers
template <class T>

//N�r du laver en template klasse s� skal der ikke v�re en tilh�rende .cpp fil. 
//Implementering foreg�r alts� i .h filen.
// Eksempel p� en template klasse i .h.
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

//Et eksempel p� en af metoderne i .h filen der bruger template datatypen

template <class T>
T Plade<T>::getLaengde() const
{
	return laengde_;
}