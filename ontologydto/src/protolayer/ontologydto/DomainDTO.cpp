#include "DomainDTO.h"


namespace protolayer
{

namespace ontologydto
{

namespace
{

pooling::Pool pool(10000);

}


void* DomainDTO::operator new(size_t numberBytes)
{
  return pool.acquire(numberBytes);
}


void DomainDTO::operator delete(void* object)
{
  pool.release(object);
}


void DomainDTO::initialise(xercesc::DOMElement& element)
  throw (Exception)
{
  // need to assert its a "domain" named element

  _description = xml::extractAttribute("description", element, "No Description");

  // Use short cut for getting 

  const XMLCh* typeCh = xercesc::XMLString::transcode("type");
  xercesc::DOMNodeList* elements = element.getElementsByTagName(typeCh);
  for (int i = 0; i < elements->getLength(); ++i) {
    xercesc::DOMNode* node = elements->item(i);
    xercesc::DOMElement* childElement = dynamic_cast < xercesc::DOMElement* > (node);
    TypeDTO* type = new TypeDTO(*childElement);
    _types.insert(type);
  }

  const XMLCh* assocCh = xercesc::XMLString::transcode("association");
  elements = element.getElementsByTagName(assocCh);
  for (int i = 0; i < elements->getLength(); ++i) {
    xercesc::DOMNode* node = elements->item(i);
    xercesc::DOMElement* childElement = dynamic_cast <xercesc::DOMElement*> (node);
    AssociationDTO* association = new AssociationDTO(*childElement);
    _associations.insert(association);
  }

  const XMLCh* genCh = xercesc::XMLString::transcode("generalisation");
  elements = element.getElementsByTagName(genCh);
  for (int i = 0; i < elements->getLength(); ++i) {
    xercesc::DOMNode* node = elements->item(i);
    xercesc::DOMElement* childElement = dynamic_cast <xercesc::DOMElement*> (node);
    GeneralisationDTO* generalisation = new GeneralisationDTO(*childElement);
    _generalisations.insert(generalisation);
  }
}


DomainDTO::DomainDTO() throw (Exception)
{
  _id = 0;
}


DomainDTO::DomainDTO(const std::string& title) :
  _title(title)
{
  _id = 0;
}


DomainDTO::DomainDTO(xercesc::DOMDocument& document)
  throw (Exception)
{
  _id = 0;

  const XMLCh* domainCh = xercesc::XMLString::transcode("domain");
  xercesc::DOMNodeList* elements = document.getElementsByTagName(domainCh);

  if (elements->getLength() == 0) {
    throw Exception("Supplied XML document does not contain a domain element");
  }

  if (elements->getLength() > 1) {
    throw Exception("Supplied XML document must contain only one domain");
  }

  xercesc::DOMNode* node = elements->item(0);
  xercesc::DOMElement* element = dynamic_cast <xercesc::DOMElement*> (node);
  initialise(*element);
}


DomainDTO::DomainDTO(iostream::XdrInputStream& stream)
{
  stream.read(_id);
  stream.read(_title);
  stream.read(_description);

  int numberOf = 0;

  stream.read(numberOf);
  for (int i = 0; i < numberOf; ++i) {
    TypeDTO* type = new TypeDTO(stream);
    _types.insert(type);
  }

  stream.read(numberOf);
  for (int i = 0; i < numberOf; ++i) {
    AssociationDTO* association = new AssociationDTO(stream);
    _associations.insert(association);
  }

  stream.read(numberOf);
  for (int i = 0; i < numberOf; ++i) {
    GeneralisationDTO* generalisation = new GeneralisationDTO(stream);
    _generalisations.insert(generalisation);
  }
}


DomainDTO::~DomainDTO()
{
  for (std::set <TypeDTO*>::iterator iter = _types.begin(); iter != _types.end(); iter++) {
    delete (*iter);
  }

  for (std::set <AssociationDTO*>::iterator iter = _associations.begin(); iter != _associations.end(); iter++) {
    delete (*iter);
  }

  for (std::set <GeneralisationDTO*>::iterator iter = _generalisations.begin(); iter != _generalisations.end(); iter++) {
    delete (*iter);
  }
}


void DomainDTO::encode(iostream::XdrOutputStream& stream)
{
  stream.write(_id);
  stream.write(_title);
  stream.write(_description);

  stream.write((int) _types.size());
  for (std::set <TypeDTO*>::iterator iter = _types.begin(); iter != _types.end(); iter++) {
    (*iter)->encode(stream);
  }

  stream.write((int) _associations.size());
  for (std::set <AssociationDTO*>::iterator iter = _associations.begin(); iter != _associations.end(); iter++) {
    (*iter)->encode(stream);
  }

  stream.write((int) _generalisations.size());
  for (std::set <GeneralisationDTO*>::iterator iter = _generalisations.begin(); iter != _generalisations.end(); iter++) {
    (*iter)->encode(stream);
  }
}


void DomainDTO::clear()
{
  _id = 0;
  _title.clear();
  _description.clear();

  for (std::set <TypeDTO*>::iterator iter = _types.begin(); iter != _types.end(); iter++) {
    delete (*iter);
  }
  _types.clear();

  for (std::set <AssociationDTO*>::iterator iter = _associations.begin(); iter != _associations.end(); iter++) {
    delete (*iter);
  }
  _associations.clear();

  for (std::set <GeneralisationDTO*>::iterator iter = _generalisations.begin(); iter != _generalisations.end(); iter++) {
    delete (*iter);
  }
  _generalisations.clear();  
}


void DomainDTO::decode(iostream::XdrInputStream& stream)
{
  clear();

  stream.read(_id);
  stream.read(_title);
  stream.read(_description);

  int numberOf = 0;

  stream.read(numberOf);
  for (int i = 0; i < numberOf; ++i) {
    TypeDTO* type = new TypeDTO(stream);
    _types.insert(type);
  }

  stream.read(numberOf);
  for (int i = 0; i < numberOf; ++i) {
    AssociationDTO* association = new AssociationDTO(stream);
    _associations.insert(association);
  }

  stream.read(numberOf);
  for (int i = 0; i < numberOf; ++i) {
    GeneralisationDTO* generalisation = new GeneralisationDTO(stream);
    _generalisations.insert(generalisation);
  }
}


int& DomainDTO::getId()
{
  return _id;
}


std::string& DomainDTO::getTitle()
{
  return _title;
}


std::string& DomainDTO::getDescription()
{
  return _description;
}


std::set <TypeDTO*>& DomainDTO::getTypes()
{
  return _types;
}


std::set <AssociationDTO*>& DomainDTO::getAssociations()
{
  return _associations;
}


std::set <GeneralisationDTO*>& DomainDTO::getGeneralisations()
{
  return _generalisations;
}


}


}
