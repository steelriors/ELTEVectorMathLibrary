#ifndef _SSE_QUATERNION_H_
#define _SSE_QUATERNION_H_
#include <iostream>
#include "Scalar.h"

//#include <emmintrin.h> // sse2
//#include <smmintrin.h> // sse4.1
#include <nmmintrin.h> // sse4.2

namespace ELTEVectorMathLib
{
	class alignas(16) SSEQuaternion
	{
	private:
		__m128 xyzw;
	public:
		SSEQuaternion(Scalar x = 0, Scalar y = 0, Scalar z = 0, Scalar w = 0);
		~SSEQuaternion();

		void* operator new(size_t i){ return _mm_malloc(i, 16); }
		void operator delete(void* p) { _mm_free(p); }

		Scalar x() const;
		Scalar y() const;
		Scalar z() const;
		Scalar w() const;
	};


	std::ostream& operator<<(std::ostream& os, const SSEQuaternion& v);
}

#endif // _SSE_QUATERNION_H_

