#ifndef PROTOLAYER_ONTOLOGY_ENDTEST_HPP
#define PROTOLAYER_ONTOLOGY_ENDTEST_HPP

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

class EndTest : public XMLRelatedTest
{
private:
  /** TODO: Documentation */
  xercesc::DOMElement* _endElement;

  /** TODO: Documentation */
  Type* _type;

  /** TODO: Documentation */
  Type* _otherType;

  /** TODO: Documentation */
  std::map <int, Type*> _typeDictionary;

public:
  /**
   * TODO: Documentation
   *
   */
  EndTest()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
  ~EndTest()
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
      testName();
      tearDown();

      setUp();
      testXdr();
      tearDown();

    } catch (ontology::Exception ex) {
      std::cout << "Failure" << std::endl;      
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
    XMLCh* valueCh = xercesc::XMLString::transcode("Boundary");
    typeElement->setAttribute(nameCh, valueCh);
    ontologydto::TypeDTO* typeDTO = new ontologydto::TypeDTO(*typeElement);
    typeDTO->getId() = 10;
    _type = new Type(*typeDTO);

    nameCh = xercesc::XMLString::transcode("name");
    valueCh = xercesc::XMLString::transcode("Atom");
    typeElement->setAttribute(nameCh, valueCh);
    typeDTO = new ontologydto::TypeDTO(*typeElement);
    typeDTO->getId() = 11;
    _otherType = new Type(*typeDTO);


    _typeDictionary[_type->getId()] = _type;
    _typeDictionary[_otherType->getId()] = _otherType;

    str = xercesc::XMLString::transcode("from");
    _endElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Boundary");
    _endElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("1..*");
    _endElement->setAttribute(nameCh, valueCh);
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testConstruction()
  {
    try {
      ontologydto::EndDTO* endDTO= new ontologydto::EndDTO(*_endElement);
      endDTO->getConceptId() = 10;
      End* end = new End(*endDTO, _typeDictionary);
      assertTrue("Successful construction");
    } catch (ontology::Exception ex) {
      assertFalse("Failed to construct End instance.");
    }
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testGetters()
  {
    ontologydto::EndDTO* endDTO= new ontologydto::EndDTO(*_endElement);
    endDTO->getConceptId() = 10;
    End* end = new End(*endDTO, _typeDictionary);

    //    assertTrue(end->getName() == "");

    //    Multiplicity& multi = end->getMultiplicity();
    assertTrue(end->getLowerBound() == 1);
    assertTrue(end->getUpperBound() == End::UNBOUNDED);

    assertTrue(_type == &(end->getType()));
    assertFalse(_otherType == &(end->getType()));
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testQueries()
  {
    ontologydto::EndDTO* endDTO= new ontologydto::EndDTO(*_endElement);
    endDTO->getConceptId() = 10;
    End* end = new End(*endDTO, _typeDictionary);

    assertTrue(end->isType(*_type));
    assertFalse(end->isType(*_otherType));

    //    Multiplicity& multi = end->getMultiplicity();
    //    assertTrue(end->isMultiplicity(multi));
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testName()
  {
    XMLCh* nameCh = xercesc::XMLString::transcode("name");
    XMLCh* valueCh = xercesc::XMLString::transcode("outer");
    _endElement->setAttribute(nameCh, valueCh);

    ontologydto::EndDTO* endDTO= new ontologydto::EndDTO(*_endElement);
    endDTO->getId() = 1;
    endDTO->getConceptId() = 10;
    endDTO->getDomainId() = 3;

    End* end = new End(*endDTO, _typeDictionary);

    //    assertTrue(end->getName() != "");
    //    assertTrue(end->getName() == "outer");
    //    assertTrue(end->getName() != "another");

    std::string outer("outer");
    std::string inner("inner");
    //    assertTrue(end->getName() == outer);
    //    assertTrue(end->getName() != inner);
  }

  /**
   * TODO: Documentation
   *
   */
  void testXdr()
  {
    /*
    ontologydto::EndDTO* endDTO= new ontologydto::EndDTO(*_endElement);
    End* end = new End(*endDTO, _typeDictionary);
    iostream::XdrOutputStream ostream("testfile");
    end.encode(ostream);
    ostream.close();

    std::map <int, void*> addressMappings;
    addressMappings[(int) _type] = static_cast <void*> (_type);
    addressMappings[(int) _otherType] = static_cast <void*> (_otherType);

    iostream::XdrInputStream istream("testfile");
    endDTO = new ontologydto::EndDTO(*_endElement);
    End decodedEnd(*endDTO, _typeDictionary);
    istream.close();
    remove("testfile");

    //    assertTrue(decodedEnd.getName() == "");
    assertTrue(_type == &(decodedEnd.getType()));
    assertFalse(_otherType == &(decodedEnd.getType()));
    //    Multiplicity& multi = decodedEnd.getMultiplicity();
    assertTrue(decodedEnd.getLowerBound() == 1);
    assertTrue(decodedEnd.getUpperBound() == End::UNBOUNDED);
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
  EndTest(const EndTest& endTest);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  EndTest& operator=(const EndTest& endTest);

};


}


}


#endif // PROTOLAYER_ONTOLOGY_ENDTEST_H
