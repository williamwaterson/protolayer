#ifndef PROTOLAYER_ONTOLOGY_GENERALISATIONTEST_HPP
#define PROTOLAYER_ONTOLOGY_GENERALISATIONTEST_HPP

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

class GeneralisationTest : public XMLRelatedTest
{
private:
  /** TODO: Documentation */
  xercesc::DOMElement* _genElement;

  /** TODO: Documentation */
  Type* _superType;

  /** TODO: Documentation */
  Type* _subType;

  /** TODO: Documentation */
  Type* _thirdType;

  /** TODO: Documentation */
  std::map <int, Type*> _typeDictionary;

public:
  /**
   * TODO: Documentation
   *
   */
  GeneralisationTest()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
 ~GeneralisationTest()
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
      testComparators();
      tearDown();

      setUp();
      //      testXdr();
      tearDown();

    } catch (ontology::Exception ex) {
      std::cout << "Failure " << ex.getMessage() << std::endl;
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
    xercesc::DOMElement* superTypeElement = getDOMDocument().createElement(str);
    XMLCh* nameCh = xercesc::XMLString::transcode("name");
    XMLCh* valueCh = xercesc::XMLString::transcode("Boundary");
    superTypeElement->setAttribute(nameCh, valueCh);
    ontologydto::TypeDTO* typeDTO = new ontologydto::TypeDTO(*superTypeElement);
    typeDTO->getId() = 10;
    _superType = new Type(*typeDTO);

    xercesc::DOMElement* subTypeElement = getDOMDocument().createElement(str);
    valueCh = xercesc::XMLString::transcode("SpatialBoundary");
    subTypeElement->setAttribute(nameCh, valueCh);
    typeDTO = new ontologydto::TypeDTO(*subTypeElement);
    typeDTO->getId() = 11;
    _subType = new Type(*typeDTO);

    xercesc::DOMElement* thirdTypeElement = getDOMDocument().createElement(str);
    valueCh = xercesc::XMLString::transcode("Atom");
    thirdTypeElement->setAttribute(nameCh, valueCh);
    typeDTO = new ontologydto::TypeDTO(*thirdTypeElement);
    typeDTO->getId() = 12;
    _thirdType = new Type(*typeDTO);

    _typeDictionary[_subType->getId()] = _subType;
    _typeDictionary[_superType->getId()] = _superType;
    _typeDictionary[_thirdType->getId()] = _thirdType;

    str = xercesc::XMLString::transcode("generalisation");
    _genElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("supertype");
    valueCh = xercesc::XMLString::transcode("Boundary");
    _genElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("subtype");
    valueCh = xercesc::XMLString::transcode("SpatialBoundary");
    _genElement->setAttribute(nameCh, valueCh);
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testConstruction()
  {
    try {
      ontologydto::GeneralisationDTO* genDTO = new ontologydto::GeneralisationDTO(*_genElement);
      genDTO->getId() = 20;
      genDTO->getSuperTypeId() = 10;
      genDTO->getSubTypeId() = 11;

      Generalisation* gen = new Generalisation(*genDTO, _typeDictionary);
      assertTrue(true);
    } catch (ontology::Exception ex) {
      throw; // fail("Failed construction test.");
    }
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testGetters()
  {
    ontologydto::GeneralisationDTO* genDTO = new ontologydto::GeneralisationDTO(*_genElement);
    genDTO->getId() = 20;
    genDTO->getSuperTypeId() = 10;
    genDTO->getSubTypeId() = 11;

    Generalisation* gen = new Generalisation(*genDTO, _typeDictionary);

    assertTrue(&(gen->getSuperType()) == _superType);
    assertTrue(&(gen->getSubType()) == _subType);
    assertFalse(&(gen->getSuperType()) == _subType);
    assertFalse(&(gen->getSubType()) == _superType);
    assertFalse(&(gen->getSubType()) == _thirdType);
    assertFalse(&(gen->getSuperType()) == _thirdType);
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testQueries()
  {
    ontologydto::GeneralisationDTO* genDTO = new ontologydto::GeneralisationDTO(*_genElement);
    genDTO->getId() = 20;
    genDTO->getSuperTypeId() = 10;
    genDTO->getSubTypeId() = 11;

    Generalisation* gen = new Generalisation(*genDTO, _typeDictionary);
    /*
    assertTrue(gen->isSuperType(*_superType));
    assertTrue(gen->isSubType(*_subType));
    assertFalse(gen->isSuperType(*_subType));
    assertFalse(gen->isSubType(*_superType));
    assertFalse(gen->isSuperType(*_thirdType));
    assertFalse(gen->isSubType(*_thirdType));

    assertTrue(gen->involves(*_superType));
    assertTrue(gen->involves(*_subType));
    assertFalse(gen->involves(*_thirdType));

    assertTrue(gen->involves(*_superType, *_subType));
    assertTrue(gen->involves(*_subType, *_superType));
    assertFalse(gen->involves(*_thirdType, *_superType));
    assertFalse(gen->involves(*_subType, *_thirdType));
    assertFalse(gen->involves(*_thirdType, *_subType));
    assertFalse(gen->involves(*_superType, *_thirdType));

    assertTrue(gen->matches(*_superType, *_subType));
    assertFalse(gen->matches(*_subType, *_superType));
    assertFalse(gen->matches(*_thirdType, *_superType));
    assertFalse(gen->matches(*_subType, *_thirdType));
    assertFalse(gen->matches(*_thirdType, *_subType));
    assertFalse(gen->matches(*_superType, *_thirdType));
    */
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testComparators()
  {
    ontologydto::GeneralisationDTO* genDTO = new ontologydto::GeneralisationDTO(*_genElement);
    genDTO->getId() = 20;
    genDTO->getSuperTypeId() = 10;
    genDTO->getSubTypeId() = 11;
    Generalisation* gen = new Generalisation(*genDTO, _typeDictionary);

    genDTO = new ontologydto::GeneralisationDTO(*_genElement);
    genDTO->getId() = 20;
    genDTO->getSuperTypeId() = 10;
    genDTO->getSubTypeId() = 11;
    Generalisation* equivGen = new Generalisation(*genDTO, _typeDictionary);

    XMLCh* str = xercesc::XMLString::transcode("generalisation");
    xercesc::DOMElement* reverseElement =
      getDOMDocument().createElement(str);

    XMLCh* nameCh = xercesc::XMLString::transcode("supertype");
    XMLCh* valueCh = xercesc::XMLString::transcode("SpatialBoundary");
    reverseElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("subtype");
    valueCh = xercesc::XMLString::transcode("Boundary");
    reverseElement->setAttribute(nameCh, valueCh);

    genDTO = new ontologydto::GeneralisationDTO(*reverseElement);
    genDTO->getId() = 20;
    genDTO->getSuperTypeId() = 11;
    genDTO->getSubTypeId() = 10;

    Generalisation* reverseGen = new Generalisation(*genDTO, _typeDictionary);

    str = xercesc::XMLString::transcode("generalisation");
    xercesc::DOMElement* otherElement =
      getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("supertype");
    valueCh = xercesc::XMLString::transcode("Boundary");
    otherElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("subtype");
    valueCh = xercesc::XMLString::transcode("Atom");
    otherElement->setAttribute(nameCh, valueCh);

    genDTO = new ontologydto::GeneralisationDTO(*otherElement);
    genDTO->getId() = 20;
    genDTO->getSuperTypeId() = 10;
    genDTO->getSubTypeId() = 12;

    Generalisation* otherGen = new Generalisation(*genDTO, _typeDictionary);

    assertTrue(gen->isEquivalent(*equivGen));
    assertFalse(gen->isEquivalent(*reverseGen));
    assertFalse(gen->isEquivalent(*otherGen));

    assertFalse(gen->isReverse(*equivGen));
    assertTrue(gen->isReverse(*reverseGen));
    assertFalse(gen->isReverse(*otherGen));

    assertTrue(gen->isSimilar(*equivGen));
    assertTrue(gen->isSimilar(*reverseGen));
    assertFalse(gen->isSimilar(*otherGen));
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testXdr()
  {
    /*    ontologydto::GeneralisationDTO* genDTO = new ontologydto::GeneralisationDTO(*_genElement);
    Generalisation encodingGen(*genDTO, _typeDictionary);

    iostream::XdrOutputStream ostream("testfile");
    encodingGen.encode(ostream);
    ostream.close();

    std::map <int, void*> addressMappings;
    addressMappings[(int) _superType] = static_cast <void*> (_superType);
    addressMappings[(int) _subType] = static_cast <void*> (_subType);

    iostream::XdrInputStream istream("testfile");
    Generalisation decodedGen(istream, addressMappings);
    istream.close();

    remove("testfile");

    Type& superType = decodedGen.getSuperType();
    Type& subType = decodedGen.getSubType();
    assertTrue(&superType == _superType);
    assertTrue(&subType == _subType);
    */
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
  GeneralisationTest(const GeneralisationTest& generalisationTest);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  GeneralisationTest& operator=(const GeneralisationTest& generalisationTest);

};


}


}


#endif // PROTOLAYER_ONTOLOGY_GENERALISATIONTEST_H
