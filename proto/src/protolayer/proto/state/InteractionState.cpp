#include "InteractionState.h"


namespace protolayer
{

namespace proto
{

InteractionState::InteractionState(RenderingState& renderingState)
{
  _renderingState = &renderingState;
}


InteractionState::~InteractionState()
{
}


void InteractionState::keyDown()
{
  std::cout << "keyDown" << std::endl;
}


void InteractionState::keyUp()
{
  std::cout << "keyUp" << std::endl;
}


void InteractionState::mouseMoved(float x, float y)
{
  std::cout << "mouseMoved" << std::endl;
}


void InteractionState::mouseDown(float x, float y, int clickCount)
{
  std::cout << "mouseDown" << std::endl;
}


void InteractionState::mouseDragged(float x, float y)
{
  std::cout << "mouseDragged" << std::endl;
}


void InteractionState::mouseUp(float x, float y)
{
  std::cout << "mouseUp" << std::endl;
}


}


}
