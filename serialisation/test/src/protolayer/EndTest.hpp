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

#include "protolayer/protolayer-ontologydto.h"

#include "XMLRelatedTest.hpp"

namespace protolayer
{

namespace ontologydto
{

class EndTest : public XMLRelatedTest
{
private:
  /** TODO: Documentation */
  xercesc::DOMElement* _endElement;

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

    } catch (ontologydto::Exception ex) {
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

    nameCh = xercesc::XMLString::transcode("name");
    valueCh = xercesc::XMLString::transcode("Atom");
    typeElement->setAttribute(nameCh, valueCh);

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
      EndDTO* end = new EndDTO(*_endElement);
      assertTrue("Successful construction");
    } catch (ontologydto::Exception ex) {
      assertFalse("Failed to construct End instance.");
    }
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testGetters()
  {
    EndDTO* end = new EndDTO(*_endElement);

    assertTrue("Boundary" == end->getTypeName());
    assertFalse("OtherBoundary" == end->getTypeName());

    assertTrue("1..*" == end->getMultiplicity());
    assertFalse("0..*" == end->getMultiplicity());

    delete end;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testQueries()
  {
    EndDTO* end = new EndDTO(*_endElement);

    //    assertTrue(end->isType(*_type));
    //    assertFalse(end->isType(*_otherType));

    //    Multiplicity& multi = end->getMultiplicity();
    //    assertTrue(end->isMultiplicity(multi));

    delete end;
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

    EndDTO* end = new EndDTO(*_endElement);

    //    assertTrue(end->getName() != "");
    //    assertTrue(end->getName() == "outer");
    //    assertTrue(end->getName() != "another");

    //    std::string outer("outer");
    //    std::string inner("inner");
    //    assertTrue(end->getName() == outer);
    //    assertTrue(end->getName() != inner);

    delete end;
  }

  /**
   * TODO: Documentation
   *
   */
  void testXdr()
  {
    EndDTO end(*_endElement);
    iostream::XdrOutputStream ostream("testfile");
    end.encode(ostream);
    ostream.close();

    iostream::XdrInputStream istream("testfile");
    EndDTO decodedEnd(istream);
    istream.close();
    remove("testfile");

    assertFalse(decodedEnd.getTypeName() == "");
    assertTrue("Boundary" == decodedEnd.getTypeName());
    assertFalse("AnotherBoundary" == decodedEnd.getTypeName());
    assertTrue("1..*" == decodedEnd.getMultiplicity());
    assertFalse("0..*" == decodedEnd.getMultiplicity());
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
