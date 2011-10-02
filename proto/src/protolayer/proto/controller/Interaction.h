#ifndef PROTOLAYER_PROTO_INTERACTION_H
#define PROTOLAYER_PROTO_INTERACTION_H

#include <map>
#include <set>

#include <protolayer/protolayer-workflow.h>

namespace protolayer
{

namespace proto
{

/**
 * TODO: Documentation
 * <p>
 */
class Interaction : public workflow::Task
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  Interaction();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Interaction() = 0;

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void mouseDown(float x, float y, int clickCount);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void mouseMoved(float x, float y);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void mouseDragged(float x, float y);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void mouseUp(float x, float y);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void keyDown();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void keyUp();

private:
  /**
   * TODO: Documentation
   *
   */
  Interaction(const Interaction& interaction);

  /**
   * TODO: Documentation
   *
   */
  Interaction& operator=(const Interaction& interaction);

};


}


}


#endif // PROTOLAYER_PROTO_INTERACTION_H
