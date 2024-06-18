#include <math.h>
#include "precision.h"

namespace cyclone {
  // Holds a vector in 3d, 4 data parameters

  class Vector3 {
    public:
      real x;
      real y;
      real z;

    private:

      // Padding to ensure 4 word alignment. (this is related to performance)
      real pad;

    public:
      // Constructor por default
      Vector3(): x(0), y(0), z(0) {}

      // Explicit constructor
      Vector3(const real x, const real y, const real z)
            : x(x), y(y), z(z) {}

      void invert()
      {
        x = -x;
        y = -y;
        z = -z;
      }

      // Gets magnitude of the vector
      real magnitude() const
      {
        return real_sqrt(x*x + y*y + z*z);
      }

      // Gets squared magnitude of the vector
      real squareMagnitude() const
      {
        return x*x + y*y + z*z;
      }

      // Turns a non-zero vector into a vector

      void normalize()
      {
        real l = magnitude();
        if (l > 0 ) 
        {
          (*this)*= ((real)1)/l;

        }
      }

      // Multiplies given vector by a scalar
      void operator*=(const real value)
      {
        x *= value; // Multiply the current x by the value
        y *= value;
        z *= value;
      }

      // Returns a copy of this vector scaled the given value
      Vector3 operator*(const real value) const
      {
        return Vector3(x*value, y*value, z*value)
      }

      // Vector Addition
      // Adds the given vector
      void operator+=(const Vector3& v)
      {
        x += v.x;
        y += v.y;
        z += v.z;
      }

      // Return the value of the given vector added to this
      Vector3 operator+(const Vector3& v)
      {
        return Vector3(x+v.x, y+v.y, z+v.z);
      }

      // Vector addition for scaled vectors
      // Ads the given vector to this, scaled by the given amount
      void addScaledVector(const Vector3& vector, real scale)
      {
        x += vector.x*scale;
        y += vector.y*scale;
        z += vector.z*scale;
      }

      // Vector substraction
      // Substracts the given vector
      void operator-=(const Vector3& v)
      {
        x -= v.x;
        y -= v.y;
        z -= v.z;
      }

      // Return the value of the given vector substracted to this
      Vector3 operator-(const Vector3& v)
      {
        return Vector3(x-v.x, y-v.y, z-v.z);
      }

      // Vector component product
      // Calculates and returns a component-wise product of this vector with 
      // the given vector.
      Vector3 componentProduct(const Vector3 &vector) const
      {
        return Vector3(x *vector.x, y *vector.y, z *vector.z);
      }

      // Performs a component-wise product with the given vector and sets this vector to its result.
      void componentProductUpdate(const Vector3 &vector)
      {
        x *= vector.x;
        y *= vector.y;
        z *= vector.z;
      }

      // Vecrtor scalar product
      // Calculate the scalar product of this vector with the given vector
      real scalarProduct(const Vector3 &vector) const
      {
        return x *vector.x + y *vector.y + z *vector.z;
      }

      // Calculate the scalar product of this vector with the given vector 
      real operator*(const Vector3 &vector) const
      {
        return x *vector.x + y *vector.y + z *vector.z;
      }

      // Vector product (a X b)
      // Calculate the vector product with the given vector
      Vector3 vectorProduct(const Vector3 &vector) const
      {
        return Vector3(
          y*vector.z - z*vector.y,
          z*vector.x - x*vector.z,
          x*vector.y - y*vector.x
        );
      }

      // Updates this vector to the vector product
      // of it's current value and the given vector.
      Vector3 operator%(const Vector3 &vector) const
      {
        return Vector3(
          y*vector.z - z*vector.y,
          z*vector.x - x*vector.z,
          x*vector.y - y*vector.x
        );
      }


      // Orthonormal basis
      void makeOrthonormalBasis(Vector3 *a, Vector3 *b, Vector3 *c)
      {
        a->normalize();
        (*c) = a->vectorProduct(*b); // Or it can be (*a) % (*b)
        if (c->squareMagnitude() == 0.0) return; // Or generate error.
        c->normalize();
        (*b) = (*c) % (*a);
      }

      

  }
};