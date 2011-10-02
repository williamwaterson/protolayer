#ifndef PROTOLAYER_ONTOLOGY_TYPEDEPENDENCYTEST_HPP
#define PROTOLAYER_ONTOLOGY_TYPEDEPENDENCYTEST_HPP

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

class TypeDependencyTest
{
public:
  /**
   * TODO: Documentation
   *
   */
  TypeDependencyTest()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
 ~TypeDependencyTest()
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
  TypeDependencyTest(const TypeDependencyTest& typeDependencyTest);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  TypeDependencyTest& operator=(const TypeDependencyTest& typeDependencyTest);

};


}


}


#endif // PROTOLAYER_ONTOLOGY_TYPEDEPENDENCYTEST_H
