#ifndef MESON_LAYEREDSCENESELECTIONMODEL_H
#define MESON_LAYEREDSCENESELECTIONMODEL_H

#include "../../forward.h"

#include "ReferenceArrow.h"
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
class LayeredSceneSelectionModel
{
public:
  /** Iterator type definition */
  typedef std::set <scenegraph::Node*>::iterator ShapeIteratorType;

  /** Iterator type definition */
  typedef std::set <InstanceNode*>::iterator InstanceNodeIteratorType;

  /** Iterator type definition */
  typedef std::set <ReferenceArrow*>::iterator ReferenceArrowIteratorType;

private:
  /** TODO: Documentation */
  std::set <scenegraph::Node*> _selected;

  /** TODO: Documentation */
  std::set <InstanceNode*> _nodes;

  /** TODO: Documentation */
  std::set <ReferenceArrow*> _connections;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  LayeredSceneSelectionModel();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~LayeredSceneSelectionModel();

  /**
   * TODO: Documentation
   * <p>
   */
  bool isSelected(scenegraph::Node& node) const;

  /**
   * TODO: Documentation
   * <p>
   */
  void add(InstanceNode& node);

  /**
   * TODO: Documentation
   * <p>
   */
  void add(ReferenceArrow& connection);

  /**
   * TODO: Documentation
   * <p>
   */
  void remove(InstanceNode& node);

  /**
   * TODO: Documentation
   * <p>
   */
  void remove(ReferenceArrow& connection);

  /**
   * TODO: Documentation
   * <p>
   */
  void clear();

  /**
   * TODO: Documentation
   * <p>
   */
  ShapeIteratorType getItems();

  /**
   * TODO: Documentation
   * <p>
   */
  InstanceNodeIteratorType getInstanceNode();

  /**
   * TODO: Documentation
   * <p>
   */
  ReferenceArrowIteratorType getReferenceArrows();

  /**
   * TODO: Documentation
   * <p>
   */
  ShapeIteratorType getLastItem();

  /**
   * TODO: Documentation
   * <p>
   */
  InstanceNodeIteratorType getLastInstanceNode();

  /**
   * TODO: Documentation
   * <p>
   */
  ReferenceArrowIteratorType getLastReferenceArrow();

private:
  /**
   * TODO: Documentation
   * <p>
   */
  LayeredSceneSelectionModel(const LayeredSceneSelectionModel& state);

  /**
   * TODO: Documentation
   * <p>
   */
  LayeredSceneSelectionModel& operator=(const LayeredSceneSelectionModel& state);

};


}


}


#endif MESON_LAYEREDSCENESELECTIONMODEL_H
