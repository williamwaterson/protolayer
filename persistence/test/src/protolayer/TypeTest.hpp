#ifndef PROTOLAYER_ONTOLOGY_TYPETEST_HPP
#define PROTOLAYER_ONTOLOGY_TYPETEST_HPP

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

class TypeTest : public XMLRelatedTest
{
private:
  /** TODO: Documentation */
  xercesc::DOMElement* _typeElement;

public:
  /**
   * TODO: Documentation
   *
   */
  TypeTest()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
  ~TypeTest()
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
      testCompletedAttributesCase1();
      tearDown();

      setUp();
      testCompletedAttributesCase2();
      tearDown();

      setUp();
      testCompletedAttributesCase3();
      tearDown();

      setUp();
      testCompletedAttributesCase4();
      tearDown();

      setUp();
      testCompletedAttributesCase5();
      tearDown();

      setUp();
      testCompletedAttributesCase6();
      tearDown();

      setUp();
      testCompletedAttributesCase7();
      tearDown();

      setUp();
      testCompletedAttributesCase8();
      tearDown();

      setUp();
      testMissingNameAttribute();
      tearDown();

      setUp();
      testMissingSingletonAttribute();
      tearDown();

      setUp();      
      testMissingAbstractAttribute();
      tearDown();

      setUp();
      testMissingLeafAttribute();
      tearDown();

      setUp();
      testMissingAllOptionalAttributes();
      tearDown();

