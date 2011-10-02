#ifndef PROTOLAYER_PROTO_REFERENCEARROW_H
#define PROTOLAYER_PROTO_REFERENCEARROW_H

#include "../../forward.h"
#include "InstanceNode.h"

namespace protolayer
{

namespace proto
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class ReferenceArrow : public geometry::TaperedArrow
{
  /** TODO: Documentation */
  bool _isGhosted;

  /** TODO: Documentation */
  InstanceNode* _fromNode;

  /** TODO: Documentation */
  InstanceNode* _toNode;

  /** TODO: Documentation */
  scenegraph::Camera* _camera;

  /** TODO: Documentation */
  assembly::Reference* _reference;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  ReferenceArrow(InstanceNode& fromNode, InstanceNode& toNode,
                 scenegraph::Camera& camera);

  /**
   * TODO: Documentation
   * <p>
   */
  ReferenceArrow(assembly::Reference& reference,
                 InstanceNode& fromNode, InstanceNode& toNode,
                 scenegraph::Camera& camera);

  /**
   * TODO: Documentation
   * <p>
   */
  bool isFromNode(InstanceNode& node);

  /**
   * TODO: Documentation
   * <p>
   */
  bool isToNode(InstanceNode& node);

  /**
   * TODO: Documentation
   * <p>
   */
  assembly::Reference& getReference();

  /**
   * TODO: Documentation
   * <p>
   */
  InstanceNode& getFromNode();

  /**
   * TODO: Documentation
   * <p>
   */
  InstanceNode& getToNode();

  /**
   * TODO: Documentation
   * <p>
   */
  void setGhosted(bool flag);

  /**
   * TODO: Documentation
   * <p>
   */
  bool isGhosted();

  /**
   * TODO: Documentation
   * <p>
   */
  void updateEndPositions();

};


}


}


#endif PROTOLAYER_PROTO_REFERENCEARROW_H
