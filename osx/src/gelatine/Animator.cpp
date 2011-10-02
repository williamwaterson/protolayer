#include "Animator.h"


namespace gelatine
{


Animator::Animator(GelatinePane& pane) :
  EventLoopTimerListener(DurationMillisecond * 40),
  _pane(pane)
{
}


Animator::~Animator()
{
}


void
Animator::timerTriggered()
{
  _pane.getView().swapPortsAndDisplay();
}


}
