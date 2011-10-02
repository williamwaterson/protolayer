#ifndef PROTOLAYER_ASSEMBLY_DOMAININSTANCEDEPENDENCYTEST_HPP
#define PROTOLAYER_ASSEMBLY_DOMAININSTANCEDEPENDENCYTEST_HPP

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

class DomainInstanceDependencyTest
{
public:
  /**
   * TODO: Documentation
   *
   */
  DomainInstanceDependencyTest()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
 ~DomainInstanceDependencyTest()
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
  DomainInstanceDependencyTest(const DomainInstanceDependencyTest& test);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  DomainInstanceDependencyTest& operator=(const DomainInstanceDependencyTest& test);

};


}


}


#endif // PROTOLAYER_ASSEMBLY_DOMAININSTANCEDEPENDENCYTEST_H
