#include "Font.h"


namespace protolayer
{



namespace renderer
{

namespace
{
}


Font::Font()
{
  _id = glGenLists(96);

#ifdef __APPLE__
  Str255 fontName;
  CopyCStringToPascal("Arial", fontName);
  _fontType = FMGetFontFamilyFromName(fontName);
  assert(_fontType != kInvalidFontFamily);
  aglUseFont(aglGetCurrentContext(), _fontType, bold, 16, 32, 96, _id);
#endif
}


Font::~Font()
{
}


}


}
