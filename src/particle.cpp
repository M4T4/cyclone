#include <assert.h>
#include <cyclone/particle.h>

using namespace cyclone;

void Particle::integrate(real duration)
{
  // We don't integrate things with infinite mass
  if(inverseMass <= 0.0f) return;

  assert(duration > 0.0);

  // Update linear position
  position.addScaledVector(velocity, duration);

  // Work out the acceleration from the force.
  // (We will add to this vector when we come to generate F)
  Vector3 resultingAcc = acceleration;

  // Update linear velocity from acceleration
  velocity.addScaledVector(resultingAcc, duration);

  // Impose drag
  velocity *= real_pow(damping, duration);

  // Clean the forces
  clearAccumulator();

}
