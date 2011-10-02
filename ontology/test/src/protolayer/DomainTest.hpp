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

#include "protolayer/protolayer-ontology.h"
#include "protolayer/protolayer-ontologydto.h"

#include "XMLRelatedTest.hpp"

namespace protolayer
{

namespace ontology
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

    } catch (ontology::Exception ex) {
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
    XMLCh* valueCh = xercesc::XMLString::transcode("Chemistry");
    domainElement->setAttribute(nameCh, valueCh);
    
    str = xercesc::XMLString::transcode("type");

    str = xercesc::XMLString::transcode("type");
    xercesc::DOMElement* typeElement = getDOMDocument().createElement(str);
    valueCh = xercesc::XMLString::transcode("Molecule");
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
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testConstruction()
  {
    try {
      ontologydto::DomainDTO* domainDTO = new ontologydto::DomainDTO(getDOMDocument());
      domainDTO->getId() = 1;

      typedef std::set <ontologydto::TypeDTO*>::iterator IterType;
      for (IterType iter = domainDTO->getTypes().begin(); iter != domainDTO->getTypes().end(); iter++) {
	if ((*iter)->getName() == "Molecule") {
	  (*iter)->getId() = 1;
	} else if ((*iter)->getName() == "Atom") {
	  (*iter)->getId() = 2;
	} else if ((*iter)->getName() == "Bond") {
	  (*iter)->getId() = 3;
	}
      }

      Domain* domain = new Domain(*domainDTO);
      delete domain;
    } catch (ontology::Exception ex) {
      fail("Failed construction.");
    }
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testGetters()
  {
    Domain* domain = 0;
    try {
      ontologydto::DomainDTO* domainDTO = new ontologydto::DomainDTO(getDOMDocument());
      domainDTO->getTitle() = "Chemistry";
      domain = new Domain(*domainDTO);
    } catch (ontology::Exception ex) {
      throw; // fail(); //(ex.getMessage());
    }

    assertFalse(domain == 0);
    assertTrue(domain->getTitle() == "Chemistry");
    //    assertTrue(domain->getScope() == "Chemistry");
    assertTrue(domain->getDescription() == "No Description");
    assertTrue(domain->getTypeByUnscopedName("Atom")->getName() == "Atom");
    assertTrue(domain->getTypeByUnscopedName("Bond")->getName() == "Bond");
    assertTrue(domain->getTypeByUnscopedName("Molecule")->getName() == "Molecule");
    assertTrue(domain->getTypeByUnscopedName("SomeType") == 0);

    assertTrue(domain->getNumberTypes() == 3);

    Domain::IteratorType iter;
    for (iter = domain->getTypes(); iter.hasNext(); ) {
      Type* type = &(iter.next());
      std::string name = type->getName();
      assertTrue(domain->getTypeByUnscopedName(name) == type);
    }

    delete domain;    
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testQueries()
  {
    ontologydto::DomainDTO* domainDTO = new ontologydto::DomainDTO(getDOMDocument());
    Domain* domain = new Domain(*domainDTO);

    Type* atomType = domain->getTypeByUnscopedName("Atom");
    assertFalse(atomType == 0);
    assertTrue(domain->contains(*atomType));

    Type* bondType = domain->getTypeByUnscopedName("Bond");
    assertFalse(bondType == 0);
    assertTrue(domain->contains(*bondType));

    Type* moleculeType = domain->getTypeByUnscopedName("Molecule");
    assertFalse(moleculeType == 0);
    assertTrue(domain->contains(*moleculeType));

    XMLCh* str = xercesc::XMLString::transcode("type");
    xercesc::DOMElement* typeElement = getDOMDocument().createElement(str);
    XMLCh* nameCh = xercesc::XMLString::transcode("name");
    XMLCh* valueCh = xercesc::XMLString::transcode("Flow");
    typeElement->setAttribute(nameCh, valueCh);

    ontologydto::TypeDTO* typeDTO = new ontologydto::TypeDTO(*typeElement);
    Type* flowType =  new Type(*typeDTO);
    assertFalse(flowType == 0);
    assertFalse(domain->contains(*flowType));

    delete domain;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testXdr()
  {
    /*
    ontologydto::DomainDTO* domainDTO = new ontologydto::DomainDTO(getDOMDocument());
    Domain domain(*domainDTO)

    iostream::XdrOutputStream ostream("testfile");
    domain.encode(ostream);
    ostream.close();

    std::map <int, void*> addressMappings;
    iostream::XdrInputStream istream("testfile");
    Domain decodedDomain(istream, addressMappings);
    istream.close();

    remove("testfile");

    assertTrue(decodedDomain.getName() == "Chemistry");
//    assertTrue(decodedDomain.getScope() == "Chemistry");
    assertTrue(decodedDomain.getDescription() == "No Description");
    assertTrue(decodedDomain.getType("Atom")->getName() == "Atom");
    assertTrue(decodedDomain.getType("Bond")->getName() == "Bond");
    assertTrue(decodedDomain.getType("Molecule")->getName() == "Molecule");
    assertTrue(decodedDomain.getType("SomeType") == 0);

    assertTrue(decodedDomain.getNumberTypes() == 3);

    Domain::IteratorType iter;
    for (iter = decodedDomain.getTypes(); iter.hasNext(); ) {
      Type* type = &(iter.next());
      std::string name = type->getName();
      assertTrue(decodedDomain.getType(name) == type);
    }
    */
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
