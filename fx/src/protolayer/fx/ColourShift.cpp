#include "FadeInItem.h"


namespace protolayer
{

namespace fx
{

FadeInItem::FadeInItem(long timePeriod, Item* target)
{
  _timePeriod = timePeriod;
  _timeStarted = ZERO;
  _timeElapsed = ZERO;
  _fraction = ZERO;

  _finalEdgeColour[0] = finalEdgeColour[0];
  _finalEdgeColour[1] = finalEdgeColour[1];
  _finalEdgeColour[2] = finalEdgeColour[2];
  _finalEdgeColour[3] = finalEdgeColour[3];

  _finalFaceColour[0] = finalFaceColour[0];
  _finalFaceColour[1] = finalFaceColour[1];
  _finalFaceColour[2] = finalFaceColour[2];
  _finalFaceColour[3] = finalFaceColour[3];

  _initialEdgeColour[0] = initialEdgeColour[0];
  _initialEdgeColour[1] = initialEdgeColour[1];
  _initialEdgeColour[2] = initialEdgeColour[2];
  _initialEdgeColour[3] = initialEdgeColour[3];

  _initialFaceColour[0] = initialFaceColour[0];
  _initialFaceColour[1] = initialFaceColour[1];
  _initialFaceColour[2] = initialFaceColour[2];
  _initialFaceColour[3] = initialFaceColour[3];

  _deltaEdgeColour[0] = _finalEdgeColour[0] - _initialEdgeColour[0];
  _deltaEdgeColour[1] = _finalEdgeColour[1] - _initialEdgeColour[1];
  _deltaEdgeColour[2] = _finalEdgeColour[2] - _initialEdgeColour[2];
  _deltaEdgeColour[3] = _finalEdgeColour[3] - _initialEdgeColour[3];

  _deltaFaceColour[0] = _finalFaceColour[0] - _initialFaceColour[0];
  _deltaFaceColour[1] = _finalFaceColour[1] - _initialFaceColour[1];
  _deltaFaceColour[2] = _finalFaceColour[2] - _initialFaceColour[2];
  _deltaFaceColour[3] = _finalFaceColour[3] - _initialFaceColour[3];

  _inProgress = false;
  _target = &target;
}


void
FadeInItem::setTimePeriod(long timePeriod)
{
  _timePeriod = timePeriod;
}


void
FadeInItem::setTarget(Item* target)
{
  _target = target;
}


void
FadeInItem::commence(long timeStarted)
{
  _timeStarted = timeStarted;
  _inProgress = true;
}


bool
FadeInItem::inProgress()
{
  return _inProgress;
}


void
FadeInItem::increment(long timeCurrent)
{
  _timeElapsed = timeCurrent;
  _timeElapsed -= _timeStarted;

  _fraction = (float) _timeElapsed;
  _fraction /= (float) _timePeriod;

  if (_fraction > UNITY) {
    _target->getModel().setModifierAlpha(1);


    _inProgress = false;
  } else {      
    _target->getModel().setModifierAlpha( (float) (_fraction) );


  }
}


void
FadeInItem::postComplete()
{
  _timeStarted = ZERO;
  _timeElapsed = ZERO;
  _fraction = ZERO;
}


}


}
