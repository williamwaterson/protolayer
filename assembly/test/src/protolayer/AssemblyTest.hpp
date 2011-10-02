#ifndef PROTOLAYER_ASSEMBLY_ASSEMBLYTEST_HPP
#define PROTOLAYER_ASSEMBLY_ASSEMBLYTEST_HPP

#include <iostream.h>
#include <map>
#include <string>

#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLChar.hpp>
#include <xercesc/util/XMLString.hpp>

#include <protolayer/protolayer-iostream.h>
#include <protolayer/protolayer-ontology.h>
#include <protolayer/protolayer-util.h>
#include <protolayer/protolayer-xml.h>

#include "protolayer/protolayer-assembly.h"

#include "XMLRelatedTest.hpp"

namespace protolayer
{

namespace assembly
{

class AssemblyTest : public XMLRelatedTest
{
private:
  /** TODO: Documentation */
  ontology::Ontology* _ontology;

public:
  /**
   * TODO: Documentation
   *
   */
  AssemblyTest()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
 ~AssemblyTest()
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
      testInstanceRelatedMethods();
      tearDown();

      setUp();
      testReferenceRelatedMethods();
      tearDown();

      setUp();
      testDomainInstanceRelatedMethods();
      tearDown();

      setUp();
      testLayerRelatedMethods();
      tearDown();

      setUp();
      testParticipation();
      tearDown();

      setUp();
      //      testXdr();
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
    ::protolayer::XMLRelatedTest::setUp();

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


    std::set <ontologydto::DomainDTO*> domainDTOs;

    ontologyElement->appendChild(chemistryDomainElement);
    ontologydto::DomainDTO* domainDTO = new ontologydto::DomainDTO(*ontologyDocument);
    domainDTO->getTitle() = "Chemistry";
    domainDTO->getId() = 1;
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

    domainDTOs.insert(domainDTO);
    ontologyElement->removeChild(chemistryDomainElement);    


