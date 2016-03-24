#include "../include/SSEVector.h"

using namespace std;

namespace ELTEVectorMathLib
{
	///Constructor
	SSEVector::SSEVector(Scalar x, Scalar y, Scalar z, Scalar w)
	{
		_ASSERT(sizeof(Scalar) == sizeof(float) && "Double precision SSE Vector not implemented!");
		xyzw = _mm_set_ps(w, z, y, x);
	}
	///Destructor
	SSEVector::~SSEVector()
	{
	}

	///Get the first component of the vector
	Scalar SSEVector::x() const
	{
		alignas(16) float a[4];
		_mm_store_ps(a, xyzw);
		return a[0];
	}
	///Get the second component of the vector
	Scalar SSEVector::y() const
	{
		alignas(16) float a[4];
		_mm_store_ps(a, xyzw);
		return a[1];
	}
	///Get the third component of the vector
	Scalar SSEVector::z() const
	{
		alignas(16) float a[4];
		_mm_store_ps(a, xyzw);
		return a[2];
	}
	///Get the fourth component of the vector
	Scalar SSEVector::w() const
	{
		alignas(16) float a[4];
		_mm_store_ps(a, xyzw);
		return a[3];
	}

	///Add two vectors
	SSEVector SSEVector::Add(const SSEVector& a, const SSEVector& b)
	{
		SSEVector result;
		result.xyzw = _mm_add_ps(a.xyzw, b.xyzw);
		return result;
	}
	///Multiply two vectors
	SSEVector SSEVector::Multiply(const SSEVector& a, const SSEVector& b)
	{
		SSEVector result;
		result.xyzw = _mm_mul_ps(a.xyzw, b.xyzw);
		return result;
	}
	///Do a dot product of two vectors
	SSEVector SSEVector::Dot(const SSEVector& a, const SSEVector& b)
	{
		SSEVector result;
		__m128 m = _mm_mul_ps(a.xyzw, b.xyzw);
		__m128 t = _mm_add_ps(m, _mm_shuffle_ps(m, m, _MM_SHUFFLE(2, 3, 0, 1)));
		result.xyzw = _mm_add_ps(t, _mm_shuffle_ps(t, t, _MM_SHUFFLE(1, 0, 3, 2)));
		return result;
	}

	///print vector
	ostream& operator<<(ostream& os, const SSEVector& v)
	{
		os << fixed << "( " << v.x() << ", " << v.y() << ", " << v.z() << ", " << v.w() << " )";
		return os;
	}
}
