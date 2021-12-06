//---------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#ifndef PARTICLE_H
#define PARTICLE_H

// include
#include "Vect4D.h"
#include "ParticleData.h"

class Particle : public Align16
{
public:
	//friend class ParticleEmitter;

	Particle() = default;
	Particle(const Particle&);
	Particle& operator = (const Particle&) = default;
	~Particle();

	//float Determinant(const Vect4D&, const Vect4D&, const Vect4D&, const Vect4D) const;
	Particle(const Vect4D& _position, const Vect4D& _velocity);
	//void Update(const float& time_elapsed);
public:
	ParticleData* pParticleData;
	//Vect4D z_axis;
	////Vect4D v;
	//Vect4D	position;
	//Vect4D	velocity;
	//Vect4D	scale;
	////float	diff;
	//float	life;
	//float	rotation;
	//float	rotation_velocity;


};

#endif 

// --- End of File ---
