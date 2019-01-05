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