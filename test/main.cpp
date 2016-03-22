#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "../include/Scalar.h"
#include "../include/Vector.h"
#include "../include/Matrix.h"
#include "../include/Quaternion.h"


#include <iostream>
using namespace std;
using namespace ELTEVectorMathLib;

Matrix A(Vector(0, 2, 4, 6), Vector(1, 3, 5, 7), Vector(2, 4, 6, 8), Vector(3, 5, 7, 9));
Matrix B(Vector(9, 8, 7, 6), Vector(5, 4, 3, 2), Vector(1, 0, 9, 8), Vector(7, 6, 5, 4));
Matrix At(Vector(0, 1, 2, 3), Vector(2, 3, 4, 5), Vector(4, 5, 6, 7), Vector(6, 7, 8, 9));
Matrix AB(Vector(56, 44, 72, 60), Vector(78, 62, 96, 80), Vector(100, 80, 120, 100), Vector(122, 98, 144, 120));

TEST_CASE("Transpose") {
	REQUIRE( Matrix::Transpose(A) == At );
}

TEST_CASE("Multiply") {
	REQUIRE( Matrix::Multiply(A,B) == AB );
}

TEST_CASE("Normalize") {
	REQUIRE(Vector::Length(Vector::Normalize(Vector(34, 2, 4543, 2.777777777))) - 1 < FLT_EPSILON);
}