#ifndef OBISIDIAN_PROTO_LAYERPRISM_H
#define OBISIDIAN_PROTO_LAYERPRISM_H


#include "../../forward.h"
#include "LayerHexMesh.h"


namespace protolayer
{

namespace proto
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class LayerPrism : public geometry::RectangularPrism
{
public:
  /** TODO: Documentation */
  static const float LENGTH = 4.0f;

  /** TODO: Documentation */
  static const float HEIGHT = 0.5f;

private:
  /** TODO: Documentation */
  scenegraph::Shape* _item;

  /** TODO: Documentation */
  LayerHexMesh& _layerHexMesh;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit LayerPrism(LayerHexMesh& layerHexMesh);

  /**
   * TODO: Documentation
   * <p>
   */
  LayerHexMesh& getLayerHexMesh();

};


}


}


#endif OBISIDIAN_PROTO_LAYERPRISM_H
