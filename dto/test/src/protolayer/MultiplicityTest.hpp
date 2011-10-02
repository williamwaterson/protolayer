#ifndef PROTOLAYER_ONTOLOGY_MULTIPLICITYTEST_HPP
#define PROTOLAYER_ONTOLOGY_MULTIPLICITYTEST_HPP

#include <map>
#include <string>

#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLChar.hpp>
#include <xercesc/util/XMLString.hpp>

#include <protolayer/protolayer-util.h>
#include <protolayer/protolayer-xml.h>

#include "protolayer/protolayer-ontology.h"
#include "XMLRelatedTest.hpp"

namespace protolayer
{

namespace ontology
{

class MultiplicityTest : public XMLRelatedTest
{
private:
  /** TODO: Documentation */
  xercesc::DOMElement* _endElement;

public:
  /**
   * TODO: Documentation
   *
   */
  MultiplicityTest()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
  ~MultiplicityTest()
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
      testStar();
      tearDown();

      setUp();
      testInteger();
      tearDown();

      setUp();
      testIntegerDotDotInteger();
      tearDown();

      setUp();
      testIntegerDotDotStar();
      tearDown();

      setUp();
      testMiscellaneousInvalidValues();
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

    XMLCh* str = xercesc::XMLString::transcode("from");
    _endElement = getDOMDocument().createElement(str);

