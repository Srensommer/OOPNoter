BitSet & BitSet::shiftIn(int data)
{
	// validerer hvis det er et "bit"
	if (data == 0 || data == 1)
	{
		// da der er en plads 0, skal size_ -1.
		for (int i = 0; i < size_ - 1; ++i)
		{
			// incrementer dataPtr_[]
			dataPtr_[i] = dataPtr_[i + 1];
		}
		//indsætter på pladse længst "til højre"
		dataPtr_[size_ - 1] = data;
	}
	return *this;
}


Txt::Txt(string name, bool priority) : Document(name + ".txt", priority)
{
	//Attributten text_ er en pointer til et dynamisk allokeret array, som skal indeholde
	//dokumentets tekst.
	text_ = new char[1]{ '\0' };
	*text_ = '\0';
	text_[0] = '\0';
}
