#ifndef PROTOLAYER_ONTOLOGY_XMLEXCEPTIONTEST_HPP
#define PROTOLAYER_ONTOLOGY_XMLEXCEPTIONTEST_HPP

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

class XMLExceptionTest
{
public:
  /**
   * TODO: Documentation
   *
   */
  XMLExceptionTest()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
 ~XMLExceptionTest()
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
  XMLExceptionTest(const XMLExceptionTest& test);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  XMLExceptionTest& operator=(const XMLExceptionTest& test);

};


}


#endif // PROTOLAYER_ONTOLOGY_XMLEXCEPTIONTEST_H
