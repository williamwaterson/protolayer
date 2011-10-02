#ifndef PROTOLAYER_ONTOLOGY_DOMAINTEST_HPP
#define PROTOLAYER_ONTOLOGY_DOMAINTEST_HPP

#include <iostream.h>
#include <map>
#include <string>

#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLChar.hpp>
#include <xercesc/util/XMLString.hpp>

#include <protolayer/protolayer-util.h>
#include <protolayer/protolayer-xml.h>

#include "protolayer/protolayer-ontologydto.h"

#include "XMLRelatedTest.hpp"

namespace protolayer
{

namespace ontologydto
{

class DomainTest : public XMLRelatedTest
{
public:
  /**
   * TODO: Documentation
   *
   */
  DomainTest()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
 ~DomainTest()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testSuite()
  {
    try {
      setUp();
      testConstruction();
      tearDown();

      setUp();
      testGetters();
      tearDown();

      setUp();
      testQueries();
      tearDown();

      setUp();
      testXdr();
      tearDown();

    } catch (ontologydto::Exception ex) {
      std::cout << ex.getMessage() << std::endl;
    }
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void setUp()
  {
    XMLRelatedTest::setUp();

    XMLCh* str = xercesc::XMLString::transcode("ontology");
    xercesc::DOMElement* ontologyElement = getDOMDocument().createElement(str);    
    getDOMDocument().getDocumentElement()->appendChild(ontologyElement);

    str = xercesc::XMLString::transcode("domain");
    xercesc::DOMElement* domainElement = getDOMDocument().createElement(str);
    ontologyElement->appendChild(domainElement);

    XMLCh* nameCh = xercesc::XMLString::transcode("name");
    str = xercesc::XMLString::transcode("type");
    xercesc::DOMElement* typeElement = getDOMDocument().createElement(str);
    XMLCh* valueCh = xercesc::XMLString::transcode("Molecule");
    typeElement->setAttribute(nameCh, valueCh);
    domainElement->appendChild(typeElement);

    typeElement = getDOMDocument().createElement(str);
    valueCh = xercesc::XMLString::transcode("Atom");
    typeElement->setAttribute(nameCh, valueCh);
    domainElement->appendChild(typeElement);    

    typeElement = getDOMDocument().createElement(str);
    valueCh = xercesc::XMLString::transcode("Bond");
    typeElement->setAttribute(nameCh, valueCh);
    domainElement->appendChild(typeElement);

    typeElement = getDOMDocument().createElement(str);
    valueCh = xercesc::XMLString::transcode("Phase");
    typeElement->setAttribute(nameCh, valueCh);
    domainElement->appendChild(typeElement);
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testConstruction()
  {
    try {
      DomainDTO* domain = new DomainDTO(getDOMDocument());
      delete domain;
    } catch (ontologydto::Exception ex) {
      //      fail("Failed construction.");
      std::cout << ex.getMessage() << std::endl;
    }
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testGetters()
  {
    DomainDTO* domain = 0;
    try {
      domain = new DomainDTO(getDOMDocument());
    } catch (ontologydto::Exception ex) {
      throw; // fail(); //(ex.getMessage());
    }

    domain->getTypes();
    domain->getAssociations();
    domain->getGeneralisations();

    //    assertFalse(domain == 0);
    //assertTrue(domain->getDescription() == "No Description");
    //    assertTrue(domain->getType("Atom")->getName() == "Atom");
    //    assertTrue(domain->getType("Bond")->getName() == "Bond");
    //    assertTrue(domain->getType("Molecule")->getName() == "Molecule");
    //    assertTrue(domain->getType("SomeType") == 0);

    //    assertFalse(domain->getTypes().size() == 0);
    
    assertTrue(domain->getTypes().size() == 4);

    //    Domain::IteratorType iter;
    //    for (iter = domain->getTypes(); iter.hasNext(); ) {
    //      Type* type = &(iter.next());
    //      std::string name = type->getName();
      //      assertTrue(domain->getType(name) == type);
    //    }

    delete domain;    
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testQueries()
  {
    DomainDTO* domain = new DomainDTO(getDOMDocument());

    //    Type* atomType = domain->getType("Atom");
    //    assertFalse(atomType == 0);
    //    assertTrue(domain->contains(*atomType));

    //    Type* bondType = domain->getType("Bond");
    //    assertFalse(bondType == 0);
    //    assertTrue(domain->contains(*bondType));

    //    Type* moleculeType = domain->getType("Molecule");
    //    assertFalse(moleculeType == 0);
    //    assertTrue(domain->contains(*moleculeType));

    //    XMLCh* str = xercesc::XMLString::transcode("type");
    //    xercesc::DOMElement* typeElement = getDOMDocument().createElement(str);
    //    XMLCh* nameCh = xercesc::XMLString::transcode("name");
    //    XMLCh* valueCh = xercesc::XMLString::transcode("Flow");
    //    typeElement->setAttribute(nameCh, valueCh);
    //    std::string scope = "Chemistry";
    //    Type* flowType =  new Type(scope, *typeElement);
    //    assertFalse(flowType == 0);
    //    assertFalse(domain->contains(*flowType));

    delete domain;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testXdr()
  {
    DomainDTO domain(getDOMDocument());
    domain.getTitle() = "Chemistry";

    iostream::XdrOutputStream ostream("testfile");
    domain.encode(ostream);
    ostream.close();

    iostream::XdrInputStream istream("testfile");
    DomainDTO decodedDomain(istream);
    istream.close();

    remove("testfile");

    //assertTrue(decodedDomain.getTitle() == "Chemistry");
    //assertTrue(decodedDomain.getDescription() == "No Description");
    //    assertTrue(decodedDomain.getType("Atom")->getName() == "Atom");
    //    assertTrue(decodedDomain.getType("Bond")->getName() == "Bond");
    //    assertTrue(decodedDomain.getType("Molecule")->getName() == "Molecule");
    //    assertTrue(decodedDomain.getType("SomeType") == 0);

    assertTrue(decodedDomain.getTypes().size() == 4);

    //    DomainDTO::IteratorType iter;
    //    for (iter = decodedDomain.getTypes(); iter.hasNext(); ) {
    //      Type* type = &(iter.next());
    //      std::string name = type->getName();
      //      assertTrue(decodedDomain.getType(name) == type);
    //    }
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void tearDown()
  {
    XMLRelatedTest::tearDown();
  }

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  DomainTest(const DomainTest& domainTest);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  DomainTest& operator=(const DomainTest& domainTest);

};


}


}


#endif // PROTOLAYER_ONTOLOGY_DOMAINTEST_H
