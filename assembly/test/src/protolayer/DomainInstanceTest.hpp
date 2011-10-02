#ifndef PROTOLAYER_ASSEMBLY_DOMAININSTANCETEST_HPP
#define PROTOLAYER_ASSEMBLY_DOMAININSTANCETEST_HPP

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

class DomainInstanceTest : public XMLRelatedTest
{
private:
  /** TODO: Documentation */
  ontology::Ontology* _ontology;

  /** TODO: Documentation */
  ontology::Domain* _domain;

  /** TODO: Documentation */
  std::set <ontologydto::DomainDTO*> _domainDTOs;

public:
  /**
   * TODO: Documentation
   *
   */
  DomainInstanceTest()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
 ~DomainInstanceTest()
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
      testInstances();
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

    xercesc::DOMDocument* ontologyDocument = &(getDOMDocument());    

    XMLCh* str = xercesc::XMLString::transcode("domain");
    xercesc::DOMElement* chemistryDomainElement =
      getDOMDocument().createElement(str);
    XMLCh* nameCh = xercesc::XMLString::transcode("name");
    XMLCh* valueCh = xercesc::XMLString::transcode("Chemistry");
    chemistryDomainElement->setAttribute(nameCh, valueCh);

    xercesc::DOMElement* spatialDomainElement =
      getDOMDocument().createElement(str);
    valueCh = xercesc::XMLString::transcode("Spatial");
    spatialDomainElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("type");

    xercesc::DOMElement* typeElement = getDOMDocument().createElement(str);
    valueCh = xercesc::XMLString::transcode("Molecule");
    typeElement->setAttribute(nameCh, valueCh);
    chemistryDomainElement->appendChild(typeElement);

    typeElement = getDOMDocument().createElement(str);
    valueCh = xercesc::XMLString::transcode("Atom");
    typeElement->setAttribute(nameCh, valueCh);
    chemistryDomainElement->appendChild(typeElement);    

    typeElement = getDOMDocument().createElement(str);
    valueCh = xercesc::XMLString::transcode("Bond");
    typeElement->setAttribute(nameCh, valueCh);
    chemistryDomainElement->appendChild(typeElement);

    typeElement = getDOMDocument().createElement(str);
    valueCh = xercesc::XMLString::transcode("Vertex");
    typeElement->setAttribute(nameCh, valueCh);
    spatialDomainElement->appendChild(typeElement);    

    typeElement = getDOMDocument().createElement(str);
    valueCh = xercesc::XMLString::transcode("Edge");
    typeElement->setAttribute(nameCh, valueCh);
    spatialDomainElement->appendChild(typeElement);

    typeElement = getDOMDocument().createElement(str);
    valueCh = xercesc::XMLString::transcode("Face");
    typeElement->setAttribute(nameCh, valueCh);
    spatialDomainElement->appendChild(typeElement);    

    typeElement = getDOMDocument().createElement(str);
    valueCh = xercesc::XMLString::transcode("Region");
    typeElement->setAttribute(nameCh, valueCh);
    spatialDomainElement->appendChild(typeElement);    


    str = xercesc::XMLString::transcode("ontology");
    xercesc::DOMElement* ontologyElement = getDOMDocument().createElement(str);    
    ontologyDocument->getDocumentElement()->appendChild(ontologyElement);


    str = xercesc::XMLString::transcode("from");
    xercesc::DOMElement* fromElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Molecule");
    fromElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("1");
    fromElement->setAttribute(nameCh, valueCh);


    str = xercesc::XMLString::transcode("to");
    xercesc::DOMElement* toElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Bond");
    toElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("0..*");
    toElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("association");
    xercesc::DOMElement* assocElement = getDOMDocument().createElement(str);
    assocElement->appendChild(fromElement);
    assocElement->appendChild(toElement);

    chemistryDomainElement->appendChild(assocElement);


    str = xercesc::XMLString::transcode("from");
    fromElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Bond");
    fromElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("0..*");
    fromElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("to");
    toElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Atom");
    toElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("2");
    toElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("association");
    assocElement = getDOMDocument().createElement(str);
    assocElement->appendChild(fromElement);
    assocElement->appendChild(toElement);

