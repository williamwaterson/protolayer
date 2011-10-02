#include "XdrInputStream.h"


namespace protolayer
{

void decode(iostream::XdrInputStream& stream, bool& value)
{
  stream.read(value);  
}


void decode(iostream::XdrInputStream& stream, char& value)
{
  stream.read(value);  
}


void decode(iostream::XdrInputStream& stream, short& value)
{
  stream.read(value);  
}


void decode(iostream::XdrInputStream& stream, int& value)
{
  stream.read(value);  
}


void decode(iostream::XdrInputStream& stream, long& value)
{
  stream.read(value);  
}


void decode(iostream::XdrInputStream& stream, float& value)
{
  stream.read(value);  
}


void decode(iostream::XdrInputStream& stream, double& value)
{
  stream.read(value);
}


void decode(iostream::XdrInputStream& stream, std::string& value)
{
  stream.read(value);  
}


namespace iostream
{

void XdrInputStream::read(std::set <bool>& collection)
{
  int numberOf = 0;
  read(numberOf);

  bool value;
  for (int i = 0; i < numberOf; ++i) {
    read(value);
    collection.insert(value);
  }
}


void XdrInputStream::read(std::set <char>& collection)
{
  int numberOf = 0;
  read(numberOf);

  char value;
  for (int i = 0; i < numberOf; ++i) {
    read(value);
    collection.insert(value);
  }
}


void XdrInputStream::read(std::set <short>& collection)
{
  int numberOf = 0;
  read(numberOf);

  short value;
  for (int i = 0; i < numberOf; ++i) {
    read(value);
    collection.insert(value);
  }
}


void XdrInputStream::read(std::set <int>& collection)
{
  int numberOf = 0;
  read(numberOf);

  int value;
  for (int i = 0; i < numberOf; ++i) {
    read(value);
    collection.insert(value);
  }
}


void XdrInputStream::read(std::set <long>& collection)
{
  int numberOf = 0;
  read(numberOf);

  long value;
  for (int i = 0; i < numberOf; ++i) {
    read(value);
    collection.insert(value);
  }
}


void XdrInputStream::read(std::set <float>& collection)
{
  int numberOf = 0;
  read(numberOf);

  float value;
  for (int i = 0; i < numberOf; ++i) {
    read(value);
    collection.insert(value);
  }
}


void XdrInputStream::read(std::set <double>& collection)
{
  int numberOf = 0;
  read(numberOf);

  double value;
  for (int i = 0; i < numberOf; ++i) {
    read(value);
    collection.insert(value);
  }
}


void XdrInputStream::read(std::set <std::string>& collection)
{
  int numberOf = 0;
  read(numberOf);

  std::string value;
  for (int i = 0; i < numberOf; ++i) {
    read(value);
    collection.insert(value);
  }
}


XdrInputStream::XdrInputStream(int socketFd)
  throw (Exception)
{
  _file = fdopen(socketFd, "r");
  if (_file == NULL) {
    logger::Logger::getSingleton().debug("Iostream", strerror(errno));
    throw Exception(strerror(errno));
  }

  xdrstdio_create(&_xdr, _file, XDR_DECODE);
}


XdrInputStream::XdrInputStream(char* fileName)
  throw (Exception)
{
  _file = fopen(fileName, "r");
  if (_file == NULL) {
    logger::Logger::getSingleton().debug("Iostream", strerror(errno));
    throw Exception(strerror(errno));
  }

  xdrstdio_create(&_xdr, _file, XDR_DECODE);
}


XdrInputStream::~XdrInputStream()
{
  // xdr_destroy(&_xdr);
  // try {
  // fclose(_file);
  //} catch (Exception& ex) {
  //  // Ignore failure during destruction
  //}

  //  if ((&_xdr)->x_ops) {
  //    if ((&_xdr)->x_ops->x_destroy) {
  //      (*(&_xdr)->x_ops->x_destroy)();
  //    }
  //  }
}


void XdrInputStream::close()
  throw (Exception)
{
  if (fclose(_file) != 0) {
    logger::Logger::getSingleton().debug("Iostream", strerror(errno));
    throw Exception(strerror(errno));
  }
}

void XdrInputStream::read(bool& value)
{
  //  int* temp = (int*) (&value);
  //  xdr_bool(&_xdr, temp);
  bool_t temp;
  xdr_bool(&_xdr, &temp);
  if (temp == FALSE) {
    value = false;
  } else {
    value = true;
  }
}


void XdrInputStream::read(char& value)
{
  xdr_char(&_xdr, &value);
}


void XdrInputStream::read(short& value)
{
  xdr_short(&_xdr, &value);
}


void XdrInputStream::read(int& value)
{
  xdr_int(&_xdr, &value);
}


void XdrInputStream::read(long& value)
{
  xdr_long(&_xdr, &value);
}


void XdrInputStream::read(float& value)
{
  xdr_float(&_xdr, &value);
}


void XdrInputStream::read(double& value)
{
  xdr_double(&_xdr, &value);
}


void XdrInputStream::read(std::string& value)
{
  int length;
  read(length);
  value.erase(value.begin(), value.end()); // replacement for clear() missing in gcc 2.95.4
  char readChar;
  for (int i = 0; i < length; i++) {
    xdr_char(&_xdr, &readChar);
    value.append(1, readChar);
  }
}


}


}
