#include "Vector.h"
#include "Matrix.h"

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


	ostream& operator<<(ostream& os, const Vector& v)
	{
		os << "( " << v.x << ", " << v.y << ", " << v.z << ", " << v.w << " )";
		return os;
	}
}
