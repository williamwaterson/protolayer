#include "TechniqueDTO.h"


namespace protolayer
{

namespace dto
{

namespace
{
  const std::string typeName("Technique");
}


const std::string& TechniqueDTO::getClassName()
{
  return typeName;
}


TechniqueDTO::TechniqueDTO()
{
  _id = 0;
  _conceptId = 0;
}


TechniqueDTO::TechniqueDTO(protolayer::iostream::XdrInputStream& stream)
{
  stream.read(_id);
  stream.read(_title);
  stream.read(_conceptId);
}


TechniqueDTO::~TechniqueDTO()
{
}


void TechniqueDTO::encode(protolayer::iostream::XdrOutputStream& stream)
{
  stream.write(_id);
  stream.write(_title);
  stream.write(_conceptId);
}


int& TechniqueDTO::getId()
{
  return _id;
}


std::string& TechniqueDTO::getDescription()
{
  return _description;
}


std::string& TechniqueDTO::getTitle()
{
  return _title;
}


int& TechniqueDTO::getConceptId()
{
  return _conceptId;
}


}


}
