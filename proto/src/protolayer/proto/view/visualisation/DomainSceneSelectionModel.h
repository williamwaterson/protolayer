#ifndef LITHO_DOMAINSCENESELECTIONMODEL_H
#define LITHO_DOMAINSCENESELECTIONMODEL_H

#include "../../forward.h"

#include "DependencyArrow.h"
#include "DomainNode.h"
#include "LayerPrism.h"
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
class DomainSceneSelectionModel
{
public:
  /** Iterator type definition */
  typedef std::set <scenegraph::Node*>::iterator ShapeIteratorType;

  /** Iterator type definition */
  typedef std::set <DependencyArrow*>::iterator DependencyArrowIteratorType;

  /** Iterator type definition */
  typedef std::set <DomainNode*>::iterator DomainNodeIteratorType;

private:
  /** TODO: Documentation */
  std::set <scenegraph::Node*> _selected;

  /** TODO: Documentation */
  std::set <DependencyArrow*> _dependencies;

  /** TODO: Documentation */
  std::set <DomainNode*> _domains;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  DomainSceneSelectionModel();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~DomainSceneSelectionModel();

  /**
   * TODO: Documentation
   * <p>
   */
  void add(DependencyArrow& arrow);

  /**
   * TODO: Documentation
   * <p>
   */
  void add(DomainNode& domainNode);

  /**
   * TODO: Documentation
   * <p>
   */
  void remove(DependencyArrow& connection);

  /**
   * TODO: Documentation
   * <p>
   */
  void remove(DomainNode& domainNode);

  /**
   * TODO: Documentation
   * <p>
   */
  void clear();

  /**
   * TODO: Documentation
   * <p>
   */
  void clearDomainNodes();

  /**
   * TODO: Documentation
   * <p>
   */
  void clearDependencyArrows();

  /**
   * TODO: Documentation
   * <p>
   */
  DomainSceneSelectionModel& getSelectionModel();

  /**
   * TODO: Documentation
   * <p>
   */
  ShapeIteratorType getItems();

  /**
   * TODO: Documentation
   * <p>
   */
  DependencyArrowIteratorType getDependencyArrows();

  /**
   * TODO: Documentation
   * <p>
   */
  DomainNodeIteratorType getDomainNodes();

  /**
   * TODO: Documentation
   * <p>
   */
  ShapeIteratorType getLastItem();

  /**
   * TODO: Documentation
   * <p>
   */
  DependencyArrowIteratorType getLastDependencyArrow();

  /**
   * TODO: Documentation
   * <p>
   */
  DomainNodeIteratorType getLastDomainNode();

  /**
   * TODO: Documentation
   * <p>
   */
  bool isSelected(DomainNode& prism);

  /**
   * TODO: Documentation
   * <p>
   */
  bool isSelected(DependencyArrow& arrow);

private:
  /**
   * TODO: Documentation
   * <p>
   */
  DomainSceneSelectionModel(const DomainSceneSelectionModel& state);

  /**
   * TODO: Documentation
   * <p>
   */
  DomainSceneSelectionModel& operator=(const DomainSceneSelectionModel& state);

};


}


}


#endif LITHO_DOMAINSCENESELECTIONMODEL_H
