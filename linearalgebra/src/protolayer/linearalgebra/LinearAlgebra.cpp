#include "LinearAlgebra.h"
#include <iostream.h>

namespace protolayer
{

namespace linearalgebra
{

/**
 * TODO: Documentation
 * <p>
 */
void crossProduct(const float a[3],
                  const float b[3],
                  float result[3])
{
  result[0] = a[1] * b[2] - a[2] * b[1];
  result[1] = -a[0] * b[2] + a[2] * b[0];
  result[2] = a[0] * b[1] - a[1] * b[0];
}


/**
 * TODO: Documentation
 * <p>
 */
void crossProduct3(const float* a,
                   const float* b,
                   float* result)
{
  result[0] = a[1] * b[2] - a[2] * b[1];
  result[1] = -a[0] * b[2] + a[2] * b[0];
  result[2] = a[0] * b[1] - a[1] * b[0];
}


/**
 * TODO: Documentation
 * <p>
 */
float dotProduct3(const float* a,
		  const float* b)
{
  float result;

  result = a[0] * b[0];
  result += a[1] * b[1];
  result += a[2] * b[2];

  return result;
}


/**
 * TODO: Documentation
 * <p>
 */
float dotProduct(const float a[3],
		 const float b[3])
{
  return dotProduct3(a, b);
}


/**
 * TODO: Documentation
 * <p>
 */
void normalise(float vector[3])
{
  float length = (float) sqrt(vector[0] * vector[0] +
                              vector[1] * vector[1] +
                              vector[2] * vector[2]);

  vector[0] /= length;
  vector[1] /= length;
  vector[2] /= length;
}


/**
 * TODO: Documentation
 * <p>
 */
void inverse(float a[3][3], float inv[3][3])
{
  float det  =  a[0][0] * (a[2][2] * a[1][1] - a[2][1] * a[1][2]) -
    a[1][0] * (a[2][2] * a[0][1] - a[2][1] * a[0][2]) +
    a[2][0] * (a[1][2] * a[0][1] - a[1][1] * a[0][2]);

  inv[0][0] =   a[2][2] * a[1][1] - a[2][1] * a[1][2];
  inv[0][1] = -(a[2][2] * a[0][1] - a[2][1]* a[0][2]);
  inv[0][2] =   a[1][2] * a[0][1] - a[1][1] * a[0][2]; 

  inv[1][0] = -(a[2][2] * a[1][0] - a[2][0] * a[1][2]);
  inv[1][1] =   a[2][2] * a[0][0] - a[2][0] * a[0][2]; 
  inv[1][2] = -(a[1][2] * a[0][0] - a[1][0] * a[0][2]);

  inv[2][0] =   a[2][1] * a[1][0] - a[2][0] * a[1][1];
  inv[2][1] = -(a[2][1] * a[0][0] - a[2][0] * a[0][1]);
  inv[2][2] =   a[1][1] * a[0][0] - a[1][0] * a[0][1];

  inv[0][0] /= det;
  inv[0][1] /= det;
  inv[0][2] /= det;

  inv[1][0] /= det;
  inv[1][1] /= det;
  inv[1][2] /= det;

  inv[2][0] /= det;
  inv[2][1] /= det;
  inv[2][2] /= det;
}


/**
 * TODO: Documentation
 * <p>
 */
void inverse(float a[4][4], float inv[4][4])
{
  inv[0][0] = 1;
  inv[0][1] = 0;
  inv[0][2] = 0;
  inv[0][3] = 0;

  inv[1][0] = 0;
  inv[1][1] = 1;
  inv[1][2] = 0;
  inv[1][3] = 0;

  inv[2][0] = 0;
  inv[2][1] = 0;
  inv[2][2] = 1;
  inv[2][3] = 0;

  inv[3][0] = 0;
  inv[3][1] = 0;
  inv[3][2] = 0;
  inv[3][3] = 1;

  float factor = a[0][0];
  a[0][0] /= factor;
  a[0][1] /= factor;
  a[0][2] /= factor;
  a[0][3] /= factor;
  inv[0][0] /= factor;
  inv[0][1] /= factor;
  inv[0][2] /= factor;
  inv[0][3] /= factor;

  factor = a[1][0];
  a[1][0] -= a[0][0] * factor;
  a[1][1] -= a[0][1] * factor;
  a[1][2] -= a[0][2] * factor;
  a[1][3] -= a[0][3] * factor;
  inv[1][0] -= inv[0][0] * factor;
  inv[1][1] -= inv[0][1] * factor;
  inv[1][2] -= inv[0][2] * factor;
  inv[1][3] -= inv[0][3] * factor;

  factor = a[2][0];
  a[2][0] -= a[0][0] * factor;
  a[2][1] -= a[0][1] * factor;
  a[2][2] -= a[0][2] * factor;
  a[2][3] -= a[0][3] * factor;
  inv[2][0] -= inv[0][0] * factor;
  inv[2][1] -= inv[0][1] * factor;
  inv[2][2] -= inv[0][2] * factor;
  inv[2][3] -= inv[0][3] * factor;

  factor = a[3][0];
  a[3][0] -= a[0][0] * factor;
  a[3][1] -= a[0][1] * factor;
  a[3][2] -= a[0][2] * factor;
  a[3][3] -= a[0][3] * factor;
  inv[3][0] -= inv[0][0] * factor;
  inv[3][1] -= inv[0][1] * factor;
  inv[3][2] -= inv[0][2] * factor;
  inv[3][3] -= inv[0][3] * factor;


  factor = a[1][1];
  a[1][0] /= factor;
  a[1][1] /= factor;
  a[1][2] /= factor;
  a[1][3] /= factor;
  inv[1][0] /= factor;
  inv[1][1] /= factor;
  inv[1][2] /= factor;
  inv[1][3] /= factor;

  factor = a[0][1];
  a[0][0] -= a[1][0] * factor;
  a[0][1] -= a[1][1] * factor;
  a[0][2] -= a[1][2] * factor;
  a[0][3] -= a[1][3] * factor;
  inv[0][0] -= inv[1][0] * factor;
  inv[0][1] -= inv[1][1] * factor;
  inv[0][2] -= inv[1][2] * factor;
  inv[0][3] -= inv[1][3] * factor;

  factor = a[2][1];
  a[2][0] -= a[1][0] * factor;
  a[2][1] -= a[1][1] * factor;
  a[2][2] -= a[1][2] * factor;
  a[2][3] -= a[1][3] * factor;
  inv[2][0] -= inv[1][0] * factor;
  inv[2][1] -= inv[1][1] * factor;
  inv[2][2] -= inv[1][2] * factor;
  inv[2][3] -= inv[1][3] * factor;

  factor = a[3][1];
  a[3][0] -= a[1][0] * factor;
  a[3][1] -= a[1][1] * factor;
  a[3][2] -= a[1][2] * factor;
  a[3][3] -= a[1][3] * factor;
  inv[3][0] -= inv[1][0] * factor;
  inv[3][1] -= inv[1][1] * factor;
  inv[3][2] -= inv[1][2] * factor;
  inv[3][3] -= inv[1][3] * factor;


  factor = a[1][1];
  a[1][0] /= factor;
  a[1][1] /= factor;
  a[1][2] /= factor;
  a[1][3] /= factor;
  inv[1][0] /= factor;
  inv[1][1] /= factor;
  inv[1][2] /= factor;
  inv[1][3] /= factor;

  factor = a[0][1];
  a[0][0] -= a[1][0] * factor;
  a[0][1] -= a[1][1] * factor;
  a[0][2] -= a[1][2] * factor;
  a[0][3] -= a[1][3] * factor;
  inv[0][0] -= inv[1][0] * factor;
  inv[0][1] -= inv[1][1] * factor;
  inv[0][2] -= inv[1][2] * factor;
  inv[0][3] -= inv[1][3] * factor;

  factor = a[2][1];
  a[2][0] -= a[1][0] * factor;
  a[2][1] -= a[1][1] * factor;
  a[2][2] -= a[1][2] * factor;
  a[2][3] -= a[1][3] * factor;
  inv[2][0] -= inv[1][0] * factor;
  inv[2][1] -= inv[1][1] * factor;
  inv[2][2] -= inv[1][2] * factor;
  inv[2][3] -= inv[1][3] * factor;

  factor = a[3][1];
  a[3][0] -= a[1][0] * factor;
  a[3][1] -= a[1][1] * factor;
  a[3][2] -= a[1][2] * factor;
  a[3][3] -= a[1][3] * factor;
  inv[3][0] -= inv[1][0] * factor;
  inv[3][1] -= inv[1][1] * factor;
  inv[3][2] -= inv[1][2] * factor;
  inv[3][3] -= inv[1][3] * factor;


  factor = a[2][2];
  a[2][0] /= factor;
  a[2][1] /= factor;
  a[2][2] /= factor;
  a[2][3] /= factor;
  inv[2][0] /= factor;
  inv[2][1] /= factor;
  inv[2][2] /= factor;
  inv[2][3] /= factor;

  factor = a[0][2];
  a[0][0] -= a[2][0] * factor;
  a[0][1] -= a[2][1] * factor;
  a[0][2] -= a[2][2] * factor;
  a[0][3] -= a[2][3] * factor;
  inv[0][0] -= inv[2][0] * factor;
  inv[0][1] -= inv[2][1] * factor;
  inv[0][2] -= inv[2][2] * factor;
  inv[0][3] -= inv[2][3] * factor;

  factor = a[1][2];
  a[1][0] -= a[2][0] * factor;
  a[1][1] -= a[2][1] * factor;
  a[1][2] -= a[2][2] * factor;
  a[1][3] -= a[2][3] * factor;
  inv[1][0] -= inv[2][0] * factor;
  inv[1][1] -= inv[2][1] * factor;
  inv[1][2] -= inv[2][2] * factor;
  inv[1][3] -= inv[2][3] * factor;

  factor = a[3][2];
  a[3][0] -= a[2][0] * factor;
  a[3][1] -= a[2][1] * factor;
  a[3][2] -= a[2][2] * factor;
  a[3][3] -= a[2][3] * factor;
  inv[3][0] -= inv[2][0] * factor;
  inv[3][1] -= inv[2][1] * factor;
  inv[3][2] -= inv[2][2] * factor;
  inv[3][3] -= inv[2][3] * factor;


  factor = a[3][3];
  a[3][0] /= factor;
  a[3][1] /= factor;
  a[3][2] /= factor;
  a[3][3] /= factor;
  inv[3][0] /= factor;
  inv[3][1] /= factor;
  inv[3][2] /= factor;
  inv[3][3] /= factor;

  factor = a[0][3];
  a[0][0] -= a[3][0] * factor;
  a[0][1] -= a[3][1] * factor;
  a[0][2] -= a[3][2] * factor;
  a[0][3] -= a[3][3] * factor;
  inv[0][0] -= inv[3][0] * factor;
  inv[0][1] -= inv[3][1] * factor;
  inv[0][2] -= inv[3][2] * factor;
  inv[0][3] -= inv[3][3] * factor;

  factor = a[1][3];
  a[1][0] -= a[3][0] * factor;
  a[1][1] -= a[3][1] * factor;
  a[1][2] -= a[3][2] * factor;
  a[1][3] -= a[3][3] * factor;
  inv[1][0] -= inv[3][0] * factor;
  inv[1][1] -= inv[3][1] * factor;
  inv[1][2] -= inv[3][2] * factor;
  inv[1][3] -= inv[3][3] * factor;

  factor = a[2][3];
  a[2][0] -= a[3][0] * factor;
  a[2][1] -= a[3][1] * factor;
  a[2][2] -= a[3][2] * factor;
  a[2][3] -= a[3][3] * factor;
  inv[2][0] -= inv[3][0] * factor;
  inv[2][1] -= inv[3][1] * factor;
  inv[2][2] -= inv[3][2] * factor;
  inv[2][3] -= inv[3][3] * factor;
}


// Determine the start point for the final scene's camera
void multiply(float matrix[3][3], float vector[3], float result[3])
{
  result[0] = matrix[0][0] * vector[0] +
    matrix[0][1] * vector[1] +
    matrix[0][2] * vector[2];

  result[1] = matrix[1][0] * vector[0] +
    matrix[1][1] * vector[1] +
    matrix[1][2] * vector[2];

  result[2] = matrix[2][0] * vector[0] +
    matrix[2][1] * vector[1] +
    matrix[2][2] * vector[2];
}



void multiply(float matrix[4][4], float vector[4], float result[4])
{
  result[0] = matrix[0][0] * vector[0] +
    matrix[0][1] * vector[1] +
    matrix[0][2] * vector[2] +
    matrix[0][3] * vector[3];

  result[1] = matrix[1][0] * vector[0] +
    matrix[1][1] * vector[1] +
    matrix[1][2] * vector[2] +
    matrix[1][3] * vector[3];

  result[2] = matrix[2][0] * vector[0] +
    matrix[2][1] * vector[1] +
    matrix[2][2] * vector[2] +
    matrix[2][3] * vector[3];

  result[3] = matrix[3][0] * vector[0] +
    matrix[3][1] * vector[1] +
    matrix[3][2] * vector[2] +
    matrix[3][3] * vector[3];
}


float determinant(float* vector, int dimension)
{
  float length = 0;
  for (int i = 0; i < dimension; i++) {
    length += vector[i] * vector[i];
  }

  length = (float) sqrt(length);  
  return length;
}


/**
 * TODO: Documentation
 * <p>
 */
float evaluateAngle3(float* first,
		     float* second)
{
  float firstDet = determinant(first, 3);
  float secondDet = determinant(second, 3);

  float cosAngle = dotProduct3(first, second);
  cosAngle /= firstDet;
  cosAngle /= secondDet;

  float cross[3];
  crossProduct3(first, second, cross);
  float sinAngle = determinant(cross, 3);
  sinAngle /= firstDet;
  sinAngle /= secondDet;

  float result = 0;
  if (cosAngle >= 0 && sinAngle >= 0) {
    result = acos(cosAngle);
  } else if (cosAngle < 0 && sinAngle >= 0) {
    result = acos(cosAngle);
  } else if (cosAngle < 0 && sinAngle < 0) {
    result = 2 * M_PI - acos(cosAngle);
  } else {
    result = 2 * M_PI - acos(cosAngle);
  }

  return result;
}


void normalise(float* vector, int dimension)
{
  float length = determinant(vector, dimension);
  for (int i = 0; i < dimension; i++) {
    vector[i] /= length;
  }
}


}


}
