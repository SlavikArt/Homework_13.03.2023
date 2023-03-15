#include <iostream>
using namespace std;

class Circle
{
protected:
	double circleR;
	double circleS;
	double circleP;
	double circleD;
public:
	Circle();
	Circle(double r);

	double CircleSquare();
	double CirclePerimeter();
	double CircleDiameter();

	void CircleOutput();

	friend ostream& operator<<(ostream& o, const Circle& cr);
};

Circle::Circle()
{
	circleR = 0;
	circleS = 0;
	circleP = 0;
	circleD = 0;
}

Circle::Circle(double r)
{
	if (r > 0)
	{
		circleR = r;
		circleD = CircleDiameter();
		circleP = CirclePerimeter();
		circleS = CircleSquare();
	}
	else
	{
		circleR = 0;
		circleS = 0;
		circleP = 0;
		circleD = 0;
	}
}

double Circle::CircleSquare()
{
	circleS = 3.14 * circleR * circleR;
	return circleS;
}

double Circle::CirclePerimeter()
{
	circleP = 2 * 3.14 * circleR;
	return circleP;
}

double Circle::CircleDiameter()
{
	circleD = circleR * 2;
	return circleD;
}

void Circle::CircleOutput()
{
	cout << *this;
}

ostream& operator<<(ostream& o, const Circle& cr)
{
	o << "-Circle-" << "\n"
		<< "Radius: " << cr.circleR << "\n"
		<< "Diameter: " << cr.circleD << "\n"
		<< "Perimeter: " << cr.circleP << "\n"
		<< "Square: " << cr.circleS << "\n";
	return o;
}

class Quadrate
{
protected:
	double quadrateSide;
	double quadrateDiagonal;
	double quadrateS;
	double quadrateP;
public:
	Quadrate();
	Quadrate(double side);

	double QuadrateSquare();
	double QuadratePerimeter();
	double QuadrateDiagonal();

	void QuadrateOutput();

	friend ostream& operator<<(ostream& o, const Quadrate& qd);
};

Quadrate::Quadrate()
{
	quadrateSide = 0;
	quadrateDiagonal = 0;
	quadrateS = 0;
	quadrateP = 0;
}

Quadrate::Quadrate(double side)
{
	if (side > 0)
	{
		quadrateSide = side;
		quadrateDiagonal = QuadrateDiagonal();
		quadrateP = QuadratePerimeter();
		quadrateS = QuadrateSquare();
	}
	else
	{
		quadrateSide = 0;
		quadrateDiagonal = 0;
		quadrateS = 0;
		quadrateP = 0;
	}
}

double Quadrate::QuadrateSquare()
{
	quadrateS = quadrateSide * quadrateSide;
	return quadrateS;
}

double Quadrate::QuadratePerimeter()
{
	quadrateP = quadrateSide * 4;
	return quadrateP;
}

double Quadrate::QuadrateDiagonal()
{
	quadrateDiagonal = quadrateSide * sqrt(2);
	return quadrateDiagonal;
}

void Quadrate::QuadrateOutput()
{
	cout << *this;
}

ostream& operator<<(ostream& o, const Quadrate& qd)
{
	o << "-Quadrate-" << "\n"
		<< "Side: " << qd.quadrateSide << "\n"
		<< "Diagonal: " << qd.quadrateDiagonal << "\n"
		<< "Perimeter: " << qd.quadrateP << "\n"
		<< "Square: " << qd.quadrateS << "\n";
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
