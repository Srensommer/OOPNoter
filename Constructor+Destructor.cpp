//Constructor/destructor helt basic
// .h filen
public:
// default constructor
	Circle();
// explicit constructor
	Circle(double);
// kombineret default / explicit constructor
	Circle(double x, double y, double r);

	
//.cpp filen
Circle::Circle()
{
	x_ = 0.0;
	y_ = 0.0;
	radius_ = 1.0;
}
	
	
Circle::Circle(double r)
{
	if (r > 0)
		radius_ = r;
	else
		radius_ = 1;
}

//Assignment i constructor
Circle::Circle(double x, double y, double r) 
{
	x_ = x; 
	y_ = y;
	radius_ = (r > 0 ? r : 1.0);
}


// Copy constructor