#ifndef PROTOLAYER_ONTOLOGY_EXTRACTIONTEST_HPP
#define PROTOLAYER_ONTOLOGY_EXTRACTIONTEST_HPP

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

class ExtractionTest
{
public:
  /**
   * TODO: Documentation
   *
   */
  ExtractionTest()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
 ~ExtractionTest()
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
  ExtractionTest(const ExtractionTest& extractionTest);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  ExtractionTest& operator=(const ExtractionTest& extractionTest);

};


}


#endif // PROTOLAYER_ONTOLOGY_EXTRACTIONTEST_H
