#include "RemoteDoclet.h"


namespace protolayer
{

namespace cppdoclet
{

namespace
{

std::string REMOTE = "@remote";

}


RemoteDoclet::RemoteDoclet(Dependencies& dependencies) :
  _component(dependencies.getTargetComponent())
{
  if (!_component.containsAnnotation(REMOTE)) {
    std::cout << "No match for annotation @remote. Skipping..." << std::endl;
    return;
  }

  if (_component.containsAttributeAnnotation(REMOTE)) {
    throw "@remote annotations are prohibited for attributes";
  }

  generateClient(_component.getTree());
  generateService(_component.getTree());
}


void RemoteDoclet::generateClient(Namespace& instance)
{
}

void RemoteDoclet::generateClient(Component& component)
{
}


void RemoteDoclet::generateClient(Class& instance)
{
}


void RemoteDoclet::generateClient(Method& method)
{
  if (method.isConstructor()) {
    return;
  }

  if (method.isDestructor()) {
    return;
  }

  if (method.isAbstract()) {
    return;
  }
}


void RemoteDoclet::generateService(Component& component)
{
}


void RemoteDoclet::generateService(Namespace& instance)
{
}


void RemoteDoclet::generateService(Class& instance)
{
}


void RemoteDoclet::generateService(Method& method)
{
}


}


}
