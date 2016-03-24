/**
* \class Scalar
*
* \ingroup ELTEVectorMathLibrary
*
* This is a simple class for creating
* and manipulating scalars.
*
* \author Janos Turanszki, Tamas Nyiri, Gergo Kiss
*
* \version 0.1
*
* \date $Date: 2016/03/24
*
*/

#ifndef _SCALAR_H_
#define _SCALAR_H_

namespace ELTEVectorMathLib
{
	typedef float Scalar;

#define lerp(a, b, t)	(((1 - (t))*(a)) + ((t)*(b)))
#define sqr(x) ((x)*(x))

}

#endif // _SCALAR_H_

