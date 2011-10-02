#ifndef PROTOLAYER_ASSEMBLY_INSTANCETEST_HPP
#define PROTOLAYER_ASSEMBLY_INSTANCETEST_HPP

#include <map>
#include <string>

#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLChar.hpp>
#include <xercesc/util/XMLString.hpp>

#include <protolayer/protolayer-containerservice.h>
#include <protolayer/protolayer-ontology.h>
#include <protolayer/protolayer-util.h>
#include <protolayer/protolayer-xml.h>

#include <protolayer/protolayer-nameservice.h>

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

      /*
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
      */
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
      ConceptInstance instance(*type);

      //      protolayer::nameservice::Client nameClient(77000);
      //      std::string location = nameClient.nextLocation("urn:protolayer:tech1");

      protolayer::nameservice::Client _nameClient(80001);
      std::string location = _nameClient.nextLocation("urn:protolayer:tech1");

      protolayer::containerservice::Client _containerClient(50000);
      _containerClient.populate(location, instance);
      _containerClient.validate(location, instance);
      _containerClient.evaluate(location, instance);

    } catch (nameservice::Exception ex) {
      std::cout << "nameservice::Exception" << std::endl;
      std::cout << ex.getMessage() << std::endl;
      //      fail("containerservice::Exception failed also");

    } catch (containerservice::Exception ex) {
      std::cout << "containerservice::Exception" << std::endl;
      std::cout << ex.getMessage() << std::endl;
      //      fail("containerservice::Exception failed also");

    } catch (Exception ex) {
      //      fail("Incorrectly failed to construct from instantiable type.");

    } catch (net::Exception ex) {
      std::cout << ex.getMessage() << std::endl;

    } catch (iostream::Exception ex) {
      std::cout << "iostream::Exception" << std::endl;
      std::cout << ex.getMessage() << std::endl;

    } catch (...) {
      std::cout << "All other exceptions" << std::endl;
    }


    /*    try {
      ConceptInstance instance(*type);

      protolayer::nameservice::Client _nameClient(80001);
      std::string location = _nameClient.nextLocation("urn:protolayer:tech12");

      protolayer::containerservice::Client _containerClient(50000);
      //      _containerClient.populate(location, instance);
      //      _containerClient.validate(location, instance);
      //      _containerClient.evaluate(location, instance);

    } catch (containerservice::Exception ex) {
//      fail("containerservice::Exception failed also");
    } catch (Exception ex) {
//      fail("Incorrectly failed to construct from instantiable type.");
    }
    */
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testConstructionFromAbstractType()
  {
    XMLCh* nameCh = xercesc::XMLString::transcode("isAbstract");
    XMLCh* valueCh = xercesc::XMLString::transcode("true");
    _typeElement->setAttribute(nameCh, valueCh);

    ontologydto::TypeDTO* typeDTO = new ontologydto::TypeDTO(*_typeElement);
    ontology::Type* type = new ontology::Type(*typeDTO);

    bool result = true;
    try {
      ConceptInstance instance(*type);
      result = false;
    } catch (Exception ex) {
      assertTrue("Successful failure to construct instance from abstract type.");
    }

    if (!result) {
      //fail("Incorrectly succeeded at constructing instance from abstract type.");
    }
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testGetType()
  {
    ontologydto::TypeDTO* typeDTO = new ontologydto::TypeDTO(*_typeElement);
    ontology::Type* type = new ontology::Type(*typeDTO);

    ConceptInstance instance(*type);
    assertTrue(&(instance.getType()) == type);
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testName()
  {
    ontologydto::TypeDTO* typeDTO = new ontologydto::TypeDTO(*_typeElement);
    ontology::Type* type = new ontology::Type(*typeDTO);

    ConceptInstance* instance = new ConceptInstance(*type);
    assertTrue(instance->getName() == "");

    std::string name("New name.");
    instance->setName(name);
    assertTrue(instance->getName() == "New name.");
    instance->setName("Another name.");
    assertTrue(instance->getName() != "New name.");
    assertTrue(instance->getName() == "Another name.");

    delete instance;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testXdr()
  {
    ontologydto::TypeDTO* typeDTO = new ontologydto::TypeDTO(*_typeElement);
    ontology::Type type(*typeDTO);

    typeDTO = new ontologydto::TypeDTO(*_typeElement);
    ontology::Type otherType(*typeDTO);

    ConceptInstance instance(type);

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
    ConceptInstance decodedInst(istream, addressMappings);
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
