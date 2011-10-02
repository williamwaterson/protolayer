#ifndef PROTOLAYER_ONTOLOGY_ONTOLOGYEXCEPTIONTEST_HPP
#define PROTOLAYER_ONTOLOGY_ONTOLOGYEXCEPTIONTEST_HPP

#include <map>
#include <string>

#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLChar.hpp>
#include <xercesc/util/XMLString.hpp>

#include <protolayer/protolayer-util.h>
#include <protolayer/protolayer-xml.h>

#include "protolayer/protolayer-ontology.h"

namespace protolayer
{

namespace ontology
{

class ExceptionTest
{
private:
  /** TODO: Documentation */
  ontology::Exception* _exception;

public:
  /**
   * TODO: Documentation
   *
   */
  ExceptionTest()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
 ~ExceptionTest()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testSuite()
  {
    setUp();
    testCharArrayConstruction();
    tearDown();

    setUp();
    testStringConstruction();
    tearDown();

    setUp();
    testCopyConstructor();
    tearDown();

    setUp();
    testOperatorEquals();
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
  void testCharArrayConstruction()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testStringConstruction()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testCopyConstructor()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testOperatorEquals()
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
  ExceptionTest(const ExceptionTest& ontologyExceptionTest);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  ExceptionTest& operator=(const ExceptionTest& ontologyExceptionTest);

};


}


}


#endif // PROTOLAYER_ONTOLOGY_ONTOLOGYEXCEPTIONTEST_H
