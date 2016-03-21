#ifndef _SCALAR_H_
#define _SCALAR_H_

namespace ELTEVectorMathLib
{
	typedef float Scalar;

#define lerp(a, b, t)	(((1 - (t))*(a)) + ((t)*(b)))
#define sqr(x) ((x)*(x))

}

#endif // _SCALAR_H_