    XMLCh* nameCh = xercesc::XMLString::transcode("type");
    XMLCh* valueCh = xercesc::XMLString::transcode("Chemistry.Atom");
    _endElement->setAttribute(nameCh, valueCh);
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testStar()
  {
    XMLCh* nameCh = xercesc::XMLString::transcode("multiplicity");
    XMLCh* valueCh = xercesc::XMLString::transcode("*");
    _endElement->setAttribute(nameCh, valueCh);
    verifyMultiplicity(*_endElement, 0, Multiplicity::UNBOUNDED);
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testInteger()
  {
    XMLCh* nameCh = xercesc::XMLString::transcode("multiplicity");

    XMLCh* valueCh = xercesc::XMLString::transcode("2");
    _endElement->setAttribute(nameCh, valueCh);
    verifyMultiplicity(*_endElement, 2, 2);

    valueCh = xercesc::XMLString::transcode("12340");
    _endElement->setAttribute(nameCh, valueCh);
    verifyMultiplicity(*_endElement, 12340, 12340);

    valueCh = xercesc::XMLString::transcode("-12340");
    _endElement->setAttribute(nameCh, valueCh);
    verifyMultiplicityFailure(*_endElement);

    valueCh = xercesc::XMLString::transcode("0");
    _endElement->setAttribute(nameCh, valueCh);
    verifyMultiplicityFailure(*_endElement);
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testIntegerDotDotInteger()
  {
    XMLCh* nameCh = xercesc::XMLString::transcode("multiplicity");

    XMLCh* valueCh = xercesc::XMLString::transcode("2..23");
    _endElement->setAttribute(nameCh, valueCh);
    verifyMultiplicity(*_endElement, 2, 23);

    valueCh = xercesc::XMLString::transcode("0..2");
    _endElement->setAttribute(nameCh, valueCh);
    verifyMultiplicity(*_endElement, 0, 2);

    valueCh = xercesc::XMLString::transcode("4..4");
    _endElement->setAttribute(nameCh, valueCh);
    verifyMultiplicity(*_endElement, 4, 4);

    valueCh = xercesc::XMLString::transcode("465..4234");
    _endElement->setAttribute(nameCh, valueCh);
    verifyMultiplicity(*_endElement, 465, 4234);

    valueCh = xercesc::XMLString::transcode("3..-2");
    _endElement->setAttribute(nameCh, valueCh);
    verifyMultiplicityFailure(*_endElement);

    valueCh = xercesc::XMLString::transcode("342..-2");
    _endElement->setAttribute(nameCh, valueCh);
    verifyMultiplicityFailure(*_endElement);

    valueCh = xercesc::XMLString::transcode("3..0");
    _endElement->setAttribute(nameCh, valueCh);
    verifyMultiplicityFailure(*_endElement);

    valueCh = xercesc::XMLString::transcode("342..0");
    _endElement->setAttribute(nameCh, valueCh);
    verifyMultiplicityFailure(*_endElement);
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testIntegerDotDotStar()
  {
    XMLCh* nameCh = xercesc::XMLString::transcode("multiplicity");
    XMLCh* valueCh = xercesc::XMLString::transcode("0..*");
    _endElement->setAttribute(nameCh, valueCh);
    verifyMultiplicity(*_endElement, 0, Multiplicity::UNBOUNDED);

    valueCh = xercesc::XMLString::transcode("1..*");
    _endElement->setAttribute(nameCh, valueCh);
    verifyMultiplicity(*_endElement, 1, Multiplicity::UNBOUNDED);

    valueCh = xercesc::XMLString::transcode("4..*");
    _endElement->setAttribute(nameCh, valueCh);
    verifyMultiplicity(*_endElement, 4, Multiplicity::UNBOUNDED);

    valueCh = xercesc::XMLString::transcode("245..*");
    _endElement->setAttribute(nameCh, valueCh);
    verifyMultiplicity(*_endElement, 245, Multiplicity::UNBOUNDED);

    valueCh = xercesc::XMLString::transcode("-1..*");
    _endElement->setAttribute(nameCh, valueCh);
    verifyMultiplicityFailure(*_endElement);

    valueCh = xercesc::XMLString::transcode("-23..*");
    _endElement->setAttribute(nameCh, valueCh);
    verifyMultiplicityFailure(*_endElement);
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testMiscellaneousInvalidValues()
  {
    XMLCh* nameCh = xercesc::XMLString::transcode("multiplicity");

    XMLCh* valueCh = xercesc::XMLString::transcode("1da2");
    _endElement->setAttribute(nameCh, valueCh);
    verifyMultiplicityFailure(*_endElement);

    valueCh = xercesc::XMLString::transcode("*..0");
    _endElement->setAttribute(nameCh, valueCh);
    verifyMultiplicityFailure(*_endElement);
    
    valueCh = xercesc::XMLString::transcode("*..1");
    _endElement->setAttribute(nameCh, valueCh);
    verifyMultiplicityFailure(*_endElement);

    valueCh = xercesc::XMLString::transcode("*..232");
    _endElement->setAttribute(nameCh, valueCh);
    verifyMultiplicityFailure(*_endElement);

    valueCh = xercesc::XMLString::transcode("*..232sf");
    _endElement->setAttribute(nameCh, valueCh);
    verifyMultiplicityFailure(*_endElement);

    valueCh = xercesc::XMLString::transcode("a*..232sf");
    _endElement->setAttribute(nameCh, valueCh);
    verifyMultiplicityFailure(*_endElement);

    valueCh = xercesc::XMLString::transcode("*af..232");
    _endElement->setAttribute(nameCh, valueCh);
    verifyMultiplicityFailure(*_endElement);

    valueCh = xercesc::XMLString::transcode("1da2..*");
    _endElement->setAttribute(nameCh, valueCh);
    verifyMultiplicityFailure(*_endElement);
  }

  /**
   * TODO: Documentation
   *
   */
  void testXdr()
  {
    XMLCh* nameCh = xercesc::XMLString::transcode("multiplicity");
    XMLCh* valueCh = xercesc::XMLString::transcode("0..*");
    _endElement->setAttribute(nameCh, valueCh);

    Multiplicity* multiplicity;
    try {
      multiplicity = new Multiplicity(*_endElement);
    } catch (ontology::Exception ex) {
      fail("Unable to create Multiplicity instance");
    }

    iostream::XdrOutputStream ostream("testfile");
    multiplicity->encode(ostream);
    ostream.close();

    iostream::XdrInputStream istream("testfile");
    Multiplicity decodedMultiplicity(istream);
    istream.close();

    remove("testfile");

    assertTrue(decodedMultiplicity.getLowerBound() == 0);
    assertTrue(decodedMultiplicity.getUpperBound() == Multiplicity::UNBOUNDED);
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void tearDown()
  {
    XMLRelatedTest::tearDown();
  }


  /**
   * TODO: Documentation
   * <p>
   */
  void verifyMultiplicity(xercesc::DOMElement& element,
			  int expectedLower,
			  int expectedUpper)
  {
    Multiplicity* multi;
    try {
      multi = new Multiplicity(element);
    } catch (ontology::Exception ex) {
      fail("Unable to create Multiplicity instance");
    }
    assertTrue(multi->getLowerBound() == expectedLower);
    assertTrue(multi->getUpperBound() == expectedUpper);
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void verifyMultiplicityFailure(xercesc::DOMElement& element)
  {
    try {
      Multiplicity* multi = new Multiplicity(element);
      fail("Multiplicity should not construct.");
    } catch (ontology::Exception ex) {
      assertTrue(true);
    }
  }

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  MultiplicityTest(const MultiplicityTest& multiplicityTest);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  MultiplicityTest& operator=(const MultiplicityTest& multiplicityTest);

};


}


}


#endif // PROTOLAYER_ONTOLOGY_MULTIPLICITYTEST_H
