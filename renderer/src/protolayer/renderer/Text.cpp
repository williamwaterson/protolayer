#include "Text.h"


namespace protolayer
{

namespace renderer
{

namespace
{
}


Text::Text(Font& font)
{
  _font = &font;
}


Text::~Text()
{
}


void Text::render(float alpha)
{
  glColor4f(0, 0, 0, 1);
  glPushAttrib( GL_LIST_BIT );
  glListBase(_font->_id - 32 );
  char* message = "I am therefore I sleep";
  glRasterPos3f(1.0, 1.0, 1.0);

  glCallLists(strlen(message), GL_UNSIGNED_BYTE, message);

  glPopAttrib();
}


}


}
