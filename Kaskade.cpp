//Metoden returnerer en reference til Budget objektet, s�ledes at der kan laves
//kaskadekald med indsaetPost.
Budget & Budget::indsaetPost(const BudgetPost & post)
{
	poster_.push_back(post);
	return *this;
}

//Kaskadekaldet udf�res s�ledes med et objekt prut
Budget prut;
prut.indsaetPost(t1).indsaetPost(t2).indsaetPost(t3).indsaetPost(t4).indsaetPost(t5);


// Returnerer reference til objektet selv, s�ledes at addOscar() kan kaldes i kaskade
MoviePerson& MoviePerson::addOscar()
{
	numberOfOscars_++;
	return *this;
}