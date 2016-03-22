#ifndef _SSE_VECTOR_H_
#define _SSE_VECTOR_H_
#include <iostream>
#include <emmintrin.h> // sse
#include "Scalar.h"

namespace ELTEVectorMathLib
{
	class alignas(16) SSEVector
	{
	private:
		__m128 xyzw;
	public:
		SSEVector(Scalar x = 0, Scalar y = 0, Scalar z = 0, Scalar w = 0);
		~SSEVector();

		void* operator new(size_t i){ return _mm_malloc(i, 16); }
		void operator delete(void* p) { _mm_free(p); }

		Scalar x() const;
		Scalar y() const;
		Scalar z() const;
		Scalar w() const;

		static SSEVector Add(const SSEVector& a, const SSEVector& b);
		static SSEVector Multiply(const SSEVector& a, const SSEVector& b);
		static SSEVector Dot(const SSEVector& a, const SSEVector& b);
	};


	std::ostream& operator<<(std::ostream& os, const SSEVector& v);
}

#endif // _SSE_VECTOR_H_

