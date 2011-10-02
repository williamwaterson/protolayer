#ifndef PROTOLAYER_DATABASE_FACADE_H
#define PROTOLAYER_DATABASE_FACADE_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

#include <mysql/mysql.h>

#include "Exception.h"
#include "ConnectionPool.h"
#include "Connection.h"

#include "protolayer/protolayer-dto.h"
#include "protolayer/protolayer-naming.h"
#include "protolayer/protolayer-logger.h"
#include "protolayer/protolayer-ontologydto.h"


namespace protolayer
{

namespace database
{

void retrieveDependencyDomainIDs(int domainId, std::set <int>& dependencies);

int create(dto::UserDTO& dto) throw (database::Exception);

int create(ontologydto::DomainDTO& dto) throw (database::Exception);

int create(ontologydto::TypeDTO& dto) throw (database::Exception);

int create(ontologydto::EndDTO& dto) throw (database::Exception);

int create(ontologydto::AssociationDTO& dto) throw (database::Exception);

int create(ontologydto::GeneralisationDTO& dto) throw (database::Exception);

int create(dto::TechniqueDTO& dto) throw (database::Exception);

void retrieve(int id, dto::UserDTO& dto) throw (database::Exception);

void retrieve(int id, dto::TechniqueDTO& dto) throw (database::Exception);

void retrieve(int id, ontologydto::DomainDTO& dto) throw (database::Exception);

void retrieve(int id, ontologydto::TypeDTO& dto) throw (database::Exception);

int retrieveTypeId(int domainId, std::string typeName) throw (database::Exception);

void retrieve(int id, ontologydto::EndDTO& dto) throw (database::Exception);

void retrieve(int id, ontologydto::AssociationDTO& dto) throw (database::Exception);

void retrieve(int id, ontologydto::GeneralisationDTO& dto) throw (database::Exception);

void retrieve(dto::UserDTO& dto) throw (database::Exception);

void retrieve(dto::TechniqueDTO& dto) throw (database::Exception);

void retrieve(ontologydto::DomainDTO& dto) throw (database::Exception);

void retrieve(ontologydto::TypeDTO& dto) throw (database::Exception);

void retrieve(ontologydto::EndDTO& dto) throw (database::Exception);

void retrieve(ontologydto::AssociationDTO& dto) throw (database::Exception);

void retrieve(ontologydto::GeneralisationDTO& dto) throw (database::Exception);

void update(ontologydto::DomainDTO& dto) throw (database::Exception);

void update(ontologydto::TypeDTO& dto) throw (database::Exception);

void update(ontologydto::EndDTO& dto) throw (database::Exception);

void update(ontologydto::AssociationDTO& dto) throw (database::Exception);

void update(ontologydto::GeneralisationDTO& dto) throw (database::Exception);

void update(dto::UserDTO& dto) throw (database::Exception);

void update(dto::TechniqueDTO& dto) throw (database::Exception);

bool findType(int id);

bool findType(int domainId, std::string name);

bool findAssociation(int id);

bool findGeneralisation(int id);

bool findEnd(int id);

bool findDomain(int id);

bool findTechnique(int id);

bool findUser(int id);

void removeType(int id);

void removeAssociation(int id);

void removeGeneralisation(int id);

void removeEnd(int id);

void removeDomain(int id);

void removeTechnique(int id);

void removeUser(int id);


//void search(std::string& criteria, DomainResultSet& results) throw (database::Exception);

//void search(std::string& criteria, TechniqueResultSet& results) throw (database::Exception);

//void search(std::string& criteria, UserResultSet& results) throw (database::Exception);

}


}


#endif // PROTOLAYER_COLLECTIVEDQL_FACADE_H
