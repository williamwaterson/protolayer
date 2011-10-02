#ifndef PROTOLAYER_PROTO_DOMAINNODE_H
#define PROTOLAYER_PROTO_DOMAINNODE_H

#include <vector>

#include "../../forward.h"
#include "LayeredScene.h"
#include "LayerPrism.h"


namespace protolayer
{

namespace proto
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class DomainNode : public protolayer::geometry::QuadSphere
{
  /** TODO: Documentation */
  typedef std::vector <LayerPrism*>::iterator LayerPrismIteratorType;

  /** TODO: Documentation */
  typedef std::vector <LayerPrism*>::reverse_iterator DownwardsLayerPrismIteratorType;

public:
  /** TODO: Documentation */
  static const float HORIZONTAL_INSET = 0.25f;

  /** TODO: Documentation */
  static const float VERTICAL_INSET = 0.25f;

  /** TODO: Documentation */
  static const float VERTICAL_SPACING = 0.25f;

private:
  /** TODO: Documentation */
  assembly::Domain& _domain;

  /** TODO: Documentation */
  scenegraph::Shot* _shot;

  /** TODO: Documentation */
  LayeredScene* _layeredScene;

  /** TODO: Documentation */
  std::vector <LayerPrism*> _layerPrisms;

  /** TODO: Documentation */
  scenegraph::Shape* _item;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  DomainNode(assembly::Domain& domain,
              style::Appearance& edgeAppearance,
              style::Appearance& faceAppearance);

  /**
   * TODO: Documentation
   * <p>
   */
  scenegraph::Shot& getShot();

  /**
   * TODO: Documentation
   * <p>
   */
  LayeredScene& getLayeredScene();

  /**
   * TODO: Documentation
   * <p>
   */
  assembly::Domain& getDomain();

  /**
   * TODO: Documentation
   * <p>
   */
  bool isDomain(assembly::Domain& domain);

  /**
   * TODO: Documentation
   * <p>
   */
  //  LayerPrismIteratorType getLayerPrismsUpwards();

  /**
   * TODO: Documentation
   * <p>
   */
  //  LayerPrismIteratorType getLayerPrismsUpwards(const LayerPrism& prism);

  /**
   * TODO: Documentation
   * <p>
   */
  //  DownwardsLayerPrismIteratorType getLayerPrismsDownwards();

  /**
   * TODO: Documentation
   * <p>
   */
  //  DownwardsLayerPrismIteratorType getLayerPrismsDownwards(const LayerPrism& prism);

  /**
   * TODO: Documentation
   * <p>
   */
  //  LayerPrismIteratorType getUpwardsEnd();

  /**
   * TODO: Documentation
   * <p>
   */
  //  DownwardsLayerPrismIteratorType getDownwardsEnd();

};


}


}


#endif PROTOLAYER_PROTO_DOMAINPRISM_H
