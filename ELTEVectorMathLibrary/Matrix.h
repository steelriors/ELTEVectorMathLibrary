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

		static Matrix Multiply(const Matrix& a, const Matrix& b);
		static Matrix Transpose(const Matrix& a);
		static Matrix Identity();
	};


	std::ostream& operator<<(std::ostream& os, const Matrix& m);
}

#endif // _MATRIX_H_
