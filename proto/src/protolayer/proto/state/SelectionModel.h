#ifndef PROTO_SELECTIONMODEL_H
#define PROTO_SELECTIONMODEL_H

#include "../forward.h"

namespace protolayer
{

namespace proto
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class SelectionModel
{
public:
  /** Iterator type definition */
  typedef std::set <scenegraph::Node*>::iterator NodeIteratorType;

private:
  /** TODO: Documentation */
  std::set <scenegraph::Node*> _selected;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  SelectionModel();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~SelectionModel();

  /**
   * TODO: Documentation
   * <p>
   */
  bool isSelected(scenegraph::Node& node) const;

  /**
   * TODO: Documentation
   * <p>
   */
  bool contains(scenegraph::Node& node) const;

  /**
   * TODO: Documentation
   * <p>
   */
  void add(scenegraph::Node& mode);

  /**
   * TODO: Documentation
   * <p>
   */
  void remove(scenegraph::Node& node);

  /**
   * TODO: Documentation
   * <p>
   */
  void clear();

  /**
   * TODO: Documentation
   * <p>
   */
  NodeIteratorType getNodes();

  /**
   * TODO: Documentation
   * <p>
   */
  NodeIteratorType getLastNode();

private:
  /**
   * TODO: Documentation
   * <p>
   */
  SelectionModel(const SelectionModel& state);

  /**
   * TODO: Documentation
   * <p>
   */
  SelectionModel& operator=(const SelectionModel& state);

};


}


}


#endif PROTO_SELECTIONMODEL_H
