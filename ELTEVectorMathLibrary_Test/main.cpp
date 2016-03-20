#include <iostream>

#include "Scalar.h"
#include "Vector.h"
#include "Matrix.h"
#pragma comment(lib,"ELTEVectorMathLibrary.lib")

using namespace std;
using namespace ELTEVectorMathLib;

int main(int argc, char** argv)
{
	Vector v(0,1,2,3);
	Matrix m(v);

	cout << "ELTE Vector Math Library" << endl;

	cout << v << endl << m << endl << Matrix::Transpose(m) << endl << Matrix::Identity();

	cout << endl << endl << Vector::Multiply(v, m) << endl << Vector::Multiply(m, v);

	cout << endl << endl << Vector::Dot(v, v) << endl << Matrix::Multiply(m, Matrix::Identity());

	cout << endl << endl << Vector::Cross(v, Vector(1, 1, 1, 1)) << endl << Vector::Multiply(v, 2) << endl << Vector::Add(v, v);

	cin.get();

	return 0;
}