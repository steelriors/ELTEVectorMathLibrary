#include <iostream>

#include "../ELTEVectorMathLibrary/Scalar.h"
#include "../ELTEVectorMathLibrary/Vector.h"
#include "../ELTEVectorMathLibrary/Matrix.h"
#include "../ELTEVectorMathLibrary/Quaternion.h"

using namespace std;
using namespace ELTEVectorMathLib;

int main(int argc, char** argv)
{
	const float PI = 3.1415927f;

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
		cout << endl << endl << Vector::Norm_p(v,(Scalar)i);

	cout << endl << endl << v;

	cout << endl << endl << Vector::Norm_inf(v);

	cout << endl << endl << Vector::Distance(Vector(1), Vector(32,5,21));

	auto dfds = Vector::Normalize(Vector(2332, 11, 33, 2));
	cout << endl << endl << dfds << " Length: " << Vector::Length(dfds);

	auto dfsdffsm = Quaternion::Normalize(Quaternion(3, 4, 5, 6));
	cout << endl << endl << dfsdffsm << " Length: " << Quaternion::Length(dfsdffsm);

	cout << endl << endl << Quaternion::CreateFromAxisAngle(Vector(1, 1, 1), PI);

	auto kldsfklsdglm = Matrix::CreateRotation(PI / 2, 0, 0);
	cout << endl << endl << kldsfklsdglm << endl << Vector::Multiply(Vector(0, 1, 0), kldsfklsdglm);

	auto lllllllllllllllllll = Quaternion::CreateMatrix(Quaternion::CreateFromAxisAngle(Vector(1, 0, 0), PI / 2));
	cout << endl << endl << lllllllllllllllllll << endl << Vector::Multiply(Vector(0, 1, 0), lllllllllllllllllll);

	cin.get();

	return 0;
}