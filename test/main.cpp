/**
* \class Test
*
* \ingroup ELTEVectorMathLibrary
*
* This is a class for testing out 
* the functions if they are working
* properly or not. It uses Catch testing
* https://github.com/philsquared/Catch
*
* \author Janos Turanszki, Tamas Nyiri, Gergo Kiss
*
* \version 0.1
*
* \date $Date: 2016/03/24
*
*/

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
Vector b(9, 8, 7, 6);
Vector aRot180X(0, -1, -2, 3);
Vector aRot180Y(0, 1, -2, 3);
Vector aRot180Z(0, -1, 2, 3);
Scalar adotb = 40;
Vector acrossb(-9, 18, -9, 0);
Vector aplusb(9, 9, 9, 9);
Vector aminusb(-9, -7, -5, -3);
Vector aA(14, 26, 38, 50);
Vector Aa(28, 34, 40, 46);
Quaternion q(0, 1, 2, 3);

TEST_CASE("Matrix+Matrix") {
	REQUIRE(Matrix::Add(A, B) == Matrix::Add(B, A));
	REQUIRE(Matrix::Add(A, B) == AplusB);
}

TEST_CASE("Matrix-Matrix") {
	REQUIRE(Matrix::Subtract(A, B) == AminusB);
}

TEST_CASE("Matrix*Matrix") {
	REQUIRE( Matrix::Multiply(A,B) == AB );
}

TEST_CASE("Matrix*Scalar") {
	REQUIRE(Matrix::Multiply(A, 1) == A);
	REQUIRE(Matrix::Multiply(A, 0) == Matrix::Null());
}

TEST_CASE("Matrix^p") {
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
	REQUIRE(abs(Matrix::Norm_max(Matrix::Subtract(Vector::Multiply(Matrix::CreateRotation(PI, 0, 0), a), aRot180X))) < FLT_EPSILON*10);
	REQUIRE(abs(Matrix::Norm_max(Matrix::Subtract(Vector::Multiply(Matrix::CreateRotation(0, PI, 0), a), aRot180Y))) < FLT_EPSILON*10);
	REQUIRE(abs(Matrix::Norm_max(Matrix::Subtract(Vector::Multiply(Matrix::CreateRotation(0, 0, PI), a), aRot180Z))) < FLT_EPSILON*10);
	REQUIRE(abs(Matrix::Norm_max(Matrix::Subtract(Matrix::CreateRotation(0.0f, PI, PI),Matrix::CreateRotation(2.0f * PI, 5.0f * PI, 7.0f * PI)))) < FLT_EPSILON*100);
}

TEST_CASE("Dot Multiplication") {
	REQUIRE(Vector::Dot(a, b) == adotb);
}

TEST_CASE("Cross Multiplication") {
	REQUIRE(Vector::Cross(a, b) == acrossb);
}

TEST_CASE("Vector+Vector") {
	REQUIRE(Vector::Add(a, b) == aplusb);
}

TEST_CASE("Vector-Vector") {
	REQUIRE(Vector::Subtract(a, b) == aminusb);
}

TEST_CASE("Vector*Matrix") {
	REQUIRE(Vector::Multiply(a, A) == aA);
}

TEST_CASE("Matrix*Vector") {
	REQUIRE(Vector::Multiply(A, a) == Aa);
}

TEST_CASE("Normalization, p-norm, length") {
	REQUIRE(Vector::Length(Vector::Normalize(a)) == Vector::Norm_p(Vector::Normalize(a),2));
	REQUIRE((Vector::Norm_p(Vector::Normalize(a), 2) - 1) < FLT_EPSILON);
}

TEST_CASE("Inf Norm") {
	REQUIRE(Vector::Norm_inf(a) == 3);
}

TEST_CASE("Quaternion*Scalar") {
	REQUIRE(Quaternion::Multiply(q, 2) == Quaternion(0,2,4,6));
}

TEST_CASE("Quaternion length, normalize") {
	REQUIRE(Quaternion::Length(q) == Vector::Length(a));
	REQUIRE(Quaternion::Length(Quaternion::Normalize(q)) - 1 < FLT_EPSILON);
}



