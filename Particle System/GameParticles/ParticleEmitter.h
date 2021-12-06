//---------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#ifndef PARTICLEEMITTER_H
#define PARTICLEEMITTER_H

#include "Matrix.h"
#include "Vect4D.h"
#include "Particle.h"
#include "Settings.h"

class ParticleEmitter
{
public:
	ParticleEmitter();
	ParticleEmitter(const ParticleEmitter&) = default;
	ParticleEmitter& operator=(const ParticleEmitter&) = default;
	~ParticleEmitter();

	void SpawnParticle();
	void update();
	void draw();

	void Execute(Vect4D& pos, Vect4D& vel, Vect4D& sc);

private:
	Matrix cameraMatrix;

	Vect4D	start_position; // 13629192
	Vect4D	start_velocity;
	Vect4D	vel_variance;
	Vect4D	pos_variance;

	Particle** headParticle;
	Particle* particles[NUM_PARTICLES] = { nullptr };

	float	current_time;
	float	time_elapsed;
	float	last_spawn;
	float	last_loop;
	int		last_active_particle;

};

#endif 

// --- End of File ---
