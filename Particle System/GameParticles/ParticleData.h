//---------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#ifndef PARTICLE_DATA_H
#define PARTICLE_DATA_H

// include
#include "Vect4D.h"

class ParticleData : public Align16
{
public:
	//friend class ParticleEmitter;

	ParticleData() = default;
	ParticleData(const ParticleData&);
	ParticleData& operator = (const ParticleData&) = default;
	~ParticleData();

	//float Determinant(const Vect4D&, const Vect4D&, const Vect4D&, const Vect4D) const;
	ParticleData(const Vect4D& _position, const Vect4D& _velocity);
	void Update(const float& time_elapsed);
public:
	Vect4D z_axis;
	//Vect4D v;
	Vect4D	position;
	Vect4D	velocity;
	Vect4D	scale;
	//float	diff;
	float	life;
	float	rotation;
	float	rotation_velocity;


};

#endif 

// --- End of File ---