    chemistryDomainElement->appendChild(assocElement);


    str = xercesc::XMLString::transcode("from");
    fromElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Molecule");
    fromElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("1");
    fromElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("to");
    toElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Atom");
    toElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("1..*");
    toElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("association");
    assocElement = getDOMDocument().createElement(str);
    assocElement->appendChild(fromElement);
    assocElement->appendChild(toElement);

    chemistryDomainElement->appendChild(assocElement);


    str = xercesc::XMLString::transcode("from");
    fromElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Molecule");
    fromElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("1");
    fromElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("to");
    toElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Vertex");
    toElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("1..*");
    toElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("association");
    assocElement = getDOMDocument().createElement(str);
    assocElement->appendChild(fromElement);
    assocElement->appendChild(toElement);

    chemistryDomainElement->appendChild(assocElement);


    str = xercesc::XMLString::transcode("from");
    fromElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Edge");
    fromElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("0..*");
    fromElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("to");
    toElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Vertex");
    toElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("2");
    toElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("association");
    assocElement = getDOMDocument().createElement(str);
    assocElement->appendChild(fromElement);
    assocElement->appendChild(toElement);

    spatialDomainElement->appendChild(assocElement);


    ontologyElement->appendChild(chemistryDomainElement);
    ontologydto::DomainDTO* domainDTO = new ontologydto::DomainDTO(*ontologyDocument);
    domainDTO->getId() = 1;
    domainDTO->getTitle() = "Chemistry";
    _domainDTOs.insert(domainDTO);

    typedef std::set <ontologydto::TypeDTO*>::iterator IterType;
    for (IterType iter = domainDTO->getTypes().begin(); iter != domainDTO->getTypes().end(); iter++) {
      if ((*iter)->getName() == "Molecule") {
	(*iter)->getId() = 1;
      } else if ((*iter)->getName() == "Atom") {
	(*iter)->getId() = 2;
      } else if ((*iter)->getName() == "Bond") {
	(*iter)->getId() = 3;
      }
    }

    typedef std::set <ontologydto::AssociationDTO*>::iterator AssIterType;
    for (AssIterType iter = domainDTO->getAssociations().begin(); iter != domainDTO->getAssociations().end(); iter++) {
      if ((*iter)->getFromEnd().getTypeName() == "Molecule") {
	(*iter)->getFromEnd().getConceptId() = 1;
	(*iter)->getFromEnd().getDomainId() = 1;
      } else if ((*iter)->getFromEnd().getTypeName() == "Atom") {
	(*iter)->getFromEnd().getConceptId() = 2;
	(*iter)->getFromEnd().getDomainId() = 1;
      } else if ((*iter)->getFromEnd().getTypeName() == "Bond") {
	(*iter)->getFromEnd().getConceptId() = 3;
	(*iter)->getFromEnd().getDomainId() = 1;
      } else if ((*iter)->getFromEnd().getTypeName() == "Vertex") {
	(*iter)->getFromEnd().getConceptId() = 4;
	(*iter)->getFromEnd().getDomainId() = 2;
      } else if ((*iter)->getFromEnd().getTypeName() == "Edge") {
	(*iter)->getFromEnd().getConceptId() = 5;
	(*iter)->getFromEnd().getDomainId() = 2;
      } else if ((*iter)->getFromEnd().getTypeName() == "Face") {
	(*iter)->getFromEnd().getConceptId() = 6;
	(*iter)->getFromEnd().getDomainId() = 2;
      } else if ((*iter)->getFromEnd().getTypeName() == "Region") {
	(*iter)->getFromEnd().getConceptId() = 7;
	(*iter)->getFromEnd().getDomainId() = 2;
      }

      if ((*iter)->getToEnd().getTypeName() == "Molecule") {
	(*iter)->getToEnd().getConceptId() = 1;
	(*iter)->getToEnd().getDomainId() = 1;
      } else if ((*iter)->getToEnd().getTypeName() == "Atom") {
	(*iter)->getToEnd().getConceptId() = 2;
	(*iter)->getToEnd().getDomainId() = 1;
      } else if ((*iter)->getToEnd().getTypeName() == "Bond") {
	(*iter)->getToEnd().getConceptId() = 3;
	(*iter)->getToEnd().getDomainId() = 1;
      } else if ((*iter)->getToEnd().getTypeName() == "Vertex") {
	(*iter)->getToEnd().getConceptId() = 4;
	(*iter)->getToEnd().getDomainId() = 2;
      } else if ((*iter)->getToEnd().getTypeName() == "Edge") {
	(*iter)->getToEnd().getConceptId() = 5;
	(*iter)->getToEnd().getDomainId() = 2;
      } else if ((*iter)->getToEnd().getTypeName() == "Face") {
	(*iter)->getToEnd().getConceptId() = 6;
	(*iter)->getToEnd().getDomainId() = 2;
      } else if ((*iter)->getToEnd().getTypeName() == "Region") {
	(*iter)->getToEnd().getConceptId() = 7;
	(*iter)->getToEnd().getDomainId() = 2;
      }
    }

