#include "TechniqueRecord.h"


namespace protolayer
{

namespace nameservice
{

TechniqueRecord::TechniqueRecord() throw (Exception)
{
}


TechniqueRecord::TechniqueRecord(iostream::XdrInputStream& istream)
  throw (Exception) : Record(istream)
{
  istream.read(_implementedConceptUrn);
}


void TechniqueRecord::encode(iostream::XdrOutputStream& ostream)
{
  Record::encode(ostream);
  ostream.write(_implementedConceptUrn);
}


void TechniqueRecord::setImplementedConceptUrn(const std::string& conceptUrn)
{
  _implementedConceptUrn = conceptUrn;
}


std::string& TechniqueRecord::getImplementedConceptUrn()
{
  return _implementedConceptUrn;
}


const std::string& TechniqueRecord::getImplementedConceptUrn() const
{
  return _implementedConceptUrn;
}


}


}
