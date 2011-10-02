#ifndef PROTOLAYER_CARBON_DATABROWSER_H
#define PROTOLAYER_CARBON_DATABROWSER_H

#include <vector>

#include "forward.h"
#include "EmbeddingControl.h"
#include "Tab.h"

namespace protolayer
{

namespace carbon
{

/**
 * TODO: Documentation
 * <p>
 */
class DataBrowser : public EmbeddingControl
{
public:
  /** TODO: Documentation */
  enum Style { NO_VIEW = kDataBrowserNoView,
               LIST_VIEW = kDataBrowserListView,
               COLUMN_VIEW = kDataBrowserColumnView};

private:
  /** TODO: Documentation */
  Style _style;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  DataBrowser(short x, short y, short w, short h, Style style);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~DataBrowser();

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

#endif // PROTOLAYER_CARBON_DATABROWSER_H
