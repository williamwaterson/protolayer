#ifndef PROTOLAYER_TEST_XMLRELATEDTEST_HPP
#define PROTOLAYER_TEST_XMLRELATEDTEST_HPP

#include <map>
#include <string>
#include <iostream.h>

#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLChar.hpp>
#include <xercesc/util/XMLString.hpp>

#include <protolayer/protolayer-util.h>
#include <protolayer/protolayer-xml.h>

namespace protolayer
{

class XMLRelatedTest
{
private:
  /** TODO: Documentation */
  xercesc::DOMImplementation* _implementation;

  /** TODO: Documentation */
  xercesc::DOMDocument* _document;

public:
  /**
   * TODO: Documentation
   *
   */
  XMLRelatedTest()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
 ~XMLRelatedTest()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
  xercesc::DOMDocument& getDOMDocument()
  {
    return *_document;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  xercesc::DOMImplementation& getDOMImplementation()
  {
    return *_implementation;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void testSuite()
  {
    setUp();

    

    tearDown();
  }

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void setUp()
  {
    try {
      xercesc::XMLPlatformUtils::Initialize();
    } catch (const xercesc::XMLException& toCatch) {
      throw; // XMLTestException("Failed initialisation");
    }

    XMLCh* str = xercesc::XMLString::transcode("Range");
    _implementation =
      xercesc::DOMImplementationRegistry::getDOMImplementation(str);

    str = xercesc::XMLString::transcode("root");
    _document = _implementation->createDocument(0, str, 0);
  }

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void tearDown() {
    xercesc::XMLPlatformUtils::Terminate();
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void assertTrue(char* message, bool testResult) {
    if (!testResult) {
      throw ontologydto::Exception(message);
    }
    std::cout << "Success" << std::endl;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void assertTrue(bool testResult) {
    if (!testResult) {
      throw ontologydto::Exception("Generic Failure");
    }
    std::cout << "Success" << std::endl;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void assertFalse(char* message, bool testResult)  {
    if (testResult) {
      throw ontologydto::Exception(message);
    }
    std::cout << "Success" << std::endl;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void fail(char* message)  {
    throw ontologydto::Exception(message);
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void assertFalse(bool testResult) {
    if (testResult) {
      throw ontologydto::Exception("Generic Failure");
    }
    std::cout << "Success" << std::endl;
  }

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  XMLRelatedTest(const XMLRelatedTest& test);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  XMLRelatedTest& operator=(const XMLRelatedTest& test);

};


}


#endif // PROTOLAYER_ONTOLOGY_XMLRELATEDTEST_H
