#include "Documentation.h"


namespace protolayer
{

namespace cppdoclet
{

Documentation::Documentation(const std::string& signature)
{
  _signature = util::trim(signature);

  std::size_t position = _signature.find("@", position);
  _description = _signature.substr(0, position);

  std::size_t next;

  std::string token;
  std::string buffer = _signature;
  position = 0;
  while (position != std::string::npos) {
    position = util::next(_signature, position, token);
    if (util::beginsWith(token, "@")) {
      Annotation* annotation = new Annotation(token);
      _annotations.insert(annotation);
    }
  }
}


void Documentation::serialise(std::string& output, const std::string& componentName)
{
  output += _signature + "\n*/\n";
}


std::set <Annotation*>& Documentation::getAnnotations()
{
  return _annotations;
}


bool Documentation::containsAnnotation(const std::string& name)
{
  bool flag = false;
  
  typedef std::set <Annotation*>::iterator IterType;
  for (IterType iter = _annotations.begin(); iter != _annotations.end(); iter++) {
    if ((*iter)->getName() == name) {
      flag = true;
    }
  }

  return flag;
}


}


}
