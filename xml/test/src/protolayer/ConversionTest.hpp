#ifndef PROTOLAYER_ONTOLOGY_CONVERSIONTEST_HPP
#define PROTOLAYER_ONTOLOGY_CONVERSIONTEST_HPP

#include <map>
#include <string>

#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLChar.hpp>
#include <xercesc/util/XMLString.hpp>

#include <protolayer/protolayer-util.h>
#include <protolayer/xml.h>

#include "protolayer/protolayer-ontology.h"

namespace protolayer
{

class ConversionTest
{
public:
  /**
   * TODO: Documentation
   *
   */
  ConversionTest()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
 ~ConversionTest()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testSuite()
  {
    setUp();
    tearDown();
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void setUp()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void tearDown()
  {
  }

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  ConversionTest(const ConversionTest& conversionTest);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  ConversionTest& operator=(const ConversionTest& conversionTest);

};


}


#endif // PROTOLAYER_ONTOLOGY_CONVERSIONTEST_H
