#include "Facade.h"


namespace protolayer
{

namespace persistence
{

void retrieveDependencyDomainIDs(int domainId, std::set <int>& dependencies)
{
}

int create(dto::UserDTO& dto) throw (persistence::Exception)
{
}

int create(ontologydto::DomainDTO& dto) throw (persistence::Exception)
{
}

int create(ontologydto::TypeDTO& dto) throw (persistence::Exception)
{
}

int create(ontologydto::EndDTO& dto) throw (persistence::Exception)
{
}

int create(ontologydto::AssociationDTO& dto) throw (persistence::Exception)
{
}

int create(ontologydto::GeneralisationDTO& dto) throw (persistence::Exception)
{
}

int create(dto::TechniqueDTO& dto) throw (persistence::Exception)
{
}

void retrieve(int id, dto::UserDTO& dto) throw (persistence::Exception)
{
}

void retrieve(int id, dto::TechniqueDTO& dto) throw (persistence::Exception)
{
}

void retrieve(int id, ontologydto::DomainDTO& dto) throw (persistence::Exception)
{
}

  void retrieve(int id, ontologydto::TypeDTO& dto) throw (persistence::Exception)
  {
  }

int retrieveTypeId(int domainId, std::string typeName) throw (persistence::Exception)
{
  return 0;
}

  void retrieve(int id, ontologydto::EndDTO& dto) throw (persistence::Exception){
  }

  void retrieve(int id, ontologydto::AssociationDTO& dto) throw (persistence::Exception) {
  }

  void retrieve(int id, ontologydto::GeneralisationDTO& dto) throw (persistence::Exception) {
  }

  void retrieve(dto::UserDTO& dto) throw (persistence::Exception) {
  }

  void retrieve(dto::TechniqueDTO& dto) throw (persistence::Exception) {
  }

  void retrieve(ontologydto::DomainDTO& dto) throw (persistence::Exception) {
  }

  void retrieve(ontologydto::TypeDTO& dto) throw (persistence::Exception) {
  }

  void retrieve(ontologydto::EndDTO& dto) throw (persistence::Exception) {
  }

  void retrieve(ontologydto::AssociationDTO& dto) throw (persistence::Exception) {
  }

  void retrieve(ontologydto::GeneralisationDTO& dto) throw (persistence::Exception) {
  }

  void update(ontologydto::DomainDTO& dto) throw (persistence::Exception) {
  }

  void update(ontologydto::TypeDTO& dto) throw (persistence::Exception) {
  }

  void update(ontologydto::EndDTO& dto) throw (persistence::Exception) {
  }

  void update(ontologydto::AssociationDTO& dto) throw (persistence::Exception) {
  }

  void update(ontologydto::GeneralisationDTO& dto) throw (persistence::Exception) {
  }

  void update(dto::UserDTO& dto) throw (persistence::Exception) {
  }

  void update(dto::TechniqueDTO& dto) throw (persistence::Exception) {
  }

  bool findType(int id) {
    return true;
  }

  bool findType(int domainId, std::string name) {
    return true;
  }

  bool findAssociation(int id) {
    return true;
  }

  bool findGeneralisation(int id) {
    return true;
  }

  bool findEnd(int id) {
    return true;
  }

  bool findDomain(int id) {
    return true;
  }

  bool findTechnique(int id) {
    return true;
  }

  bool findUser(int id) {
    return true;
  }

  void removeType(int id) {
  }

  void removeAssociation(int id) {
  }

  void removeGeneralisation(int id) {
  }

  void removeEnd(int id) {
  }

  void removeDomain(int id) {
  }

  void removeTechnique(int id) {
  }

  void removeUser(int id) {
  }


}


}
