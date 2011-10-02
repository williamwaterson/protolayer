#ifndef PROTOLAYER_RENDERER_HITMODEL_H
#define PROTOLAYER_RENDERER_HITMODEL_H

#include "forward.h"
#include "Node.h"

namespace protolayer
{

namespace renderer
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.4 $
 */
class HitModel
{
  /** TODO: Documentation */
  friend class protolayer::renderer::Shot;

private:
  /** TODO: Documentation */
  protolayer::renderer::Node* _node;

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
