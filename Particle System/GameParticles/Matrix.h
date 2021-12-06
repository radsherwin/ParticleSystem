//---------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#ifndef MATRIX_H
#define MATRIX_H

// includes
#include "Vect4D.h"

// forward declare
//class Vect4D;

// class
class Matrix final : public Align16
{
public:

	enum class Identity
	{
		XYZ
	};


	enum class CameraEnum
	{
		XYZ
	};
public:
	Matrix();
	Matrix(const Matrix& t);
	Matrix& operator=(const Matrix&);
	~Matrix() = default;

	//Matrix(const Vect4D&, const Vect4D&, const Vect4D&, const Vect4D&);
	//Matrix(const float& _m0, const float& _m1, const float& _m4, const float& _m12, const float& _m13, const float& _m14, const float& _m15=1.0f);

	Matrix(Matrix::CameraEnum);
	Matrix(Matrix::Identity);

	void setMatrix(const Vect4D& s, const Vect4D& t, const float& az);
	float Cosine(float& x);

	//Matrix operator*(const Matrix& t) const;

	union
	{
		struct
		{
			Vect4D v0;
			Vect4D v1;
			Vect4D v2;
			Vect4D v3;
		};

		struct
		{
			float m0;
			float m1;
			float m2;
			float m3;
			float m4;
			float m5;
			float m6;
			float m7;
			float m8;
			float m9;
			float m10;
			float m11;
			float m12;
			float m13;
			float m14;
			float m15;
		};
	};
};

#endif  

// --- End of File ---
