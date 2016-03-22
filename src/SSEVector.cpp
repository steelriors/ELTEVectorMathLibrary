#include "../include/SSEVector.h"

using namespace std;

namespace ELTEVectorMathLib
{

	SSEVector::SSEVector(Scalar x, Scalar y, Scalar z, Scalar w)
	{
		_ASSERT(sizeof(Scalar) == sizeof(float) && "Double precision SSE Vector not implemented!");
		alignas(16) float a[] = { x, y, z, w };
		xyzw = _mm_load_ps(a);
	}

	SSEVector::~SSEVector()
	{
	}


	Scalar SSEVector::x() const
	{
		alignas(16) float a[4];
		_mm_store_ps(a, xyzw);
		return a[0];
	}
	Scalar SSEVector::y() const
	{
		alignas(16) float a[4];
		_mm_store_ps(a, xyzw);
		return a[1];
	}
	Scalar SSEVector::z() const
	{
		alignas(16) float a[4];
		_mm_store_ps(a, xyzw);
		return a[2];
	}
	Scalar SSEVector::w() const
	{
		alignas(16) float a[4];
		_mm_store_ps(a, xyzw);
		return a[3];
	}

	SSEVector SSEVector::Add(const SSEVector& a, const SSEVector& b)
	{
		SSEVector result;
		result.xyzw = _mm_add_ps(a.xyzw, b.xyzw);
		return result;
	}
	SSEVector SSEVector::Multiply(const SSEVector& a, const SSEVector& b)
	{
		SSEVector result;
		result.xyzw = _mm_mul_ps(a.xyzw, b.xyzw);
		return result;
	}
	SSEVector SSEVector::Dot(const SSEVector& a, const SSEVector& b)
	{
		SSEVector result;
		//result.xyzw = _mm_dp_ps(a.xyzw, b.xyzw, 1);
		__m128 m = _mm_mul_ps(a.xyzw, b.xyzw);
		__m128 t = _mm_add_ps(m, _mm_shuffle_ps(m, m, _MM_SHUFFLE(2, 3, 0, 1)));
		result.xyzw = _mm_add_ps(t, _mm_shuffle_ps(t, t, _MM_SHUFFLE(1, 0, 3, 2)));
		return result;
	}


	ostream& operator<<(ostream& os, const SSEVector& v)
	{
		os << fixed << "( " << v.x() << ", " << v.y() << ", " << v.z() << ", " << v.w() << " )";
		return os;
	}
}