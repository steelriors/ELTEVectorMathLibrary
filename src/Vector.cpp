#include "../include/Vector.h"
#include "../include/Matrix.h"

using namespace std;

namespace ELTEVectorMathLib
{

	Vector::Vector(Scalar x, Scalar y, Scalar z, Scalar w) :x(x), y(y), z(z), w(w) 
	{
	}

	Vector::~Vector()
	{
	}

	Scalar Vector::Dot(const Vector& a, const Vector& b)
	{
		return (a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w);
	}
	Vector Vector::Cross(const Vector& a, const Vector& b)
	{
		return Vector(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 0);
	}
	Vector Vector::Add(const Vector& a, const Vector& b)
	{
		return Vector(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
	}
	Vector Vector::Subtract(const Vector& a, const Vector& b)
	{
		return Vector(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
	}
	Vector Vector::Multiply(const Vector& a, Scalar b)
	{
		return Vector(a.x*b, a.y*b, a.z*b, a.w*b);
	}
	Vector Vector::Multiply(const Vector& a, const Vector& b)
	{
		return Vector(a.x*b.x, a.y*b.y, a.z*b.z, a.w*b.w);
	}
	Vector Vector::Multiply(const Vector& a, const Matrix& b)
	{
		return Vector(
			a.x*b.row[0].x + a.y*b.row[1].x + a.z*b.row[2].x + a.w*b.row[3].x,
			a.x*b.row[0].y + a.y*b.row[1].y + a.z*b.row[2].y + a.w*b.row[3].y,
			a.x*b.row[0].z + a.y*b.row[1].z + a.z*b.row[2].z + a.w*b.row[3].z,
			a.x*b.row[0].w + a.y*b.row[1].w + a.z*b.row[2].w + a.w*b.row[3].w
			);
	}
	Vector Vector::Multiply(const Matrix& a, const Vector& b)
	{
		return Multiply(b, Matrix::Transpose(a));
	}
	Vector Vector::Pow(const Vector& a, /*unsigned int*/Scalar p)
	{
		//if (p == 0)
		//	return Vector::Identity();

		//Vector retVal = a;

		//for (unsigned int i = 0; i < p - 1; i++) {
		//	retVal = Vector::Multiply(retVal, a);
		//}

		//return retVal;
		return Vector(pow(a.x, p), pow(a.y, p), pow(a.z, p), pow(a.w, p));
	}
	Vector Vector::Identity()
	{
		return Vector(1, 0, 0, 0);
	}
	Vector Vector::Null()
	{
		return Vector(0, 0, 0, 0);
	}
	Vector Vector::RotateAroundX(const Vector& a, Scalar radians)
	{
		Matrix rotmatrix(Vector(1, 0, 0, 0),
			Vector(0, cos(radians), -sin(radians), 0),
			Vector(0, sin(radians), cos(radians), 0),
			Vector(0, 0, 0, 1));
		Vector retval;
		retval = Vector::Multiply(rotmatrix,a);
		return retval;
	}
	Vector Vector::RotateAroundY(const Vector& a, Scalar radians)
	{
		Matrix rotmatrix(Vector(cos(radians), 0, sin(radians), 0),
			Vector(0, 1, 0, 0),
			Vector(-sin(radians), 0, cos(radians), 0),
			Vector(0, 0, 0, 1));
		Vector retval;
		retval = Vector::Multiply(rotmatrix, a);
		return retval;
	}
	Vector Vector::RotateAroundZ(const Vector& a, Scalar radians)
	{
		Matrix rotmatrix(Vector(cos(radians), -sin(radians), 0, 0),
			Vector(sin(radians), cos(radians), 0, 0),
			Vector(0, 0, 1, 0),
			Vector(0, 0, 0, 1));
		Vector retval;
		retval = Vector::Multiply(rotmatrix, a);
		return retval;
	}
	Scalar Vector::Norm_p(const Vector& a, Scalar p)
	{
		Scalar retVal = 0;
		retVal = pow(a.x, p) + pow(a.y, p) + pow(a.z, p) + pow(a.w, p);
		retVal = pow(retVal, 1 / p);
		return retVal;
	}
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
	Vector Vector::Normalize(const Vector& a)
	{
		return Multiply(a, (Scalar)(1.0 / Length(a)));
	}
	Scalar Vector::Length(const Vector& a)
	{
		return sqrt(a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w);
	}
	Scalar Vector::Distance(const Vector& a, const Vector& b)
	{
		return Length(Subtract(b, a));
	}
	Vector Vector::Lerp(const Vector& a, const Vector& b, Scalar t)
	{
		return Vector(lerp(a.x, b.x, t), lerp(a.y, b.y, t), lerp(a.z, b.z, t), lerp(a.w, b.w, t));
	}


	ostream& operator<<(ostream& os, const Vector& v)
	{
		os << fixed << "( " << v.x << ", " << v.y << ", " << v.z << ", " << v.w << " )";
		return os;
	}
}
