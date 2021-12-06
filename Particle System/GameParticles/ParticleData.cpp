#include "ParticleData.h"

ParticleData::ParticleData(const ParticleData& p)
	: position(p.position),
	velocity(p.velocity),
	scale(p.scale),
	life(p.life),
	rotation(p.rotation),
	rotation_velocity(p.rotation_velocity)
{
}

ParticleData::~ParticleData()
{

}


ParticleData::ParticleData(const Vect4D& _position, const Vect4D& _velocity)
	:z_axis(0.0f, 0.0f, 3.0f),
	position(_position),
	velocity(_velocity),
	scale(-1.0f, -1.0f, -1.0f, -1.0f),
	life(0.0f),
	rotation(0.0f),
	rotation_velocity(-0.25f)
{
}

void ParticleData::Update(const float& time_elapsed)
{
	life += time_elapsed;
	position += (velocity * time_elapsed);
	//Vect4D z_axis(0.0f, 0.0f, 3.0f);
	Vect4D v(2, 2, 0);
	position.Cross(z_axis, v);
	v.norm(v);
	position += v * 0.05f * life;


	rotation += rotation_velocity * time_elapsed * 2.0f; //
}
