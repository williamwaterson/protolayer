#include "End.h"


namespace protolayer
{

namespace ontology
{

namespace
{

bool isDigit(char value) {

  return (value == '1' || value == '2' ||
          value == '3' || value == '4' ||
          value == '5' || value == '6' ||
          value == '7' || value == '8' ||
          value == '9' || value == '0');
}


bool isInteger(std::string& value) {
  bool result = true;
  for (unsigned int i = 0; i < value.length(); i++) {
    if (!isDigit(value[i])) {
      result = false;
    }
  }
  return result;
}


bool isDot(char value) {
  return value == '.';
}


bool isStar(char value) {
  return value == '*';
}


bool isStar(std::string& value) {
  return (value.length() == 1) && (isStar(value[0]));
}


bool isSpace(char value) {
  return value == ' ';
}


bool isDigitDotStar(char value) {
  return isStar(value) || isDot(value) || isDigit(value);
}


bool isDigitStar(char value) {
  return isStar(value) || isDigit(value);
}


int countDoubleDot(std::string& value) {

  int count = 0;
  for (unsigned int i = 0; i < value.length(); i++) {
    unsigned int pos = value.find("..", i);
    if (pos == std::string::npos) {
      i = value.length();
    } else {
      count += 1;
      i = pos + 1;
    }
  }

  return count;
}


}


void End::handleSingleChar(std::string& multiplicity)
  throw (Exception)
{
  char value = multiplicity[0];
  if (isStar(value)) {
    _lowerBound = 0;
    _upperBound = UNBOUNDED;
  } else if (isDigit(value)) {
    _lowerBound = atoi(multiplicity.c_str());
    _upperBound = _lowerBound;
  } else {
    throw Exception("Invalid character in multiplicity value.");
  }  
}


void End::handleWithoutDoubleDot(std::string& multiplicity)
  throw (Exception)
{
  if (multiplicity.length() == 1) {
    handleSingleChar(multiplicity);
  } else if (isInteger(multiplicity)) {
    _lowerBound = atoi(multiplicity.c_str());
    _upperBound = _lowerBound;
  } else {
    throw Exception("Invalid character in multiplicity value.");
  }
}


void End::handleWithDoubleDot(std::string& multiplicity)
  throw (Exception)
{
  std::string::size_type pos = multiplicity.find ("..");
  if (pos == 0 || pos == std::string::npos) {
    throw Exception("Malformed multiplicity value.");
  }

  std::string lower = multiplicity.substr(0, pos - 0);
  if (isInteger(lower)) {
    _lowerBound = atoi(lower.c_str());
  } else {
    throw Exception("Malformed multiplicity value.");
  }

  pos += 2;
  if (pos >= multiplicity.length()) {
    throw Exception("Malformed multiplicity value.");
  }

  std::string upper = multiplicity.substr(pos);
  if (isStar(upper)) {
    _upperBound = UNBOUNDED;
  } else if (isInteger(upper)) {
    _upperBound = atoi(upper.c_str());
  } else {
    throw Exception("Malformed multiplicity value.");
  }
}


void End::checkBounds()
  throw (Exception)
{
  if (_lowerBound < 0) {
    throw Exception("Negative lower bound is unacceptable.");
  }

  if (_lowerBound > _upperBound && _upperBound != UNBOUNDED) {
    throw Exception("Lower bound cannot exceed upperbound");
  }

}


/** TODO: Improve with better handling of zero id */
End::End(ontologydto::EndDTO& endDto,
	 std::map <int, Type*>& typeDictionary)
{
  _id = endDto._id;
  _conceptId = endDto._conceptId;
  _domainId = endDto._domainId;

  int typeId = endDto.getConceptId();
  if (typeDictionary.count(typeId) == 1) {
    _type = typeDictionary[typeId];
  } else {
    throw Exception("Nonexistent Concept ID for Association End.");
  }

  std::string multiplicity = endDto.getMultiplicity();

  int count = countDoubleDot(multiplicity);
  if (count == 0) {
    handleWithoutDoubleDot(multiplicity);
  } else if (count == 1) {
    handleWithDoubleDot(multiplicity);
  } else {
    throw Exception("Malformed multiplicity value.");
  }

  checkBounds();
}


int End::getId() const
{
  return _id;
}


int End::getConceptId() const
{
  return _conceptId;
}


int End::getDomainId() const
{
  return _domainId;
}


int End::getLowerBound() const {
  return _lowerBound;
}


int End::getUpperBound() const {
  return _upperBound;
}


//const std::string& End::getName() const
//{
//  return _name;
//}


Type& End::getType()
{
  return *_type;
}


bool End::isType(Type& type)
{
  return _type == &type;
}


End::~End()
{
}


}


}
