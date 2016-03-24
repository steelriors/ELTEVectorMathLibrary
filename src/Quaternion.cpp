#include "../include/Quaternion.h"
#include "../include/Vector.h"
#include "../include/Matrix.h"

using namespace std;

namespace ELTEVectorMathLib
{
	///Constructor
	Quaternion::Quaternion(Scalar x, Scalar y, Scalar z, Scalar w) :x(x), y(y), z(z), w(w)
	{
	}
	///Destructor
	Quaternion::~Quaternion()
	{
	}
	///Creates quaternion with no rotation
	Quaternion Quaternion::Identity()
	{
		return Quaternion(0, 0, 0, 1);
	}
	///Multiplies two quaternions
	Quaternion Quaternion::Multiply(const Quaternion& a, Scalar b)
	{
		return Quaternion(a.x*b, a.y*b, a.z*b, a.w*b);
	}
	///Returns concatenation of two quaternions
	Quaternion Quaternion::Concatenate(const Quaternion& a, const Quaternion& b)
	{
		return Quaternion(
			a.w*b.x + a.x*b.w + a.y*b.z - a.z*b.y,
			a.w*b.y - a.x*b.z + a.y*b.w + a.z*b.x,
			a.w*b.z + a.x*b.y - a.y*b.x + a.z*b.w,
			a.w*b.w - a.x*b.x - a.y*b.y - a.z*b.z
			);
	}
	///Returns length of the quaternion
	Scalar Quaternion::Length(const Quaternion& a)
	{
		return sqrt(a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w);
	}
	///Makes length of quaternion 1
	Quaternion Quaternion::Normalize(const Quaternion& a)
	{
		Scalar l = Length(a);
		return Multiply(a, (Scalar)(1.0 / Length(a)));
	}
	///
	Quaternion Quaternion::CreateFromAxisAngle(const Vector& axis, Scalar angleRadians)
	{
		Quaternion result;
		float angle = angleRadians / 2.0f;
		float sinAngle = sin(angle);
		Vector n = Vector::Normalize(axis);
		result.x = n.x * sinAngle;
		result.y = n.y * sinAngle;
		result.z = n.z * sinAngle;
		result.w = cos(angle);
		return result;
	}
	///
	Matrix Quaternion::CreateMatrix(const Quaternion& q)
	{
		return Matrix(
			Vector(1 - 2 * sqr(q.y), 2 * q.x*q.y - 2 * q.z*q.w, 2 * q.x*q.z + 2 * q.y*q.w),
			Vector(2 * q.x*q.y + 2 * q.z*q.w, 1 - 2 * sqr(q.x) - 2 * sqr(q.z), 2 * q.y*q.z - 2 * q.x*q.w),
			Vector(2 * q.x*q.z - 2 * q.y*q.w, 2 * q.y*q.z + 2 * q.x*q.w, 1 - 2 * sqr(q.x) - 2 * sqr(q.y))
			);
	}
	///Prints out the quaternion
	ostream& operator<<(ostream& os, const Quaternion& q)
	{
		os << fixed << "{ " << q.x << ", " << q.y << ", " << q.z << ", " << q.w << " }";
		return os;
	}
}