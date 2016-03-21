#ifndef _QUATERNION_H_
#define _QUATERNION_H_
#include <iostream>
#include "Scalar.h"

namespace ELTEVectorMathLib
{
	class Matrix;
	class Vector;

	class Quaternion
	{
	public:
		Quaternion(Scalar x = 0, Scalar y = 0, Scalar z = 0, Scalar w = 1);
		~Quaternion();

		Scalar x, y, z, w;

		static Quaternion Identity();
		static Quaternion Multiply(const Quaternion& a, Scalar b);
		static Quaternion Concatenate(const Quaternion& a, const Quaternion& b);
		static Scalar Length(const Quaternion& a);
		static Quaternion Normalize(const Quaternion& a);
		static Quaternion CreateFromAxisAngle(const Vector& axis, Scalar angleRadians);
		static Matrix CreateMatrix(const Quaternion& q);
	};


	std::ostream& operator<<(std::ostream& os, const Quaternion& v);
}

#endif // _QUATERNION_H_
