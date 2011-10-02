#include "SearchField.h"


namespace protolayer
{

namespace carbon
{


SearchField::SearchField(short x,
			 short y,
			 short width,
			 short height) :
  NonEmbeddingControl(x, y, width, height)
{
  _label = CFSTR("");
  _bounds.origin.x = x;
  _bounds.origin.y = y;
  _bounds.size.width = width;
  _bounds.size.width = width;
}


SearchField::SearchField(const char* label,
                       short x,
                       short y,
                       short width,
                       short height) :
  NonEmbeddingControl(x, y, width, height)
{
  _label = CFStringCreateWithCString(NULL, label, kCFStringEncodingMacRoman);
  _bounds.origin.x = x;
  _bounds.origin.y = y;
  _bounds.size.width = width;
  _bounds.size.width = width;
}


SearchField::~SearchField()
{
}


void
SearchField::setText(const char* text)
{
  SetControlData(getControlRef(), 0, kControlStaticTextTextTag, strlen(text), text);
}


OSStatus SearchField::create(WindowRef windowRef)
{
  //  kHISearchFieldNoAttributes = 0,
  //kHISearchFieldAttributesCancel = (1 << 0),
  //kHISearchFieldAttributesSearchIcon = (1 << 1)

  OSStatus result = HISearchFieldCreate(&_bounds,
					kHISearchFieldNoAttributes,
					NULL,
					_label,
					&getControlRef());

  initialise();
  applyActivity();
  applyVisibility();
  return result;
}


void SearchField::dispose()
{
  cleanup();
  DisposeControl(getControlRef());
}


}


}
