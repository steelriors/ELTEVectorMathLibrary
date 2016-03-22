#include "Matrix.h"
#include <math.h> 

using namespace std;

namespace ELTEVectorMathLib
{

	Matrix::Matrix(const Vector& row0, const Vector& row1, const Vector& row2, const Vector& row3)
	{
		row[0] = row0;
		row[1] = row1;
		row[2] = row2;
		row[3] = row3;
	}


	Matrix::~Matrix()
	{
	}

	Matrix Matrix::Multiply(const Matrix& a, const Matrix& b)
	{
		Matrix retVal;
		Matrix b_transposed = Transpose(b);

		retVal.row[0] = Vector(Vector::Dot(a.row[0], b_transposed.row[0]), Vector::Dot(a.row[0], b_transposed.row[1]), Vector::Dot(a.row[0], b_transposed.row[2]), Vector::Dot(a.row[0], b_transposed.row[3]));
		retVal.row[1] = Vector(Vector::Dot(a.row[1], b_transposed.row[0]), Vector::Dot(a.row[1], b_transposed.row[1]), Vector::Dot(a.row[1], b_transposed.row[2]), Vector::Dot(a.row[1], b_transposed.row[3]));
		retVal.row[2] = Vector(Vector::Dot(a.row[2], b_transposed.row[0]), Vector::Dot(a.row[2], b_transposed.row[1]), Vector::Dot(a.row[2], b_transposed.row[2]), Vector::Dot(a.row[2], b_transposed.row[3]));
		retVal.row[3] = Vector(Vector::Dot(a.row[3], b_transposed.row[0]), Vector::Dot(a.row[3], b_transposed.row[1]), Vector::Dot(a.row[3], b_transposed.row[2]), Vector::Dot(a.row[3], b_transposed.row[3]));

		return retVal;
	}
	Matrix Matrix::Pow(const Matrix& a, unsigned int p)
	{
		if (p == 0)
			return Matrix::Identity();

		Matrix retVal = a;

		for (int i = 0; i < p-1; i++) {
			retVal = Matrix::Multiply(retVal, a);
		}

		return retVal;
	}
	Matrix Matrix::Transpose(const Matrix& a)
	{
		Matrix retVal;

		retVal.row[0] = Vector(a.row[0].x, a.row[1].x, a.row[2].x, a.row[3].x);
		retVal.row[1] = Vector(a.row[0].y, a.row[1].y, a.row[2].y, a.row[3].y);
		retVal.row[2] = Vector(a.row[0].z, a.row[1].z, a.row[2].z, a.row[3].z);
		retVal.row[3] = Vector(a.row[0].w, a.row[1].w, a.row[2].w, a.row[3].w);

		return retVal;
	}
	Matrix Matrix::Identity()
	{
		Matrix retVal;

		retVal.row[0] = Vector(1, 0, 0, 0);
		retVal.row[1] = Vector(0, 1, 0, 0);
		retVal.row[2] = Vector(0, 0, 1, 0);
		retVal.row[3] = Vector(0, 0, 0, 1);

		return retVal;
	}
	Matrix Matrix::Null()
	{
		Matrix retVal;

		for (int i = 0; i < 4; i++)
			retVal.row[i] = Vector(0, 0, 0, 0);

		return retVal;
	}
	Scalar Matrix::Norm_max(const Matrix& a)
	{
		Scalar max = abs(a.row[0].x);
		for (int i = 0; i < 4; i++) {
			if (max < abs(a.row[i].x))
				max = abs(a.row[i].x);
			if (max < abs(a.row[i].y))
				max = abs(a.row[i].y);
			if (max < abs(a.row[i].z))
				max = abs(a.row[i].z);
			if (max < abs(a.row[i].w))
				max = abs(a.row[i].w);
		}
		return max;
	}
	Scalar Matrix::Norm_1(const Matrix& a)
	{
		Scalar max = abs(a.row[0].x) + abs(a.row[1].x) + abs(a.row[2].x) + abs(a.row[3].x);
		if (max < abs(a.row[0].y) + abs(a.row[1].y) + abs(a.row[2].y) + abs(a.row[3].y))
			max = abs(a.row[0].y) + abs(a.row[1].y) + abs(a.row[2].y) + abs(a.row[3].y);
		if (max < abs(a.row[0].z) + abs(a.row[1].z) + abs(a.row[2].z) + abs(a.row[3].z))
			max = abs(a.row[0].z) + abs(a.row[1].z) + abs(a.row[2].z) + abs(a.row[3].z);
		if (max < abs(a.row[0].w) + abs(a.row[1].w) + abs(a.row[2].w) + abs(a.row[3].w))
			max = abs(a.row[0].w) + abs(a.row[1].w) + abs(a.row[2].w) + abs(a.row[3].w);
		return max;
	}
	Scalar Matrix::Norm_inf(const Matrix& a)
	{
		Scalar max = abs(a.row[0].x) + abs(a.row[0].y) + abs(a.row[0].z) + abs(a.row[0].w);
		for (int i = 1; i < 4; i++) {
			if (max < abs(a.row[i].x) + abs(a.row[i].y) + abs(a.row[i].z) + abs(a.row[i].w))
				max = abs(a.row[i].x) + abs(a.row[i].y) + abs(a.row[i].z) + abs(a.row[i].w);
		}
		return max;
	}
	Scalar Matrix::Norm_frob(const Matrix& a)
	{
		Scalar retVal = 0;
		for (int i = 0; i < 4; i++) {
			retVal += pow(a.row[i].x,2);
			retVal += pow(a.row[i].y,2);
			retVal += pow(a.row[i].z,2);
			retVal += pow(a.row[i].w,2);
		}
		retVal = sqrt(retVal);
		return retVal;
	}


	ostream& operator<<(ostream& os, const Matrix& m)
	{
		os << "[" << m.row[0] << endl << " " << m.row[1] << endl << " " << m.row[2] << endl << " " << m.row[3] << "]";
		return os;
	}

	bool operator==(const Matrix& a, const Matrix& b)
	{
		for (int i = 0; i < 4; i++) {
			if (a.row[i].x != b.row[i].x || a.row[i].y != b.row[i].y || a.row[i].z != b.row[i].z || a.row[i].w != b.row[i].w)
				return false;
			return true;
		}
	}
}