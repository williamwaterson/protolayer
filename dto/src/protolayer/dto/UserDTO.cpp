#include "UserDTO.h"


namespace protolayer
{

namespace dto
{

namespace
{
  const std::string typeName("User");
}


const std::string& UserDTO::getClassName()
{
  return typeName;
}


UserDTO::UserDTO()
{
  _id = 0;
}


UserDTO::UserDTO(protolayer::iostream::XdrInputStream& stream)
{
  stream.read(_id);
  stream.read(_username);
  stream.read(_password);
  stream.read(_email);
}


UserDTO::~UserDTO()
{
}


void UserDTO::encode(protolayer::iostream::XdrOutputStream& stream)
{
  stream.write(_id);
  stream.write(_username);
  stream.write(_password);
  stream.write(_email);
}


int& UserDTO::getId()
{
  return _id;
}


std::string& UserDTO::getUserName()
{
  return _username;
}


std::string& UserDTO::getUsername()
{
  return _username;
}


std::string& UserDTO::getPassword()
{
  return _password;
}


std::string& UserDTO::getEmail()
{
  return _email;
}


}


}
