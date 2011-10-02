#ifndef PROTOLAYER_LINEARALGEBRA_LINEARALGEBRA_H
#define PROTOLAYER_LINEARALGEBRA_LINEARALGEBRA_H

#include <math.h>


namespace protolayer
{

namespace linearalgebra
{

/**
 * TODO: Documentation
 * <p>
 */
float determinant(float* vector, int dimension);

/**
 * TODO: Documentation
 * <p>
 */
float evaluateAngle3(float* first,
		     float* second);

/**
 * TODO: Documentation
 * <p>
 */
void crossProduct(const float first[3],
                  const float second[3],
                  float result[3]);

/**
 * TODO: Documentation
 * <p>
 */
void crossProduct3(const float* a,
                   const float* b,
                   float* result);

/**
 * TODO: Documentation
 * <p>
 */
float dotProduct3(const float* a,
		  const float* b);

/**
 * TODO: Documentation
 * <p>
 */
float dotProduct(const float a[3],
		 const float b[3]);

/**
 * TODO: Documentation
 * <p>
 */
void normalise(float vector[3]);


/**
 * TODO: Documentation
 * <p>
 */
void inverse(float original[3][3],
             float inverted[3][3]);

/**
 * TODO: Documentation
 * <p>
 */
void inverse(float original[4][4],
             float inverted[4][4]);

/**
 * TODO: Documentation
 * <p>
 */
void multiply(float matrix[3][3],
              float vector[3],
              float result[3]);

/**
 * TODO: Documentation
 * <p>
 */
void multiply(float matrix[4][4],
              float vector[4],
              float result[4]); 

/**
 * TODO: Documentation
 * <p>
 */
void normalise(float* vector,
               int dimension);


}


}


#endif // PROTOLAYER_LINEARALGEBRA_LINEARALGEBRA_H
