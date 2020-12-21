//vect.cpp --method for vector class
#include<cmath>
#include"../inc/vector.h"
using std::sin;
using std::cos;
using std::atan2;
using std::cout;
namespace VECTOR 
{
	const double Rad_to_deg = 57.2957795130823;

	//private methods
	//calculates magnitude from x and y
	void Vector::set_mag() 
	{
		mag = sqrt(x*x+y*y);
	}

	void Vector::set_ang() 
	{
		if (x == 0.0 && y == 0.0)
		{
			ang = 0.0;
		}
		else 
		{
			ang = atan2(y, x); //函数返回的是原点至点(x,y)的方位角，即与 x 轴的夹角
		}
	}

	void Vector::set_x() 
	{
		x = mag * cos(ang);
	}
	
	void Vector::set_y() 
	{
		y = mag * sin(ang);
	}

	//piblic methods
	Vector::Vector()
	{
		x = y = mag = ang = 0.0;
		mode = 'r';
	}

	//construct vector from rectangular coordinates if form is r
	//(the default) or else from polar coordinates if is p
	Vector::Vector(double n1, double n2, char form) 
	{
		mode = form;
		if (form == 'r')
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == 'p') 
		{
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else 
		{
			cout << "Incorrect 3rd argument to Vector()--";
			cout << "vector set to 0\n";
			x = y = ang = 0.0;
			mode = 'r';
		}
	}

	//set vector from rectangular coordinates if form is r (the default)
	//or else from polar coordinates if form is p
	void Vector::set(double n1, double n2, char form)
	{
		mode = form;
		if (form == 'r') 
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == 'p') 
		{
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else 
		{
			cout << "Incorrect 3rd argument to Vector()--";
			cout << "vectro set to 0\n";
			x = y = ang = 0.0;
			mode = 'r';
		}
	}

	Vector::~Vector()  //destructor
	{
	}

	void Vector::polar_mode() 
	{
		mode = 'p';
	}

	void Vector::rect_mode() 
	{
		mode = 'r';
	}

	//operator overloading
	//add two Vectors
	Vector Vector::operator +(const Vector& b)const
	{
		return Vector(x + b.x, y + b.y);
	}

	//substract Vector b from a
	Vector Vector::operator-(const Vector& b)const 
	{
		return Vector(x - b.x, y - b.y);
	}

	//reverse sign of Vector
	Vector Vector::operator-()const 
	{
		return Vector(-x, -y);
	}

	//multiple vector by n
	Vector Vector::operator*(double n)const 
	{
		return Vector(x * n, y * n);
	}

	//friend methods
	//multply n by Vector a
	Vector operator* (double n, const Vector& a) 
	{
		return a * n;
	}

	//display rectangular coordinates if mode is r
	//else display popar coordinates if mode is p
	std::ostream& operator <<(std::ostream& os, const Vector& v) 
	{
		if (v.mode == 'r') 
		{
			os << "(x,y)=(" << v.x << "," << v.y << ")";
		}
		else if (v.mode == 'p') 
		{
			os << "(m,a)=(" << v.mag << "," << v.ang*Rad_to_deg << ")";
		}
		else 
		{
			os <<"Vector object mode is invalid";
		}
		return os;
	}
}