    _domain = new ontology::Domain(*domainDTO);
    ontologyElement->removeChild(chemistryDomainElement);    


    ontologyElement->appendChild(spatialDomainElement);
    domainDTO = new ontologydto::DomainDTO(*ontologyDocument);
    domainDTO->getId() = 2;
    domainDTO->getTitle() = "Spatial";

    for (IterType iter = domainDTO->getTypes().begin(); iter != domainDTO->getTypes().end(); iter++) {
      if ((*iter)->getName() == "Vertex") {
	(*iter)->getId() = 4;
      } else if ((*iter)->getName() == "Edge") {
	(*iter)->getId() = 5;
      } else if ((*iter)->getName() == "Face") {
	(*iter)->getId() = 6;
      } else if ((*iter)->getName() == "Region") {
	(*iter)->getId() = 7;
      }
    }


    typedef std::set <ontologydto::AssociationDTO*>::iterator AssIterType;
    for (AssIterType iter = domainDTO->getAssociations().begin(); iter != domainDTO->getAssociations().end(); iter++) {
      if ((*iter)->getFromEnd().getTypeName() == "Molecule") {
	(*iter)->getFromEnd().getConceptId() = 1;
	(*iter)->getFromEnd().getDomainId() = 1;
      } else if ((*iter)->getFromEnd().getTypeName() == "Atom") {
	(*iter)->getFromEnd().getConceptId() = 2;
	(*iter)->getFromEnd().getDomainId() = 1;
      } else if ((*iter)->getFromEnd().getTypeName() == "Bond") {
	(*iter)->getFromEnd().getConceptId() = 3;
	(*iter)->getFromEnd().getDomainId() = 1;
      } else if ((*iter)->getFromEnd().getTypeName() == "Vertex") {
	(*iter)->getFromEnd().getConceptId() = 4;
	(*iter)->getFromEnd().getDomainId() = 2;
      } else if ((*iter)->getFromEnd().getTypeName() == "Edge") {
	(*iter)->getFromEnd().getConceptId() = 5;
	(*iter)->getFromEnd().getDomainId() = 2;
      } else if ((*iter)->getFromEnd().getTypeName() == "Face") {
	(*iter)->getFromEnd().getConceptId() = 6;
	(*iter)->getFromEnd().getDomainId() = 2;
      } else if ((*iter)->getFromEnd().getTypeName() == "Region") {
	(*iter)->getFromEnd().getConceptId() = 7;
	(*iter)->getFromEnd().getDomainId() = 2;
      }

      if ((*iter)->getToEnd().getTypeName() == "Molecule") {
	(*iter)->getToEnd().getConceptId() = 1;
	(*iter)->getToEnd().getDomainId() = 1;
      } else if ((*iter)->getToEnd().getTypeName() == "Atom") {
	(*iter)->getToEnd().getConceptId() = 2;
	(*iter)->getToEnd().getDomainId() = 1;
      } else if ((*iter)->getToEnd().getTypeName() == "Bond") {
	(*iter)->getToEnd().getConceptId() = 3;
	(*iter)->getToEnd().getDomainId() = 1;
      } else if ((*iter)->getToEnd().getTypeName() == "Vertex") {
	(*iter)->getToEnd().getConceptId() = 4;
	(*iter)->getToEnd().getDomainId() = 2;
      } else if ((*iter)->getToEnd().getTypeName() == "Edge") {
	(*iter)->getToEnd().getConceptId() = 5;
	(*iter)->getToEnd().getDomainId() = 2;
      } else if ((*iter)->getToEnd().getTypeName() == "Face") {
	(*iter)->getToEnd().getConceptId() = 6;
	(*iter)->getToEnd().getDomainId() = 2;
      } else if ((*iter)->getToEnd().getTypeName() == "Region") {
	(*iter)->getToEnd().getConceptId() = 7;
	(*iter)->getToEnd().getDomainId() = 2;
      }
    }

