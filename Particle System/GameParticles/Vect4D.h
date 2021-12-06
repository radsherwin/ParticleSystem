//---------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#ifndef Vect4D_H
#define Vect4D_H

// includes
#include <xmmintrin.h>
#include <smmintrin.h>

// Foward Declarations
class Matrix;

// class
class Vect4D final : public Align16
{
public:
	//friend class Matrix;

	Vect4D();
	Vect4D(const Vect4D&);
	Vect4D& operator = (const Vect4D& v);
	~Vect4D() = default;

	Vect4D(const float& tx, const float& ty, const float& tz, const float& tw = 0.0f);
	void set(const float& tx, const float& ty, const float& tz);

	const void Cross(const Vect4D& vin, Vect4D& vout) const;

	void norm(Vect4D& out) const;

	Vect4D operator * (const float& scale) const;
	Vect4D operator - (const Vect4D& t);
	Vect4D operator + (const Vect4D& t) const;
	Vect4D operator += (const Vect4D& t);

public:

	union
	{
		__m128	_m;

		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
	};
};

#endif

// --- End of File ---
