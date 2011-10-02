#ifndef GELATINE_LINEARALGEBRA_H
#define GELATINE_LINEARALGEBRA_H


#include <math.h>


namespace gelatine
{


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
void multiply(float matrix[3][3], float vector[3], float result[3]);

/**
 * TODO: Documentation
 * <p>
 */
void multiply(float matrix[4][4], float vector[4], float result[4]); 

}


#endif // GELATINE_LINEARALGEBRA_H
