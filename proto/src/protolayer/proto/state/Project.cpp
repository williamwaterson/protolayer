#include "Project.h"


namespace protolayer
{

namespace proto
{

Project::Project()
{
  /** TODO: Documenation */
  xercesc::DOMElement* _ontologyElement;

  /** TODO: Documenation */
  xercesc::DOMElement* _chemistryDomainElement;

  /** TODO: Documenation */
  xercesc::DOMElement* _spatialDomainElement;

  /** TODO: Documenation */
  ontologydto::DomainDTO* _chemistryDomainDTO;

  /** TODO: Documenation */
  ontologydto::DomainDTO* _spatialDomainDTO;

  /** TODO: Documenation */
  std::set <ontologydto::DomainDTO*> _domainDTOs;

  /** TODO: Documentation */
  xercesc::DOMImplementation* _implementation;

  /** TODO: Documentation */
  xercesc::DOMDocument* _document;

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


    str = xercesc::XMLString::transcode("ontology");
    XMLCh* nameCh = xercesc::XMLString::transcode("name");
    XMLCh* valueCh = xercesc::XMLString::transcode("Chemistry");
    //    _chemistryDomainElement->setAttribute(nameCh, valueCh);

    _ontologyElement = _document->createElement(str);    
    _document->getDocumentElement()->appendChild(_ontologyElement);

    str = xercesc::XMLString::transcode("domain");
    _chemistryDomainElement = _document->createElement(str);
    _spatialDomainElement = _document->createElement(str);

    //    _spatialDomainElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("type");

    xercesc::DOMElement* typeElement = _document->createElement(str);
    nameCh = xercesc::XMLString::transcode("name");
    valueCh = xercesc::XMLString::transcode("Molecule");
    typeElement->setAttribute(nameCh, valueCh);
    nameCh = xercesc::XMLString::transcode("id");
    valueCh = xercesc::XMLString::transcode("1");
    typeElement->setAttribute(nameCh, valueCh);
    _chemistryDomainElement->appendChild(typeElement);

    typeElement = _document->createElement(str);
    nameCh = xercesc::XMLString::transcode("name");
    valueCh = xercesc::XMLString::transcode("Atom");
    typeElement->setAttribute(nameCh, valueCh);
    nameCh = xercesc::XMLString::transcode("id");
    valueCh = xercesc::XMLString::transcode("2");
    typeElement->setAttribute(nameCh, valueCh);
    _chemistryDomainElement->appendChild(typeElement);    

    typeElement = _document->createElement(str);
    nameCh = xercesc::XMLString::transcode("name");
    valueCh = xercesc::XMLString::transcode("Bond");
    typeElement->setAttribute(nameCh, valueCh);
    nameCh = xercesc::XMLString::transcode("id");
    valueCh = xercesc::XMLString::transcode("3");
    typeElement->setAttribute(nameCh, valueCh);
    _chemistryDomainElement->appendChild(typeElement);


    typeElement = _document->createElement(str);
    nameCh = xercesc::XMLString::transcode("name");
    valueCh = xercesc::XMLString::transcode("Vertex");
    typeElement->setAttribute(nameCh, valueCh);
    nameCh = xercesc::XMLString::transcode("id");
    valueCh = xercesc::XMLString::transcode("4");
    typeElement->setAttribute(nameCh, valueCh);
    _spatialDomainElement->appendChild(typeElement);    

    typeElement = _document->createElement(str);
    nameCh = xercesc::XMLString::transcode("name");
    valueCh = xercesc::XMLString::transcode("Edge");
    typeElement->setAttribute(nameCh, valueCh);
    nameCh = xercesc::XMLString::transcode("id");
    valueCh = xercesc::XMLString::transcode("5");
    typeElement->setAttribute(nameCh, valueCh);
    _spatialDomainElement->appendChild(typeElement);

    typeElement = _document->createElement(str);
    nameCh = xercesc::XMLString::transcode("name");
    valueCh = xercesc::XMLString::transcode("Face");
    typeElement->setAttribute(nameCh, valueCh);
    nameCh = xercesc::XMLString::transcode("id");
    valueCh = xercesc::XMLString::transcode("6");
    typeElement->setAttribute(nameCh, valueCh);
    _spatialDomainElement->appendChild(typeElement);    

    typeElement = _document->createElement(str);
    nameCh = xercesc::XMLString::transcode("name");
    valueCh = xercesc::XMLString::transcode("Region");
    typeElement->setAttribute(nameCh, valueCh);
    nameCh = xercesc::XMLString::transcode("id");
    valueCh = xercesc::XMLString::transcode("7");
    typeElement->setAttribute(nameCh, valueCh);
    _spatialDomainElement->appendChild(typeElement);    


    str = xercesc::XMLString::transcode("from");
    xercesc::DOMElement* fromElement = _document->createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Molecule");
    fromElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("typeId");
    valueCh = xercesc::XMLString::transcode("1");
    fromElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("1");
    fromElement->setAttribute(nameCh, valueCh);


    str = xercesc::XMLString::transcode("to");
    xercesc::DOMElement* toElement = _document->createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Bond");
    toElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("typeId");
    valueCh = xercesc::XMLString::transcode("3");
    toElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("0..*");
    toElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("association");
    xercesc::DOMElement* assocElement = _document->createElement(str);
    assocElement->appendChild(fromElement);
    assocElement->appendChild(toElement);

    _chemistryDomainElement->appendChild(assocElement);
    //    _ontologyElement->appendChild(assocElement);

    str = xercesc::XMLString::transcode("from");
    fromElement = _document->createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Bond");
    fromElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("typeId");
    valueCh = xercesc::XMLString::transcode("3");
    fromElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("0..*");
    fromElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("to");
    toElement = _document->createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Atom");
    toElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("typeId");
    valueCh = xercesc::XMLString::transcode("2");
    toElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("2");
    toElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("association");
    assocElement = _document->createElement(str);
    assocElement->appendChild(fromElement);
    assocElement->appendChild(toElement);

    _chemistryDomainElement->appendChild(assocElement);


    str = xercesc::XMLString::transcode("from");
    fromElement = _document->createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Molecule");
    fromElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("typeId");
    valueCh = xercesc::XMLString::transcode("1");
    fromElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("1");
    fromElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("to");
    toElement = _document->createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Atom");
    toElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("typeId");
    valueCh = xercesc::XMLString::transcode("2");
    toElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("1..*");
    toElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("association");
    assocElement = _document->createElement(str);
    assocElement->appendChild(fromElement);
    assocElement->appendChild(toElement);

    _chemistryDomainElement->appendChild(assocElement);


    str = xercesc::XMLString::transcode("from");
    fromElement = _document->createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Molecule");
    fromElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("typeId");
    valueCh = xercesc::XMLString::transcode("1");
    fromElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("1");
    fromElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("to");
    toElement = _document->createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Vertex");
    toElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("typeId");
    valueCh = xercesc::XMLString::transcode("4");
    toElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("1..*");
    toElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("association");
    assocElement = _document->createElement(str);
    assocElement->appendChild(fromElement);
    assocElement->appendChild(toElement);

    _spatialDomainElement->appendChild(assocElement);


    str = xercesc::XMLString::transcode("from");
    fromElement = _document->createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Edge");
    fromElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("typeId");
    valueCh = xercesc::XMLString::transcode("5");
    fromElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("0..*");
    fromElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("to");
    toElement = _document->createElement(str);

    nameCh = xercesc::XMLString::transcode("type");
    valueCh = xercesc::XMLString::transcode("Vertex");
    toElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("typeId");
    valueCh = xercesc::XMLString::transcode("4");
    toElement->setAttribute(nameCh, valueCh);

    nameCh = xercesc::XMLString::transcode("multiplicity");
    valueCh = xercesc::XMLString::transcode("2");
    toElement->setAttribute(nameCh, valueCh);

    str = xercesc::XMLString::transcode("association");
    assocElement = _document->createElement(str);
    assocElement->appendChild(fromElement);
    assocElement->appendChild(toElement);

    _spatialDomainElement->appendChild(assocElement);


    _ontologyElement->appendChild(_chemistryDomainElement);
    _chemistryDomainDTO = new ontologydto::DomainDTO(*_document);
    _chemistryDomainDTO->getTitle() = "Chemistry";
    _chemistryDomainDTO->getId() = 1;
    _ontologyElement->removeChild(_chemistryDomainElement);

    _ontologyElement->appendChild(_spatialDomainElement);
    _spatialDomainDTO = new ontologydto::DomainDTO(*_document);
    _spatialDomainDTO->getTitle() = "Spatial";
    _spatialDomainDTO->getId() = 2;
    _ontologyElement->removeChild(_spatialDomainElement);

    _document->getDocumentElement()->removeChild(_ontologyElement);

    _domainDTOs.clear();
    _domainDTOs.insert(_chemistryDomainDTO);
    _domainDTOs.insert(_spatialDomainDTO);

    ontology::Ontology* _ontology;
    _ontology = new ontology::Ontology(_domainDTOs);
    _assembly = new assembly::Assembly(*_ontology);
}


Project::~Project()
{
  delete _assembly;
}


assembly::Assembly& Project::getAssembly()
{
  return *_assembly;
}


}


}
