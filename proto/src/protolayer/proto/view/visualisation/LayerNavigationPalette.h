#ifndef PROTOLAYER_MESON_LAYERNAVIGATIONPALETTE_H
#define PROTOLAYER_MESON_LAYERNAVIGATIONPALETTE_H


#include <protolayer/protolayer-carbon.h>

#include "../forward.h"
#include "UtilityButton.h"


namespace protolayer
{

namespace proto
{

using namespace protolayer::carbon;

/**
 * TODO: Documentation
 * <p>
 */
class LayerNavigationPalette : public protolayer::carbon::UserPane
{
public:
  /** TODO: Documentation */
  static const short SPACING = 10;

  /** TODO: Documentation */
  static const short INSET = 3;

  /** TODO: Documentation */
  static const short WIDTH = 100;

  /** TODO: Documentation */
  static const short HEIGHT = 50;

private:
  /** TODO: Documentation */
  BevelButton* _upLayerButton;

  /** TODO: Documentation */
  BevelButton* _downLayerButton;

public:
  /**
   * TODO: Documentation
   * <p>
   */  
  LayerNavigationPalette(short left, short top);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~LayerNavigationPalette();

  /**
   * TODO: Documentation
   * <p>
   */
  BevelButton& getUpLayerButton();

  /**
   * TODO: Documentation
   * <p>
   */
  BevelButton& getDownLayerButton();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  LayerNavigationPalette(const LayerNavigationPalette& palette);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  LayerNavigationPalette& operator=(const LayerNavigationPalette& palette);

};


}


}


#endif // PROTOLAYER_MESON_LAYERNAVIGATIONPALETTE_H
