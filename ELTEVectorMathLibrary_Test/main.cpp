#include <iostream>

#include "../ELTEVectorMathLibrary/Scalar.h"
#include "../ELTEVectorMathLibrary/Vector.h"
#include "../ELTEVectorMathLibrary/Matrix.h"

using namespace std;
using namespace ELTEVectorMathLib;

int main(int argc, char** argv)
{
	const float PI = 3.1415927;

	Vector v(0,1,2,3);
	Matrix m(v);

	cout << "ELTE Vector Math Library" << endl;

	cout << v << endl << m << endl << Matrix::Transpose(m) << endl << Matrix::Identity();

	cout << endl << endl << Vector::Multiply(v, m) << endl << Vector::Multiply(m, v);

	cout << endl << endl << Vector::Dot(v, v) << endl << Matrix::Multiply(m, Matrix::Identity());

	cout << endl << endl << Vector::Cross(v, Vector(1, 1, 1, 1)) << endl << Vector::Multiply(v, 2) << endl << Vector::Add(v, v);

	cout << endl << endl << Vector::RotateAroundX(v, PI);

	cout << endl << endl << Vector::RotateAroundY(v, PI);

	cout << endl << endl << Vector::RotateAroundZ(v, PI);

	cout << endl << endl << Matrix::Norm_max(m);

	cout << endl << endl << Matrix::Norm_1(m);

	cout << endl << endl << Matrix::Norm_inf(m);

	cout << endl << endl << Matrix::Norm_frob(m);

	for (int i = 1; i < 5; i++)
		cout << endl << endl << Vector::Norm_p(v,i);

	cout << endl << endl << Vector::Norm_inf(v);

	m = Matrix(Vector(1, 2, 3, 4), Vector(2, 3, 4, 5), Vector(3, 4, 5, 6), Vector(4, 5, 6, 7));

	cout << endl << endl << m;

	for (int i = 0; i < 5; i++)
		cout << endl << endl << Matrix::Pow(m, i);

	cout << endl << endl << v;

	for (int i = 0; i < 5; i++)
		cout << endl << endl << Vector::Pow(v, i);

	cin.get();

	return 0;
}