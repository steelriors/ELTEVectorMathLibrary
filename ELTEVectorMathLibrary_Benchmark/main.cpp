#include "../include/Scalar.h"
#include "../include/Vector.h"
#include "../include/Matrix.h"
#include "../include/Quaternion.h"
#include "../include/SSEVector.h"

#include <iostream>
using namespace std;
using namespace ELTEVectorMathLib;

#include "Timer.h"


#define _loop 1000000

int main()
{
	Vector vec0(3, 67, 2, 546);
	Vector vec1(325, 6, 34552, 132);
	SSEVector ssevec0(3, 67, 2, 546);
	SSEVector ssevec1(325, 6, 34552, 132);
	Matrix mat0(Vector(0, 2, 4, 6), Vector(1, 3, 5, 7), Vector(2, 4, 6, 8), Vector(3, 5, 7, 9));
	Matrix mat1(Vector(9, 8, 7, 6), Vector(5, 4, 3, 2), Vector(1, 0, 9, 8), Vector(7, 6, 5, 4));
	Quaternion quat0(21, 2, 324, 3);
	Quaternion quat1(3, 234, 43, 435345);

	////////////////////////////////////////////////////////////////////////////
	{
		TIMER("Vector Benchmark - Dot - FLOAT");
		for (int i = 0; i < _loop; ++i)
		{
			vec1 = Vector::Dot(vec0, vec1);
		}
	}
	{
		TIMER("Vector Benchmark - Dot - SSE");
		for (int i = 0; i < _loop; ++i)
		{
			ssevec1 = SSEVector::Dot(ssevec0, ssevec1);
		}
	}
	////////////////////////////////////////////////////////////////////////////
	{
		TIMER("Matrix Benchmark - Multiply - FLOAT");
		for (int i = 0; i < _loop; ++i)
		{
			mat1 = Matrix::Multiply(mat0, mat1);
		}
	}
	////////////////////////////////////////////////////////////////////////////
	{
		TIMER("Quaternion Benchmark - ConcatenateNormalized - FLOAT");
		for (int i = 0; i < _loop; ++i)
		{
			quat1 = Quaternion::Concatenate(Quaternion::Normalize(quat0), Quaternion::Normalize(quat1));
		}
	}
	////////////////////////////////////////////////////////////////////////////
	{
		TIMER("Vector Benchmark - MatrixMultiply - FLOAT");
		for (int i = 0; i < _loop; ++i)
		{
			vec0 = Vector::Multiply(vec0, mat0);
		}
	}
	////////////////////////////////////////////////////////////////////////////

	return 0;
}

