#ifndef GELATINE_DIMENSIONS_H
#define GELATINE_DIMENSIONS_H


namespace gelatine
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.1.1.1 $
 */
class Dimensions
{
private:
  /** TODO: Documentation */
  int _width;

  /** TODO: Documentation */
  int _height;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Dimensions();

  /**
   * TODO: Documentation
   *
   */
  Dimensions(int width, int height);

  /**
   * TODO: Documentation
   * <p>
   */
  void setDimensions(int width, int height);

  /**
   * TODO: Documentation
   * <p>
   */
  int getWidth();

  /**
   * TODO: Documentation
   * <p>
   */
  int getHeight();

  /**
   * TODO: Documentation
   * <p>
   */
  float getAspectRatio();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Dimensions(const Dimensions& Dimensions);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Dimensions& operator=(const Dimensions& Dimensions);

};


}


#endif // GELATINE_DIMENSIONS_H

