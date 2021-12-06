//---------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#include "Vect4D.h"

Vect4D::Vect4D()
	: x(0), y(0), z(0), w(0)
{}

Vect4D::Vect4D(const float& tx, const float& ty, const float& tz, const float& tw)
	: x(tx), y(ty), z(tz), w(tw)
{
}

Vect4D::Vect4D(const Vect4D& v)
	: x(v.x), y(v.y), z(v.z), w(v.w)
{

}

Vect4D& Vect4D::operator=(const Vect4D& v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	this->w = v.w;

	return *this;
}

void Vect4D::set(const float& tx, const float& ty, const float& tz)
{
	this->x = tx;
	this->y = ty;
	this->z = tz;
}

 void Vect4D::norm(Vect4D& out) const
{
	//0x7F to ignore W so we don't have to do the conditional if
	__m128 dp = _mm_dp_ps(this->_m, this->_m, 0x7F);

	// compute rsqrt of the dot product
	dp = _mm_rsqrt_ps(dp);

	// vec * rsqrt(dot(vec, vec))
	out._m = _mm_mul_ps(this->_m, dp);
}

Vect4D Vect4D::operator + (const Vect4D& t) const
{

	return Vect4D(this->x + t.x, this->y + t.y, this->z + t.z);
}

Vect4D Vect4D::operator+=(const Vect4D& t)
{
	this->x += t.x;
	this->y += t.y;
	this->z += t.z;

	return *this;
}


Vect4D Vect4D::operator *(const float& scale) const
{

	return Vect4D(this->x * scale, this->y * scale, this->z * scale);
}

Vect4D Vect4D::operator - (const Vect4D& t)
{
	//Vect4D tmp;
	this->_m = _mm_sub_ps(this->_m, t._m);
	this->w = 0;
	return *this;
	//return Vect4D(this->x - t.x, this->y - t.y, this->z - t.z);

	/*this->x = t.x - this->x;
	this->y = t.y - this->y;
	this->z = t.z - this->z;

	return *this;*/
}



const void Vect4D::Cross(const Vect4D& vin, Vect4D& vout) const
{
	vout.x = (y * vin.z - z * vin.y);
	vout.y = (z * vin.x - x * vin.z);
	vout.z = (x * vin.y - y * vin.x);
	vout.w = 1.0f;

	/*__m128 tmp0 = _mm_shuffle_ps(this->_m, this->_m, _MM_SHUFFLE(3, 0, 2, 1));
	vout._m = _mm_shuffle_ps(vin._m, vin._m, _MM_SHUFFLE(3, 1, 0, 2));
	__m128 tmp2 = _mm_mul_ps(tmp0, vin._m);
	vout._m = _mm_mul_ps(tmp0, vout._m);
	tmp2 = _mm_shuffle_ps(tmp2, tmp2, _MM_SHUFFLE(3, 0, 2, 1));
	vout._m = _mm_sub_ps(vout._m, tmp2);*/
}

// --- End of File ---
