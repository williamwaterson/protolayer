#ifndef PROTOLAYER_ASSEMBLY_REFERENCETEST_HPP
#define PROTOLAYER_ASSEMBLY_REFERENCETEST_HPP

#include <map>
#include <string>

#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLChar.hpp>
#include <xercesc/util/XMLString.hpp>

#include <protolayer/protolayer-ontology.h>
#include <protolayer/protolayer-util.h>
#include <protolayer/protolayer-xml.h>

#include "protolayer/protolayer-assembly.h"

#include "XMLRelatedTest.hpp"

namespace protolayer
{

namespace assembly
{

class ReferenceTest : public XMLRelatedTest
{
private:
  /** TODO: Documentation */
  ontology::Type* _fromType;

  /** TODO: Documentation */
  ontology::Type* _toType;

  /** TODO: Documentation */
  ontology::Association* _association;

public:
  /**
   * TODO: Documentation
   *
   */
  ReferenceTest()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
 ~ReferenceTest()
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
      testEquivalence();
      tearDown();

      setUp();
      testXdr();
      tearDown();

    } catch (Exception ex) {
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

    std::string scope("Chemistry");
    XMLCh* str = xercesc::XMLString::transcode("type");
    xercesc::DOMElement* typeElement = getDOMDocument().createElement(str);

    XMLCh* nameCh = xercesc::XMLString::transcode("name");
    XMLCh* valueCh = xercesc::XMLString::transcode("Bond");
    typeElement->setAttribute(nameCh, valueCh);
    ontologydto::TypeDTO fromTypeDTO(*typeElement);
    fromTypeDTO.getId() = 10;
    _fromType = new ontology::Type(fromTypeDTO);

    valueCh = xercesc::XMLString::transcode("Atom");
    typeElement->setAttribute(nameCh, valueCh);
    ontologydto::TypeDTO toTypeDTO(*typeElement);
    toTypeDTO.getId() = 11;
    _toType = new ontology::Type(toTypeDTO);

    std::map <int, ontology::Type*> typeDictionary;
    typeDictionary[_fromType->getId()] = _fromType;
    typeDictionary[_toType->getId()] = _toType;

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
    xercesc::DOMElement* assocElement = getDOMDocument().createElement(str);
    assocElement->appendChild(fromElement);
    assocElement->appendChild(toElement);


    ontologydto::AssociationDTO associationDTO(*assocElement);
    associationDTO.getId() = 20;

    associationDTO.getFromEnd().getConceptId() = 10;
    associationDTO.getToEnd().getConceptId() = 11;

    _association = new ontology::Association(associationDTO, typeDictionary);
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testConstruction()
  {
    Instance* fromInstance = new Instance(*_fromType);
    Instance* toInstance = new Instance(*_toType);
    try {
      Reference* reference = new Reference(*_association,
					   *fromInstance,
					   *toInstance);
      delete reference;
      assertTrue("Successfully constructed Reference instance.");
    } catch (Exception ex) {
      delete fromInstance;
      delete toInstance;
      fail("Incorrectly failed to construct the Reference instance.");
    }
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testGetters()
  {
    Instance* fromInstance = new Instance(*_fromType);
    Instance* toInstance = new Instance(*_toType);
    Reference* reference = new Reference(*_association,
					 *fromInstance,
					 *toInstance);

    assertTrue(&(reference->getAssociation()) == _association);
    assertTrue(&(reference->getFromInstance()) == fromInstance);
    assertTrue(&(reference->getToInstance()) == toInstance);

    delete reference;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testQueries()
  {
    Instance* fromInstance = new Instance(*_fromType);
    Instance* toInstance = new Instance(*_toType);
    Instance* otherInstance = new Instance(*_toType);

    Reference* reference = new Reference(*_association,
					 *fromInstance,
					 *toInstance);

    assertTrue(reference->isAssociation(*_association));

    assertTrue(reference->isFromInstance(*fromInstance));
    assertTrue(reference->isToInstance(*toInstance));
    assertFalse(reference->isFromInstance(*toInstance));
    assertFalse(reference->isToInstance(*fromInstance));
    assertFalse(reference->isFromInstance(*otherInstance));
    assertFalse(reference->isToInstance(*otherInstance));

    assertTrue(reference->involves(*fromInstance));
    assertTrue(reference->involves(*toInstance));
    assertFalse(reference->involves(*otherInstance));

    assertTrue(reference->involves(*fromInstance, *toInstance));
    assertTrue(reference->involves(*toInstance, *fromInstance));
    assertFalse(reference->involves(*fromInstance, *otherInstance));
    assertFalse(reference->involves(*otherInstance, *toInstance));
    assertFalse(reference->involves(*otherInstance, *fromInstance));
    assertFalse(reference->involves(*toInstance, *otherInstance));

    assertTrue(reference->matches(*fromInstance, *toInstance));
    assertFalse(reference->matches(*toInstance, *fromInstance));
    assertFalse(reference->matches(*fromInstance, *otherInstance));
    assertFalse(reference->matches(*otherInstance, *toInstance));
    assertFalse(reference->matches(*otherInstance, *fromInstance));
    assertFalse(reference->matches(*toInstance, *otherInstance));

    delete reference;
    delete fromInstance;
    delete toInstance;
    delete otherInstance;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testEquivalence()
  {
    Instance* fromInstance = new Instance(*_fromType);
    Instance* toInstance = new Instance(*_toType);
    Instance* otherInstance = new Instance(*_toType);

    Reference* reference = new Reference(*_association,
					 *fromInstance,
					 *toInstance);

    Reference* equivReference = new Reference(*_association,
					      *fromInstance,
					      *toInstance);

    Reference* nonequivReference = new Reference(*_association,
						 *fromInstance,
						 *otherInstance);

    assertTrue(reference->isEquivalent(*reference));
    assertTrue(reference->isEquivalent(*equivReference));
    assertFalse(reference->isEquivalent(*nonequivReference));

    delete nonequivReference;
    delete equivReference;
    delete reference;
    delete fromInstance;
    delete toInstance;
    delete otherInstance;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testXdr()
  {
    Instance* fromInstance = new Instance(*_fromType);
    Instance* toInstance = new Instance(*_toType);
    Instance* otherInstance = new Instance(*_toType);

    Reference reference(*_association,
			*fromInstance,
			*toInstance);

    iostream::XdrOutputStream ostream("testfile");
    reference.encode(ostream);
    ostream.close();

    std::map <int, void*> addressMappings;
    addressMappings[(int) fromInstance] = static_cast <void*> (fromInstance);
    addressMappings[(int) toInstance] = static_cast <void*> (toInstance);
    addressMappings[(int) otherInstance] = static_cast <void*> (otherInstance);
    addressMappings[(int) _association] = static_cast <void*> (_association);

    iostream::XdrInputStream istream("testfile");
    Reference decodedRef(istream, addressMappings);
    istream.close();

    remove("testfile");

    assertTrue(reference.isAssociation(*_association));

    assertTrue(reference.isFromInstance(*fromInstance));
    assertTrue(reference.isToInstance(*toInstance));
    assertFalse(reference.isFromInstance(*toInstance));
    assertFalse(reference.isToInstance(*fromInstance));
    assertFalse(reference.isFromInstance(*otherInstance));
    assertFalse(reference.isToInstance(*otherInstance));

    assertTrue(reference.involves(*fromInstance));
    assertTrue(reference.involves(*toInstance));
    assertFalse(reference.involves(*otherInstance));
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void tearDown()
  {
    XMLRelatedTest::tearDown();

    delete _association;
    delete _fromType;
    delete _toType;
  }

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  ReferenceTest(const ReferenceTest& referenceTest);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  ReferenceTest& operator=(const ReferenceTest& referenceTest);

};


}


}


#endif // PROTOLAYER_ASSEMBLY_REFERENCETEST_H
