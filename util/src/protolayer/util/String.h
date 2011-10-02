#ifndef PROTOLAYER_UTIL_STRING_H
#define PROTOLAYER_UTIL_STRING_H

#include <string>

namespace protolayer
{

namespace util
{

std::size_t current(const std::string& buffer, std::size_t startFrom, std::string& resultToken);

std::size_t next(const std::string& buffer, std::size_t startFrom, std::string& resultToken);

std::size_t previous(const std::string& buffer, std::size_t startFrom, std::string& resultToken);

bool contains(const std::string& buffer, const std::string& substr);

bool endsWith(const std::string& buffer, const std::string& suffix);

bool beginsWith(const std::string& buffer, const std::string& prefix);

bool erase(std::string& buffer, const std::string& substr);

bool eraseAll(std::string& buffer, const std::string& substr);

std::string itoa(int value, int base = 10);

std::string ltrim(const std::string& str, const std::string& whitespace = "\t ");

std::string rtrim(const std::string& str, const std::string& whitespace = "\t\n\r ");

std::string trim(const std::string& str, const std::string& whitespace = "\t\n\r ");

std::string toUpperCase(const std::string& str);

std::string toLowerCase(const std::string& str);

}


}


#endif // PROTOLAYER_UTIL_STRING_H
