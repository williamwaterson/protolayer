#include "Application.h"


namespace protolayer
{ 

namespace proto
{

Application::Application()
{
  Project* project = new Project();
  _projects.insert(project);
}


Application::~Application()
{
}


}


}
