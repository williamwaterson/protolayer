#ifndef PROTOLAYER_PROTO_INSTANCENODE_H
#define PROTOLAYER_PROTO_INSTANCENODE_H

#include "../../forward.h"

//#include "DomainNode.h"


namespace protolayer
{

namespace proto
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class InstanceNode : public protolayer::geometry::QuadSphere
{
  /** TODO: Documentation */
  static const float DIAMETER = 0.5f;

  /** TODO: Documentation */
  //  std::set <DomainNode*> _attributePrisms;

  /** TODO: Documentation */
  //  protolayer::xulcarbon::Dialog* _techniqueDialog;

  /** TODO: Documentation */
  float _offset[3];

  /** TODO: Documentation */
  assembly::Instance* _instance;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  InstanceNode(float x, float y, float z,
                style::Appearance& edgeAppearance,
                style::Appearance& faceAppearance);

  /**
   * TODO: Documentation
   * <p>
   */
  InstanceNode(assembly::Instance& instance,
                float x, float y, float z,
                style::Appearance& edgeAppearance,
                style::Appearance& faceAppearance);
    
  /**
   * TODO: Documentation
   * <p>
   */
  void setOffset(float x, float y, float z);

  /**
   * TODO: Documentation
   * <p>
   */
  assembly::Instance& getInstance();

  /**
   * TODO: Documentation
   * <p>
   */
  const float* getOffset() const;

  /**
   * TODO: Documentation
   * <p>
   */
  //  protolayer::xulcarbon::Dialog* getTechniqueDialog();

  /**
   * TODO: Documentation
   * <p>
   */
  void setTechniqueDialog(xercesc::DOMElement& element);

};


}


}


#endif // PROTOLAYER_PROTO_INSTANCENODE_H