      setUp();
      testXdrCaseA();
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
    _typeElement = getDOMDocument().createElement(str);
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
  void testCompletedAttributesCase1()
  {
    XMLCh* nameCh = xercesc::XMLString::transcode("name");
    XMLCh* valueCh = xercesc::XMLString::transcode("Atom");
    _typeElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("isAbstract");
    valueCh = xercesc::XMLString::transcode("false");
    _typeElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("isSingleton");
    valueCh = xercesc::XMLString::transcode("false");
    _typeElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("isLeaf");
    valueCh = xercesc::XMLString::transcode("false");
    _typeElement->setAttribute(nameCh, valueCh);

    TypeDTO* type = new TypeDTO(*_typeElement);
    assertTrue(type->getName() == "Atom");
    assertFalse(type->isAbstract());
    assertFalse(type->isSingleton());
    assertFalse(type->isLeaf());
    delete type;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testCompletedAttributesCase2()
  {
    XMLCh* nameCh = xercesc::XMLString::transcode("name");
    XMLCh* valueCh = xercesc::XMLString::transcode("Atom");
    _typeElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("isAbstract");
    valueCh = xercesc::XMLString::transcode("true");
    _typeElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("isSingleton");
    valueCh = xercesc::XMLString::transcode("false");
    _typeElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("isLeaf");
    valueCh = xercesc::XMLString::transcode("false");
    _typeElement->setAttribute(nameCh, valueCh);

    TypeDTO* type = new TypeDTO(*_typeElement);
    assertTrue(type->getName() == "Atom");
    assertTrue(type->isAbstract());
    assertFalse(type->isSingleton());
    assertFalse(type->isLeaf());
    delete type;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testCompletedAttributesCase3()
  {
    XMLCh* nameCh = xercesc::XMLString::transcode("name");
    XMLCh* valueCh = xercesc::XMLString::transcode("Atom");
    _typeElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("isAbstract");
    valueCh = xercesc::XMLString::transcode("false");
    _typeElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("isSingleton");
    valueCh = xercesc::XMLString::transcode("true");
    _typeElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("isLeaf");
    valueCh = xercesc::XMLString::transcode("false");
    _typeElement->setAttribute(nameCh, valueCh);

    TypeDTO* type = new TypeDTO(*_typeElement);
    assertTrue(type->getName() == "Atom");
    assertFalse(type->isAbstract());
    assertTrue(type->isSingleton());
    assertFalse(type->isLeaf());
    delete type;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testCompletedAttributesCase4()
  {
    XMLCh* nameCh = xercesc::XMLString::transcode("name");
    XMLCh* valueCh = xercesc::XMLString::transcode("Atom");
    _typeElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("isAbstract");
    valueCh = xercesc::XMLString::transcode("false");
    _typeElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("isSingleton");
    valueCh = xercesc::XMLString::transcode("false");
    _typeElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("isLeaf");
    valueCh = xercesc::XMLString::transcode("true");
    _typeElement->setAttribute(nameCh, valueCh);

    TypeDTO* type = new TypeDTO(*_typeElement);
    assertTrue(type->getName() == "Atom");
    assertFalse(type->isAbstract());
    assertFalse(type->isSingleton());
    assertTrue(type->isLeaf());
    delete type;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testCompletedAttributesCase5()
  {
    XMLCh* nameCh = xercesc::XMLString::transcode("name");
    XMLCh* valueCh = xercesc::XMLString::transcode("Atom");
    _typeElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("isAbstract");
    valueCh = xercesc::XMLString::transcode("true");
    _typeElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("isSingleton");
    valueCh = xercesc::XMLString::transcode("true");
    _typeElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("isLeaf");
    valueCh = xercesc::XMLString::transcode("false");
    _typeElement->setAttribute(nameCh, valueCh);

    TypeDTO* type = new TypeDTO(*_typeElement);
    assertTrue(type->getName() == "Atom");
    assertTrue(type->isAbstract());
    assertTrue(type->isSingleton());
    assertFalse(type->isLeaf());
    delete type;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testCompletedAttributesCase6()
  {
    XMLCh* nameCh = xercesc::XMLString::transcode("name");
    XMLCh* valueCh = xercesc::XMLString::transcode("Atom");
    _typeElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("isAbstract");
    valueCh = xercesc::XMLString::transcode("true");
    _typeElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("isSingleton");
    valueCh = xercesc::XMLString::transcode("false");
    _typeElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("isLeaf");
    valueCh = xercesc::XMLString::transcode("true");
    _typeElement->setAttribute(nameCh, valueCh);

    TypeDTO* type = new TypeDTO(*_typeElement);
    assertTrue(type->getName() == "Atom");
    assertTrue(type->isAbstract());
    assertFalse(type->isSingleton());
    assertTrue(type->isLeaf());
    delete type;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testCompletedAttributesCase7()
  {
    XMLCh* nameCh = xercesc::XMLString::transcode("name");
    XMLCh* valueCh = xercesc::XMLString::transcode("Atom");
    _typeElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("isAbstract");
    valueCh = xercesc::XMLString::transcode("false");
    _typeElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("isSingleton");
    valueCh = xercesc::XMLString::transcode("true");
    _typeElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("isLeaf");
    valueCh = xercesc::XMLString::transcode("true");
    _typeElement->setAttribute(nameCh, valueCh);

    TypeDTO* type = new TypeDTO(*_typeElement);
    assertTrue(type->getName() == "Atom");
    assertFalse(type->isAbstract());
    assertTrue(type->isSingleton());
    assertTrue(type->isLeaf());
    delete type;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testCompletedAttributesCase8()
  {
    XMLCh* nameCh = xercesc::XMLString::transcode("name");
    XMLCh* valueCh = xercesc::XMLString::transcode("Atom");
    _typeElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("isAbstract");
    valueCh = xercesc::XMLString::transcode("true");
    _typeElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("isSingleton");
    valueCh = xercesc::XMLString::transcode("true");
    _typeElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("isLeaf");
    valueCh = xercesc::XMLString::transcode("true");
    _typeElement->setAttribute(nameCh, valueCh);

    TypeDTO* type = new TypeDTO(*_typeElement);
    assertTrue(type->getName() == "Atom");
    assertTrue(type->isAbstract());
    assertTrue(type->isSingleton());
    assertTrue(type->isLeaf());
    delete type;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testMissingNameAttribute()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testMissingAbstractAttribute()
  {
    XMLCh* nameCh = xercesc::XMLString::transcode("name");
    XMLCh* valueCh = xercesc::XMLString::transcode("Atom");
    _typeElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("isSingleton");
    valueCh = xercesc::XMLString::transcode("true");
    _typeElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("isLeaf");
    valueCh = xercesc::XMLString::transcode("true");
    _typeElement->setAttribute(nameCh, valueCh);

    TypeDTO* type = new TypeDTO(*_typeElement);
    assertTrue(type->getName() == "Atom");
    assertFalse(type->isAbstract());
    assertTrue(type->isSingleton());
    assertTrue(type->isLeaf());
    delete type;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testMissingSingletonAttribute()
  {
    XMLCh* nameCh = xercesc::XMLString::transcode("name");
    XMLCh* valueCh = xercesc::XMLString::transcode("Atom");
    _typeElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("isAbstract");
    valueCh = xercesc::XMLString::transcode("true");
    _typeElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("isLeaf");
    valueCh = xercesc::XMLString::transcode("true");
    _typeElement->setAttribute(nameCh, valueCh);

    TypeDTO* type = new TypeDTO(*_typeElement);
    assertTrue(type->getName() == "Atom");
    assertTrue(type->isAbstract());
    assertFalse(type->isSingleton());
    assertTrue(type->isLeaf());
    delete type;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testMissingLeafAttribute()
  {
    XMLCh* nameCh = xercesc::XMLString::transcode("name");
    XMLCh* valueCh = xercesc::XMLString::transcode("Atom");
    _typeElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("isAbstract");
    valueCh = xercesc::XMLString::transcode("true");
    _typeElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("isSingleton");
    valueCh = xercesc::XMLString::transcode("true");
    _typeElement->setAttribute(nameCh, valueCh);

    TypeDTO* type = new TypeDTO(*_typeElement);
    assertTrue(type->getName() == "Atom");
    assertTrue(type->isAbstract());
    assertTrue(type->isSingleton());
    assertFalse(type->isLeaf());
    delete type;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testMissingAllOptionalAttributes()
  {
    XMLCh* nameCh = xercesc::XMLString::transcode("name");
    XMLCh* valueCh = xercesc::XMLString::transcode("Atom");
    _typeElement->setAttribute(nameCh, valueCh);

    TypeDTO* type = new TypeDTO(*_typeElement);
    assertTrue(type->getName() == "Atom");
    assertFalse(type->isAbstract());
    assertFalse(type->isSingleton());
    assertFalse(type->isLeaf());
    delete type;
  }

  /**
   * TODO: Documentation
   *
   */
  void testXdrCaseA()
  {
    XMLCh* nameCh = xercesc::XMLString::transcode("name");
    XMLCh* valueCh = xercesc::XMLString::transcode("Atom");
    _typeElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("isAbstract");
    valueCh = xercesc::XMLString::transcode("false");
    _typeElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("isSingleton");
    valueCh = xercesc::XMLString::transcode("false");
    _typeElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("isLeaf");
    valueCh = xercesc::XMLString::transcode("false");
    _typeElement->setAttribute(nameCh, valueCh);

    TypeDTO encodingType(*_typeElement);

    iostream::XdrOutputStream ostream("testfile");
    encodingType.encode(ostream);
    ostream.close();

    iostream::XdrInputStream istream("testfile");
    TypeDTO decodingType(istream);
    istream.close();

    remove("testfile");

    assertTrue(decodingType.getName() == "Atom");
    assertFalse(decodingType.isAbstract());
    assertFalse(decodingType.isSingleton());
    assertFalse(decodingType.isLeaf());
  }

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  TypeTest(const TypeTest& typeTest);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  TypeTest& operator=(const TypeTest& typeTest);

};


}


}


#endif // PROTOLAYER_ONTOLOGY_TYPETEST_H
