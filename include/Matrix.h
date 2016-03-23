#ifndef _MATRIX_H_
#define _MATRIX_H_
#include <iostream>
#include "Vector.h"

namespace ELTEVectorMathLib
{

	class Matrix
	{
	public:
		Matrix(const Vector& row0 = Vector(), const Vector& row1 = Vector(), const Vector& row2 = Vector(), const Vector& row3 = Vector());
		~Matrix();

		Vector row[4];

		static Matrix Add(const Matrix& a, const Matrix& b);
		static Matrix Subtract(const Matrix& a, const Matrix& b);
		static Matrix Multiply(const Matrix& a, const Matrix& b);
		static Matrix Pow(const Matrix& a, Scalar p);
		static Matrix Transpose(const Matrix& a);
		static Matrix Identity();
		static Matrix Null();
		static Scalar Norm_max(const Matrix& a);
		static Scalar Norm_1(const Matrix& a);
		static Scalar Norm_inf(const Matrix& a);
		static Scalar Norm_frob(const Matrix& a);
		static Matrix CreateRotation(Scalar x, Scalar y, Scalar z);
	};


	std::ostream& operator<<(std::ostream& os, const Matrix& m);
	bool operator==(const Matrix& a, const Matrix& b);
}

#endif // _MATRIX_H_
