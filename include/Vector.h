#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <iostream>
#include "Scalar.h"

namespace ELTEVectorMathLib
{
	class Matrix;

	class Vector
	{
	public:
		Vector(Scalar x = 0, Scalar y = 0, Scalar z = 0, Scalar w = 0);
		~Vector();

		Scalar x, y, z, w;

		static Scalar Dot(const Vector& a, const Vector& b);
		static Vector Cross(const Vector& a, const Vector& b);
		static Vector Add(const Vector& a, const Vector& b);
		static Vector Subtract(const Vector& a, const Vector& b);
		static Vector Multiply(const Vector& a, Scalar b);
		static Vector Multiply(const Vector& a, const Vector& b);
		static Vector Multiply(const Vector& a, const Matrix& b);
		static Vector Multiply(const Matrix& a, const Vector& b);
		static Vector Identity();
		static Vector Null();
		static Vector Pow(const Vector& a, Scalar p);
		static Scalar Norm_p(const Vector& a, Scalar p);
		static Scalar Norm_inf(const Vector& a);
		static Vector Normalize(const Vector& a);
		static Scalar Length(const Vector& a);
		static Scalar Distance(const Vector& a, const Vector& b);
		static Vector Lerp(const Vector& a, const Vector& b, Scalar t);
	};


	std::ostream& operator<<(std::ostream& os, const Vector& v);
}

#endif // _VECTOR_H_

