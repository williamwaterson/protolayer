#ifndef PROTOLAYER_ONTOLOGY_GENERALISATIONTEST_HPP
#define PROTOLAYER_ONTOLOGY_GENERALISATIONTEST_HPP

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

class GeneralisationTest : public XMLRelatedTest
{
private:
  /** TODO: Documentation */
  xercesc::DOMElement* _genElement;

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
      testXdr();
      tearDown();

    } catch (ontologydto::Exception ex) {
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

    xercesc::DOMElement* subTypeElement = getDOMDocument().createElement(str);
    valueCh = xercesc::XMLString::transcode("SpatialBoundary");
    subTypeElement->setAttribute(nameCh, valueCh);

    xercesc::DOMElement* thirdTypeElement = getDOMDocument().createElement(str);
    valueCh = xercesc::XMLString::transcode("Atom");
    thirdTypeElement->setAttribute(nameCh, valueCh);

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
      GeneralisationDTO* gen = new GeneralisationDTO(*_genElement);
      assertTrue(true);
      delete gen;
    } catch (ontologydto::Exception ex) {
      throw; // fail("Failed construction test.");
    }
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testGetters()
  {
    GeneralisationDTO* gen = new GeneralisationDTO(*_genElement);

    assertTrue(gen->getSuperTypeName() == "Boundary");
    assertTrue(gen->getSubTypeName() == "SpatialBoundary");

    delete gen;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testQueries()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testComparators()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testXdr()
  {
    GeneralisationDTO encodingGen(*_genElement);

    iostream::XdrOutputStream ostream("testfile");
    encodingGen.encode(ostream);
    ostream.close();

    iostream::XdrInputStream istream("testfile");
    GeneralisationDTO decodedGen(istream);
    istream.close();

    remove("testfile");

    assertTrue(decodedGen.getSuperTypeName() == encodingGen.getSuperTypeName());
    assertTrue(decodedGen.getSubTypeName() == encodingGen.getSubTypeName());
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
