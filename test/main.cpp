#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "../include/Scalar.h"
#include "../include/Vector.h"
#include "../include/Matrix.h"
#include "../include/Quaternion.h"


#include <iostream>
using namespace std;
using namespace ELTEVectorMathLib;

float PI = 3.1415926535897932384626433832795;

Matrix A(Vector(0, 2, 4, 6), Vector(1, 3, 5, 7), Vector(2, 4, 6, 8), Vector(3, 5, 7, 9));
Matrix B(Vector(9, 8, 7, 6), Vector(5, 4, 3, 2), Vector(1, 0, 9, 8), Vector(7, 6, 5, 4));
Matrix AplusB(Vector(9, 10, 11, 12), Vector(6, 7, 8, 9), Vector(3, 4, 15, 16), Vector(10, 11, 12, 13));
Matrix AminusB(Vector(-9, -6, -3, 0), Vector(-4, -1, 2, 5), Vector(1, 4, -3, 0), Vector(-4, -1, 2, 5));
Matrix At(Vector(0, 1, 2, 3), Vector(2, 3, 4, 5), Vector(4, 5, 6, 7), Vector(6, 7, 8, 9));
Matrix AB(Vector(56, 44, 72, 60), Vector(78, 62, 96, 80), Vector(100, 80, 120, 100), Vector(122, 98, 144, 120));
Vector a(0, 1, 2, 3);

TEST_CASE("Add") {
	REQUIRE(Matrix::Add(A, B) == Matrix::Add(B, A));
	REQUIRE(Matrix::Add(A, B) == AplusB);
}

TEST_CASE("Subtract") {
	REQUIRE(Matrix::Subtract(A, B) == AminusB);
}

TEST_CASE("Multiply") {
	REQUIRE( Matrix::Multiply(A,B) == AB );
}

TEST_CASE("Raise to power") {
	Matrix APowi = A;
	for (int i = 1; i < 10; i++) {
		REQUIRE(Matrix::Pow(A, i) == APowi);
		APowi = Matrix::Multiply(APowi, A);
	}
}

TEST_CASE("Transpose") {
	REQUIRE(Matrix::Transpose(A) == At);
}

TEST_CASE("Max Norm") {
	REQUIRE(Matrix::Norm_max(A) == 9);
}

TEST_CASE("1 Norm") {
	REQUIRE(Matrix::Norm_1(A) == 30);
}

TEST_CASE("Infinity Norm") {
	REQUIRE(Matrix::Norm_inf(A) == 24);
}

TEST_CASE("Frobenius Norm") {
	REQUIRE(abs(Matrix::Norm_frob(A) - sqrt(0.0f + 4.0f + 16.0f + 36.0f + 1.0f + 9.0f + 25.0f + 49.0f + 4.0f + 16.0f + 36.0f + 64.0f + 9.0f + 25.0f + 49.0f + 81.0f)) < FLT_EPSILON);
}

TEST_CASE("Rotation") {
	REQUIRE(Matrix::Norm_max(Matrix::Subtract(Matrix::CreateRotation(2.0f * PI, 2.0f * PI, 2.0f * PI) , Matrix::Identity())) < 0.000001);
}

TEST_CASE("Normalize") {
	REQUIRE(abs(Vector::Length(Vector::Normalize(Vector(34, 2, 4543, 2.777777777))) - 1) < FLT_EPSILON);
}