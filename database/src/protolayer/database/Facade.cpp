#include "Facade.h"


namespace protolayer
{

namespace database
{

void exiterr(MYSQL& handle, int exitcode)
{
  fprintf(stderr, "%s\n", ::mysql_error(&handle));
  exit(exitcode);
}

void executeConnect(MYSQL& handle)
{
  if(mysql_init(&handle) == NULL) {
    exiterr(handle, 1);
  }

  if (!(::mysql_real_connect(&handle, "localhost", "root", "rootpassword", NULL, 0, NULL, 0))) {
    std::cout << "Failed to connect" << std::endl;
    fprintf(stderr, "%s\n", ::mysql_error(&handle));
    exit(1);
  }

  if (mysql_query(&handle, "USE Protolayer;") != 0) {
    std::cout << "Failed to select Protolayer database" << std::endl;
    exiterr(handle, 1);
  }
}


void executeQuery(MYSQL& handle, std::string& query)
{
  if (mysql_query(&handle, query.c_str()) != 0) {
    std::cout << "INFO: Failed to apply query" << std::endl;
    fprintf(stderr, "%s\n", ::mysql_error(&handle));
  }
}


bool findTechnique(int id)
{
  MYSQL handle;
  MYSQL_RES* results;
  int numberRows;

  executeConnect(handle);

  std::string query = "SELECT * FROM Techniques WHERE id = " + util::itoa(id, 10);
  executeQuery(handle, query);

  results = mysql_store_result(&handle);

  if (results != NULL) {
    numberRows = mysql_num_rows(results);
  } else {
    mysql_free_result(results);
    mysql_close(&handle);
    throw database::Exception("Null pointer returned on result set");
  }

  mysql_free_result(results);
  mysql_close(&handle);

  return numberRows == 1;
}


bool findUser(int id)
{
  MYSQL handle;
  MYSQL_RES* results;
  int numberRows;

  executeConnect(handle);

  std::string query = "SELECT * FROM Users WHERE id = " + util::itoa(id, 10);
  executeQuery(handle, query);

  results = mysql_store_result(&handle);

  if (results != NULL) {
    numberRows = mysql_num_rows(results);
  } else {
    mysql_free_result(results);
    mysql_close(&handle);
    throw database::Exception("Null pointer returned on result set");
  }

  mysql_free_result(results);
  mysql_close(&handle);

  return numberRows == 1;
}


void retrieveDependencyDomainIDs(int domainId, std::set <int>& dependencies)
{
  MYSQL handle;
  MYSQL_RES* results;
  MYSQL_ROW row;
  int numberRows;

  executeConnect(handle);

  // Obtain all the types from this domain


  // Obtain all ends involving types from that domain


  // Obtain all associations where those ends are from ends


  // Obtain types from to ends which are only those targeting types in other domains


  // Obtain the domain IDs for these other types


  //  std::string query = "SELECT id FROM Associations WHERE domain = " + util::itoa(domainId, 10) + " AND name = '" + typeName + "'";
  //  std::cout << query << std::endl;
  //executeQuery(handle, query);

  //  results = mysql_store_result(&handle);

  //  int result = 0;
  //  if (results != NULL) {
  // numberRows = mysql_num_rows(results);
  //if (numberRows == 1) {
  //  row = mysql_fetch_row(results);
  //  result = atoi(row[0]);
  //}
  //}

  //  mysql_free_result(results);
  //mysql_close(&handle);

  //  return result;
}


int retrieveTypeId(int domainId, std::string typeName) throw (database::Exception)
{
  MYSQL handle;
  MYSQL_RES* results;
  MYSQL_ROW row;
  int numberRows;

  executeConnect(handle);

  std::string query = "SELECT id FROM Concepts WHERE domain = " + util::itoa(domainId, 10) + " AND name = '" + typeName + "'";
  std::cout << query << std::endl;
  executeQuery(handle, query);

  results = mysql_store_result(&handle);

  int result = 0;
  if (results != NULL) {
    numberRows = mysql_num_rows(results);
    if (numberRows == 1) {
      row = mysql_fetch_row(results);
      result = atoi(row[0]);
    }
  }

  mysql_free_result(results);
  mysql_close(&handle);

  return result;
}


bool findType(int domainId, std::string name)
{
  MYSQL handle;
  MYSQL_RES* results;
  int numberRows;

  executeConnect(handle);

  std::string query = "SELECT id FROM Concepts WHERE domain = " + util::itoa(domainId, 10) + " AND name = '" + name + "'";
  executeQuery(handle, query);

  results = mysql_store_result(&handle);

  bool result = false;
  if (results != NULL) {
    numberRows = mysql_num_rows(results);
    result = (numberRows == 1);
  }

  mysql_free_result(results);
  mysql_close(&handle);

  return result;
}


bool findType(int id)
{
  MYSQL handle;
  MYSQL_RES* results;
  int numberRows;

  executeConnect(handle);

  std::string query = "SELECT * FROM Concepts WHERE id = " + util::itoa(id, 10);
  executeQuery(handle, query);

  results = mysql_store_result(&handle);

  if (results != NULL) {
    numberRows = mysql_num_rows(results);
  } else {
    mysql_free_result(results);
    mysql_close(&handle);
    throw database::Exception("Null pointer returned on result set");
  }

  mysql_free_result(results);
  mysql_close(&handle);

  return numberRows == 1;
}


bool findAssociation(int id)
{
  MYSQL handle;
  MYSQL_RES* results;

  executeConnect(handle);

  std::string query = "SELECT * FROM Associations WHERE id = " + util::itoa(id, 10);
  executeQuery(handle, query);

  results = mysql_store_result(&handle);
  
  // Perform null pointer check on results

  int numberRows = mysql_num_rows(results);

  mysql_free_result(results);
  mysql_close(&handle);

  return numberRows == 1;
}


bool findGeneralisation(int id)
{
  MYSQL handle;
  MYSQL_RES* results;

  executeConnect(handle);

  std::string query = "SELECT * FROM Generalisations WHERE id = " + util::itoa(id, 10);
  executeQuery(handle, query);

  results = mysql_store_result(&handle);
  
  // Perform null pointer check on results

  int numberRows = mysql_num_rows(results);

  mysql_free_result(results);
  mysql_close(&handle);

  return numberRows == 1;
}


bool findEnd(int id)
{
  MYSQL handle;
  MYSQL_RES* results;

  executeConnect(handle);

  std::string query = "SELECT * FROM Ends WHERE id = " + util::itoa(id, 10);
  executeQuery(handle, query);

  results = mysql_store_result(&handle);
  
  // Perform null pointer check on results

  int numberRows = mysql_num_rows(results);

  mysql_free_result(results);
  mysql_close(&handle);

  return numberRows == 1;
}


bool findDomain(int id)
{
  MYSQL handle;
  MYSQL_RES* results;

  executeConnect(handle);

  std::string query = "SELECT * FROM Domains WHERE id = " + util::itoa(id, 10);
  executeQuery(handle, query);

  results = mysql_store_result(&handle);
  
  // Perform null pointer check on results

  int numberRows = mysql_num_rows(results);

  mysql_free_result(results);
  mysql_close(&handle);

  return numberRows == 1;
}


void removeType(int id)
{
  MYSQL handle;

  executeConnect(handle);

  std::string query = "DELETE FROM Concepts WHERE id = " + util::itoa(id, 10);
  executeQuery(handle, query);

  mysql_close(&handle);
}


void removeAssociation(int id)
{
  MYSQL handle;

  executeConnect(handle);

  std::string query = "DELETE FROM Associations WHERE id = " + util::itoa(id, 10);
  executeQuery(handle, query);

  mysql_close(&handle);
}


void removeGeneralisation(int id)
{
  MYSQL handle;

  executeConnect(handle);

  std::string query = "DELETE FROM Generalisations WHERE id = " + util::itoa(id, 10);
  executeQuery(handle, query);

  mysql_close(&handle);
}


void removeEnd(int id)
{
  MYSQL handle;

  executeConnect(handle);

  std::string query = "DELETE FROM Ends WHERE id = " + util::itoa(id, 10);
  executeQuery(handle, query);

  mysql_close(&handle);
}


void removeDomain(int id)
{
  MYSQL handle;

  executeConnect(handle);

  std::string query = "DELETE FROM Domains WHERE id = " + util::itoa(id, 10);
  executeQuery(handle, query);

  mysql_close(&handle);
}


void removeTechnique(int id)
{
}


void removeUser(int id)
{
}


int create(dto::UserDTO& dto) throw (database::Exception)
{
  MYSQL handle;
  executeConnect(handle);

  std::string query;
  query += "INSERT INTO Users VALUES(NULL, '" + dto.getUsername() + "','" + dto.getPassword() + "','" + dto.getEmail() + "');";
  std::cout << query << std::endl;

  if (mysql_query(&handle, query.c_str()) != 0) {
    std::cout << "INFO: Failed to apply query" << std::endl;
    fprintf(stderr, "%s\n", ::mysql_error(&handle));
  }

  int id = mysql_insert_id(&handle);
  dto.getId() = id;
  std::cout << dto.getId() << std::endl;

  mysql_close(&handle);

  return id;
}


int persist(MYSQL& handle,
	   ontologydto::TypeDTO& dto) throw (database::Exception)
{
  std::string domainId = util::itoa(dto.getDomainId(), 10);

  std::string isAbstract("0");
  if (dto.isAbstract()) {
    isAbstract = "1";
  }

  std::string isLeaf("0");
  if (dto.isLeaf()) {
    isLeaf = "1";
  }

  std::string isSingleton("0");
  if (dto.isSingleton()) {
    isSingleton = "1";
  }

  std::string query("INSERT INTO Concepts VALUES(NULL,'" + dto.getName() + "','" + domainId + "','" + isLeaf + "','" + isAbstract + "','" + isSingleton + "');");
  std::cout << query << std::endl;

  executeQuery(handle, query);

  int id = mysql_insert_id(&handle);
  dto.getId() = id;

  return id;
}


int create(ontologydto::TypeDTO& dto) throw (database::Exception)
{
  MYSQL handle;
  executeConnect(handle);

  int id = persist(handle, dto);

  mysql_close(&handle);
  return id;
}


int persist(MYSQL& handle,
	   ontologydto::EndDTO& dto) throw (database::Exception)
{
  std::string conceptId = util::itoa(dto.getConceptId(), 10);

  std::string query("INSERT INTO Ends VALUES(NULL,'" + dto.getLabel() + "','" + conceptId + "','" + dto.getMultiplicity() + "');");
  std::cout << query << std::endl;
  executeQuery(handle, query);

  int id = mysql_insert_id(&handle);
  dto.getId() = id;

  return id;
}


int create(ontologydto::EndDTO& dto) throw (database::Exception)
{
  MYSQL handle;
  executeConnect(handle);

  int id = persist(handle, dto);

  mysql_close(&handle);
  return id;
}


int persist(MYSQL& handle,
	   ontologydto::AssociationDTO& dto) throw (database::Exception)
{
  persist(handle, dto.getFromEnd());
  persist(handle, dto.getToEnd());

  std::string fromEndId = util::itoa(dto.getFromEnd().getId(), 10);
  std::string toEndId = util::itoa(dto.getToEnd().getId(), 10);

  std::string query("INSERT INTO Associations VALUES(NULL,'" + fromEndId + "','" + toEndId + "');");

  std::cout << query << std::endl;
  executeQuery(handle, query);

  int id = mysql_insert_id(&handle);
  dto.getId() = id;

  return id;
}


int create(ontologydto::AssociationDTO& dto) throw (database::Exception)
{
  MYSQL handle;
  executeConnect(handle);

  int id = persist(handle, dto);

  mysql_close(&handle);
  return id;
}


int persist(MYSQL& handle,
	   ontologydto::GeneralisationDTO& dto) throw (database::Exception)
{
  std::string superTypeId = util::itoa(dto.getSuperTypeId(), 10);
  std::string subTypeId = util::itoa(dto.getSubTypeId(), 10);

  std::string query("INSERT INTO Generalisations VALUES(NULL,'" + superTypeId + "','" + subTypeId + "');");

  std::cout << query << std::endl;
  executeQuery(handle, query);

  int id = mysql_insert_id(&handle);
  dto.getId() = id;

  return id;
}


int persist(MYSQL& handle,
	   dto::TechniqueDTO& dto) throw (database::Exception)
{
  std::string title = dto.getTitle();
  std::string conceptId = util::itoa(dto.getConceptId(), 10);

  std::string query("INSERT INTO Techniques VALUES(NULL,'" +
		    title +
		    "', NULL, '" +
		    conceptId + "');");

  std::cout << query << std::endl;
  executeQuery(handle, query);

  int id = mysql_insert_id(&handle);
  dto.getId() = id;

  return id;
}


int create(dto::TechniqueDTO& dto) throw (database::Exception)
{
  MYSQL handle;
  executeConnect(handle);

  // 

  int id = persist(handle, dto);

  mysql_close(&handle);
  return id;
}


void persist(MYSQL& handle, std::set <ontologydto::TypeDTO*>& types)
{
  typedef std::set <ontologydto::TypeDTO*>::iterator TypeIterType;
  for (TypeIterType iter = types.begin(); iter != types.end(); iter++) {
    persist(handle, **iter);
  }
}


void persist(MYSQL& handle, std::set <ontologydto::AssociationDTO*>& assocs)
{
  typedef std::set <ontologydto::AssociationDTO*>::iterator AssocIterType;
  for (AssocIterType iter = assocs.begin(); iter != assocs.end(); iter++) {
    persist(handle, **iter);
  }
}


void persist(MYSQL& handle, std::set <ontologydto::GeneralisationDTO*>& generalisations)
{
  typedef std::set <ontologydto::GeneralisationDTO*>::iterator GenIterType;
  for (GenIterType iter = generalisations.begin(); iter != generalisations.end(); iter++) {
    persist(handle, **iter);
  }
}


// Need to move this method elsewhere (over to service)
void propagateDomainIds(ontologydto::DomainDTO& dto) throw (database::Exception)
{
  for (std::set < ontologydto::TypeDTO*>::iterator iter = dto.getTypes().begin(); iter != dto.getTypes().end(); iter++) {
    (*iter)->getDomainId() = dto.getId();
  }  

  for (std::set < ontologydto::AssociationDTO*>::iterator iter = dto.getAssociations().begin(); iter != dto.getAssociations().end(); iter++) {
    ontologydto::EndDTO& fromEnd = (*iter)->getFromEnd();
    if (0 == fromEnd.getDomainId()) {
      fromEnd.getDomainId() = dto.getId();
    }

    ontologydto::EndDTO& toEnd = (*iter)->getToEnd();
    if (0 == toEnd.getDomainId()) {
      toEnd.getDomainId() = dto.getId();
    }
  }

  for (std::set < ontologydto::GeneralisationDTO*>::iterator iter = dto.getGeneralisations().begin(); iter != dto.getGeneralisations().end(); iter++) {
    if (0 == (*iter)->getSuperTypeDomainId()) {
      (*iter)->getSuperTypeDomainId() = dto.getId();
    }

    if (0 == (*iter)->getSubTypeDomainId()) {
      (*iter)->getSubTypeDomainId() = dto.getId();
    }
  }  
}


// Need to move this method elsewhere (over to service)
// Need to also add trim checks on strings to ensure correct matching of types to typenames
void propagateTypeIds(ontologydto::DomainDTO& dto) throw (database::Exception)
{
  logger::Logger::getSingleton().debug("Database", "Creating id-to-type dictionary");
  std::map <std::string, int> typeDictionary;

  int domainId = dto.getId();
  logger::Logger::getSingleton().debug("Database", "Looping through type names");

  for (std::set < ontologydto::TypeDTO*>::iterator iter = dto.getTypes().begin(); iter != dto.getTypes().end(); iter++) {
    logger::Logger::getSingleton().debug("Database", "Creating scoped name for " + (*iter)->getName());
    std::string scopedName = naming::constructScopedName(domainId, (*iter)->getName());

    logger::Logger::getSingleton().debug("Database", "Scoped name is " + scopedName);
    typeDictionary[scopedName] = (*iter)->getId();
  }
  logger::Logger::getSingleton().debug("Database", "Id-to-type dictionary created");

  logger::Logger::getSingleton().debug("Database", "Obtain dependencies and related concept IDs");
  std::map <std::string, ontologydto::AssociationDTO*> associationDictionary;
  for (std::set < ontologydto::AssociationDTO*>::iterator iter = dto._associations.begin(); iter != dto._associations.end(); iter++) {
    std::string typeName = (*iter)->getFromEnd().getTypeName();
    int domainId = (*iter)->getFromEnd().getDomainId();
    if (domainId != 0) {
      int id = retrieveTypeId(domainId, typeName);
      std::string scopedName = naming::constructScopedName(domainId, typeName);

      logger::Logger::getSingleton().debug("Database", "Scoped name is " + scopedName + " for id: " + util::itoa(id, 10));
      typeDictionary[scopedName] = id;
    }

    typeName = (*iter)->getToEnd().getTypeName();
    domainId = (*iter)->getToEnd().getDomainId();
    if (domainId != 0) {
      int id = retrieveTypeId(domainId, typeName);
      std::string scopedName = naming::constructScopedName(domainId, typeName);
      logger::Logger::getSingleton().debug("Database", "Scoped name is " + scopedName + " for id: " + util::itoa(id, 10));
      typeDictionary[scopedName] = id;
    }
  }
  logger::Logger::getSingleton().debug("Database", "Obtain dependencies");

  logger::Logger::getSingleton().debug("Database", "Setting association end typeIDs using id-to-type dictionary lookup");
  for (std::set < ontologydto::AssociationDTO*>::iterator iter = dto.getAssociations().begin(); iter != dto._associations.end(); iter++) {
    ontologydto::EndDTO& fromEnd = (*iter)->getFromEnd();
    if (0 == fromEnd.getConceptId()) {
      std::string scopedName = naming::constructScopedName(fromEnd.getDomainId(), fromEnd.getTypeName());
      if (typeDictionary.count(scopedName) == 0) {
	logger::Logger::getSingleton().debug("Database", "Nonexistent type name: " + scopedName);
	throw "Nonexistent type name";
      } else {
	fromEnd.getConceptId() = typeDictionary[scopedName];
      }
    }

    ontologydto::EndDTO& toEnd = (*iter)->getToEnd();
    if (0 == toEnd.getConceptId()) {
      std::string scopedName = naming::constructScopedName(toEnd.getDomainId(), toEnd.getTypeName());
      if (typeDictionary.count(scopedName) == 0) {
	logger::Logger::getSingleton().debug("Database", "Nonexistent type name: " + scopedName);
	throw "Nonexistent type name";
      } else {
	toEnd.getConceptId() = typeDictionary[scopedName];
      }
    }
  }
  logger::Logger::getSingleton().debug("Database", "Association end typeIDs set");

  logger::Logger::getSingleton().debug("Database", "Setting generalisation typeIDs using id-to-type dictionary lookup");
  for (std::set < ontologydto::GeneralisationDTO*>::iterator iter = dto._generalisations.begin(); iter != dto._generalisations.end(); iter++) {
    if (0 == (*iter)->getSuperTypeId()) {
      std::string scopedName = naming::constructScopedName(domainId, (*iter)->getSuperTypeName());
      logger::Logger::getSingleton().debug("Database", "Generalisation supertype scoped name is: " + scopedName);
      if (typeDictionary.count(scopedName) == 0) {
	logger::Logger::getSingleton().debug("Database", "Nonexistent type name: " + scopedName);
	throw "Nonexistent type name";
      } else {
	logger::Logger::getSingleton().debug("Database", "Generalisation supertype ID is: " + typeDictionary[scopedName]);
	(*iter)->getSuperTypeId() = typeDictionary[scopedName];
      }
    }

    if (0 == (*iter)->getSubTypeId()) {
      std::string scopedName = naming::constructScopedName(domainId, (*iter)->getSubTypeName());
      logger::Logger::getSingleton().debug("Database", "Generalisation subtype scoped name is: " + scopedName);
      if (typeDictionary.count(scopedName) == 0) {
	logger::Logger::getSingleton().debug("Database", "Nonexistent type name: " + scopedName);
	throw "Nonexistent type name";
      } else {
	logger::Logger::getSingleton().debug("Database", "Generalisation subtype ID is: " + typeDictionary[scopedName]);
	(*iter)->getSubTypeId() = typeDictionary[scopedName];
      }

    }
  }
  logger::Logger::getSingleton().debug("Database", "Generalisation end typeIDs set");

}


void trim(ontologydto::GeneralisationDTO& dto) {
  dto._superTypeName = util::trim(dto._superTypeName);
  dto._subTypeName = util::trim(dto._subTypeName);
}


void trimGeneralisations(ontologydto::DomainDTO& domain) {
  typedef std::set <ontologydto::GeneralisationDTO*>::iterator IterType;  
  for (IterType iter = domain._generalisations.begin(); iter != domain._generalisations.end(); iter++) {
    trim(**iter);
  }
}


void trim(ontologydto::AssociationDTO& association) {
  association._name = util::trim(association._name);

  association._fromEnd->_typeName = util::trim(association._fromEnd->_typeName);
  association._toEnd->_typeName = util::trim(association._toEnd->_typeName);

  association._fromEnd->_multiplicity = util::trim(association._fromEnd->_multiplicity);
  association._toEnd->_multiplicity = util::trim(association._toEnd->_multiplicity);
}


void trimAssociations(ontologydto::DomainDTO& domain) {
  typedef std::set <ontologydto::AssociationDTO*>::iterator IterType;  
  for (IterType iter = domain._associations.begin(); iter != domain._associations.end(); iter++) {
    trim(**iter);
  }
}


void trimTypes(ontologydto::DomainDTO& domain) {
  typedef std::set <ontologydto::TypeDTO*>::iterator IterType;  
  for (IterType iter = domain._types.begin(); iter != domain._types.end(); iter++) {
    ontologydto::TypeDTO* dto = *iter;
    (*iter)->_name = util::trim((*iter)->_name);
  }
}


void trimAll(ontologydto::DomainDTO& domain) {
  trimTypes(domain);
  trimAssociations(domain);
  trimGeneralisations(domain);
}


void normaliseTypes(ontologydto::DomainDTO& domain)
{
}


void normaliseFromEnd(ontologydto::AssociationDTO& assoc, bool isNewDomain)
{
  ontologydto::EndDTO& end = assoc.getFromEnd();

  int domainId = end.getDomainId();
  std::string typeName = end.getTypeName();
  std::cout << "before to end isvalidname" << std::endl;
  if (!naming::isValidName(typeName)) {
    throw "Invalid association end";
  }
  std::cout << "before to end from domains" << std::endl;
  // Cannot have the scope specified for from-domains when creating a domain from scratch
  if (isNewDomain) {
    if (domainId != 0 || naming::isScoped(typeName)) {
      throw "Invalid association end";
    }
  }
  std::cout << "after to end from domains" << std::endl;
}


void normaliseToEnd(ontologydto::AssociationDTO& assoc)
{
  ontologydto::EndDTO& end = assoc.getToEnd();

  int domainId = end.getDomainId();
  std::string typeName = end.getTypeName();

  logger::Logger::getSingleton().debug("Database ", "toEnd " + end.getTypeName());

  if (!naming::isValidName(typeName)) {
    logger::Logger::getSingleton().debug("Database", "Invalid type name");
    throw "Invalid association end";
  }

  logger::Logger::getSingleton().debug("Database", "Valid type name");
  if (naming::isScoped(typeName)) {

    int scopeId = naming::getScopeId(typeName);
    std::string scope = naming::getScope(typeName);
    logger::Logger::getSingleton().debug("Database", "Scoped typename with scope of: " + scope);

    // If domain Id specified differs to scope then fail
    if (domainId != 0 && scopeId != domainId) {
      logger::Logger::getSingleton().error("Database", "Nonzero domain ID differs from scoped typename scope");
      throw "Invalid association end";
    }

    // If domain Id not specified then set to scope
    if (domainId == 0) {
      logger::Logger::getSingleton().debug("Database", "Setting zero domain ID to scoped typename scope");
      end.getDomainId() = scopeId;
    }

    // Revert any scoped type name to unscoped type name for to-end
    end._typeName = naming::getUnscopedName(typeName);
    logger::Logger::getSingleton().debug("Database ", "New unscoped toEnd typename is " + end._typeName);
  }
}


void normaliseAssociations(ontologydto::DomainDTO& domain)
{
  typedef std::set <ontologydto::AssociationDTO*>::iterator IterType;  
  for (IterType iter = domain._associations.begin(); iter != domain._associations.end(); iter++) {
    normaliseFromEnd(**iter, true);
    normaliseToEnd(**iter);
  }
}


void normaliseSuperType(ontologydto::GeneralisationDTO& gen, bool isNewDomain)
{
  std::string typeName = gen.getSuperTypeName();

  /*
  int domainId = gen.getSuperType().getDomainId();
  std::string typeName = end.getTypeName();

  if (!naming::isValidName(typeName)) {
    throw "Invalid supertype specified for generalisation";
  }

  if (isNewDomain) {
    // Cannot have the scope specified for from-domains when creating a domain from scratch
    if (domainId != 0 || naming::isScoped(typeName)) {
      throw "Invalid generalisation";
    }
  } else {
    if (domainId == 0 && !naming::isScoped(typeName)) {
      throw "Invalid generalisation";
    } else if (domainId != 0 && naming::isScoped(typeName)) {
      int scopedId = naming::getScopeId(typeName);
      if (scopeId != domainId) {
	throw "Invalid generalisation";
      }
    } else if (domainId == 0 && naming::isScoped(typeName)) {
      gen.getSuperTypeId() = getScopeId(typeName);
    }
  }
  */
}


void normaliseSubType(ontologydto::GeneralisationDTO& gen)
{
}


void normalise(ontologydto::GeneralisationDTO& dto)
{
  normaliseSuperType(dto, false);
  normaliseSubType(dto);
}


void normaliseGeneralisations(ontologydto::DomainDTO& domain)
{
  typedef std::set <ontologydto::GeneralisationDTO*>::iterator IterType;  
  for (IterType iter = domain._generalisations.begin(); iter != domain._generalisations.end(); iter++) {
    normalise(**iter);
  }
}


bool check(ontologydto::TypeDTO& type)
{
}


bool check(ontologydto::EndDTO& end)
{
  // Ensure type exists in database

}


bool check(ontologydto::AssociationDTO& assoc)
{
  // Ensure from-type and to-type exist in the database
}


bool check(ontologydto::GeneralisationDTO& gen)
{
  // Ensure supertype and subtype exist in database
}


bool checkTypes(ontologydto::DomainDTO& domain)
{
}


bool checkAssociations(ontologydto::DomainDTO& domain)
{
}


bool checkGeneralisations(ontologydto::DomainDTO& domain)
{
}


int persist(ontologydto::DomainDTO& dto) throw (database::Exception)
{
  MYSQL handle;
  executeConnect(handle);

  std::string query;
  query += "INSERT INTO Domains VALUES(NULL,'" + dto.getTitle() + "','" + dto.getDescription() + "',NULL);";

  executeQuery(handle, query);
  dto._id = mysql_insert_id(&handle);
  propagateDomainIds(dto);

  persist(handle, dto.getTypes());

  logger::Logger::getSingleton().debug("Database", "Propagating Type IDs");
  propagateTypeIds(dto);
  logger::Logger::getSingleton().debug("Database", "Type IDs propagated");

  logger::Logger::getSingleton().debug("Database", "Creating Associations in database");
  persist(handle, dto.getAssociations());
  logger::Logger::getSingleton().debug("Database", "Associations created");

  logger::Logger::getSingleton().debug("Database", "Creating Generalisations in database");
  persist(handle, dto.getGeneralisations());
  logger::Logger::getSingleton().debug("Database", "Generalisations created");

  mysql_close(&handle);

  return dto.getId();
}


void prepare(ontologydto::DomainDTO& dto) throw (database::Exception)
{
  trimAll(dto);
}


void prepare(ontologydto::GeneralisationDTO& dto) throw (database::Exception)
{
  trim(dto);
}

void normalise(ontologydto::DomainDTO& dto) throw (database::Exception)
{
  normaliseTypes(dto);
  normaliseAssociations(dto);
  normaliseGeneralisations(dto);
}


void check(ontologydto::DomainDTO& dto)
{
  checkTypes(dto);
  checkAssociations(dto);
  checkGeneralisations(dto);

  // extract domain dependencies
  
  // check these deps exist in database

  // load related domains from database

  // check cyclic dependencies

}


int create(ontologydto::GeneralisationDTO& dto) throw (database::Exception)
{
  MYSQL handle;
  executeConnect(handle);

  prepare(dto);
  normalise(dto);
  check(dto);

  int id = persist(handle, dto);

  mysql_close(&handle);
  return id;
}


int create(ontologydto::DomainDTO& dto) throw (database::Exception)
{
  prepare(dto);
  normalise(dto);
  //  check(dto);
  return persist(dto);
}


void retrieve(int id, dto::UserDTO& dto) throw (database::Exception)
{
  MYSQL handle;
  MYSQL_RES* results;
  MYSQL_ROW row;

  executeConnect(handle);

  std::string query = "SELECT * FROM Users WHERE id = " + util::itoa(id, 10);
  executeQuery(handle, query);

  results = mysql_store_result(&handle);

  if (results != NULL) {
    int numberRows = 0;
    numberRows = mysql_num_rows(results);
    if (numberRows == 1) {
      row = mysql_fetch_row(results);
      dto.getId() = id;
      dto.getUsername() = row[1];
      dto.getPassword() = row[2];
      dto.getEmail() = row[3];
    } else {
      throw database::Exception("No database entry for that record ID");
    }
  } else {
    mysql_free_result(results);
    mysql_close(&handle);
    throw database::Exception("Null pointer returned on result set");
  }

  mysql_free_result(results);
  mysql_close(&handle);
}


void retrieve(int id, dto::TechniqueDTO& dto) throw (database::Exception)
{
  MYSQL handle;
  MYSQL_RES* results;
  MYSQL_ROW row;

  executeConnect(handle);

  std::string query = "SELECT * FROM Techniques WHERE id = " + util::itoa(id, 10);
  executeQuery(handle, query);

  results = mysql_store_result(&handle);

  if (results != NULL) {
    int numberRows = 0;
    numberRows = mysql_num_rows(results);
    if (numberRows == 1) {
      row = mysql_fetch_row(results);
      dto.getId() = id;
      dto.getTitle() = row[1];
      dto.getDescription() = row[2];
      dto.getConceptId() = atoi(row[3]);
    } else {
      throw database::Exception("No database entry for that record ID");
    }
  } else {
    mysql_free_result(results);
    mysql_close(&handle);
    throw database::Exception("Null pointer returned on result set");
  }

  mysql_free_result(results);
  mysql_close(&handle);
}


void retrieve(MYSQL& handle, int id, ontologydto::TypeDTO& dto)
  throw (database::Exception)
{
  MYSQL_RES* results;
  MYSQL_ROW row;

  std::string query = "SELECT * FROM Concepts WHERE id = " + util::itoa(id, 10);
  executeQuery(handle, query);

  results = mysql_store_result(&handle);

  if (results != NULL) {
    int numberRows = 0;
    numberRows = mysql_num_rows(results);
    std::cout << numberRows << std::endl;
    if (numberRows == 1) {
      row = mysql_fetch_row(results);
      dto.getId() = id;
      dto.getName() = row[1];
      dto.getDomainId() = atoi(row[2]);
      dto.isLeaf() = atoi(row[3]);
      dto.isAbstract() = atoi(row[4]);
      dto.isSingleton() = atoi(row[5]);
    } else {
      throw database::Exception("No database entry for that record ID");
    }
  } else {
    mysql_free_result(results);
    mysql_close(&handle);
    throw database::Exception("Null pointer returned on result set");
  }


  mysql_free_result(results);
}


void retrieve(int id, ontologydto::TypeDTO& dto) throw (database::Exception)
{
  MYSQL handle;
  executeConnect(handle);

  retrieve(handle, id, dto);

  mysql_close(&handle);
}


void retrieve(ontologydto::TypeDTO& dto) throw (database::Exception)
{
  retrieve(dto.getId(), dto);
}


void retrieve(MYSQL& handle, int id, ontologydto::EndDTO& dto) throw (database::Exception)
{
  MYSQL_RES* results;
  MYSQL_ROW row;

  std::string query = "SELECT * FROM Ends WHERE id = " + util::itoa(id, 10);
  executeQuery(handle, query);

  results = mysql_store_result(&handle);

  if (results != NULL) {
    int numberRows = 0;
    numberRows = mysql_num_rows(results);
    if (numberRows == 1) {
      row = mysql_fetch_row(results);

      dto.getId() = id;
      dto.getLabel() = row[1];
      dto.getConceptId() = atoi(row[2]);
      dto.getMultiplicity() = row[3];

    } else {
      throw database::Exception("No database entry for that record ID");
    }
  } else {
    mysql_free_result(results);
    mysql_close(&handle);
    throw database::Exception("Null pointer returned on result set");
  }

  mysql_free_result(results);
  mysql_close(&handle);

  mysql_free_result(results);
}


void retrieve(int id, ontologydto::EndDTO& dto) throw (database::Exception)
{
  MYSQL handle;
  executeConnect(handle);

  retrieve(handle, id, dto);

  mysql_close(&handle);
}


void retrieve(MYSQL& handle, int id, ontologydto::AssociationDTO& dto) throw (database::Exception)
{
  MYSQL_RES* results;
  MYSQL_ROW row;

  std::string query = "SELECT * FROM Associations WHERE id = " + util::itoa(id, 10);
  executeQuery(handle, query);

  results = mysql_store_result(&handle);

  if (results != NULL) {
    int numberRows = 0;
    numberRows = mysql_num_rows(results);
    if (numberRows == 1) {
      row = mysql_fetch_row(results);

      dto.getId() = id;
      int fromEndId = atoi(row[1]);
      int toEndId = atoi(row[2]);

      retrieve(handle, fromEndId, dto.getFromEnd());
      retrieve(handle, toEndId, dto.getToEnd());

    } else {
      throw database::Exception("No database entry for that record ID");
    }
  } else {
    mysql_free_result(results);
    mysql_close(&handle);
    throw database::Exception("Null pointer returned on result set");
  }

  mysql_free_result(results);
  mysql_close(&handle);

  mysql_free_result(results);
}


void retrieve(int id, ontologydto::AssociationDTO& dto) throw (database::Exception)
{
  MYSQL handle;
  executeConnect(handle);

  retrieve(handle, id, dto);

  mysql_close(&handle);
}


void retrieve(MYSQL& handle, int id, ontologydto::GeneralisationDTO& dto) throw (database::Exception)
{
  MYSQL_RES* results;
  MYSQL_ROW row;

  std::string query = "SELECT * FROM Generalisations WHERE id = " + util::itoa(id, 10);
  executeQuery(handle, query);

  results = mysql_store_result(&handle);

  if (results != NULL) {
    int numberRows = 0;
    numberRows = mysql_num_rows(results);
    if (numberRows == 1) {
      row = mysql_fetch_row(results);

      dto.getId() = id;

      ontologydto::TypeDTO type;

      retrieve(dto._superTypeId, type);
      dto._superTypeId = type._id;
      dto._superTypeDomainId = type._domainId;
      dto._superTypeName = type._name;

      retrieve(dto._subTypeId, type);
      dto._subTypeId = type._id;
      dto._subTypeDomainId = type._domainId;
      dto._subTypeName = type._name;

    } else {
      throw database::Exception("No database entry for that record ID");
    }

  } else {
    mysql_free_result(results);
    mysql_close(&handle);
    throw database::Exception("Null pointer returned on result set");
  }

  mysql_free_result(results);
  mysql_close(&handle);
}


void retrieve(int id, ontologydto::GeneralisationDTO& dto) throw (database::Exception)
{
  MYSQL handle;
  executeConnect(handle);

  retrieve(handle, id, dto);

  mysql_close(&handle);
}


void retrieveGeneralisations(MYSQL& handle, ontologydto::DomainDTO& dto) throw (database::Exception)
{
  MYSQL_RES* results;
  MYSQL_ROW row;

  std::string query = "SELECT * FROM Generalisations WHERE domain = " + util::itoa(dto.getId(), 10);
  executeQuery(handle, query);

  results = mysql_store_result(&handle);

  if (results != NULL) {
    int numberRows = 0;
    numberRows = mysql_num_rows(results);
    
    for (int i = 0; i < numberRows; i++) {
      row = mysql_fetch_row(results);
      ontologydto::GeneralisationDTO* gen = new ontologydto::GeneralisationDTO();
      gen->_id = atoi(row[0]);
      retrieve(handle, gen->_id, *gen);
      dto._generalisations.insert(gen);
    }

  } else {
    mysql_free_result(results);
    mysql_close(&handle);
    throw database::Exception("Null pointer returned on result set");

  }

  mysql_free_result(results);
  mysql_close(&handle);
}


void retrieveTypes(MYSQL& handle, ontologydto::DomainDTO& dto) throw (database::Exception)
{
  MYSQL_RES* results;
  MYSQL_ROW row;

  std::string query = "SELECT * FROM Concepts WHERE domain = " + util::itoa(dto.getId(), 10);
  executeQuery(handle, query);

  results = mysql_store_result(&handle);

  if (results != NULL) {
    int numberRows = 0;
    numberRows = mysql_num_rows(results);
    
    for (int i = 0; i < numberRows; i++) {
      row = mysql_fetch_row(results);
      ontologydto::TypeDTO* type = new ontologydto::TypeDTO();
      type->_id = atoi(row[0]);
      retrieve(handle, type->_id, *type);
      dto._types.insert(type);
    }

  } else {
    mysql_free_result(results);
    mysql_close(&handle);
    throw database::Exception("Null pointer returned on result set");

  }

  mysql_free_result(results);
  mysql_close(&handle);
}


void retrieveAssociations(MYSQL& handle, ontologydto::DomainDTO& dto) throw (database::Exception)
{
  MYSQL_RES* results;
  MYSQL_ROW row;

  std::string query = "SELECT * FROM Associations WHERE domain = " + util::itoa(dto.getId(), 10);
  executeQuery(handle, query);

  results = mysql_store_result(&handle);

  if (results != NULL) {
    int numberRows = 0;
    numberRows = mysql_num_rows(results);
    
    for (int i = 0; i < numberRows; i++) {
      row = mysql_fetch_row(results);
      ontologydto::AssociationDTO* assoc = new ontologydto::AssociationDTO();
      assoc->_id = atoi(row[0]);
      retrieve(handle, assoc->_id, *assoc);
      dto._associations.insert(assoc);
    }

  } else {
    mysql_free_result(results);
    mysql_close(&handle);
    throw database::Exception("Null pointer returned on result set");

  }

  mysql_free_result(results);
  mysql_close(&handle);
}


void retrieve(MYSQL& handle, int id, ontologydto::DomainDTO& dto) throw (database::Exception)
{
  MYSQL_RES* results;
  MYSQL_ROW row;

  std::string query = "SELECT * FROM Domains WHERE id = " + util::itoa(id, 10);
  executeQuery(handle, query);

  results = mysql_store_result(&handle);

  if (results != NULL) {
    int numberRows = 0;
    numberRows = mysql_num_rows(results);
    if (numberRows == 1) {
      row = mysql_fetch_row(results);

      dto.getId() = id;
      dto.getTitle() = row[1];
      dto.getDescription() = row[2];

      //      retrieveTypes(handle, dto);
      //      retrieveAssociations(handle, dto);
      //      retrieveGeneralisations(handle, dto);

    } else {
      throw database::Exception("No database entry for that record ID");
    }
  } else {
    mysql_free_result(results);
    mysql_close(&handle);
    throw database::Exception("Null pointer returned on result set");
  }

  mysql_free_result(results);
  mysql_close(&handle);
}


void retrieve(int id, ontologydto::DomainDTO& dto) throw (database::Exception)
{
  MYSQL handle;
  executeConnect(handle);

  retrieve(handle, id, dto);

  mysql_close(&handle);
}


void update(dto::UserDTO& dto) throw (database::Exception)
{
}


void update(dto::TechniqueDTO& dto) throw (database::Exception)
{
}


void update(ontologydto::DomainDTO& dto) throw (database::Exception)
{
}


void update(ontologydto::TypeDTO& dto) throw (database::Exception)
{
}


void update(ontologydto::EndDTO& dto) throw (database::Exception)
{
}


void update(ontologydto::AssociationDTO& dto) throw (database::Exception)
{
}


void update(ontologydto::GeneralisationDTO& dto) throw (database::Exception)
{
}


}


}
