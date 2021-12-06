//---------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#include "OpenGLDevice.h"
#include "ParticleEmitter.h"

PerformanceTimer globalTimer;

ParticleEmitter::ParticleEmitter()
	: cameraMatrix(Matrix::CameraEnum::XYZ),
	start_position(0.0f, 0.0f, 50.0f),
	start_velocity(0.0f, -1.0f, 0.0f),
	vel_variance(1.0f, 2.0f, -0.8f),
	pos_variance(0.50f, 0.50f, 0.50f),
	headParticle(&particles[0]),
	current_time(0.0f),
	time_elapsed(0.0f),
	last_spawn(globalTimer.GetGlobalTime()),
	last_loop(globalTimer.GetGlobalTime()),
	last_active_particle(-1)
	
{
	/*vel_variance(1.0f, 2.0f, -0.8f),
	pos_variance(0.50f, 0.50f, 0.50f),*/
}

ParticleEmitter::~ParticleEmitter()
{
	Trace::out("ParticleEmitter ~Destructor()\n");

	Particle** pParticle = particles;
	for (int i = 0; i < NUM_PARTICLES; i++)
	{
		Particle* pDeleteMe = *pParticle;
		pParticle++;
		delete pDeleteMe;
		pDeleteMe = nullptr;
		
	}
}

void ParticleEmitter::SpawnParticle()
{
	// create another particle if there are ones free
	if (last_active_particle < NUM_PARTICLES - 1)
	{

		// create new particle
		Particle* newParticle = new Particle(start_position, start_velocity);

		// apply the variance
		this->Execute(newParticle->pParticleData->position, newParticle->pParticleData->velocity,newParticle->pParticleData->scale);
		if (last_active_particle == -1)headParticle = &particles[0];
		// increment count
		last_active_particle++;

		// add to list
		
		while (*headParticle != nullptr)
		{

				headParticle++;
				
			
		}
		*headParticle = newParticle;

	}
}

void ParticleEmitter::update()
{
	// get current time
	current_time = globalTimer.GetGlobalTime();
	//Particle* p = this->headParticle;
	// spawn particles
	time_elapsed = current_time - last_spawn;

	// update
	while (0.0000001f < time_elapsed)
	{
		// spawn a particle
		this->SpawnParticle();
		// adjust time
		time_elapsed -= 0.0000001f;
		// last time
		last_spawn = current_time;
	}

	// total elapsed
	time_elapsed = current_time - last_loop;

	
	// walk the particles

	Particle** pParticle = particles;
	for (int i = 0; i < NUM_PARTICLES; i++)
	{

		//Particle* s = *pParticle++;
		if (*pParticle != nullptr)
		{
			(*pParticle)->pParticleData->Update(time_elapsed);
			if ((last_active_particle >= 0) && ((*pParticle)->pParticleData->life > MAX_LIFE))
			{
				Particle* pDeleteMe = *pParticle;
				headParticle = &pDeleteMe;
				delete pDeleteMe;
				*pParticle = nullptr;
				last_active_particle--;
				
			}
		}
		pParticle++;
		

	}

	last_loop = current_time;
}

void ParticleEmitter::draw()
{
	// initialize the camera matrix
	//Matrix cameraMatrix(Matrix::CameraEnum::XYZ);

	Particle** pParticle = particles;
	for (int i = 0; i < NUM_PARTICLES; i++)
	{
		Particle* s = *pParticle++;

		if (s != nullptr)
		{
			// Matrix
			cameraMatrix.setMatrix(s->pParticleData->scale, s->pParticleData->position, s->pParticleData->rotation);

			// ------------------------------------------------
			//  Set the Transform Matrix and Draws Triangle
			// ------------------------------------------------
			//Trace::out("matrix float: %f\n", *(float*)&cameraMatrix);
			OpenGLDevice::SetTransformMatrixFloat((const float*)&cameraMatrix.m0);
		}
		

	}

}

void ParticleEmitter::Execute(Vect4D& pos, Vect4D& vel, Vect4D& sc)
{
	// Ses it's ugly - I didn't write this so don't bitch at me
	// Sometimes code like this is inside real commerical code ( so now you know how it feels )
	//float posF = 0.5f;
	//float velF = 1.0f;
	// x - variance
	float var = (float)(rand() % 1000) * 0.001f;
	float sign = (float)(rand() % 2);
	float* t_pos = (float*)(&pos);
	float* t_var = &pos_variance.x;
	//Trace::out("tvar: %d\n", t_var);
	if (sign == 0)
	{
		var *= -1.0f;
	}
	*t_pos += *t_var * var;

	// y - variance
	var = (float)(rand() % 1000) * 0.001f;
	sign = (float)(rand() % 2);
	t_pos++;
	t_var++;
	if (sign == 0)
	{
		var *= -1.0f;
	}
	*t_pos += *t_var * var;

	// z - variance
	var = (float)(rand() % 1000) * 0.001f;
	sign = (float)(rand() % 2);
	t_pos++;
	t_var++;
	if (sign == 0)
	{
		var *= -1.0f;
	}
	*t_pos += *t_var * var;

	var = (float)(rand() % 1000) * 0.001f;
	sign = (float)(rand() % 2);

	// x  - add velocity
	t_pos = &vel.x;
	t_var = &vel_variance.x;
	if (sign == 0)
	{
		var *= -1.0f;
	}
	*t_pos += *t_var * var;

	// y - add velocity
	var = (float)(rand() % 1000) * 0.001f;
	sign = (float)(rand() % 2);
	t_pos++;
	t_var++;
	if (sign == 0)
	{
		var *= -2.0f;
	}
	*t_pos += *t_var * var;

	// z - add velocity
	var = (float)(rand() % 1000) * 0.001f;
	sign = (float)(rand() % 2);
	t_pos++;
	t_var++;
	if (sign == 0)
	{
		var *= -2.0f;
	}
	*t_pos += *t_var * var;

	// correct the sign
	var = 2.0f * (float)(rand() % 1000) * 0.001f;
	sign = (float)(rand() % 2);

	if (sign == 0)
	{
		var *= -2.0f;
	}
	//Trace::out("tvar: %d\n", t_var);
	sc = sc * var;
}

// --- End of File ---
