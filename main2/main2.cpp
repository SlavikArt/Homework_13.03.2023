#include <iostream>
using namespace std;

class Circle
{
protected:
	double circleR;
public:
	Circle();
	Circle(double r);

	double CircleSquare() const;
	double CirclePerimeter() const;
	double CircleDiameter() const;

	void CircleOutput();

	friend ostream& operator<<(ostream& o, const Circle& cr);
};

Circle::Circle()
{
	circleR = 0;
}

Circle::Circle(double r)
{
	if (r > 0)
	{
		circleR = r;
	}
	else
	{
		circleR = 0;
	}
}

double Circle::CircleSquare() const
{
	return 3.14 * circleR * circleR;
}

double Circle::CirclePerimeter() const
{
	return 2 * 3.14 * circleR;
}

double Circle::CircleDiameter() const
{
	return circleR * 2;
}

void Circle::CircleOutput()
{
	cout << *this;
}

ostream& operator<<(ostream& o, const Circle& cr)
{
	o << "-Circle-" << "\n"
		<< "Radius: " << cr.circleR << "\n"
		<< "Diameter: " << cr.CircleDiameter() << "\n"
		<< "Perimeter: " << cr.CirclePerimeter() << "\n"
		<< "Square: " << cr.CircleSquare() << "\n";
	return o;
}

class Quadrate
{
protected:
	double quadrateSide;
public:
	Quadrate();
	Quadrate(double side);

	double QuadrateSquare() const;
	double QuadratePerimeter() const;
	double QuadrateDiagonal() const;

	void QuadrateOutput();

	friend ostream& operator<<(ostream& o, const Quadrate& qd);
};

Quadrate::Quadrate()
{
	quadrateSide = 0;
}

Quadrate::Quadrate(double side)
{
	if (side > 0)
	{
		quadrateSide = side;
	}
	else
	{
		quadrateSide = 0;
	}
}

double Quadrate::QuadrateSquare() const
{
	return quadrateSide * quadrateSide;
}

double Quadrate::QuadratePerimeter() const
{
	return quadrateSide * 4;
}

double Quadrate::QuadrateDiagonal() const
{
	return quadrateSide * sqrt(2);
}

void Quadrate::QuadrateOutput()
{
	cout << *this;
}

ostream& operator<<(ostream& o, const Quadrate& qd)
{
	o << "-Quadrate-" << "\n"
		<< "Side: " << qd.quadrateSide << "\n"
		<< "Diagonal: " << qd.QuadrateDiagonal() << "\n"
		<< "Perimeter: " << qd.QuadratePerimeter() << "\n"
		<< "Square: " << qd.QuadrateSquare() << "\n";
	return o;
}


class CircleInQuadrate : public Circle, public Quadrate
{
public:
	CircleInQuadrate();
	CircleInQuadrate(double R);

	void Output();
};

CircleInQuadrate::CircleInQuadrate()
{
}

CircleInQuadrate::CircleInQuadrate(double R)
	: Circle(R), Quadrate(R)
{

}

void CircleInQuadrate::Output()
{
	cout << "-CircleInQuadrate-\n\n";
	Circle::CircleOutput();
	cout << "\n";
	Quadrate::QuadrateOutput();
}

int main()
{
	CircleInQuadrate ciq(5.5);
	ciq.Output();
}
