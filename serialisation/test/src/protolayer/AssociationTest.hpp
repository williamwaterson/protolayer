#ifndef PROTOLAYER_ONTOLOGY_ASSOCIATIONTEST_HPP
#define PROTOLAYER_ONTOLOGY_ASSOCIATIONTEST_HPP

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

class AssociationTest : public XMLRelatedTest
{
private:
  /** TODO: Documentation */
  xercesc::DOMElement* _assocElement;

public:
  /**
   * TODO: Documentation
   *
   */
  AssociationTest()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
 ~AssociationTest()
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
      testAccessors();
      tearDown();

      setUp();
      testXdr();
      tearDown();

    } catch (ontologydto::Exception ex) {
      std::cout << ex.getMessage() << std::endl;

    } catch (...) {
      std::cout << "Unknown" << std::endl;
    }
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void setUp()
  {
    XMLRelatedTest::setUp();

    XMLCh* str = xercesc::XMLString::transcode("type");
    xercesc::DOMElement* typeElement = getDOMDocument().createElement(str);

    XMLCh* nameCh = xercesc::XMLString::transcode("name");
    XMLCh* valueCh = xercesc::XMLString::transcode("Bond");
    typeElement->setAttribute(nameCh, valueCh);

    valueCh = xercesc::XMLString::transcode("Atom");
    typeElement->setAttribute(nameCh, valueCh);

    valueCh = xercesc::XMLString::transcode("Molecule");
    typeElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("from");
    xercesc::DOMElement* fromElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Bond");
    fromElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("0..*");
    fromElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("to");
    xercesc::DOMElement* toElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Atom");
    toElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("2");
    toElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("association");
    _assocElement = getDOMDocument().createElement(str);
    _assocElement->appendChild(fromElement);
    _assocElement->appendChild(toElement);

    nameCh = xercesc::XMLString::transcode("name");
    valueCh = xercesc::XMLString::transcode("bound");
    _assocElement->setAttribute(nameCh, valueCh);
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testConstruction()
  {
    try {
      AssociationDTO* assoc = new AssociationDTO(*_assocElement);
      assertTrue("Successful construction.");
    } catch (ontologydto::Exception ex) {
      std::cout << "Unknown" << std::endl;      
      throw ontologydto::Exception("Failed construction");
    }
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testAccessors()
  {
    AssociationDTO* assoc = new AssociationDTO(*_assocElement);

    assertTrue(assoc->getFromEnd().getTypeName() == "Bond");
    assertTrue(assoc->getToEnd().getTypeName() == "Atom");
    assertTrue(assoc->getName() == "bound");

    delete assoc;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testXdr()
  {
    AssociationDTO assoc(*_assocElement);

    iostream::XdrOutputStream ostream("testfile");
    assoc.encode(ostream);
    ostream.close();

    iostream::XdrInputStream istream("testfile");
    AssociationDTO decodedAssoc(istream);
    istream.close();

    remove("testfile");
    
    assertTrue(decodedAssoc.getFromEnd().getTypeName() == assoc.getFromEnd().getTypeName());
    assertTrue(decodedAssoc.getFromEnd().getMultiplicity() == assoc.getFromEnd().getMultiplicity());

    assertTrue(decodedAssoc.getToEnd().getTypeName() == assoc.getToEnd().getTypeName());
    assertTrue(decodedAssoc.getToEnd().getMultiplicity() == assoc.getToEnd().getMultiplicity());
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
  AssociationTest(const AssociationTest& associationTest);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  AssociationTest& operator=(const AssociationTest& associationTest);

};


}


}


#endif // PROTOLAYER_ONTOLOGY_ASSOCIATIONTEST_H
