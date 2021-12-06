//---------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#include <Math.h>
#include "Matrix.h"

Matrix::Matrix() 
	: m0(0.0f), m1(0.0f), m2(0.0f), m3(0.0f), m4(0.0f), m5(0.0f), m6(0.0f),
m7(0.0f), m8(0.0f), m9(0.0f), m10(0.0f), m11(0.0f), m12(0.0f), m13(0.0f),
m14(0.0f), m15(0.0f) 
{}

//Matrix::Matrix(const Vect4D& tV0,
//	const Vect4D& tV1,
//	const Vect4D& tV2,
//	const Vect4D& tV3)
//	: v0(tV0), v1(tV1), v2(tV2), v3(tV3)
//{
//
//}

Matrix::Matrix(const Matrix& t)
	: v0(t.v0), v1(t.v1), v2(t.v2), v3(t.v3)
{
}

Matrix& Matrix::operator=(const Matrix& m)
{
	this->m0 = m.m0;
	this->m1 = m.m1;
	this->m2 = m.m2;
	this->m3 = m.m3;
	this->m4 = m.m4;
	this->m5 = m.m5;
	this->m6 = m.m6;
	this->m7 = m.m7;
	this->m8 = m.m8;
	this->m9 = m.m9;
	this->m10 = m.m10;
	this->m11 = m.m11;
	this->m12 = m.m12;
	this->m13 = m.m13;
	this->m14 = m.m14;
	this->m15 = m.m15;

	return *this;
}

Matrix::Matrix(Matrix::Identity)
	: m0(1.0f), m1(0.0f), m2(0.0f), m3(0.0f), m4(0.0f), m5(1.0f), m6(0.0f),
	m7(0.0f), m8(0.0f), m9(0.0f), m10(1.0f), m11(0.0f), m12(0.0f), m13(-3.0f),
	m14(-3.0f), m15(1.0f)
{

}

Matrix::Matrix(Matrix::CameraEnum)
	: m0(1.0f), m1(0.0f), m2(0.0f), m3(0.0f), m4(0.0f), m5(1.0f), m6(0.0f),
	m7(0.0f), m8(0.0f), m9(0.0f), m10(1.0f), m11(0.0f), m12(0.0f), m13(5.0f),
	m14(40.0f), m15(1.0f)

{

}




void Matrix::setMatrix(const Vect4D& scale, const Vect4D& position, const float& az)
{
	//if (fabs(az - 0.125349253) > 0.0001) Trace::out("Different Az: %f\n", az);


	
	const float cosAz = cosf(az);
	const float sinAz = sinf(az);
	const float cosAzX = cosAz * scale.x;
	const float cosAzY = cosAz * scale.y;
	const float sinAzX = sinAz * scale.x;
	const float sinAzY = -sinAz * scale.y;

	this->m0 = scale.x * cosAzX;
	this->m1 = scale.x * sinAzY;
	this->m4 = scale.y * sinAzX;
	this->m5 = scale.y * cosAzY;

	this->m10 = scale.z * scale.z;

	this->m12 = (position.x * cosAzX) + ((-5.0f + position.y) * (sinAzX));
	this->m13 = (position.x * sinAzY) + ((-5.0f + position.y) * cosAzY);
	this->m14 = ((-40.0f + position.z) * scale.z);

}

float Matrix::Cosine(float& x)
{
	const float c1 = 0.99940307f;
	const float c2 = -0.49558072f;
	const float c3 = 0.03679168f;
	float x2;      // The input argument squared
	x2 = x * x;
	return (c1 + x2 * (c2 + c3 * x2));
}

//
//Matrix::Matrix(const float& _m0, const float& _m1, const float& _m4, const float& _m12, const float& _m13, const float& _m14, const float& _m15)
//	: m0(_m0), m1(_m1), m2(0.0f), m3(0.0f), m4(_m4), m5(_m0), m6(0.0f),
//	m7(0.0f), m8(0.0f), m9(0.0f), m10(_m0), m11(0.0f), m12(_m12), m13(_m13),
//	m14(_m14), m15(_m15)
//{
//
//}


//Matrix Matrix::operator*(const Matrix& rhs) const
//{
//	//Matrix tmp;
//	////m2, m3, m6, m7, m8, m9, m11, m15
//	//tmp.m0 = (m0 * rhs.m0) + (m1 * rhs.m4);
//	//tmp.m1 = (m0 * rhs.m1) + (m1 * rhs.m5);
//	//tmp.m4 = (m4 * rhs.m0) + (m5 * rhs.m4);
//	//tmp.m5 = (m4 * rhs.m1) + (m5 * rhs.m5);
//	//tmp.m10 =  (m10 * rhs.m10);
//	//tmp.m12 = (m12 * rhs.m0) + (m13 * rhs.m4) + (m15 * rhs.m12);
//	//tmp.m13 = (m12 * rhs.m1) + (m13 * rhs.m5) +  (m15 * rhs.m13);
//
//	////tmp.m13 = _mm_store_ps( _mm_mul_ps(_mm_set1_ps(m12), _mm_set1_ps(rhs.m1)))
//
//	//tmp.m14 =  (m14 * rhs.m10) + (m15 * rhs.m14);
//	//tmp.m15 = 1;
//
//	//return tmp;
//
//	return Matrix((m0 * rhs.m0), (m0 * rhs.m1) + (m1 * rhs.m5), (m4 * rhs.m0) + (m5 * rhs.m4), (m12 * rhs.m0) + (m13 * rhs.m4) + (m15 * rhs.m12),
//		(m12 * rhs.m1) + (m13 * rhs.m5) + (m15 * rhs.m13), (m14 * rhs.m10) + (m15 * rhs.m14));
//
//}


// --- End of File ---
