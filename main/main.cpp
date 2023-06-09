﻿#include <iostream>
using namespace std;

class BaseFigure
{
protected:
	double baseSide;
public:
	BaseFigure();
	void Output();
};

BaseFigure::BaseFigure()
{
	baseSide = 0;
}

void BaseFigure::Output()
{
	cout << "-BaseFigure-" << "\n"
		<< "Base Side: " << baseSide << "\n";
}

class Triangle : public BaseFigure
{
	double sideA;
	double sideB;

	void Initialize(double base, double A, double B);
public:
	Triangle();
	Triangle(double base, double A, double B);

	double Square() const;
	double Perimeter() const;

	void Output();

	friend istream& operator>>(istream& i, Triangle& tr);
	friend ostream& operator<<(ostream& o, const Triangle& tr);
};

void Triangle::Initialize(double base, double A, double B)
{
	if (base > 0 && A > 0 && B > 0
		&& A + B > base && B + base > A && base + A > B)
	{
		sideA = A;
		sideB = B;
		baseSide = base;
	}
	else
	{
		sideA = 0;
		sideB = 0;
		baseSide = 0;
	}
}

Triangle::Triangle()
{
	sideA = 0;
	sideB = 0;
}

Triangle::Triangle(double base, double A, double B)
{
	Initialize(base, A, B);
}

double Triangle::Square() const
{
	double p = Perimeter() / 2;
	return sqrt(p * (p - sideA) * (p - sideB) * (p - baseSide));
}

double Triangle::Perimeter() const
{
	return sideA + sideB + baseSide;
}

void Triangle::Output()
{
	BaseFigure::Output();
	cout << "\n" << *this << "\n";
}

istream& operator>>(istream& i, Triangle& tr)
{
	cout << "Enter side A of a Triangle:\n"
		<< "--> ";
	i >> tr.sideA;
	cout << "Enter side B of a Triangle:\n"
		<< "--> ";
	i >> tr.sideB;
	cout << "Enter side C of a Triangle:\n"
		<< "--> ";
	i >> tr.baseSide;
	tr.Initialize(tr.baseSide, tr.sideA, tr.sideB);
	return i;
}

ostream& operator<<(ostream& o, const Triangle& tr)
{
	o << "-Triangle-" << "\n"
		<< "Side A: " << tr.sideA << "\n"
		<< "Side B: " << tr.sideB << "\n"
		<< "Side C: " << tr.baseSide << "\n"
		<< "Perimeter: " << tr.Perimeter() << "\n"
		<< "Square: " << tr.Square() << "\n";
	return o;
}

class Quadrate : public BaseFigure
{
	void Initialize(double base);
public:
	Quadrate();
	Quadrate(double base);

	double Square() const;
	double Perimeter() const;

	void Output();

	friend istream& operator>>(istream& i, Quadrate& qd);
	friend ostream& operator<<(ostream& o, const Quadrate& qd);
};

void Quadrate::Initialize(double base)
{
	if (base > 0)
	{
		baseSide = base;
	}
	else
	{
		baseSide = 0;
	}
}

Quadrate::Quadrate()
{
}

Quadrate::Quadrate(double base)
{
	Initialize(base);
}

double Quadrate::Square() const
{
	return baseSide * baseSide;
}

double Quadrate::Perimeter() const
{
	return baseSide * 4;
}

void Quadrate::Output()
{
	BaseFigure::Output();
	cout << "\n" << *this << "\n";
}

istream& operator>>(istream& i, Quadrate& qd)
{
	cout << "Enter a side of a Quadrate:\n"
		<< "--> ";
	i >> qd.baseSide;
	qd.Initialize(qd.baseSide);
	return i;
}

ostream& operator<<(ostream& o, const Quadrate& qd)
{
	o << "-Quadrate-" << "\n"
		<< "Side A: " << qd.baseSide << "\n"
		<< "Perimeter: " << qd.Perimeter() << "\n"
		<< "Square: " << qd.Square() << "\n";
	return o;
}

class Rectangle : public BaseFigure
{
	double sideB;

	void Initialize(double A, double B);
public:
	Rectangle();
	Rectangle(double A, double B);

	double Square() const;
	double Perimeter() const;

	void Output();

	friend istream& operator>>(istream& i, Rectangle& rt);
	friend ostream& operator<<(ostream& o, const Rectangle& rt);
};

void Rectangle::Initialize(double A, double B)
{
	if (A > 0 && B > 0)
	{
		baseSide = A;
		sideB = B;
	}
	else
	{
		baseSide = 0;
		sideB = 0;
	}
}

Rectangle::Rectangle()
{
	sideB = 0;
}

Rectangle::Rectangle(double A, double B)
{
	Initialize(A, B);
}

double Rectangle::Square() const
{
	return baseSide * sideB;
}

double Rectangle::Perimeter() const
{
	return baseSide * 2 + sideB * 2;
}

void Rectangle::Output()
{
	BaseFigure::Output();
	cout << "\n" << *this << "\n";
}

istream& operator>>(istream& i, Rectangle& rt)
{
	cout << "Enter side A of a Rectangle:\n"
		<< "--> ";
	i >> rt.baseSide;
	cout << "Enter side B of a Rectangle:\n"
		<< "--> ";
	i >> rt.sideB;
	rt.Initialize(rt.baseSide, rt.sideB);
	return i;
}

ostream& operator<<(ostream& o, const Rectangle& rt)
{
	o << "-Rectangle-" << "\n"
		<< "Side A: " << rt.baseSide << "\n"
		<< "Side B: " << rt.sideB << "\n"
		<< "Perimeter: " << rt.Perimeter() << "\n"
		<< "Square: " << rt.Square() << "\n";
	return o;
}

class Circle : public BaseFigure
{
	double R;

	void Initialize(double r);
public:
	Circle();
	Circle(double r);

	double Square() const;
	double Perimeter() const;
	double Diameter() const;

	void Output();

	friend istream& operator>>(istream& i, Circle& cr);
	friend ostream& operator<<(ostream& o, const Circle& cr);
};

void Circle::Initialize(double r)
{
	if (r > 0)
	{
		baseSide = r * 2;
		R = r;
	}
	else
	{
		baseSide = 0;
		R = 0;
	}
}

Circle::Circle()
{
	R = 0;
}

Circle::Circle(double r)
{
	Initialize(r);
}

double Circle::Square()  const
{
	return 3.14 * R * R;
}

double Circle::Perimeter()  const
{
	return 2 * 3.14 * R;
}

double Circle::Diameter() const
{
	return R * 2;
}

void Circle::Output()
{
	BaseFigure::Output();
	cout << "\n" << *this << "\n";
}

istream& operator>>(istream& i, Circle& cr)
{
	cout << "Enter radius of a Circle:\n"
		<< "--> ";
	i >> cr.R;
	cr.Initialize(cr.R);
	return i;
}

ostream& operator<<(ostream& o, const Circle& cr)
{
	o << "-Circle-" << "\n"
		<< "Radius: " << cr.R << "\n"
		<< "Diameter: " << cr.Diameter() << "\n"
		<< "Perimeter: " << cr.Perimeter() << "\n"
		<< "Square: " << cr.Square() << "\n";
	return o;
}

int main()
{
	Triangle tr;
	cin >> tr;

	cout << "\n";
	tr.Output();

	Quadrate qd;
	cin >> qd;

	cout << "\n";
	qd.Output();

	Rectangle rt;
	cin >> rt;

	cout << "\n";
	rt.Output();

	Circle cr;
	cin >> cr;

	cout << "\n";
	cr.Output();
}