    ontologyElement->appendChild(spatialDomainElement);
    domainDTO = new ontologydto::DomainDTO(*ontologyDocument);
    domainDTO->getId() = 2;
    domainDTO->getTitle() = "Spatial";
    domainDTOs.insert(domainDTO);  for (IterType iter = domainDTO->getTypes().begin(); iter != domainDTO->getTypes().end(); iter++) {
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
    ontologyElement->removeChild(spatialDomainElement);

    _ontology = new ontology::Ontology(domainDTOs);
    //    _ontology = new ontology::Ontology(*ontologyDocument);
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testConstruction()
  {
    try {
      Assembly assembly(*_ontology);
    } catch (ontology::Exception& ex) {
      fail("Failed to correctly construct Assembly instance from Ontology instance.");
    }

    assertTrue("Correctly constructed Assembly instance from Ontology instance.");
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testGetters()
  {
    Assembly assembly(*_ontology);

    assertTrue(&(assembly.getOntology()) == _ontology);
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testInstanceRelatedMethods()
  {
    Assembly assembly(*_ontology);
 
    Assembly::DomainIteratorType diIter = assembly.getDomains();
    assembly::Domain& domainInstance0 = diIter.next();
    Layer& layer00 = domainInstance0.getLayer(0);
    ontology::TypeLayer& typeLayer00 = layer00.getTypeLayer();
    ontology::Type& type000 = typeLayer00.getTypes().next();
    //    Instance* inst0000 = new Instance(layer00, type000);
    Instance* inst0000 = new Instance(type000);
    assembly.add(*inst0000);

    //    Instance* inst0001 = new Instance(layer00, type000);
    Instance* inst0001 = new Instance(type000);
    assembly.add(*inst0001);

    //    Instance* inst0002 = new Instance(layer00, type000);
    Instance* inst0002 = new Instance(type000);
    assembly.add(*inst0002);

    assertTrue(inst0000 != 0);
    assertTrue(inst0001 != 0);
    assertTrue(inst0002 != 0);

    assembly::Domain& domainInstance1 = diIter.next();
    Layer& layer10 = domainInstance1.getLayer(0);
    ontology::TypeLayer& typeLayer10 = layer10.getTypeLayer();
    ontology::Type& type100 = typeLayer10.getTypes().next();

    //    Instance* inst1000 = new Instance(layer10, type100);
    Instance* inst1000 = new Instance(type100);
    assembly.add(*inst1000);

    Instance* inst1001 = new Instance(type100);
    assembly.add(*inst1001);

    Instance* inst1002 = new Instance(type100);
    assembly.add(*inst1002);

    assertTrue(inst1000 != 0);
    assertTrue(inst1001 != 0);
    assertTrue(inst1002 != 0);

    assertTrue(assembly.getNumberInstances() == 6);

    assertTrue(assembly.contains(*inst0000));
    assertTrue(assembly.contains(*inst0001));
    assertTrue(assembly.contains(*inst0002));
    assertTrue(assembly.contains(*inst1000));
    assertTrue(assembly.contains(*inst1001));
    assertTrue(assembly.contains(*inst1002));

    assertTrue(assembly.getLayer(*inst0000) == &layer00);
    assertTrue(assembly.getLayer(*inst0001) == &layer00);
    assertTrue(assembly.getLayer(*inst0002) == &layer00);
    assertTrue(assembly.getLayer(*inst1000) == &layer10);
    assertTrue(assembly.getLayer(*inst1001) == &layer10);
    assertTrue(assembly.getLayer(*inst1002) == &layer10);

    Instance* nonMemberInst0000 = new Instance(type000);
    Instance* nonMemberInst1000 = new Instance(type100);
    assertFalse(assembly.contains(*nonMemberInst0000));
    assertFalse(assembly.contains(*nonMemberInst1000));
    assertTrue(assembly.getLayer(*nonMemberInst0000) == 0);
    assertTrue(assembly.getLayer(*nonMemberInst1000) == 0);

    std::set <Instance*> compare;
    compare.insert(inst0000);
    compare.insert(inst0001);
    compare.insert(inst0002);
    compare.insert(inst1000);
    compare.insert(inst1001);
    compare.insert(inst1002);
    Assembly::InstanceIteratorType instIter;
    for (instIter = assembly.getInstances(); instIter.hasNext(); ) {
      int priorSize = compare.size();
      Instance& instance = instIter.next();
      assertTrue(compare.find(&instance) != compare.end());
      compare.erase(&instance);
      assertTrue(compare.size() == priorSize - 1);
    }
    assertTrue(compare.size() == 0);

    try {
      assembly.remove(*inst0000);

    } catch (Exception ex) {
      fail("Incorrectly failed to remove member instance from assembly.");
    }
    assertTrue(assembly.getNumberInstances() == 5);

    try {
      assembly.remove(*inst0001);
    } catch (Exception ex) {
      fail("Incorrectly failed to remove member instance from assembly.");
    }
    assertTrue(assembly.getNumberInstances() == 4);

    bool failed = false;
    try {
      assembly.remove(*nonMemberInst0000);
      failed = true;
    } catch (Exception ex) {
      assertTrue("Correctly failed to delete non-member instance from layer.");
    }

    if (failed) {
      fail("Incorrectly executed remove on non-member Instance without throwing exception.");
    }
    assertTrue(assembly.getNumberInstances() == 4);

    failed = false;
    try {
      assembly.remove(*nonMemberInst1000);
      failed = true;
    } catch (Exception ex) {
      assertTrue("Correctly failed to delete non-member instance from layer.");
    }

    if (failed) {
      fail("Incorrectly executed remove on non-member Instance without throwing exception.");
    }
    assertTrue(assembly.getNumberInstances() == 4);

    try {
      assembly.remove(*inst0002);
    } catch (Exception ex) {
      fail("Incorrectly failed to remove member instance from assembly.");
    }
    assertTrue(assembly.getNumberInstances() == 3);

    try {
      assembly.remove(*inst1000);
    } catch (Exception ex) {
      fail("Incorrectly failed to remove member instance from assembly.");
    }
    assertTrue(assembly.getNumberInstances() == 2);

    try {
      assembly.remove(*inst1001);
    } catch (Exception ex) {
      fail("Incorrectly failed to remove member instance from assembly.");
    }
    assertTrue(assembly.getNumberInstances() == 1);

    try {
      assembly.remove(*inst1002);
    } catch (Exception ex) {
      fail("Incorrectly failed to remove member instance from assembly.");
    }
    assertTrue(assembly.getNumberInstances() == 0);

    delete nonMemberInst0000;
    delete nonMemberInst1000;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testReferenceRelatedMethods()
  {
    Assembly assembly(*_ontology);

    ontology::Association& association = _ontology->getAssociations().next();
    ontology::Type& fromType = association.getFromEnd().getType();
    ontology::Type& toType = association.getToEnd().getType();

    Instance* fromInst0 = new Instance(fromType);
    assembly.add(*fromInst0);

    Instance* fromInst1 = new Instance(fromType);
    assembly.add(*fromInst1);

    Instance* toInst0 = new Instance(toType);
    assembly.add(*toInst0);

    Instance* toInst1 = new Instance(toType);
    assembly.add(*toInst1);

    assertTrue(fromInst0 != 0);
    assertTrue(fromInst1 != 0);
    assertTrue(toInst0 != 0);
    assertTrue(toInst1 != 0);

    Reference* ref00 = new Reference(association, *fromInst0, *toInst0);
    assembly.add(*ref00);

    Reference* ref01 = new Reference(association, *fromInst0, *toInst1);
    assembly.add(*ref01);

    Reference* ref10 = new Reference(association, *fromInst1, *toInst0);
    assembly.add(*ref10);

    Reference* ref11 = new Reference(association, *fromInst1, *toInst1);
    assembly.add(*ref11);

    assertTrue(ref00 != 0);
    assertTrue(ref01 != 0);
    assertTrue(ref10 != 0);
    assertTrue(ref11 != 0);

    assertTrue(assembly.getNumberReferences() == 4);

    Reference* nonMemberRef0 = new Reference(association, *fromInst0, *toInst0);
    Reference* nonMemberRef1 = new Reference(association, *fromInst0, *toInst1);
    assertTrue(nonMemberRef0 != 0);
    assertTrue(nonMemberRef1 != 0);

    assertTrue(assembly.contains(*ref00));
    assertTrue(assembly.contains(*ref01));
    assertTrue(assembly.contains(*ref10));
    assertTrue(assembly.contains(*ref11));
    assertFalse(assembly.contains(*nonMemberRef0));
    assertFalse(assembly.contains(*nonMemberRef1));

    try {
      assembly.remove(*ref00);
    } catch (Exception ex) {
      fail("Incorrectly failed to delete Reference instance.");
    }
    assertTrue(assembly.getNumberReferences() == 3);
    assertTrue(assembly.contains(*ref01));
    assertTrue(assembly.contains(*ref10));
    assertTrue(assembly.contains(*ref11));

    try {
      assembly.remove(*ref01);
    } catch (Exception ex) {
      fail("Incorrectly failed to delete Reference instance.");
    }
    assertTrue(assembly.getNumberReferences() == 2);
    assertTrue(assembly.contains(*ref10));
    assertTrue(assembly.contains(*ref11));

    bool failed = false;
    try {
      assembly.remove(*nonMemberRef0);
      failed = true;
    } catch (Exception ex) {
    }

    if (failed) {
      fail("Incorrectly deleted the reference instance.");
    }
    assertTrue(assembly.getNumberReferences() == 2);
    assertTrue(assembly.contains(*ref10));
    assertTrue(assembly.contains(*ref11));

    try {
      assembly.remove(*nonMemberRef1);
      failed = true;
    } catch (Exception ex) {
    }

    if (failed) {
      fail("Incorrectly deleted the reference instance.");
    }
    assertTrue(assembly.getNumberReferences() == 2);
    assertTrue(assembly.contains(*ref10));
    assertTrue(assembly.contains(*ref11));

    try {
      assembly.remove(*ref10);
    } catch (Exception ex) {
      fail("Incorrectly failed to delete Reference instance.");
    }
    assertTrue(assembly.getNumberReferences() == 1);
    assertTrue(assembly.contains(*ref11));

    try {
      assembly.remove(*ref11);
    } catch (Exception ex) {
      fail("Incorrectly failed to delete Reference instance.");
    }
    assertTrue(assembly.getNumberReferences() == 0);

    delete nonMemberRef0;
    delete nonMemberRef1;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testDomainInstanceRelatedMethods()
  {
    Assembly assembly(*_ontology);
    assertTrue(assembly.getNumberDomains() == _ontology->getNumberDomains());

    std::set <ontology::Domain*> domainCompare;
    std::set <std::string> domainNames;
    typedef ontology::Ontology::DomainIteratorType IterTypeA;
    for (IterTypeA iter = _ontology->getDomains(); iter.hasNext(); ) {
      ontology::Domain& domain = iter.next();
      domainCompare.insert(&domain);
      domainNames.insert(domain.getTitle());
    }
    assertTrue(domainCompare.size() == assembly.getNumberDomains());

    typedef std::set <std::string>::iterator IterTypeB;
    for (IterTypeB iter = domainNames.begin(); iter != domainNames.end(); ++iter) {
      std::string name = *iter;
      assembly::Domain* domainInstance = assembly.getDomain(name);
      assertTrue(domainInstance != 0);
      assertTrue(domainInstance->getDomain().getTitle() == name);
    }

    typedef std::set <ontology::Domain*>::iterator IterTypeC;
    std::set <assembly::Domain*> domainInstanceCompare;
    for (IterTypeC iter = domainCompare.begin(); iter != domainCompare.end(); ++iter) {
      ontology::Domain* domain = *iter;
      assembly::Domain* domainInstance = assembly.getDomain(*domain);
      assertTrue(domainInstance != 0);
      domainInstanceCompare.insert(domainInstance);
    }
    assertTrue(domainInstanceCompare.size() == assembly.getNumberDomains());

    typedef std::set <assembly::Domain*>::iterator IterTypeD;
    for (IterTypeD iter = domainInstanceCompare.begin(); iter != domainInstanceCompare.end(); ++iter) {
      assembly::Domain* domainInstance = *iter;
      assertTrue(assembly.contains(*domainInstance));
    }
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testLayerRelatedMethods()
  {
    Assembly assembly(*_ontology);

    int count = 0;
    typedef Assembly::DomainIteratorType DIIterType;
    for (DIIterType iter = assembly.getDomains(); iter.hasNext(); ) {
      count += iter.next().getNumberLayers();
    }
    assert(count == assembly.getNumberLayers());

    std::set <Layer*> layerCompare;
    typedef Assembly::LayerIteratorType LIType;
    for (LIType iter = assembly.getLayers(); iter.hasNext(); ) {
      Layer& layer = iter.next();
      layerCompare.insert(&layer);
    }
    assert(layerCompare.size() == assembly.getNumberLayers());

    typedef std::set <Layer*>::iterator liType;
    for (liType iter = layerCompare.begin(); iter != layerCompare.end(); ++iter) {
      Layer& layer = **iter;
      assertTrue(assembly.contains(layer));
    }

    Assembly::DomainIteratorType diIter = assembly.getDomains();
    assembly::Domain& domainInstance0 = diIter.next();
    Layer& layer00 = domainInstance0.getLayer(0);
    ontology::TypeLayer& typeLayer00 = layer00.getTypeLayer();
    ontology::Type& type000 = typeLayer00.getTypes().next();

    //    Instance* inst0000 = new Instance(layer00, type000);
    Instance* inst0000 = new Instance(type000);
    assembly.add(*inst0000);

    Instance* inst0001 = new Instance(type000);
    assembly.add(*inst0001);

    Instance* inst0002 = new Instance(type000);
    assembly.add(*inst0002);

    assertTrue(inst0000 != 0);
    assertTrue(inst0001 != 0);
    assertTrue(inst0002 != 0);

    assembly::Domain& domainInstance1 = diIter.next();
    Layer& layer10 = domainInstance1.getLayer(0);
    ontology::TypeLayer& typeLayer10 = layer10.getTypeLayer();
    ontology::Type& type100 = typeLayer10.getTypes().next();
    //    Instance* inst1000 = new Instance(layer10, type100);
    Instance* inst1000 = new Instance(type100);
    assembly.add(*inst1000);

    //    Instance* inst1001 = new Instance(layer10, type100);
    Instance* inst1001 = new Instance(type100);
    assembly.add(*inst1001);

    //    Instance* inst1002 = new Instance(layer10, type100);
    Instance* inst1002 = new Instance(type100);
    assembly.add(*inst1002);

    assertTrue(inst1000 != 0);
    assertTrue(inst1001 != 0);
    assertTrue(inst1002 != 0);

    assertTrue(assembly.getLayer(*inst0000) == &layer00);
    assertTrue(assembly.getLayer(*inst0001) == &layer00);
    assertTrue(assembly.getLayer(*inst0002) == &layer00);
    assertTrue(assembly.getLayer(*inst1000) == &layer10);
    assertTrue(assembly.getLayer(*inst1001) == &layer10);
    assertTrue(assembly.getLayer(*inst1002) == &layer10);

    Instance* nonMemberInst0000 = new Instance(type000);
    Instance* nonMemberInst1000 = new Instance(type100);
    assertTrue(assembly.getLayer(*nonMemberInst0000) == 0);
    assertTrue(assembly.getLayer(*nonMemberInst1000) == 0);

    Layer* layer = assembly.getLayer(*inst0000);
    assertTrue(layer == assembly.getLayer(inst0000->getType()));

    layer = assembly.getLayer(*inst0001);
    assertTrue(layer == assembly.getLayer(inst0001->getType()));

    layer = assembly.getLayer(*inst0002);
    assertTrue(layer == assembly.getLayer(inst0002->getType()));

    layer = assembly.getLayer(*inst1000);
    assertTrue(layer == assembly.getLayer(inst1000->getType()));

    layer = assembly.getLayer(*inst1001);
    assertTrue(layer == assembly.getLayer(inst1001->getType()));

    layer = assembly.getLayer(*inst1002);
    assertTrue(layer == assembly.getLayer(inst1002->getType()));


    layer = assembly.getLayer(*inst0000);
    ontology::TypeLayer* typeLayer = &(layer->getTypeLayer());
    assertTrue(layer == assembly.getLayer(*typeLayer));

    layer = assembly.getLayer(*inst0001);
    typeLayer = &(layer->getTypeLayer());
    assertTrue(layer == assembly.getLayer(*typeLayer));

    layer = assembly.getLayer(*inst0002);
    typeLayer = &(layer->getTypeLayer());
    assertTrue(layer == assembly.getLayer(*typeLayer));

    layer = assembly.getLayer(*inst1000);
    typeLayer = &(layer->getTypeLayer());
    assertTrue(layer == assembly.getLayer(*typeLayer));

    layer = assembly.getLayer(*inst1001);
    typeLayer = &(layer->getTypeLayer());
    assertTrue(layer == assembly.getLayer(*typeLayer));

    layer = assembly.getLayer(*inst1002);
    typeLayer = &(layer->getTypeLayer());
    assertTrue(layer == assembly.getLayer(*typeLayer));


    layer = assembly.getLayer(*inst0000);
    //    assertTrue(layer == assembly.getLayer(inst0000->getType().getScopedName()));

    layer = assembly.getLayer(*inst0001);
    //    assertTrue(layer == assembly.getLayer(inst0001->getType().getScopedName()));

    layer = assembly.getLayer(*inst0002);
    //    assertTrue(layer == assembly.getLayer(inst0002->getType().getScopedName()));

    layer = assembly.getLayer(*inst1000);
    //    assertTrue(layer == assembly.getLayer(inst1000->getType().getScopedName()));

    layer = assembly.getLayer(*inst1001);
    //    assertTrue(layer == assembly.getLayer(inst1001->getType().getScopedName()));

    layer = assembly.getLayer(*inst1002);
    //    assertTrue(layer == assembly.getLayer(inst1002->getType().getScopedName()));
    
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testParticipation()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testXdr()
  {
    Assembly assembly(*_ontology);

    iostream::XdrOutputStream ostream("testfile");
    assembly.encode(ostream);
    ostream.close();

    std::map <int, void*> addressMappings;
    addressMappings[(int) _ontology] = static_cast <void*> (_ontology);

    iostream::XdrInputStream istream("testfile");
    Assembly decodedAssembly(istream, addressMappings);
    istream.close();
    
    remove("testfile");


  }

  /**
   * TODO: Documentation
   * <p>
   */
  void tearDown()
  {
    delete _ontology;
  }

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  AssemblyTest(const AssemblyTest& assemblyTest);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  AssemblyTest& operator=(const AssemblyTest& assemblyTest);

};


}


}


#endif // PROTOLAYER_ASSEMBLY_ASSEMBLYTEST_H
