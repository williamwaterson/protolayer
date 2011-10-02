#include "Record.h"


namespace protolayer
{

namespace nameservice
{

Record::Record() throw (Exception)
{
}


Record::Record(iostream::XdrInputStream& istream)
   throw (Exception)
{
  istream.read(_description);

  int numberOf = 0;
  std::string keyword;

  istream.read(numberOf);
  for (int i = 0; i < numberOf; i++) {
    istream.read(keyword);
    _keywords.insert(keyword);
  }
}


Record::~Record()
{
}


void Record::encode(iostream::XdrOutputStream& ostream)
{
  ostream.write(_description);

  ostream.write((int) _keywords.size());
  for (std::set <std::string>::iterator iter = _keywords.begin(); iter != _keywords.end(); iter++) {
    ostream.write(*iter);
  }
}


void Record::setDescription(const std::string& description)
{
  _description = description;
}


std::string& Record::getDescription()
{
  return _description;
}


const std::string& Record::getDescription() const
{
  return _description;
}


void Record::setKeywords(const std::set <std::string>& keywords)
{
  _keywords = keywords;
}


std::set <std::string>& Record::getKeywords()
{
  return _keywords;
}


const std::set <std::string>& Record::getKeywords() const
{
  return _keywords;
}


}


}
