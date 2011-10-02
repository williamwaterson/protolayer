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
#include "protolayer/protolayer-ontology.h"

#include "XMLRelatedTest.hpp"

namespace protolayer
{

namespace ontology
{

class AssociationTest : public XMLRelatedTest
{
private:
  /** TODO: Documentation */
  xercesc::DOMElement* _assocElement;

  /** TODO: Documentation */
  ontologydto::AssociationDTO* _assocDTO;

  /** TODO: Documentation */
  ontologydto::TypeDTO* _fromTypeDTO;

  /** TODO: Documentation */
  ontologydto::TypeDTO* _toTypeDTO;

  /** TODO: Documentation */
  ontologydto::TypeDTO* _otherTypeDTO;

  /** TODO: Documentation */
  Type* _fromType;

  /** TODO: Documentation */
  Type* _toType;

  /** TODO: Documentation */
  Type* _otherType;

  /** TODO: Documentation */
  std::map <int, Type*> _typeDictionary;

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
      testQueries();
      tearDown();

      setUp();
      testComparators();
      tearDown();

      setUp();
      testXdr();
      tearDown();

    } catch (ontology::Exception ex) {
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

    std::string scope("Chemistry");
    XMLCh* str = xercesc::XMLString::transcode("type");
    xercesc::DOMElement* typeElement = getDOMDocument().createElement(str);

    XMLCh* nameCh = xercesc::XMLString::transcode("name");
    XMLCh* valueCh = xercesc::XMLString::transcode("Bond");
    typeElement->setAttribute(nameCh, valueCh);
    _fromTypeDTO = new ontologydto::TypeDTO(*typeElement);
    _fromTypeDTO->getId() = 1;
    _fromTypeDTO->getDomainId() = 1;
    _fromType = new Type(*_fromTypeDTO);

    valueCh = xercesc::XMLString::transcode("Atom");
    typeElement->setAttribute(nameCh, valueCh);
    _toTypeDTO = new ontologydto::TypeDTO(*typeElement);
    _toTypeDTO->getId() = 2;
    _toTypeDTO->getDomainId() = 1;
    _toType = new Type(*_toTypeDTO);

    valueCh = xercesc::XMLString::transcode("Molecule");
    typeElement->setAttribute(nameCh, valueCh);
    _otherTypeDTO = new ontologydto::TypeDTO(*typeElement);
    _otherTypeDTO->getId() = 3;
    _otherTypeDTO->getDomainId() = 1;
    _otherType = new Type(*_otherTypeDTO);

    _typeDictionary[_fromType->getId()] = _fromType;
    _typeDictionary[_toType->getId()] = _toType;
    _typeDictionary[_otherType->getId()] = _otherType;

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

    _assocDTO = new ontologydto::AssociationDTO(*_assocElement);
    _assocDTO->getId() = 1;
    _assocDTO->getFromEnd().getConceptId() = 1;
    _assocDTO->getToEnd().getConceptId() = 2;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testConstruction()
  {
    try {
      Association* assoc = new Association(*_assocDTO, _typeDictionary);
      assertTrue("Successful construction.");
    } catch (ontology::Exception ex) {
      std::cout << "Unknown" << std::endl;      
      throw ontology::Exception("Failed construction");
    }
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testAccessors()
  {
    Association* assoc = new Association(*_assocDTO, _typeDictionary);

    assertTrue(&(assoc->getFromEnd().getType()) == _fromType);
    assertTrue(&(assoc->getToEnd().getType()) == _toType);
    assertFalse(&(assoc->getFromEnd().getType()) == _toType);
    assertFalse(&(assoc->getToEnd().getType()) == _fromType);

    assertTrue(assoc->getName() == "bound");

    delete assoc;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testQueries()
  {
    Association* assoc = new Association(*_assocDTO, _typeDictionary);

    assertTrue(assoc->isFromEnd(assoc->getFromEnd()));
    assertTrue(assoc->isToEnd(assoc->getToEnd()));

    assertTrue(assoc->isFromType(*_fromType));
    assertTrue(assoc->isToType(*_toType));

    assertTrue(assoc->involves(assoc->getFromEnd()));
    assertTrue(assoc->involves(assoc->getToEnd()));
    assertTrue(assoc->involves(*_toType));
    assertTrue(assoc->involves(*_fromType));
    assertFalse(assoc->involves(*_otherType));
    assertTrue(assoc->involves(*_toType, *_fromType));
    assertTrue(assoc->involves(*_fromType, *_toType));
    assertFalse(assoc->involves(*_otherType, *_toType));
    assertFalse(assoc->involves(*_toType, *_otherType));
    assertFalse(assoc->involves(*_otherType, *_fromType));
    assertFalse(assoc->involves(*_fromType, *_otherType));
    assertTrue(assoc->involves(assoc->getFromEnd()));
    assertTrue(assoc->involves(assoc->getToEnd()));

    assertTrue(assoc->matches(*_fromType, *_toType));
    assertFalse(assoc->matches(*_toType, *_fromType));
    assertFalse(assoc->matches(*_fromType, *_otherType));
    assertFalse(assoc->matches(*_otherType, *_fromType));
    assertFalse(assoc->matches(*_toType, *_otherType));
    assertFalse(assoc->matches(*_otherType, *_toType));

    assertTrue(assoc->matches(assoc->getFromEnd(),
			      assoc->getToEnd()));

    assertFalse(assoc->matches(assoc->getToEnd(),
			       assoc->getFromEnd()));

    assertTrue(assoc->isName("bound"));

    delete assoc;    
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testComparators()
  {
    std::string scope("Chemistry");
    XMLCh* str = xercesc::XMLString::transcode("from");

    xercesc::DOMElement* fromElement = getDOMDocument().createElement(str);
    XMLCh* nameCh = xercesc::XMLString::transcode("type");
    XMLCh* valueCh = xercesc::XMLString::transcode("Bond");
    fromElement->setAttribute(nameCh, valueCh);
    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("1..*");
    fromElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("to");
    xercesc::DOMElement* toElement = getDOMDocument().createElement(str);
    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Atom");
    toElement->setAttribute(nameCh, valueCh);
    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("1..*");
    toElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("to");
    xercesc::DOMElement* otherElement = getDOMDocument().createElement(str);
    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Molecule");
    otherElement->setAttribute(nameCh, valueCh);
    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("1..*");
    otherElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("association");

    xercesc::DOMElement* equivElement = getDOMDocument().createElement(str);
    equivElement->appendChild(fromElement);
    equivElement->appendChild(toElement);
    ontologydto::AssociationDTO* equivAssocDTO = new ontologydto::AssociationDTO(*equivElement);
    equivAssocDTO->getId() = 2;
    equivAssocDTO->getFromEnd().getConceptId() = 1;
    equivAssocDTO->getToEnd().getConceptId() = 2;    
    Association* equivAssoc = new Association(*equivAssocDTO, _typeDictionary);

    xercesc::DOMElement* someElement = getDOMDocument().createElement(str);
    someElement->appendChild(fromElement);
    someElement->appendChild(otherElement);
    ontologydto::AssociationDTO* someAssocDTO = new ontologydto::AssociationDTO(*someElement);
    someAssocDTO->getId() = 2;
    someAssocDTO->getFromEnd().getConceptId() = 1;
    someAssocDTO->getToEnd().getConceptId() = 3;
    Association* someAssoc = new Association(*someAssocDTO, _typeDictionary);

    xercesc::DOMElement* reverseElement = getDOMDocument().createElement(str);
    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Bond");
    toElement->setAttribute(nameCh, valueCh);
    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Atom");
    fromElement->setAttribute(nameCh, valueCh);
    reverseElement->appendChild(fromElement);
    reverseElement->appendChild(toElement);
    ontologydto::AssociationDTO* reverseAssocDTO = new ontologydto::AssociationDTO(*reverseElement);
    reverseAssocDTO->getId() = 2;
    reverseAssocDTO->getFromEnd().getConceptId() = 2;
    reverseAssocDTO->getToEnd().getConceptId() = 1;
    Association* reverseAssoc = new Association(*reverseAssocDTO, _typeDictionary);

    ontologydto::AssociationDTO* associationDTO = new ontologydto::AssociationDTO(*_assocElement);
    associationDTO->getId() = 1;
    associationDTO->getFromEnd().getConceptId() = 1;
    associationDTO->getToEnd().getConceptId() = 2;
    Association* association = new Association(*associationDTO, _typeDictionary);

    assertTrue(association->isEquivalent(*equivAssoc));
    assertFalse(association->isEquivalent(*reverseAssoc));
    assertFalse(association->isEquivalent(*someAssoc));

    assertFalse(association->isReverse(*equivAssoc));
    assertTrue(association->isReverse(*reverseAssoc));
    assertFalse(association->isReverse(*someAssoc));

    assertTrue(association->isSimilar(*equivAssoc));
    assertTrue(association->isSimilar(*reverseAssoc));
    assertFalse(association->isSimilar(*someAssoc));
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testXdr()
  {
    /*
      AssociationDTO assocDTO(*_assocElement);
    Association assoc(*_assocDTO, _typeDictionary);

    iostream::XdrOutputStream ostream("testfile");
    assoc.encode(ostream);
    ostream.close();

    std::map <int, void*> addressMappings;
    addressMappings[(int) _fromType] = static_cast <void*> (_fromType);
    addressMappings[(int) _toType] = static_cast <void*> (_toType);

    iostream::XdrInputStream istream("testfile");
    Association decodedAssoc(istream, addressMappings);
    Association decodedAssoc(istream, addressMappings);
    istream.close();

    remove("testfile");

    End& fromEnd = decodedAssoc.getFromEnd();
    assertTrue(&(fromEnd.getType()) == _fromType);
    //    Multiplicity& fromMulti = fromEnd.getMultiplicity();
    assertTrue(fromEnd.getLowerBound() == 0);
    assertTrue(fromEnd.getUpperBound() == End::UNBOUNDED);

    End& toEnd = decodedAssoc.getToEnd();
    assertTrue(&(toEnd.getType()) == _toType);
    //    Multiplicity& toMulti = toEnd.getMultiplicity();
    assertTrue(toEnd.getLowerBound() == 2);
    assertTrue(toEnd.getUpperBound() == 2);
    */
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void tearDown()
  {
    //    XMLRelatedTest::tearDown();
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
