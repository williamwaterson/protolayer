#include "String.h"


namespace protolayer
{

namespace util
{

bool erase(std::string& buffer, const std::string& substr)
{
  bool result = false;

  std::size_t length = substr.length();
  std::size_t position = buffer.find(substr);
  if (position != std::string::npos) {
    buffer.erase(position, length);
    result = true;
  }

  return result;
}


bool eraseAll(std::string& buffer, const std::string& substr)
{
  bool result = false;

  std::size_t length = substr.length();
  std::size_t position = buffer.find(substr);
  while (position != std::string::npos) {
    buffer.erase(position, length);
    position = buffer.find(substr);
    result = true;
  }

  return result;
}


std::string toUpperCase(const std::string& str)
{
  std::string result(str);
  for (int i = 0; i < result.length(); i++) {
    result[i] = toupper(result[i]);
  }
  return result;
}


std::string toLowerCase(const std::string& str)
{
  std::string result(str);
  for (int i = 0; i < result.length(); i++) {
    result[i] = tolower(result[i]);
  }
  return result;
}


bool endsWith(const std::string& buffer, const std::string& suffix)
{
  if (suffix.length() > buffer.length()) {
    return false;
  }

  std::size_t position = buffer.find(suffix);
  return position == buffer.length() - suffix.length();
}


bool beginsWith(const std::string& buffer, const std::string& prefix)
{
  std::size_t position = buffer.find(prefix);
  return position == 0;
}


bool contains(const std::string& buffer, const std::string& substr)
{
  return buffer.find(substr) != std::string::npos;
}


std::size_t current(const std::string& buffer, std::size_t startFrom, std::string& resultToken)
{
  std::size_t end = buffer.find_first_of("\t\n\r ", startFrom);
  if (end == std::string::npos) {
    resultToken = "";
    return std::string::npos;
  }

  resultToken = buffer.substr(startFrom, end - startFrom);
  protolayer::util::trim(resultToken);

  return startFrom;
}


std::size_t next(const std::string& buffer, std::size_t startFrom, std::string& resultToken)
{
  std::size_t resultPosition = startFrom;

  std::size_t breakPosition = buffer.find_first_of("\t\n\r ", startFrom);
  if (breakPosition == std::string::npos) {
    resultToken = "";
    return std::string::npos;
  }

  resultPosition = buffer.find_first_not_of("\t\n\r ", breakPosition);
  if (breakPosition == std::string::npos) {
    resultToken = "";
    return std::string::npos;
  }

  std::size_t end = buffer.find_first_of("\t\n\r ", resultPosition);
  if (breakPosition == std::string::npos) {
    resultToken = "";
    return std::string::npos;
  }

  resultToken = buffer.substr(resultPosition, end - resultPosition);
  protolayer::util::trim(resultToken);

  return resultPosition;
}


std::size_t previous(const std::string& buffer, std::size_t startFrom, std::string& resultToken)
{
  std::size_t resultPosition = startFrom;

  std::size_t breakPosition = buffer.find_first_of("\t\n\r ", startFrom);
  if (breakPosition == std::string::npos) {
    resultToken = "";
    return std::string::npos;
  }

  resultPosition = buffer.find_first_not_of("\t\n\r ", breakPosition);
  if (breakPosition == std::string::npos) {
    resultToken = "";
    return std::string::npos;
  }

  std::size_t end = buffer.find_first_of("\t\n\r ", resultPosition);
  if (breakPosition == std::string::npos) {
    resultToken = "";
    return std::string::npos;
  }

  resultToken = buffer.substr(resultPosition, end - resultPosition);
  protolayer::util::trim(resultToken);

  return resultPosition;
}


std::string itoa(int value, int base)
{
  enum { kMaxDigits = 35 };

  std::string buf;
  buf.reserve( kMaxDigits ); // Pre-allocate enough space.

  // check that the base if valid
  if (base < 2 || base > 16) return buf;
  int quotient = value;

  // Translating number to string with base:
  do {
    buf += "0123456789abcdef"[ std::abs( quotient % base ) ];
    quotient /= base;

  }
  while ( quotient );

  // Append the negative sign for base 10
  if ( value < 0 && base == 10) buf += '-';
  std::reverse( buf.begin(), buf.end() );

  return buf;
}


std::string ltrim(const std::string &str, const std::string &whitespace)
{
  int idx = str.find_first_not_of(whitespace);
  if(idx != std::string::npos) {
    return str.substr(idx);
  }
  return "";
}


std::string rtrim( const std::string& str, const std::string& whitespace)
{
  int idx = str.find_last_not_of(whitespace);
  if(idx != std::string::npos) {
    return str.substr(0,idx+1);
  }
  return str;
}


std::string trim( const std::string &str, const std::string &whitespace)
{
  return rtrim(ltrim(str));
}


}


}
