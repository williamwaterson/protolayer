#ifndef PROTOLAYER_PERSISTENCE_FACADE_H
#define PROTOLAYER_PERSISTENCE_FACADE_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

//#include <mysql/mysql.h>

#include "Exception.h"

#include "protolayer/protolayer-database.h"
#include "protolayer/protolayer-dto.h"
#include "protolayer/protolayer-naming.h"
#include "protolayer/protolayer-logger.h"
#include "protolayer/protolayer-ontologydto.h"


namespace protolayer
{

namespace persistence
{

void retrieveDependencyDomainIDs(int domainId, std::set <int>& dependencies);

int create(dto::UserDTO& dto) throw (persistence::Exception);

int create(ontologydto::DomainDTO& dto) throw (persistence::Exception);

int create(ontologydto::TypeDTO& dto) throw (persistence::Exception);

int create(ontologydto::EndDTO& dto) throw (persistence::Exception);

int create(ontologydto::AssociationDTO& dto) throw (persistence::Exception);

int create(ontologydto::GeneralisationDTO& dto) throw (persistence::Exception);

int create(dto::TechniqueDTO& dto) throw (persistence::Exception);

void retrieve(int id, dto::UserDTO& dto) throw (persistence::Exception);

void retrieve(int id, dto::TechniqueDTO& dto) throw (persistence::Exception);

void retrieve(int id, ontologydto::DomainDTO& dto) throw (persistence::Exception);

void retrieve(int id, ontologydto::TypeDTO& dto) throw (persistence::Exception);

int retrieveTypeId(int domainId, std::string typeName) throw (persistence::Exception);

void retrieve(int id, ontologydto::EndDTO& dto) throw (persistence::Exception);

void retrieve(int id, ontologydto::AssociationDTO& dto) throw (persistence::Exception);

void retrieve(int id, ontologydto::GeneralisationDTO& dto) throw (persistence::Exception);

void retrieve(dto::UserDTO& dto) throw (persistence::Exception);

void retrieve(dto::TechniqueDTO& dto) throw (persistence::Exception);

void retrieve(ontologydto::DomainDTO& dto) throw (persistence::Exception);

void retrieve(ontologydto::TypeDTO& dto) throw (persistence::Exception);

void retrieve(ontologydto::EndDTO& dto) throw (persistence::Exception);

void retrieve(ontologydto::AssociationDTO& dto) throw (persistence::Exception);

void retrieve(ontologydto::GeneralisationDTO& dto) throw (persistence::Exception);

void update(ontologydto::DomainDTO& dto) throw (persistence::Exception);

void update(ontologydto::TypeDTO& dto) throw (persistence::Exception);

void update(ontologydto::EndDTO& dto) throw (persistence::Exception);

void update(ontologydto::AssociationDTO& dto) throw (persistence::Exception);

void update(ontologydto::GeneralisationDTO& dto) throw (persistence::Exception);

void update(dto::UserDTO& dto) throw (persistence::Exception);

void update(dto::TechniqueDTO& dto) throw (persistence::Exception);

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

}


}


#endif // PROTOLAYER_PERSISTENCE_FACADE_H
