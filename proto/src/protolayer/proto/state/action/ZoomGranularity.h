#ifndef PROTOLAYER_PROTO_ZOOMGRANULARITY_H
#define PROTOLAYER_PROTO_ZOOMGRANULARITY_H

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
class ZoomGranularity : public workflow::Action
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  ZoomGranularity();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~ZoomGranularity();

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
  ZoomGranularity(const ZoomGranularity& zoomGranularity);

  /**
   * TODO: Documentation
   *
   */
  ZoomGranularity& operator=(const ZoomGranularity& zoomGranularity);

};


}


}


#endif // PROTOLAYER_PROTO_ZOOMGRANULARITY_H
