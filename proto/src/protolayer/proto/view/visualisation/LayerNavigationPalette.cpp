#include "LayerNavigationPalette.h"


namespace protolayer
{

namespace proto
{

LayerNavigationPalette::LayerNavigationPalette(short left, short top) :
  UserPane(left, top, left + WIDTH, top + HEIGHT)
{
  short buttonLeft = INSET;
  _upLayerButton = new UtilityButton(buttonLeft, INSET);
  add(*_upLayerButton);

  buttonLeft += UtilityButton::WIDTH + SPACING;
  _downLayerButton = new UtilityButton(buttonLeft, INSET);
  add(*_downLayerButton);

  _upLayerButton->show();
  _downLayerButton->show();

  _upLayerButton->activate();
  _downLayerButton->activate();

  //  _upLayerButton->deactivate();
  //  _downLayerButton->deactivate();

  show();
  activate();
}


LayerNavigationPalette::~LayerNavigationPalette()
{
}


BevelButton& LayerNavigationPalette::getUpLayerButton()
{
  return *_upLayerButton;
}


BevelButton& LayerNavigationPalette::getDownLayerButton()
{
  return *_downLayerButton;
}


}


}
