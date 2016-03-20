#include "Matrix.h"

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


	ostream& operator<<(ostream& os, const Matrix& m)
	{
		os << "[" << m.row[0] << endl << " " << m.row[1] << endl << " " << m.row[2] << endl << " " << m.row[3] << "]";
		return os;
	}
}