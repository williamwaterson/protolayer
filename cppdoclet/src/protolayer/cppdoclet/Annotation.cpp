#include "Annotation.h"


namespace protolayer
{

namespace cppdoclet
{

Annotation::Annotation(const std::string& signature)
{
  /*
  // Erase stars
  std::string temp;
  for (std::size_t position = 0; position < signature.length(); position++) {
    char ch = signature.at(position);
    if (ch != '*') {
      temp += ch;
    }
  }

  // Erase spaces
  std::string token;
  std::size_t position = 0;
  while (position != std::string::npos) {
    position = util::next(temp, position, token);
    _signature = token + " ";
  }
  */

  _signature = util::trim(signature);
  _name = _signature;
}


const std::string& Annotation::getName() const
{
  return _name;
}


void Annotation::serialise(std::string& buffer)
{
}


}


}