    _domainDTOs.insert(domainDTO);
    _domain = new ontology::Domain(*domainDTO);
    ontologyElement->removeChild(spatialDomainElement);

    _ontology = new ontology::Ontology(_domainDTOs);
    _domain = _ontology->getDomainById("1");

    //    _domain = _ontology->getDomainById("Chemistry");
    //    _ontology = new ontology::Ontology(*ontologyDocument);
    //    _domain = _ontology->getDomainById("Chemistry");
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testConstruction()
  {
    try {
      assembly::Domain domainInstance(*_ontology, *_domain);
      assertTrue("Successful creation of assembly::Domain instance.");
    } catch (Exception ex) {
      fail("Incorrect failure to construct assembly::Domain instance.");
    }
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testGetters()
  {
    assembly::Domain domainInstance(*_ontology, *_domain);
    std::vector <Layer*> topDownLayers;
    assembly::Domain::LayerIteratorType iter;    
    for (iter = domainInstance.getTopDownLayers(); iter.hasNext(); ) {
      Layer& layer = iter.next();
      topDownLayers.push_back(&layer);
    }

    assertTrue(&(domainInstance.getDomain()) == _domain);
    assertTrue(domainInstance.getNumberLayers() == _ontology->getTypeStack(*_domain)->getNumberLayers());

    for (int index = 0; index < domainInstance.getNumberLayers(); ++index) {
      Layer& layer = domainInstance.getLayer(index);
      assertTrue(topDownLayers[index] == &layer);
    }

    for (int index = 0; index < domainInstance.getNumberLayers(); ++index) {
      Layer& layer = *(topDownLayers[index]);
      int i = index;
      for (iter = domainInstance.getTopDownLayers(layer); iter.hasNext(); ) {
	Layer& current = iter.next();
	assertTrue(topDownLayers[i] == &current);
	i++;
      }
    }
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testQueries()
  {
    assembly::Domain domainInstance(*_ontology, *_domain);
    std::vector <Layer*> topDownLayers;
    assembly::Domain::LayerIteratorType iter;    
    for (iter = domainInstance.getTopDownLayers(); iter.hasNext(); ) {
      Layer& layer = iter.next();
      topDownLayers.push_back(&layer);
    }

    std::vector <Layer*>::iterator layerIter;
    for (layerIter = topDownLayers.begin(); layerIter != topDownLayers.end(); ++layerIter) {
      Layer& layer = **layerIter;
      assertTrue(domainInstance.contains(layer));
    }
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testInstances()
  {
    assembly::Domain domainInstance(*_ontology, *_domain);

    Layer& layer0 = domainInstance.getLayer(0);
    ontology::TypeLayer& typeLayer0 = layer0.getTypeLayer();
    ontology::Type& type00 = typeLayer0.getTypes().next();
    Instance* inst00A = new Instance(type00);
    domainInstance.getLayer(0).add(*inst00A);

    Instance* inst00B = new Instance(type00);
    domainInstance.getLayer(0).add(*inst00B);

    Layer& layer1 = domainInstance.getLayer(1);
    ontology::TypeLayer& typeLayer1 = layer1.getTypeLayer();
    ontology::Type& type10 = typeLayer1.getTypes().next();

    Instance* inst10A = new Instance(type10);
    domainInstance.getLayer(1).add(*inst10A);

    Instance* inst10B = new Instance(type10);
    domainInstance.getLayer(1).add(*inst10B);

    assertTrue(domainInstance.contains(*inst00A));
    assertTrue(domainInstance.contains(*inst00B));
    assertTrue(domainInstance.contains(*inst10A));
    assertTrue(domainInstance.contains(*inst10B));
    assertTrue(domainInstance.getLayer(*inst00A) == &layer0);
    assertTrue(domainInstance.getLayer(*inst00B) == &layer0);
    assertTrue(domainInstance.getLayer(*inst10A) == &layer1);
    assertTrue(domainInstance.getLayer(*inst10B) == &layer1);

    Instance* nonMemberInst = new Instance(type00);
    assertFalse(domainInstance.contains(*nonMemberInst));
    assertTrue(domainInstance.getLayer(*nonMemberInst) == 0);    

  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testXdr()
  {
    assembly::Domain domainInstance(*_ontology, *_domain);

    Layer& layer0 = domainInstance.getLayer(0);
    ontology::TypeLayer& typeLayer0 = layer0.getTypeLayer();
    ontology::Type& type00 = typeLayer0.getTypes().next();

    Instance* inst00A = new Instance(type00);
    domainInstance.getLayer(0).add(*inst00A);

    Instance* inst00B = new Instance(type00);
    domainInstance.getLayer(0).add(*inst00B);

    Layer& layer1 = domainInstance.getLayer(1);
    ontology::TypeLayer& typeLayer1 = layer1.getTypeLayer();
    ontology::Type& type10 = typeLayer1.getTypes().next();

    Instance* inst10A = new Instance(type10);
    domainInstance.getLayer(1).add(*inst10A);

    Instance* inst10B = new Instance(type10);
    domainInstance.getLayer(1).add(*inst10B);

    iostream::XdrOutputStream ostream("testfile");
    domainInstance.encode(ostream);
    ostream.close();

    std::map <int, void*> addressMappings;
    addressMappings[(int) _ontology] = static_cast <void*> (_ontology);
    addressMappings[(int) _domain] = static_cast <void*> (_domain);

    iostream::XdrInputStream istream("testfile");
    assembly::Domain decodedDomainInst(istream, addressMappings);
    istream.close();

    remove("testfile");

    assertTrue(&(decodedDomainInst.getDomain()) == _domain);
    assertTrue(decodedDomainInst.getNumberLayers() ==
	       _ontology->getTypeStack(*_domain)->getNumberLayers());

    std::vector <Layer*> topDownLayers;
    assembly::Domain::LayerIteratorType iter;    
    for (iter = decodedDomainInst.getTopDownLayers(); iter.hasNext(); ) {
      Layer& layer = iter.next();
      topDownLayers.push_back(&layer);
    }

    for (int index = 0; index < decodedDomainInst.getNumberLayers(); ++index) {
      Layer& layer = decodedDomainInst.getLayer(index);
      assertTrue(topDownLayers[index] == &layer);
    }

    for (int index = 0; index < decodedDomainInst.getNumberLayers(); ++index) {
      Layer& layer = *(topDownLayers[index]);
      int i = index;
      for (iter = decodedDomainInst.getTopDownLayers(layer); iter.hasNext(); ) {
	Layer& current = iter.next();
	assertTrue(topDownLayers[i] == &current);
	i++;
      }
    }
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void tearDown()
  {
    delete _ontology;
    _domainDTOs.clear();
    XMLRelatedTest::tearDown();
  }

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  DomainInstanceTest(const DomainInstanceTest& test);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  DomainInstanceTest& operator=(const DomainInstanceTest& test);

};


}


}


#endif // PROTOLAYER_ASSEMBLY_DOMAININSTANCETEST_H
