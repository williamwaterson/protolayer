#ifndef PROTOLAYER_ONTOLOGY_ONTOLOGYTEST_HPP
#define PROTOLAYER_ONTOLOGY_ONTOLOGYTEST_HPP

#include <iostream.h>
#include <map>
#include <string>

#include <xercesc/dom/DOM.hpp>
#include <xercesc/framework/StdOutFormatTarget.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
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

class OntologyTest : public XMLRelatedTest
{
private:
  /** TODO: Documentation */
  xercesc::DOMDocument* _ontologyDocument;

public:
  /**
   * TODO: Documentation
   *
   */
  OntologyTest()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
 ~OntologyTest()
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
      testAccessors();
      tearDown();

      setUp();
      testQueries();
      tearDown();

      setUp();
      testCyclicTypeDependency();
      tearDown();

      setUp();
      testCyclicDomainDependency();
      tearDown();

      setUp();
      testDuplicateTypeOwnership();
      tearDown();

      setUp();
      testXdr();
      tearDown();

    } catch (ontology::Exception ex) {
      std::cout << ex.getMessage() << std::endl;
    }
  }

  void initialiseAcyclicOntology()
  {
    _ontologyDocument = &(getDOMDocument());    

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
    ontologyElement->appendChild(chemistryDomainElement);
    ontologyElement->appendChild(spatialDomainElement);
    _ontologyDocument->getDocumentElement()->appendChild(ontologyElement);


    str = xercesc::XMLString::transcode("from");
    xercesc::DOMElement* fromElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Chemistry.Molecule");
    fromElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("1");
    fromElement->setAttribute(nameCh, valueCh);


    str = xercesc::XMLString::transcode("to");
    xercesc::DOMElement* toElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Chemistry.Bond");
    toElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("0..*");
    toElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("association");
    xercesc::DOMElement* assocElement = getDOMDocument().createElement(str);
    assocElement->appendChild(fromElement);
    assocElement->appendChild(toElement);


    ontologyElement->appendChild(assocElement);

    str = xercesc::XMLString::transcode("from");
    fromElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Chemistry.Bond");
    fromElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("0..*");
    fromElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("to");
    toElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Chemistry.Atom");
    toElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("2");
    toElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("association");
    assocElement = getDOMDocument().createElement(str);
    assocElement->appendChild(fromElement);
    assocElement->appendChild(toElement);

    ontologyElement->appendChild(assocElement);


    str = xercesc::XMLString::transcode("from");
    fromElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Chemistry.Molecule");
    fromElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("1");
    fromElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("to");
    toElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Chemistry.Atom");
    toElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("1..*");
    toElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("association");
    assocElement = getDOMDocument().createElement(str);
    assocElement->appendChild(fromElement);
    assocElement->appendChild(toElement);

    ontologyElement->appendChild(assocElement);


    str = xercesc::XMLString::transcode("from");
    fromElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Chemistry.Molecule");
    fromElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("1");
    fromElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("to");
    toElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Spatial.Vertex");
    toElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("1..*");
    toElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("association");
    assocElement = getDOMDocument().createElement(str);
    assocElement->appendChild(fromElement);
    assocElement->appendChild(toElement);

    ontologyElement->appendChild(assocElement);


    str = xercesc::XMLString::transcode("from");
    fromElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Spatial.Edge");
    fromElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("0..*");
    fromElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("to");
    toElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Spatial.Vertex");
    toElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("2");
    toElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("association");
    assocElement = getDOMDocument().createElement(str);
    assocElement->appendChild(fromElement);
    assocElement->appendChild(toElement);

    ontologyElement->appendChild(assocElement);

    xercesc::LocalFileFormatTarget* target = new xercesc::LocalFileFormatTarget("output.xml");
    xercesc::DOMWriter* writer = getDOMImplementation().createDOMWriter();
    writer->writeNode(target, *_ontologyDocument);
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void setUp()
  {
    XMLRelatedTest::setUp();
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testConstruction()
  {
    initialiseAcyclicOntology();
    try {
      Ontology* ontology = new Ontology(*_ontologyDocument);
      assertTrue("Successful contruction");
    } catch (ontology::Exception ex) {
      throw;
    }
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testAccessors()
  {
    initialiseAcyclicOntology();
    Ontology* ontology = new Ontology(*_ontologyDocument);

    assertTrue(ontology->getNumberDomains() == 2);
    assertTrue(ontology->getNumberTypes() == 7);
    assertTrue(ontology->getNumberAssociations() == 5);
    assertTrue(ontology->getNumberGeneralisations() == 0);
    assertTrue(ontology->getNumberTypeDependencies() == 5);
    assertTrue(ontology->getNumberDomainDependencies() == 1);

    Domain* chemistryDomain = ontology->getDomain("Chemistry");
    Domain* spatialDomain = ontology->getDomain("Spatial");
    Domain* nonsenseDomain = ontology->getDomain("Nonsense");    
    assertTrue(chemistryDomain != 0);
    assertTrue(spatialDomain != 0);
    assertTrue(nonsenseDomain == 0);

    std::string chemistry("Chemistry");
    std::string spatial("Spatial");
    std::string nonsense("nonsense");
    chemistryDomain = ontology->getDomain(chemistry);
    spatialDomain = ontology->getDomain(spatial);
    nonsenseDomain = ontology->getDomain(nonsense);
    assertTrue(chemistryDomain != 0);
    assertTrue(spatialDomain != 0);
    assertTrue(nonsenseDomain == 0);

    Type* atomType = ontology->getType("Chemistry.Atom");
    Type* bondType = ontology->getType("Chemistry.Bond");
    Type* moleculeType = ontology->getType("Chemistry.Molecule");
    Type* vertexType = ontology->getType("Spatial.Vertex");
    Type* edgeType = ontology->getType("Spatial.Edge");
    Type* faceType = ontology->getType("Spatial.Face");
    Type* regionType = ontology->getType("Spatial.Region");
    Type* nonsenseType = ontology->getType("Spatial.Nonsense");

    assertTrue(atomType != 0);
    assertTrue(bondType != 0);
    assertTrue(moleculeType != 0);
    assertTrue(vertexType != 0);
    assertTrue(edgeType != 0);
    assertTrue(faceType != 0);
    assertTrue(regionType != 0);
    assertTrue(nonsenseType == 0);

    std::string atom("Chemistry.Atom");
    std::string bond("Chemistry.Bond");
    std::string molecule("Chemistry.Molecule");
    std::string vertex("Spatial.Vertex");
    std::string edge("Spatial.Edge");
    std::string face("Spatial.Face");
    std::string region("Spatial.Region");

    atomType = ontology->getType(atom);
    bondType = ontology->getType(bond);
    moleculeType = ontology->getType(molecule);
    vertexType = ontology->getType(vertex);
    edgeType = ontology->getType(edge);
    faceType = ontology->getType(face);
    regionType = ontology->getType(region);
    nonsenseType = ontology->getType(nonsense);

    assertTrue(ontology->getDomain(*atomType) == chemistryDomain);
    assertTrue(ontology->getDomain(*bondType) == chemistryDomain);
    assertTrue(ontology->getDomain(*moleculeType) == chemistryDomain);
    assertTrue(ontology->getDomain(*vertexType) == spatialDomain);
    assertTrue(ontology->getDomain(*edgeType) == spatialDomain);
    assertTrue(ontology->getDomain(*faceType) == spatialDomain);
    assertTrue(ontology->getDomain(*regionType) == spatialDomain);
    assertTrue(nonsenseType == 0);

    assertTrue(ontology->getDomainDependency(chemistry, spatial) != 0);
    assertTrue(ontology->getDomainDependency(spatial, chemistry) == 0);
    assertTrue(ontology->getDomainDependency(chemistry, chemistry) == 0);
    assertTrue(ontology->getDomainDependency(spatial, spatial) == 0);
    assertTrue(ontology->getDomainDependency(chemistry, nonsense) == 0);
    assertTrue(ontology->getDomainDependency(nonsense, spatial) == 0);
    assertTrue(ontology->getDomainDependency(spatial, nonsense) == 0);
    assertTrue(ontology->getDomainDependency(nonsense, chemistry) == 0);
    assertTrue(ontology->getDomainDependency(nonsense, nonsense) == 0);

    DomainDependency* domainDep = ontology->getDependency(*chemistryDomain, *spatialDomain);
    assertTrue(domainDep != 0);

    domainDep = ontology->getDependency(*spatialDomain, *chemistryDomain);
    assertTrue(domainDep == 0);

    TypeDependency* typeDep = ontology->getDependency(*moleculeType, *atomType);

    typeDep = ontology->getDependency(*moleculeType, *bondType);
    assertTrue(typeDep != 0);

    typeDep = ontology->getDependency(*bondType, *atomType);
    assertTrue(typeDep != 0);

    typeDep = ontology->getDependency(*atomType, *bondType);
    assertTrue(typeDep == 0);

    typeDep = ontology->getDependency(*atomType, *moleculeType);
    assertTrue(typeDep == 0);

    typeDep = ontology->getDependency(*moleculeType, *vertexType);
    assertTrue(typeDep != 0);

    typeDep = ontology->getDependency(*regionType, *faceType);
    assertTrue(typeDep == 0);

    typeDep = ontology->getDependency(*faceType, *edgeType);
    assertTrue(typeDep == 0);

    typeDep = ontology->getDependency(*edgeType, *vertexType);
    assertTrue(typeDep != 0);

    typeDep = ontology->getDependency(*faceType, *regionType);
    assertTrue(typeDep == 0);

    typeDep = ontology->getDependency(*edgeType, *faceType);
    assertTrue(typeDep == 0);

    typeDep = ontology->getDependency(*vertexType, *edgeType);
    assertTrue(typeDep == 0);


    typeDep = ontology->getTypeDependency(bond, atom);
    assertTrue(typeDep != 0);
    assertTrue(&(typeDep->getFromType()) == bondType);
    assertTrue(&(typeDep->getToType()) == atomType);

    typeDep = ontology->getTypeDependency(molecule, atom);
    assertTrue(typeDep != 0);
    assertTrue(&(typeDep->getFromType()) == moleculeType);
    assertTrue(&(typeDep->getToType()) == atomType);

    typeDep = ontology->getTypeDependency(molecule, bond);
    assertTrue(typeDep != 0);
    assertTrue(&(typeDep->getFromType()) == moleculeType);
    assertTrue(&(typeDep->getToType()) == bondType);

    typeDep = ontology->getTypeDependency(atom, bond);
    assertTrue(typeDep == 0);

    typeDep = ontology->getTypeDependency(region, face);
    assertTrue(typeDep == 0);

    typeDep = ontology->getTypeDependency(face, edge);
    assertTrue(typeDep == 0);

    typeDep = ontology->getTypeDependency(edge, vertex);
    assertTrue(typeDep != 0);
    assertTrue(&(typeDep->getFromType()) == edgeType);
    assertTrue(&(typeDep->getToType()) == vertexType);

    typeDep = ontology->getTypeDependency(face, region);
    assertTrue(typeDep == 0);

    typeDep = ontology->getTypeDependency(edge, face);
    assertTrue(typeDep == 0);

    typeDep = ontology->getTypeDependency(vertex, edge);
    assertTrue(typeDep == 0);

    ontology->getDomains();

    ontology->getTypes();

    ontology->getAssociations();

    ontology->getGeneralisations();

    ontology->getTypeDependencies();

    ontology->getDomainDependencies();

  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testQueries()
  {
    initialiseAcyclicOntology();

    //bool containsDomain(char* name);
    //  bool containsDomain(const std::string& name);
    //  bool containsType(const std::string& scopedMame);
    //  bool containsType(char* scopedName);
    //  bool contains(Domain& domain);
    //  bool contains(Type& type);
    //  bool contains(Association& assoc);
    //  bool contains(Generalisation& gen);
    //  bool contains(TypeDependency& dep);
    //  bool contains(DomainDependency& dep);
    //bool containsDependency(Type& fromType, Type& toType);
    //bool containsTypeDependency(std::string& fromScopedName,
    //		      std::string& toScopedName);
    //  bool containsDependency(Domain& fromDomain, Domain& toDomain);
    //  bool containsDomainDependency(std::string& fromName,
    //			std::string& toName);
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void initialiseCyclicTypeOntology()
  {
    _ontologyDocument = &(getDOMDocument());    

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
    ontologyElement->appendChild(chemistryDomainElement);
    ontologyElement->appendChild(spatialDomainElement);
    _ontologyDocument->getDocumentElement()->appendChild(ontologyElement);


    str = xercesc::XMLString::transcode("from");
    xercesc::DOMElement* fromElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Chemistry.Molecule");
    fromElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("1");
    fromElement->setAttribute(nameCh, valueCh);


    str = xercesc::XMLString::transcode("to");
    xercesc::DOMElement* toElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Chemistry.Bond");
    toElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("0..*");
    toElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("association");
    xercesc::DOMElement* assocElement = getDOMDocument().createElement(str);
    assocElement->appendChild(fromElement);
    assocElement->appendChild(toElement);


    ontologyElement->appendChild(assocElement);

    str = xercesc::XMLString::transcode("from");
    fromElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Chemistry.Bond");
    fromElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("0..*");
    fromElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("to");
    toElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Chemistry.Atom");
    toElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("2");
    toElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("association");
    assocElement = getDOMDocument().createElement(str);
    assocElement->appendChild(fromElement);
    assocElement->appendChild(toElement);

    ontologyElement->appendChild(assocElement);


    str = xercesc::XMLString::transcode("from");
    fromElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Chemistry.Atom");
    fromElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("1");
    fromElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("to");
    toElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Chemistry.Molecule");
    toElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("1..*");
    toElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("association");
    assocElement = getDOMDocument().createElement(str);
    assocElement->appendChild(fromElement);
    assocElement->appendChild(toElement);

    ontologyElement->appendChild(assocElement);


    str = xercesc::XMLString::transcode("from");
    fromElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Chemistry.Molecule");
    fromElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("1");
    fromElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("to");
    toElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Spatial.Vertex");
    toElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("1..*");
    toElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("association");
    assocElement = getDOMDocument().createElement(str);
    assocElement->appendChild(fromElement);
    assocElement->appendChild(toElement);

    ontologyElement->appendChild(assocElement);


    str = xercesc::XMLString::transcode("from");
    fromElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Spatial.Edge");
    fromElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("0..*");
    fromElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("to");
    toElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Spatial.Vertex");
    toElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("2");
    toElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("association");
    assocElement = getDOMDocument().createElement(str);
    assocElement->appendChild(fromElement);
    assocElement->appendChild(toElement);

    ontologyElement->appendChild(assocElement);
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void initialiseCyclicDomainOntology()
  {
    _ontologyDocument = &(getDOMDocument());    

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
    ontologyElement->appendChild(chemistryDomainElement);
    ontologyElement->appendChild(spatialDomainElement);
    _ontologyDocument->getDocumentElement()->appendChild(ontologyElement);


    str = xercesc::XMLString::transcode("from");
    xercesc::DOMElement* fromElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Chemistry.Molecule");
    fromElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("1");
    fromElement->setAttribute(nameCh, valueCh);


    str = xercesc::XMLString::transcode("to");
    xercesc::DOMElement* toElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Chemistry.Bond");
    toElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("0..*");
    toElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("association");
    xercesc::DOMElement* assocElement = getDOMDocument().createElement(str);
    assocElement->appendChild(fromElement);
    assocElement->appendChild(toElement);


    ontologyElement->appendChild(assocElement);

    str = xercesc::XMLString::transcode("from");
    fromElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Chemistry.Bond");
    fromElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("0..*");
    fromElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("to");
    toElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Chemistry.Atom");
    toElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("2");
    toElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("association");
    assocElement = getDOMDocument().createElement(str);
    assocElement->appendChild(fromElement);
    assocElement->appendChild(toElement);

    ontologyElement->appendChild(assocElement);


    str = xercesc::XMLString::transcode("from");
    fromElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Chemistry.Molecule");
    fromElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("1");
    fromElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("to");
    toElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Chemistry.Atom");
    toElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("1..*");
    toElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("association");
    assocElement = getDOMDocument().createElement(str);
    assocElement->appendChild(fromElement);
    assocElement->appendChild(toElement);

    ontologyElement->appendChild(assocElement);


    str = xercesc::XMLString::transcode("from");
    fromElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Chemistry.Molecule");
    fromElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("1");
    fromElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("to");
    toElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Spatial.Vertex");
    toElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("1..*");
    toElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("association");
    assocElement = getDOMDocument().createElement(str);
    assocElement->appendChild(fromElement);
    assocElement->appendChild(toElement);

    ontologyElement->appendChild(assocElement);


    str = xercesc::XMLString::transcode("from");
    fromElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Spatial.Edge");
    fromElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("0..*");
    fromElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("to");
    toElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Chemistry.Atom");
    toElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("2");
    toElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("association");
    assocElement = getDOMDocument().createElement(str);
    assocElement->appendChild(fromElement);
    assocElement->appendChild(toElement);

    ontologyElement->appendChild(assocElement);
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void initialiseDuplicateTypeOwnershipOntology()
  {
    _ontologyDocument = &(getDOMDocument());    

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
    ontologyElement->appendChild(chemistryDomainElement);
    ontologyElement->appendChild(spatialDomainElement);
    _ontologyDocument->getDocumentElement()->appendChild(ontologyElement);


    str = xercesc::XMLString::transcode("from");
    xercesc::DOMElement* fromElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Chemistry.Molecule");
    fromElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("1");
    fromElement->setAttribute(nameCh, valueCh);


    str = xercesc::XMLString::transcode("to");
    xercesc::DOMElement* toElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Chemistry.Bond");
    toElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("0..*");
    toElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("association");
    xercesc::DOMElement* assocElement = getDOMDocument().createElement(str);
    assocElement->appendChild(fromElement);
    assocElement->appendChild(toElement);


    ontologyElement->appendChild(assocElement);

    str = xercesc::XMLString::transcode("from");
    fromElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Chemistry.Bond");
    fromElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("1");
    fromElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("to");
    toElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Chemistry.Atom");
    toElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("2");
    toElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("association");
    assocElement = getDOMDocument().createElement(str);
    assocElement->appendChild(fromElement);
    assocElement->appendChild(toElement);

    ontologyElement->appendChild(assocElement);


    str = xercesc::XMLString::transcode("from");
    fromElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Chemistry.Molecule");
    fromElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("1");
    fromElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("to");
    toElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Chemistry.Atom");
    toElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("1..*");
    toElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("association");
    assocElement = getDOMDocument().createElement(str);
    assocElement->appendChild(fromElement);
    assocElement->appendChild(toElement);

    ontologyElement->appendChild(assocElement);


    str = xercesc::XMLString::transcode("from");
    fromElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Chemistry.Molecule");
    fromElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("1");
    fromElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("to");
    toElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Spatial.Vertex");
    toElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("1..*");
    toElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("association");
    assocElement = getDOMDocument().createElement(str);
    assocElement->appendChild(fromElement);
    assocElement->appendChild(toElement);

    ontologyElement->appendChild(assocElement);


    str = xercesc::XMLString::transcode("from");
    fromElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Spatial.Edge");
    fromElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("0..*");
    fromElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("to");
    toElement = getDOMDocument().createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Spatial.Vertex");
    toElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("2");
    toElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("association");
    assocElement = getDOMDocument().createElement(str);
    assocElement->appendChild(fromElement);
    assocElement->appendChild(toElement);

    ontologyElement->appendChild(assocElement);
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testCyclicTypeDependency()
  {
    bool result = false;
    initialiseCyclicTypeOntology();
    Ontology* ontology = 0;
    try {
      ontology = new Ontology(*_ontologyDocument);
      result = true;
    } catch (ontology::Exception& ex) {
      assertTrue("Successfully failed contruction from cyclic-type ontology.");
    }

    if (result) {
      delete ontology;
      fail("Incorrectly constructed from cyclic-type ontology");
    }
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testCyclicDomainDependency()
  {
    bool result = false;
    initialiseCyclicDomainOntology();
    Ontology* ontology = 0;
    try {
      ontology = new Ontology(*_ontologyDocument);
      result = true;
    } catch (ontology::Exception& ex) {
      assertTrue("Successfully failed contruction from cyclic-domain ontology.");
    }

    if (result) {
      delete ontology;
      fail("Incorrectly constructed from cyclic-domain ontology");
    }
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testDuplicateTypeOwnership()
  {
    bool result = false;
    initialiseDuplicateTypeOwnershipOntology();
    Ontology* ontology = 0;
    try {
      ontology = new Ontology(*_ontologyDocument);
      result = true;
    } catch (ontology::Exception& ex) {
      assertTrue("Successfully failed contruct from ontology containing duplicate-type ownership.");
    }

    if (result) {
      delete ontology;
      fail("Incorrectly constructed from duplicate-type ownership ontology");
    }
  }

  void testXdr()
  {
    {
      initialiseAcyclicOntology();
      Ontology ontology(*_ontologyDocument);
      iostream::XdrOutputStream ostream("testfile");
      ontology.encode(ostream);
      ostream.close();
    }

    {
      std::map <int, void*> addressMappings;
      iostream::XdrInputStream istream("testfile");
      Ontology decodedOntology(istream, addressMappings);
      istream.close();

      assertTrue(decodedOntology.getNumberDomains() == 2);
      assertTrue(decodedOntology.getNumberTypes() == 7);
      assertTrue(decodedOntology.getNumberAssociations() == 5);
      assertTrue(decodedOntology.getNumberGeneralisations() == 0);
      //assertTrue(decodedOntology.getNumberTypeDependencies() == 5);
      //assertTrue(decodedOntology.getNumberDomainDependencies() == 1);

      Domain* chemistryDomain = decodedOntology.getDomain("Chemistry");
      Domain* spatialDomain = decodedOntology.getDomain("Spatial");
      Domain* nonsenseDomain = decodedOntology.getDomain("Nonsense");    
      assertTrue(chemistryDomain != 0);
      assertTrue(spatialDomain != 0);
      assertTrue(nonsenseDomain == 0);

      std::string chemistry("Chemistry");
      std::string spatial("Spatial");
      std::string nonsense("nonsense");
      chemistryDomain = decodedOntology.getDomain(chemistry);
      spatialDomain = decodedOntology.getDomain(spatial);
      nonsenseDomain = decodedOntology.getDomain(nonsense);
      assertTrue(chemistryDomain != 0);
      assertTrue(spatialDomain != 0);
      assertTrue(nonsenseDomain == 0);

      Type* atomType = decodedOntology.getType("Chemistry.Atom");
      Type* bondType = decodedOntology.getType("Chemistry.Bond");
      Type* moleculeType = decodedOntology.getType("Chemistry.Molecule");
      Type* vertexType = decodedOntology.getType("Spatial.Vertex");
      Type* edgeType = decodedOntology.getType("Spatial.Edge");
      Type* faceType = decodedOntology.getType("Spatial.Face");
      Type* regionType = decodedOntology.getType("Spatial.Region");
      Type* nonsenseType = decodedOntology.getType("Spatial.Nonsense");

      assertTrue(atomType != 0);
      assertTrue(bondType != 0);
      assertTrue(moleculeType != 0);
      assertTrue(vertexType != 0);
      assertTrue(edgeType != 0);
      assertTrue(faceType != 0);
      assertTrue(regionType != 0);
      assertTrue(nonsenseType == 0);

      std::string atom("Chemistry.Atom");
      std::string bond("Chemistry.Bond");
      std::string molecule("Chemistry.Molecule");
      std::string vertex("Spatial.Vertex");
      std::string edge("Spatial.Edge");
      std::string face("Spatial.Face");
      std::string region("Spatial.Region");

      atomType = decodedOntology.getType(atom);
      bondType = decodedOntology.getType(bond);
      moleculeType = decodedOntology.getType(molecule);
      vertexType = decodedOntology.getType(vertex);
      edgeType = decodedOntology.getType(edge);
      faceType = decodedOntology.getType(face);
      regionType = decodedOntology.getType(region);
      nonsenseType = decodedOntology.getType(nonsense);

      assertTrue(decodedOntology.getDomain(*atomType) == chemistryDomain);
      assertTrue(decodedOntology.getDomain(*bondType) == chemistryDomain);
      assertTrue(decodedOntology.getDomain(*moleculeType) == chemistryDomain);
      assertTrue(decodedOntology.getDomain(*vertexType) == spatialDomain);
      assertTrue(decodedOntology.getDomain(*edgeType) == spatialDomain);
      assertTrue(decodedOntology.getDomain(*faceType) == spatialDomain);
      assertTrue(decodedOntology.getDomain(*regionType) == spatialDomain);
      assertTrue(nonsenseType == 0);

      /*
	assertTrue(decodedOntology.getDomainDependency(chemistry, spatial) != 0);
	assertTrue(decodedOntology.getDomainDependency(spatial, chemistry) == 0);
	assertTrue(decodedOntology.getDomainDependency(chemistry, chemistry) == 0);
	assertTrue(decodedOntology.getDomainDependency(spatial, spatial) == 0);
	assertTrue(decodedOntology.getDomainDependency(chemistry, nonsense) == 0);
	assertTrue(decodedOntology.getDomainDependency(nonsense, spatial) == 0);
	assertTrue(decodedOntology.getDomainDependency(spatial, nonsense) == 0);
	assertTrue(decodedOntology.getDomainDependency(nonsense, chemistry) == 0);
	assertTrue(decodedOntology.getDomainDependency(nonsense, nonsense) == 0);

	DomainDependency* domainDep = decodedOntology.getDependency(*chemistryDomain, *spatialDomain);
	assertTrue(domainDep != 0);

	domainDep = decodedOntology.getDependency(*spatialDomain, *chemistryDomain);
	assertTrue(domainDep == 0);

	TypeDependency* typeDep = decodedOntology.getDependency(*moleculeType, *atomType);

	typeDep = decodedOntology.getDependency(*moleculeType, *bondType);
	assertTrue(typeDep != 0);

	typeDep = decodedOntology.getDependency(*bondType, *atomType);
	assertTrue(typeDep != 0);

	typeDep = decodedOntology.getDependency(*atomType, *bondType);
	assertTrue(typeDep == 0);

	typeDep = decodedOntology.getDependency(*atomType, *moleculeType);
	assertTrue(typeDep == 0);

	typeDep = decodedOntology.getDependency(*moleculeType, *vertexType);
	assertTrue(typeDep != 0);

	typeDep = decodedOntology.getDependency(*regionType, *faceType);
	assertTrue(typeDep == 0);

	typeDep = decodedOntology.getDependency(*faceType, *edgeType);
	assertTrue(typeDep == 0);

	typeDep = decodedOntology.getDependency(*edgeType, *vertexType);
	assertTrue(typeDep != 0);

	typeDep = decodedOntology.getDependency(*faceType, *regionType);
	assertTrue(typeDep == 0);

	typeDep = decodedOntology.getDependency(*edgeType, *faceType);
	assertTrue(typeDep == 0);

	typeDep = decodedOntology.getDependency(*vertexType, *edgeType);
	assertTrue(typeDep == 0);


	typeDep = decodedOntology.getTypeDependency(bond, atom);
	assertTrue(typeDep != 0);
	assertTrue(&(typeDep->getFromType()) == bondType);
	assertTrue(&(typeDep->getToType()) == atomType);

	typeDep = decodedOntology.getTypeDependency(molecule, atom);
	assertTrue(typeDep != 0);
	assertTrue(&(typeDep->getFromType()) == moleculeType);
	assertTrue(&(typeDep->getToType()) == atomType);

	typeDep = decodedOntology.getTypeDependency(molecule, bond);
	assertTrue(typeDep != 0);
	assertTrue(&(typeDep->getFromType()) == moleculeType);
	assertTrue(&(typeDep->getToType()) == bondType);

	typeDep = decodedOntology.getTypeDependency(atom, bond);
	assertTrue(typeDep == 0);

	typeDep = decodedOntology.getTypeDependency(region, face);
	assertTrue(typeDep == 0);

	typeDep = decodedOntology.getTypeDependency(face, edge);
	assertTrue(typeDep == 0);

	typeDep = decodedOntology.getTypeDependency(edge, vertex);
	assertTrue(typeDep != 0);
	assertTrue(&(typeDep->getFromType()) == edgeType);
	assertTrue(&(typeDep->getToType()) == vertexType);

	typeDep = decodedOntology.getTypeDependency(face, region);
	assertTrue(typeDep == 0);

	typeDep = decodedOntology.getTypeDependency(edge, face);
	assertTrue(typeDep == 0);

	typeDep = decodedOntology.getTypeDependency(vertex, edge);
	assertTrue(typeDep == 0);

	decodedOntology.getDomains();

	decodedOntology.getTypes();

	decodedOntology.getAssociations();

	decodedOntology.getGeneralisations();

	decodedOntology.getTypeDependencies();

	decodedOntology.getDomainDependencies();
      */
    }
    
    remove("testfile");
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
  OntologyTest(const OntologyTest& ontologyTest);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  OntologyTest& operator=(const OntologyTest& ontologyTest);

};


}


}


#endif // PROTOLAYER_ONTOLOGY_ONTOLOGYTEST_H
