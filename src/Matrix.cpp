#include "../include/Matrix.h"
#include <math.h> 

using namespace std;

namespace ELTEVectorMathLib
{
	///Constructor
	Matrix::Matrix(const Vector& row0, const Vector& row1, const Vector& row2, const Vector& row3)
	{
		row[0] = row0;
		row[1] = row1;
		row[2] = row2;
		row[3] = row3;
	}
	///Destructor
	Matrix::~Matrix()
	{
	}
	///Adds two matrices
	Matrix Matrix::Add(const Matrix& a, const Matrix& b)
	{
		Matrix retVal = a;
		for (int i = 0; i < 4; i++)
		{
			retVal.row[i].x += b.row[i].x;
			retVal.row[i].y += b.row[i].y;
			retVal.row[i].z += b.row[i].z;
			retVal.row[i].w += b.row[i].w;
		}
		return retVal;
	}
	///Substracts 2nd matrix from 1st matrix
	Matrix Matrix::Subtract(const Matrix& a, const Matrix& b)
	{
		Matrix retVal = a;
		for (int i = 0; i < 4; i++)
		{
			retVal.row[i].x -= b.row[i].x;
			retVal.row[i].y -= b.row[i].y;
			retVal.row[i].z -= b.row[i].z;
			retVal.row[i].w -= b.row[i].w;
		}
		return retVal;
	}
	///Multiplies 1st Matrix from left, to 2nd matrix to the right
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
	///Multiplies matrix with scalar
	Matrix Matrix::Multiply(const Matrix& a, Scalar b)
	{
		Matrix retVal = a;
		
		for (int i = 0; i < 4; i++)
		{
			retVal.row[i].x *= b;
			retVal.row[i].y *= b;
			retVal.row[i].z *= b;
			retVal.row[i].w *= b;
		}

		return retVal;
	}
	///Takes matrix to power p
	Matrix Matrix::Pow(const Matrix& a, Scalar p)
	{
		if (p == 0)
			return Matrix::Identity();

		Matrix retVal = a;

		for (unsigned int i = 0; i < p-1; i++) {
			retVal = Matrix::Multiply(retVal, a);
		}

		return retVal;
	}
	/// Transposes matrix
	Matrix Matrix::Transpose(const Matrix& a)
	{
		Matrix retVal;

		retVal.row[0] = Vector(a.row[0].x, a.row[1].x, a.row[2].x, a.row[3].x);
		retVal.row[1] = Vector(a.row[0].y, a.row[1].y, a.row[2].y, a.row[3].y);
		retVal.row[2] = Vector(a.row[0].z, a.row[1].z, a.row[2].z, a.row[3].z);
		retVal.row[3] = Vector(a.row[0].w, a.row[1].w, a.row[2].w, a.row[3].w);

		return retVal;
	}
	/// Creates identity matrix
	Matrix Matrix::Identity()
	{
		Matrix retVal;

		retVal.row[0] = Vector(1, 0, 0, 0);
		retVal.row[1] = Vector(0, 1, 0, 0);
		retVal.row[2] = Vector(0, 0, 1, 0);
		retVal.row[3] = Vector(0, 0, 0, 1);

		return retVal;
	}
	///Creates null matrix
	Matrix Matrix::Null()
	{
		Matrix retVal;

		for (int i = 0; i < 4; i++)
			retVal.row[i] = Vector(0, 0, 0, 0);

		return retVal;
	}
	///Returns the biggest absolute valued element from the matrix
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
	///Returns the maximum absolute column sum norm
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
	///Returns the maximum absolute row sum norm
	Scalar Matrix::Norm_inf(const Matrix& a)
	{
		Scalar max = abs(a.row[0].x) + abs(a.row[0].y) + abs(a.row[0].z) + abs(a.row[0].w);
		for (int i = 1; i < 4; i++) {
			if (max < abs(a.row[i].x) + abs(a.row[i].y) + abs(a.row[i].z) + abs(a.row[i].w))
				max = abs(a.row[i].x) + abs(a.row[i].y) + abs(a.row[i].z) + abs(a.row[i].w);
		}
		return max;
	}
	///Returns the square root of the sum of the squares of all elements
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
	///Creates roatation around x,y,z axis (values in radian)
	Matrix Matrix::CreateRotation(Scalar x, Scalar y, Scalar z)
	{
		Matrix rotX = Matrix(
			Vector(1, 0, 0, 0),
			Vector(0, cos(x), -sin(x), 0),
			Vector(0, sin(x), cos(x), 0),
			Vector(0, 0, 0, 1)
			);
		Matrix rotY = Matrix(
			Vector(cos(y), 0, sin(y), 0),
			Vector(0, 1, 0, 0),
			Vector(-sin(y), 0, cos(y)),
			Vector(0, 0, 0, 1)
			);
		Matrix rotZ = Matrix(
			Vector(cos(z), -sin(z), 0, 0),
			Vector(sin(z), cos(z), 0, 0),
			Vector(0, 0, 1, 0),
			Vector(0, 0, 0, 1)
			);
		return Matrix::Multiply(Matrix::Multiply(rotX, rotY), rotZ);
	}
	///Creates a translational matrix in x,y,z dimensions
	Matrix Matrix::Translate(Scalar x, Scalar y, Scalar z)
	{
		return Matrix(Vector(1, 0, 0, x), Vector(0, 1, 0, y), Vector(0, 0, 1, z), Vector(0, 0, 0, 1));
	}
	///Creates a scaling matrix in x,y,z dimensions
	Matrix Matrix::Scale(Scalar x, Scalar y, Scalar z)
	{
		return Matrix(Vector(x, 0, 0, 0), Vector(0, y, 0, 0), Vector(0, 0, z, 0), Vector(0, 0, 0, 1));
	}

	///Prints out the matrix
	ostream& operator<<(ostream& os, const Matrix& m)
	{
		os << fixed << "[" << m.row[0] << endl << " " << m.row[1] << endl << " " << m.row[2] << endl << " " << m.row[3] << "]";
		return os;
	}
	///Returns true if matrices are equal, false otherwise
	bool operator==(const Matrix& a, const Matrix& b)
	{
		for (int i = 0; i < 4; i++) {
			if (a.row[i].x != b.row[i].x || a.row[i].y != b.row[i].y || a.row[i].z != b.row[i].z || a.row[i].w != b.row[i].w)
				return false;
		}
		return true;
	}
}