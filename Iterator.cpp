//Metoden udskriver alle poster, der matcher en bestemt kategori, i den
//rækkefølge de er indsat i Budget.Til sidst udskrives summen af de matchende poster.
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
			//printer det pågældede objekt
			cout << *it << endl;
			//ligger det pågældende objekts beløb sammen
			sum += it->getBeloeb();
		}
	}
	cout << endl << "Ialt udgifter for " << sum << " for kategori " << k << endl;
}