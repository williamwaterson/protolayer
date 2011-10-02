#include "Step.h"


namespace protolayer
{ 

namespace workflow
{

Step::Step(const std::string& text,
	   const std::string& description,
	   const std::string& tip)
{
  _text = text;
  _description = description;
  _tip = tip;
}


Step::~Step()
{
}


void Step::doit()
{
  _locked = true;

  typedef std::vector <Action*>::iterator IterType;
  for (IterType iter = _actions.begin(); iter != _actions.end(); iter++) {
    (*iter)->doit();
  }
}


void Step::undo()
{
  typedef std::vector <Action*>::reverse_iterator IterType;
  for (IterType iter = _actions.rbegin(); iter != _actions.rend(); iter++) {
    (*iter)->undo();
  }
}


void Step::append(Action& action)
{
  if (!_locked) {
    _actions.push_back(&action);
  }
}


const std::string& Step::getText() const
{
  return _text;
}


const std::string& Step::getDescription() const
{
  return _description;
}


const std::string& Step::getTip() const
{
  return _tip;
}


}


}
