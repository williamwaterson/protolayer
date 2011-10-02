#ifndef PROTOLAYER_SCENEGRAPH_HITMODEL_H
#define PROTOLAYER_SCENEGRAPH_HITMODEL_H

#include "Node.h"

namespace protolayer
{

namespace scenegraph
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.4 $
 */
class HitModel
{
private:
  /** TODO: Documentation */
  Node* _node;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  HitModel();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~HitModel();

  /**
   * TODO: Documentation
   * <p>
   */
  Node* getHit();

  /**
   * TODO: Documentation
   * <p>
   */
  void mouseHit(Node* node);

private:
  /**
   * TODO: Documentation
   * <p>
   */
  HitModel(const HitModel& hitModel);

  /**
   * TODO: Documentation
   * <p>
   */
  HitModel& operator=(const HitModel& hitModel);

};


}


}


#endif PROTOLAYER_RENDERER_HITMODEL_H
