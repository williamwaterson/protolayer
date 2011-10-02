#include "XdrOutputStream.h"

namespace protolayer
{

namespace reflection
{
  bool isSimpleType(const std::string& value)
  {
    bool flag = false;

    if (value == "bool") {
      flag = true;
    } else if (value == "char") {
      flag = true;
    } else if (value == "short") {
      flag = true;
    } else if (value == "int") {
      flag = true;
    } else if (value == "long") {
      flag = true;
    } else if (value == "float") {
      flag = true;
    } else if (value == "double") {
      flag = true;
    } else if (value == "std::string") {
      flag = true;
    } else if (value == "std::set <char>") {
      flag = true;
    } else if (value == "std::set <short>") {
      flag = true;
    } else if (value == "std::set <int>") {
      flag = true;
    } else if (value == "std::set <long>") {
      flag = true;
    } else if (value == "std::set <float>") {
      flag = true;
    } else if (value == "std::set <double>") {
      flag = true;
    } else if (value == "std::set <std::string>") {
      flag = true;
    }

    return flag;
  }
 
}


namespace iostream
{

void XdrOutputStream::write(std::set <bool>& collection)
{
  write((int) collection.size());
  for (std::set <bool>::iterator iter = collection.begin(); iter != collection.end(); iter++) {
    write(*iter);
  }
}


void XdrOutputStream::write(std::set <char>& collection)
{
  write((int) collection.size());
  for (std::set <char>::iterator iter = collection.begin(); iter != collection.end(); iter++) {
    write(*iter);
  }
}


void XdrOutputStream::write(std::set <short>& collection)
{
  write((int) collection.size());
  for (std::set <short>::iterator iter = collection.begin(); iter != collection.end(); iter++) {
    write(*iter);
  }
}


void XdrOutputStream::write(std::set <int>& collection)
{
  write((int) collection.size());
  for (std::set <int>::iterator iter = collection.begin(); iter != collection.end(); iter++) {
    write(*iter);
  }
}


void XdrOutputStream::write(std::set <long>& collection)
{
  write((int) collection.size());
  for (std::set <long>::iterator iter = collection.begin(); iter != collection.end(); iter++) {
    write(*iter);
  }
}


void XdrOutputStream::write(std::set <float>& collection)
{
  write((int) collection.size());
  for (std::set <float>::iterator iter = collection.begin(); iter != collection.end(); iter++) {
    write(*iter);
  }
}


void XdrOutputStream::write(std::set <double>& collection)
{
  write((int) collection.size());
  for (std::set <double>::iterator iter = collection.begin(); iter != collection.end(); iter++) {
    write(*iter);
  }
}


void XdrOutputStream::write(const std::set <std::string>& collection)
{
  write((int) collection.size());
  for (std::set <std::string>::iterator iter = collection.begin(); iter != collection.end(); iter++) {
    write(*iter);
  }
}



XdrOutputStream::XdrOutputStream(int socketFd)
{
  _file = fdopen(socketFd, "a");
  if (_file == NULL) {
    logger::Logger::getSingleton().debug("Iostream", strerror(errno));
    throw Exception(strerror(errno));
  }

  xdrstdio_create(&_xdr, _file, XDR_ENCODE);
}


XdrOutputStream::XdrOutputStream(char* fileName)
{
  _file = fopen(fileName, "a");
  if (_file == NULL) {
    logger::Logger::getSingleton().debug("Iostream", strerror(errno));
    throw Exception(strerror(errno));
  }

  xdrstdio_create(&_xdr, _file, XDR_ENCODE);
}


XdrOutputStream::~XdrOutputStream()
{
  //  if ((&_xdr)->x_ops) {
  //    if ((&_xdr)->x_ops->x_destroy) {
  //      (*(&_xdr)->x_ops->x_destroy)();
  //    }
  //  }
}


void XdrOutputStream::close()
{
  if (fclose(_file) != 0) {
    logger::Logger::getSingleton().debug("Iostream", strerror(errno));
    throw Exception(strerror(errno));
  }
}


void XdrOutputStream::write(bool value)
{
  //  int* temp = (int*) (&value);
  //  xdr_bool(&_xdr, temp);
  bool_t temp = FALSE;
  if (value) {
    temp = TRUE;
  }
  xdr_bool(&_xdr, &temp);
}


void XdrOutputStream::write(char value)
{
  xdr_char(&_xdr, &value);
}


void XdrOutputStream::write(short value)
{
  xdr_short(&_xdr, &value);
}

void XdrOutputStream::write(int value)
{
  xdr_int(&_xdr, &value);
}


void XdrOutputStream::write(long value)
{
  xdr_long(&_xdr, &value);
}


void XdrOutputStream::write(float value)
{
  xdr_float(&_xdr, &value);
}


void XdrOutputStream::write(double value)
{
  xdr_double(&_xdr, &value);
}


void XdrOutputStream::write(const std::string& value)
{
  write((int) value.size());
  char writeChar;
  for (unsigned int i = 0; i < value.size(); ++i) {
    writeChar = value[i];
    xdr_char(&_xdr, &writeChar);
  }
}


void XdrOutputStream::flush()
{
  if (::fflush(_file) != 0) {
    logger::Logger::getSingleton().debug("Iostream", strerror(errno));
    throw Exception(strerror(errno));    
  }
}


}


}
