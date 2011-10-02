#ifndef PROTOLAYER_ASSEMBLY_LAYERTEST_HPP
#define PROTOLAYER_ASSEMBLY_LAYERTEST_HPP

#include <iostream.h> 
#include <set>
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

class LayerTest : public XMLRelatedTest
{
private:
  /** TODO: Documentation */
  ontology::TypeLayer* _typeLayer;

  /** TODO: Documentation */
  std::set <ontology::Type*> _types;

  /** TODO: Documentation */
  ontology::Type* _moleculeType;

  /** TODO: Documentation */
  ontology::Type* _atomType;

  /** TODO: Documentation */
  ontology::Type* _bondType;

  /** TODO: Documentation */
  ontology::Type* _nonLayerType;

public:
  /**
   * TODO: Documentation
   *
   */
  LayerTest()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
 ~LayerTest()
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
      testGetTypeLayer();
      tearDown();

      setUp();
      testInstanceCreationDeletion();
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
    ontologydto::TypeDTO* typeDTO = new ontologydto::TypeDTO(*typeElement);
    _bondType = new ontology::Type(*typeDTO);
    _types.insert(_bondType);

    valueCh = xercesc::XMLString::transcode("Atom");
    typeElement->setAttribute(nameCh, valueCh);
    typeDTO = new ontologydto::TypeDTO(*typeElement);
    _atomType = new ontology::Type(*typeDTO);
    _types.insert(_atomType);

    valueCh = xercesc::XMLString::transcode("Molecule");
    typeElement->setAttribute(nameCh, valueCh);
    typeDTO = new ontologydto::TypeDTO(*typeElement);
    _moleculeType = new ontology::Type(*typeDTO);
    _types.insert(_moleculeType);

    _typeLayer = new ontology::TypeLayer(_types);

