#ifndef GELATINE_HITMODEL_H
#define GELATINE_HITMODEL_H

#include "forward.h"
#include "Node.h"

namespace gelatine
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.1.1.1 $
 */
class HitModel
{
  /** TODO: Documentation */
  friend class SpaceView;

private:
  /** TODO: Documentation */
  gelatine::Node* _node;

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


#endif GELATINE_HITMODEL_H
