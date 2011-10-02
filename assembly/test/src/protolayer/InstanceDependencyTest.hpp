#ifndef PROTOLAYER_ASSEMBLY_INSTANCEDEPENDENCYTEST_HPP
#define PROTOLAYER_ASSEMBLY_INSTANCEDEPENDENCYTEST_HPP

#include <map>
#include <string>

#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLChar.hpp>
#include <xercesc/util/XMLString.hpp>

#include <protolayer/protolayer-ontology.h>
#include <protolayer/protolayer-util.h>
#include <protolayer/protolayer-xml.h>

#include "protolayer/protolayer-assembly.h"

namespace protolayer
{

namespace assembly
{

class InstanceDependencyTest
{
public:
  /**
   * TODO: Documentation
   *
   */
  InstanceDependencyTest()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
  ~InstanceDependencyTest()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testSuite()
  {
    setUp();
    testXdr();
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
  void testXdr()
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
  InstanceDependencyTest(const InstanceDependencyTest& instanceDependencyTest);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  InstanceDependencyTest& operator=(const InstanceDependencyTest& instanceDependencyTest);

};


}


}


#endif // PROTOLAYER_ASSEMBLY_INSTANCEDEPENDENCYTEST_H
