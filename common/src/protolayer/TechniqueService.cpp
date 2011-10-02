#include "TechniqueService.h"


namespace protolayer
{

TechniqueService::TechniqueService(const std::string& urn) :
  _urn(urn)
{
}


TechniqueService::~TechniqueService()
{
}


const std::string& TechniqueService::getUrn() const
{
  return _urn;
}

/*
bool TechniqueService::checkValue(const std::string& name,
				  bool value)
{
  return true;
}


bool TechniqueService::checkValue(const std::string& name,
                           short value)
{
  return true;
}


bool TechniqueService::checkValue(const std::string& name,
                           int value)
{
  return true;
}


bool TechniqueService::checkValue(const std::string& name,
                           long value)
{
  return true;
}


bool TechniqueService::checkValue(const std::string& name,
                           float value)
{
  return true;
}


bool TechniqueService::checkValue(const std::string& name,
                           double value)
{
  return true;
}


bool TechniqueService::checkValue(const std::string& name,
				  const std::string& value)
{
  return true;
}
*/

}
