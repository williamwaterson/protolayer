#ifndef PROTOLAYER_NAMING_NAMING_H
#define PROTOLAYER_NAMING_NAMING_H

#include <stdio.h>
#include <stdlib.h>
#include <string>

#include <protolayer/protolayer-util.h>


namespace protolayer
{

namespace naming
{

int indexOfNextSeparator(std::string& name);

void eraseSeparators(std::string& name);

void removeScopingSeparator(std::string& name);

bool hasDanglingScope(const std::string& name);

int countScopes(const std::string& name);

bool isValidName(const std::string& name);

bool isValidScope(const std::string& scope);

bool isScoped(const std::string& name);

std::string getScope(const std::string& scopedName);

bool isNumericString(std::string value, int base = 10);

int getScopeId(const std::string& scopedName);

std::string getUnscopedName(const std::string& scopedName);

std::string constructScopedName(const std::string& scope, const std::string& unscopedName);

std::string constructScopedName(int domainId, const std::string& unscopedName);

}


}


#endif // PROTOLAYER_NAMING_NAMING_H
