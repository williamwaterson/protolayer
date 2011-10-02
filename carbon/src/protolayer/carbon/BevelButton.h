#ifndef PROTOLAYER_CARBON_BEVELBUTTON_H
#define PROTOLAYER_CARBON_BEVELBUTTON_H

#include "forward.h"
#include "NonEmbeddingControl.h"

namespace protolayer
{

namespace carbon
{

/**
 * TODO: Documentation
 * <p>
 */
class BevelButton : public NonEmbeddingControl
{
public:
  /** TODO: Documentation */
  enum Thickness { SMALL_THICKNESS = kControlBevelButtonSmallBevel,
                   MEDIUM_THICKNESS = kControlBevelButtonNormalBevel,
                   LARGE_THICKNESS = kControlBevelButtonLargeBevel };

  /** TODO: Documentation */
  enum Behaviour { PUSH_BUTTON = kControlBehaviorPushbutton,
                   TOGGLES = kControlBehaviorToggles,
                   STICKY = kControlBehaviorSticky,
                   SINGLE_VALUE = kControlBehaviorSingleValueMenu,
                   MULTI_VALUE = kControlBehaviorMultiValueMenu,
                   OFFSET_CONTENTS = kControlBehaviorOffsetContents };

private:
  /** TODO: Documentation */
  bool _isRounded;

  /** TODO: Documentation */
  ThemeButtonKind _kind;

  /** TODO: Documentation */
  Thickness _thickness;

  /** TODO: Documentation */
  Behaviour _behaviour;;

  /** TODO: Documentation */
  CFStringRef _label;

public:
  /**
   * TODO: Documentation
   * <p>
   */  
  BevelButton(short x, short y, short width, short height);

  /**
   * TODO: Documentation
   * <p>
   */
  BevelButton(const char* label, short x, short y, short w, short h);

  /**
   * TODO: Documentation
   * <p>
   */  
  BevelButton(bool isRounded, short x, short y, short width, short height);

  /**
   * TODO: Documentation
   * <p>
   */
  BevelButton(const char* label, bool isRounded, short x, short y, short w, short h);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~BevelButton();

private:
  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus create(WindowRef windowRef);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void dispose();

};


}


}


#endif // PROTOLAYER_CARBON_BEVELBUTTON_H
