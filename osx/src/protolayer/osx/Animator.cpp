#include "Animator.h"


namespace protolayer
{

namespace osx
{

Animator::Animator(Pane& pane) :
  EventLoopTimerListener(DurationMillisecond),
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


}
