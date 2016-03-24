#include "../include/SSEQuaternion.h"

using namespace std;

namespace ELTEVectorMathLib
{

	SSEQuaternion::SSEQuaternion(Scalar x, Scalar y, Scalar z, Scalar w)
	{
		_ASSERT(sizeof(Scalar) == sizeof(float) && "Double precision SSE Quaternion not implemented!");
		alignas(16) float a[] = { x, y, z, w };
		xyzw = _mm_load_ps(a);
	}

	SSEQuaternion::~SSEQuaternion()
	{
	}


	Scalar SSEQuaternion::x() const
	{
		alignas(16) float a[4];
		_mm_store_ps(a, xyzw);
		return a[0];
	}
	Scalar SSEQuaternion::y() const
	{
		alignas(16) float a[4];
		_mm_store_ps(a, xyzw);
		return a[1];
	}
	Scalar SSEQuaternion::z() const
	{
		alignas(16) float a[4];
		_mm_store_ps(a, xyzw);
		return a[2];
	}
	Scalar SSEQuaternion::w() const
	{
		alignas(16) float a[4];
		_mm_store_ps(a, xyzw);
		return a[3];
	}


	ostream& operator<<(ostream& os, const SSEQuaternion& v)
	{
		os << fixed << "( " << v.x() << ", " << v.y() << ", " << v.z() << ", " << v.w() << " )";
		return os;
	}
}