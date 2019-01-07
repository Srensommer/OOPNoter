//Metoden udskriver alle poster, der matcher en bestemt kategori, i den
//r�kkef�lge de er indsat i Budget.Til sidst udskrives summen af de matchende poster.
//ITERATOR BRUGT
// .cpp
void Budget::printKategori(string k) const
{
	double sum = 0;
	for (vector<BudgetPost>::const_iterator it = poster_.cbegin(); it != poster_.cend();
		it++)
	{
		if (it->getKategori() == k)
		{
			//printer det p�g�ldede objekt
			cout << *it << endl;
			//ligger det p�g�ldende objekts bel�b sammen
			sum += it->getBeloeb();
		}
	}
	cout << endl << "Ialt udgifter for " << sum << " for kategori " << k << endl;
}