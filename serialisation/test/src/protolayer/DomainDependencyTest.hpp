#ifndef PROTOLAYER_ONTOLOGY_DOMAINDEPENDENCYTEST_HPP
#define PROTOLAYER_ONTOLOGY_DOMAINDEPENDENCYTEST_HPP

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

class DomainDependencyTest
{
public:
  /**
   * TODO: Documentation
   *
   */
  DomainDependencyTest()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
 ~DomainDependencyTest()
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
  DomainDependencyTest(const DomainDependencyTest& domainDependencyTest);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  DomainDependencyTest& operator=(const DomainDependencyTest& domainDependencyTest);

};


}


}


#endif // PROTOLAYER_ONTOLOGY_DOMAINDEPENDENCYTEST_H
