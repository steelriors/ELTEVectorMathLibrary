#include "../include/Vector.h"
#include "../include/Matrix.h"

using namespace std;

namespace ELTEVectorMathLib
{
	///Constructor
	Vector::Vector(Scalar x, Scalar y, Scalar z, Scalar w) :x(x), y(y), z(z), w(w) 
	{
	}
	///Destructor
	Vector::~Vector()
	{
	}
	///Returns dot product of two vectors
	Scalar Vector::Dot(const Vector& a, const Vector& b)
	{
		return (a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w);
	}
	///Returns cross product of two vectors, 1st on left, 2nd on right
	Vector Vector::Cross(const Vector& a, const Vector& b)
	{
		return Vector(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 0);
	}
	///Adds two vectos
	Vector Vector::Add(const Vector& a, const Vector& b)
	{
		return Vector(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
	}
	///Substract 2nd vector from 1st
	Vector Vector::Subtract(const Vector& a, const Vector& b)
	{
		return Vector(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
	}
	///Multiplies vector with scalar
	Vector Vector::Multiply(const Vector& a, Scalar b)
	{
		return Vector(a.x*b, a.y*b, a.z*b, a.w*b);
	}
	///Multiplies vector with matrix, vector on the left, matrix on the right
	Vector Vector::Multiply(const Vector& a, const Matrix& b)
	{
		return Vector(
			a.x*b.row[0].x + a.y*b.row[1].x + a.z*b.row[2].x + a.w*b.row[3].x,
			a.x*b.row[0].y + a.y*b.row[1].y + a.z*b.row[2].y + a.w*b.row[3].y,
			a.x*b.row[0].z + a.y*b.row[1].z + a.z*b.row[2].z + a.w*b.row[3].z,
			a.x*b.row[0].w + a.y*b.row[1].w + a.z*b.row[2].w + a.w*b.row[3].w
			);
	}
	///Multiplies vector with matrix, matrix on the left, vector on the right
	Vector Vector::Multiply(const Matrix& a, const Vector& b)
	{
		return Multiply(b, Matrix::Transpose(a));
	}
	///Creates identity vector
	Vector Vector::Identity()
	{
		return Vector(1, 0, 0, 0);
	}
	///Creates null vector
	Vector Vector::Null()
	{
		return Vector(0, 0, 0, 0);
	}
	///Returns pth norm of vector
	Scalar Vector::Norm_p(const Vector& a, Scalar p)
	{
		Scalar retVal = 0;
		retVal = pow(a.x, p) + pow(a.y, p) + pow(a.z, p) + pow(a.w, p);
		retVal = pow(retVal, 1 / p);
		return retVal;
	}
	///Returns absolute value of biggest element from vector
	Scalar Vector::Norm_inf(const Vector& a)
	{
		Scalar max = abs(a.x);
		if (max < abs(a.y))
			max = abs(a.y);
		if (max < abs(a.z))
			max = abs(a.z);
		if (max < abs(a.w))
			max = abs(a.w);
		return max;

	}
	///Returns vector normalized to length of one
	Vector Vector::Normalize(const Vector& a)
	{
		return Multiply(a, (Scalar)(1.0 / Length(a)));
	}
	///Returns length of vector
	Scalar Vector::Length(const Vector& a)
	{
		return sqrt(a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w);
	}
	///Returns distance of two vectors
	Scalar Vector::Distance(const Vector& a, const Vector& b)
	{
		return Length(Subtract(b, a));
	}
	///
	Vector Vector::Lerp(const Vector& a, const Vector& b, Scalar t)
	{
		return Vector(lerp(a.x, b.x, t), lerp(a.y, b.y, t), lerp(a.z, b.z, t), lerp(a.w, b.w, t));
	}

	///Prints out vector
	ostream& operator<<(ostream& os, const Vector& v)
	{
		os << fixed << "( " << v.x << ", " << v.y << ", " << v.z << ", " << v.w << " )";
		return os;
	}
	///Returns true if two vectors are equal, false otherwise
	bool operator==(const Vector& a, const Vector& b)
	{
		if (a.x != b.x || a.y != b.y || a.z != b.z || a.w != b.w)
			return false;

		return true;
	}
	///Returns true if two vectors are NOT equal, false if they are
	bool operator!=(const Vector& a, const Vector& b)
	{
		if (a == b)
			return false;

		return true;
	}
}
