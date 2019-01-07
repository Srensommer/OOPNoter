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

// opretter en tom vector, der tager pointere til Shape objekter.
vector<Shape *> minVec;
//Ligger 3 Rectangle objekter i vectoren
minVec.push_back(new Rectangle(2, 3, 4, 5));
minVec.push_back(new Rectangle(10, 11, 14, 15));
minVec.push_back(new Rectangle(22, 23, 24, 25));
//laver loop med iterator der skriver objekterne ud en af gangen.
for (vector<Shape *>::const_iterator it = minVec.cbegin(); it != minVec.cend();
	it++)
{
	(*it)->draw();
}
}