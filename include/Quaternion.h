/**
* \class Quaternion
*
* \ingroup ELTEVectorMathLibrary
*
* This is a simple class for creating
* and manipulating quaternions.
*
* \author Janos Turanszki, Tamas Nyiri, Gergo Kiss
*
* \version 0.1
*
* \date $Date: 2016/03/24
*
*/

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
	bool operator==(const Quaternion& a, const Quaternion& b);
	bool operator!=(const Quaternion& a, const Quaternion& b);
}

#endif // _QUATERNION_H_

