#include <math.h>
#include "precision.h"

// A particle is a point mass and it's the simplest object
// that can be simulated in a physics simulation.

class Particle
{
  protected:
  
    // Holds the lineaer position of the particle.
    Vector3 position;
    

    // Holds the linear velocity of the particle.
    Vector3 velocity;

    // Holds the acceleration of the particle. 
    // This can be used to set acceleration due gravity.
    Vector3 acceleration; 

    // Holds the amount of "damping" in linear motion.
    // Damping is requires to remove energy added through 
    // numerical instability in the integrator.
    real damping;

    // Holds the inverse mass of a particle. it
    // is more useful to hold the inverse mass because
    // integration is simpler and because in real-time
    // simulation it is more useful to have objects with
    // infinite mass (immovable) than zero mass.
    real inverseMass;


    // Integrates the particle forward in time by the given amount.
    // This is a Newton-Euler integration method, which is a linear
    // aproximation to the correct integral. So unlike runge-kutta, 
    // this will be innacurate.

    void integrate(real duration); 


};