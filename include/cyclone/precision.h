namespace cyclone {
  
  // We define real to reserve the storage of vector components
  // Also in the case we need to change the precision of the type data
  // for our vector, we can change it at any moment to double.
  typedef float real;

  // Define the precision of the power operator
  #define real_pow powf
}