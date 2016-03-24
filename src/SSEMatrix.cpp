#include "../include/SSEMatrix.h"

using namespace std;

namespace ELTEVectorMathLib
{

	SSEMatrix::SSEMatrix(const SSEVector& row0, const SSEVector& row1, const SSEVector& row2, const SSEVector& row3)
	{
		row[0] = row0;
		row[1] = row1;
		row[2] = row2;
		row[3] = row3;
	}

	SSEMatrix::~SSEMatrix()
	{
	}

	SSEMatrix SSEMatrix::Add(const SSEMatrix& a, const SSEMatrix& b)
	{
		return SSEMatrix(
			SSEVector::Add(a.row[0], b.row[0]),
			SSEVector::Add(a.row[1], b.row[1]),
			SSEVector::Add(a.row[2], b.row[2]),
			SSEVector::Add(a.row[3], b.row[3])
			);
	}
	SSEMatrix SSEMatrix::Multiply(const SSEMatrix& a, const SSEMatrix& b)
	{
		SSEMatrix retVal;
		SSEMatrix b_transposed = Transpose(b);

		// TODO

		return retVal;
	}
	SSEMatrix SSEMatrix::Transpose(const SSEMatrix& a)
	{
		SSEMatrix retVal = a;
		_MM_TRANSPOSE4_PS(retVal.row[0].xyzw, retVal.row[1].xyzw, retVal.row[2].xyzw, retVal.row[3].xyzw);
		return retVal;
	}


	ostream& operator<<(ostream& os, const SSEMatrix& m)
	{
		os << fixed << "[" << m.row[0] << endl << " " << m.row[1] << endl << " " << m.row[2] << endl << " " << m.row[3] << "]";
		return os;
	}
}