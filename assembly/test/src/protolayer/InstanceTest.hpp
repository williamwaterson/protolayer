#ifndef PROTOLAYER_ASSEMBLY_INSTANCETEST_HPP
#define PROTOLAYER_ASSEMBLY_INSTANCETEST_HPP

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

class InstanceTest : public XMLRelatedTest
{
private:
  /** TODO: Documentation */
  std::string _scope;

  /** TODO: Documentation */
  xercesc::DOMElement* _typeElement;

public:
  /**
   * TODO: Documentation
   *
   */
  InstanceTest()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
 ~InstanceTest()
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
      testConstructionFromAbstractType();
      tearDown();

      setUp();
      testGetType();
      tearDown();

      setUp();
      testName();
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

    XMLCh* str = xercesc::XMLString::transcode("type");
    _typeElement = getDOMDocument().createElement(str);

    XMLCh* nameCh = xercesc::XMLString::transcode("name");
    XMLCh* valueCh = xercesc::XMLString::transcode("Atom");
    _typeElement->setAttribute(nameCh, valueCh);

    _scope = "Chemistry";
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testConstruction()
  {
    ontologydto::TypeDTO* typeDTO = new ontologydto::TypeDTO(*_typeElement);
    ontology::Type* type = new ontology::Type(*typeDTO);
    try {
      Instance instance(*type);
      assertTrue("Successful construction from instantiable type.");
    } catch (Exception ex) {
      fail("Incorrectly failed to construct from instantiable type.");
    }
  }

  void testConstructionFromAbstractType()
  {
    XMLCh* nameCh = xercesc::XMLString::transcode("isAbstract");
    XMLCh* valueCh = xercesc::XMLString::transcode("true");
    _typeElement->setAttribute(nameCh, valueCh);

    ontologydto::TypeDTO* typeDTO = new ontologydto::TypeDTO(*_typeElement);
    ontology::Type* type = new ontology::Type(*typeDTO);

    bool result = true;
    try {
      Instance instance(*type);
      result = false;
    } catch (Exception ex) {
      assertTrue("Successful failure to construct instance from abstract type.");
    }

    if (!result) {
      fail("Incorrectly succeeded at constructing instance from abstract type.");
    }
  }

  void testGetType()
  {
    ontologydto::TypeDTO* typeDTO = new ontologydto::TypeDTO(*_typeElement);
    ontology::Type* type = new ontology::Type(*typeDTO);

    Instance instance(*type);
    assertTrue(&(instance.getType()) == type);
  }

  void testName()
  {
    ontologydto::TypeDTO* typeDTO = new ontologydto::TypeDTO(*_typeElement);
    ontology::Type* type = new ontology::Type(*typeDTO);
    Instance* instance = new Instance(*type);
    assertTrue(instance->getName() == "");

    std::string name("New name.");
    instance->setName(name);
    assertTrue(instance->getName() == "New name.");
    instance->setName("Another name.");
    assertTrue(instance->getName() != "New name.");
    assertTrue(instance->getName() == "Another name.");

    delete instance;
  }

  void testXdr()
  {
    ontologydto::TypeDTO* typeDTO = new ontologydto::TypeDTO(*_typeElement);
    ontology::Type type(*typeDTO);

    ontologydto::TypeDTO* otherTypeDTO = new ontologydto::TypeDTO(*_typeElement);
    ontology::Type otherType(*otherTypeDTO);

    Instance instance(type);

    std::string name("Instance name.");
    std::string otherName("other Instance name.");
    instance.setName(name);

    iostream::XdrOutputStream ostream("testfile");
    instance.encode(ostream);
    ostream.close();

    std::map <int, void*> addressMappings;
    addressMappings[(int) &type] = static_cast <void*> (&type);
    addressMappings[(int) &otherType] = static_cast <void*> (&otherType);

    iostream::XdrInputStream istream("testfile");
    Instance decodedInst(istream, addressMappings);
    istream.close();

    remove("testfile");

    assertTrue(decodedInst.getName() == name);
    assertFalse(decodedInst.getName() == otherName);
    assertTrue(&(decodedInst.getType()) == &type);
    assertFalse(&(decodedInst.getType()) == &otherType);
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
  InstanceTest(const InstanceTest& instanceTest);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  InstanceTest& operator=(const InstanceTest& instanceTest);

};


}


}


#endif // PROTOLAYER_ASSEMBLY_INSTANCETEST_H
