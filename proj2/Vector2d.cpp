/*
 * Class to represent a 2-dimensional vector.
 */
#include <cmath>
#include "Vector2d.h"


// Default constructor
Vector2d::Vector2d() : x(0.0), y(0.0){}

Vector2d::Vector2d(double _x, double _y) : x(_x), y(_y){}

// Dot product
double Vector2d::dot(const Vector2d& v) const
{
	return x*v.x + y*v.y;
}

// Vector magnitude
double Vector2d::magnitude() const
{
	return sqrt(x*x+y*y);
}

// Nomralized vector
const Vector2d Vector2d::normalize() const
{
	if(magnitude()==0) return *this;
	return Vector2d(x/magnitude(), y/magnitude());
}

// getters and setters
double Vector2d::getX() const
{
	return x;
}

double Vector2d::getY() const
{
	return y;
}

void Vector2d::setX(double _x)
{
	x=_x;
}

void Vector2d::setY(double _y)
{
	y=_y;
}

// overloaded operators -- assignment operators
Vector2d& Vector2d::operator+=(const Vector2d& rhs)
{
	x+=rhs.x;
	y+=rhs.y;
	return *this;
}

Vector2d& Vector2d::operator-=(const Vector2d& rhs)
{
	x-=rhs.x;
	y-=rhs.y;
	return *this;
}

Vector2d& Vector2d::operator*=(double c)
{
	x*=c;
	y*=c;
	return *this;
}

// overloaded operators -- arithmetic
const Vector2d operator +(Vector2d lhs, const Vector2d& rhs)
{
	lhs+=rhs;
	return lhs;
}

const Vector2d operator -(Vector2d lhs, const Vector2d& rhs)
{
	lhs-=rhs;
	return lhs;
}

const Vector2d operator *(Vector2d lhs, double rhs)
{
	lhs*=rhs;
	return lhs;
}

const Vector2d operator *(double lhs, Vector2d rhs)
{
	rhs*=lhs;
	return rhs;
}

const Vector2d Vector2d::operator-()
{
	return Vector2d(-x, -y);
}



// overloaded operators -- comparisons
bool operator ==(const Vector2d& v1, const Vector2d& v2)
{
	return v1.x==v2.x && v1.y==v2.y;
}

bool operator !=(const Vector2d& v1, const Vector2d& v2)
{
	return !(v1==v2);
}

// overloaded I/O operators
std::ostream& operator <<(std::ostream& os, const Vector2d& v)
{
	os<<"("<<v.x<<", "<<v.y<<")";
	return os;
}

std::istream& operator >> (std::istream& is, Vector2d& v)
{
	is >> v.x;
	is >> v.y;
	return is;
}


