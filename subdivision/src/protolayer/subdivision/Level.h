#ifndef PROTOLAYER_SUBDIVISION_LEVEL_H
#define PROTOLAYER_SUBDIVISION_LEVEL_H

#include <stdio.h>
#include <vector.h>

#include "Face.h"


namespace protolayer
{

namespace subdivision
{

class Level
{
public:
  /** TODO: Documentation */
  typedef std::vector <Face*> FaceVectorType;


private:
  /** TODO: Documentation */
  std::vector <Face*> _faces;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Level(FaceVectorType& faces);

  /**
   * TODO: Documentation
   * <p>
   */
  explicit Level(Level& level);

  /**
   * TODO: Documentation
   * <p>
   */
  explicit Level(Face& face);

  /**
   * TODO: Documentation
   *
   */
  ~Level();

  /**
   * TODO: Documentation
   *
   */
  int getNumberFaces() const;

  /**
   * TODO: Documentation
   *
   */
  Face& getFace(int index);

private:
  /**
   * TODO: Documentation
   * <p>
   */
  Level operator=(Level& level);

  /**
   * TODO: Documentation
   * <p>
   */
  void construct(std::vector <Face*>& faces);

  /**
   * TODO: Documentation
   * <p>
   */
  void walk(Face& face);

};


}


}


#endif // PROTOLAYER_SUBDIVISION_LEVEL_H
