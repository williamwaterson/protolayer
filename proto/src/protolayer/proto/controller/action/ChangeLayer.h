#ifndef PROTOLAYER_PROTO_CHANGELAYER_H
#define PROTOLAYER_PROTO_CHANGELAYER_H

#include <map>
#include <set>

#include <protolayer/protolayer-assembly.h>
#include <protolayer/protolayer-ontology.h>
#include <protolayer/protolayer-workflow.h>


namespace protolayer
{

namespace proto
{

/**
 * TODO: Documentation
 * <p>
 */
class ChangeLayer : public workflow::Action
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  ChangeLayer();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~ChangeLayer();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void doit();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void undo();

private:
  /**
   * TODO: Documentation
   *
   */
  ChangeLayer(const ChangeLayer& changeLayer);

  /**
   * TODO: Documentation
   *
   */
  ChangeLayer& operator=(const ChangeLayer& changeLayer);

};


}


}


#endif // PROTOLAYER_PROTO_CHANGELAYER_H
