//---------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#include "Particle.h"


//Particle::Particle(const Vect4D& _position, const Vect4D& _velocity)
//	:z_axis(0.0f, 0.0f, 3.0f),
//	position(_position),
//	velocity(_velocity),
//	scale(-1.0f, -1.0f, -1.0f, -1.0f),
//	life(0.0f),
//	rotation(0.0f),
//	rotation_velocity(-0.25f)
//{
//
//}

Particle::Particle(const Vect4D& _position, const Vect4D& _velocity)
	: pParticleData(new ParticleData(_position, _velocity))
{

}

Particle::~Particle()
{
	//Trace::out("Particle ~Destructor()\n");
	delete pParticleData;
}

//Particle::Particle(const Particle& p)
//	: position(p.position),
//	velocity(p.velocity),
//	scale(p.scale),
//	life(p.life),
//	rotation(p.rotation),
//	rotation_velocity(p.rotation_velocity)
//
//{
//
//}

Particle::Particle(const Particle& p)
	: pParticleData(p.pParticleData)

{

}


//void Particle::Update(const float& time_elapsed)
//{	
//	this->pParticleData->Update(time_elapsed);
//	//// serious math below - magic secret sauce
//	//life += time_elapsed;
//	//position =position + (velocity * time_elapsed);
//	////Vect4D z_axis(0.0f, 0.0f, 3.0f);
//	//Vect4D v(2, 2, 0);
//	//position.Cross(z_axis, v);
//	//v.norm(v);
//	//position = position +  v * 0.05f * life;
//
//	//
//	//rotation += rotation_velocity * time_elapsed * 2.0f; //
//}



// --- End of File ---
