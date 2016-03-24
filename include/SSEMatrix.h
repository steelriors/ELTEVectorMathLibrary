#ifndef _SSE_MATRIX_H_
#define _SSE_MATRIX_H_
#include <iostream>
#include "Scalar.h"
#include "SSEVector.h"

//#include <emmintrin.h> // sse2
//#include <smmintrin.h> // sse4.1
#include <nmmintrin.h> // sse4.2

namespace ELTEVectorMathLib
{
	class alignas(16) SSEMatrix
	{
	private:
	public:
		SSEMatrix(const SSEVector& row0 = SSEVector(), const SSEVector& row1 = SSEVector(), const SSEVector& row2 = SSEVector(), const SSEVector& row3 = SSEVector());
		~SSEMatrix();

		void* operator new(size_t i){ return _mm_malloc(i, 16); }
		void operator delete(void* p) { _mm_free(p); }

		SSEVector row[4];

		static SSEMatrix __vectorcall Add(const SSEMatrix& a, const SSEMatrix& b);
		static SSEMatrix __vectorcall Multiply(const SSEMatrix& a, const SSEMatrix& b);
		static SSEMatrix __vectorcall Transpose(const SSEMatrix& a);
	};


	std::ostream& operator<<(std::ostream& os, const SSEMatrix& m);
}

#endif // _SSE_MATRIX_H_

