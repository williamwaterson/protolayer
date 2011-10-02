#ifndef MESON_DEPENDENCYARROW_H
#define MESON_DEPENDENCYARROW_H

#include "../../forward.h"
#include "DomainNode.h"

namespace protolayer
{

namespace proto
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class DependencyArrow : public geometry::TaperedArrow
{
  /** TODO: Documentation */
  bool _isGhosted;

  /** TODO: Documentation */
  assembly::DomainDependency* _dependency;

  /** TODO: Documentation */
  DomainNode* _fromDomainNode;

  /** TODO: Documentation */
  DomainNode* _toDomainNode;

  /** TODO: Documentation */
  scenegraph::Camera* _camera;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  DependencyArrow(assembly::DomainDependency& dependency,
                  DomainNode& fromDomain,
                  DomainNode& toDomain,
                  scenegraph::Camera& camera);

  /**
   * TODO: Documentation
   * <p>
   */
  bool isFrom(DomainNode& prism);

  /**
   * TODO: Documentation
   * <p>
   */
  bool isTo(DomainNode& prism);

  /**
   * TODO: Documentation
   * <p>
   */
  DomainNode& getFromDomainNode();

  /**
   * TODO: Documentation
   * <p>
   */
  DomainNode& getToDomainNode();

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


#endif MESON_DEPENDENCYARROW_H