    valueCh = xercesc::XMLString::transcode("Reaction");
    typeElement->setAttribute(nameCh, valueCh);
    typeDTO = new ontologydto::TypeDTO(*typeElement);
    _nonLayerType = new ontology::Type(*typeDTO);
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testConstruction()
  {
    try {
      Layer* layer = new Layer(*_typeLayer);
      delete layer;
      assertTrue("Successfully constructed Layer instance.");
    } catch (Exception ex) {
      fail("Incorrectly failed to construct the Layer instance.");
    }
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testGetTypeLayer()
  {
    Layer* layer = new Layer(*_typeLayer);
    assertTrue(&(layer->getTypeLayer()) == _typeLayer);
    delete layer;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testInstanceCreationDeletion()
  {
    Layer* layer = new Layer(*_typeLayer);
    Instance* nonLayerInstance = new Instance(*_nonLayerType);

    assertTrue(layer->getNumberInstances() == 0);
    Instance* atomInstance = 0;
    try {
      atomInstance = new Instance(*_atomType);
      layer->add(*atomInstance);
      assertTrue("Successfully created instance from layer type.");
    } catch (Exception ex) {
      fail("Incorrectly failed to construct instance from layer type");
    }    

    assertTrue(layer->getNumberInstances() == 1);
    Instance* bondInstance = 0;
    try {
      bondInstance = new Instance(*_bondType);
      layer->add(*bondInstance);
      assertTrue("Successfully created instance from layer type.");
    } catch (Exception ex) {
      fail("Incorrectly failed to construct instance from layer type");
    }    

    assertTrue(layer->getNumberInstances() == 2);
    Instance* moleculeInstance = 0;
    try {
      moleculeInstance = new Instance(*_moleculeType);
      layer->add(*moleculeInstance);

      assertTrue("Successfully created instance from layer type.");
    } catch (Exception ex) {
      fail("Incorrectly failed to construct instance from layer type");
    }    

    assertTrue(layer->getNumberInstances() == 3);
    bool failed = false;
    try {
      Instance* instance = new Instance(*_nonLayerType);
      layer->add(*instance);
      failed = true;
    } catch (Exception ex) {
    }

    assertTrue(layer->getNumberInstances() == 3);
    if (failed) {
      fail("Incorrectly created Instance from nprotoer Type.");
    } else {
      assertTrue("Successfully failed to construct Instance from nprotoer Type.");
    }

    assertTrue(layer->contains(*atomInstance));
    assertTrue(layer->contains(*bondInstance));
    assertTrue(layer->contains(*moleculeInstance));
    assertFalse(layer->contains(*nonLayerInstance));

    std::set <Instance*> comparing;
    comparing.insert(atomInstance);
    comparing.insert(bondInstance);
    comparing.insert(moleculeInstance);
    Layer::IteratorType iter;
    for (iter = layer->getInstances(); iter.hasNext(); ) {
      Instance& instance = iter.next();
      assertTrue(comparing.find(&instance) != comparing.end());
      comparing.erase(&instance);      
    }
    assertTrue(comparing.size() == 0);

    try {
      layer->remove(*atomInstance);
      delete atomInstance;
    } catch (Exception ex) {
      fail("Incorrectly failed to remove member instance from layer.");
    }
    assertTrue(layer->getNumberInstances() == 2);

    try {
      layer->remove(*bondInstance);
      delete bondInstance;
    } catch (Exception ex) {
      fail("Incorrectly failed to remove member instance from layer.");
    }
    assertTrue(layer->getNumberInstances() == 1);

    failed = false;
    try {
      layer->remove(*nonLayerInstance);
      delete nonLayerInstance;
      failed = true;
    } catch (Exception ex) {
      assertTrue("Correctly failed to delete non-member instance from layer.");
    }

    if (failed) {
      fail("Incorrectly executed deleteInstance on non-member Instance without throwing exception.");
    }

    assertTrue(layer->getNumberInstances() == 1);

    try {
      layer->remove(*moleculeInstance);
      delete moleculeInstance;
    } catch (Exception ex) {
      fail("Incorrectly failed to remove member instance from layer.");
    }
    assertTrue(layer->getNumberInstances() == 0);

    delete layer;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testXdr()
  {
    Layer layer(*_typeLayer);
    Instance* nonLayerInstance = new Instance(*_nonLayerType);

    Instance* atomInstance = new Instance(*_atomType);
    layer.add(*atomInstance);

    Instance* bondInstance = new Instance(*_bondType);
    layer.add(*bondInstance);

    Instance* moleculeInstance = new Instance(*_moleculeType);
    layer.add(*moleculeInstance);

    iostream::XdrOutputStream ostream("testfile");
    layer.encode(ostream);
    ostream.close();

    std::map <int, void*> addressMappings;
    addressMappings[(int) _typeLayer] = static_cast <void*> (_typeLayer);
    addressMappings[(int) atomInstance] = static_cast <void*> (atomInstance);
    addressMappings[(int) bondInstance] = static_cast <void*> (bondInstance);
    addressMappings[(int) moleculeInstance] = static_cast <void*> (moleculeInstance);
    addressMappings[(int) nonLayerInstance] = static_cast <void*> (nonLayerInstance);

    addressMappings[(int) _atomType] = static_cast <void*> (_atomType);
    addressMappings[(int) _bondType] = static_cast <void*> (_bondType);
    addressMappings[(int) _moleculeType] = static_cast <void*> (_moleculeType);
    addressMappings[(int) _nonLayerType] = static_cast <void*> (_nonLayerType);

    iostream::XdrInputStream istream("testfile");
    Layer decodedLayer(istream, addressMappings);
    istream.close();
    
    remove("testfile");

    assertTrue(decodedLayer.getNumberInstances() == 3);
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void tearDown()
  {
    delete _typeLayer;
    delete _atomType;
    delete _bondType;
    delete _moleculeType;
    delete _nonLayerType;

    XMLRelatedTest::tearDown();
  }

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  LayerTest(const LayerTest& layerTest);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  LayerTest& operator=(const LayerTest& layerTest);

};


}


}


#endif // PROTOLAYER_ASSEMBLY_LAYERTEST_H
