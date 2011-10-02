#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "mysql.h"

#include "protolayer/protolayer-database.h"

#include "TypeManager.h"
#include "EndManager.h"
#include "AssociationManager.h"
#include "GeneralisationManager.h"
#include "DomainManager.h"
#include "Exception.h"


namespace protolayer
{

namespace persistence
{

void dropDatabase() {
  database::Connection connection;
  connection.query("DROP DATABASE IF EXISTS Protolayer");
}


void createDatabase() {
  database::Connection connection;
  connection.query("CREATE DATABASE Protolayer;");
}


void createTables() {
  TypeManager::setup();
  EndManager::setup();
  AssociationManager::setup();
  GeneralisationManager::setup();
  DomainManager::setup();

  //  database::Connection connection;

  //  connection.query("USE Protolayer;");
  //  connection.query("CREATE TABLE Domains(id INT UNSIGNED NOT NULL AUTO_INCREMENT, PRIMARY KEY(id), title VARCHAR(255), description VARCHAR(100000), creator INT UNSIGNED)");
  //  connection.query("CREATE TABLE Concepts(id INT UNSIGNED NOT NULL AUTO_INCREMENT, PRIMARY KEY(id), name VARCHAR(255), domain INT UNSIGNED, isLeaf BOOL, isAbstract BOOL, isSingleton BOOL)");
  //  connection.query("CREATE TABLE Associations(id INT UNSIGNED NOT NULL AUTO_INCREMENT, PRIMARY KEY(id), fromEnd INT UNSIGNED NOT NULL, toEnd INT UNSIGNED NOT NULL)");
  //  connection.query("CREATE TABLE Generalisations(id INT UNSIGNED NOT NULL AUTO_INCREMENT, PRIMARY KEY(id), superType INT UNSIGNED NOT NULL, subType INT UNSIGNED NOT NULL)");
  //  connection.query("CREATE TABLE Ends(id INT UNSIGNED NOT NULL AUTO_INCREMENT, PRIMARY KEY(id), label VARCHAR(255), concept INT UNSIGNED, multiplicity VARCHAR(255))");
  //  connection.query("CREATE TABLE Techniques(id INT UNSIGNED NOT NULL AUTO_INCREMENT, PRIMARY KEY(id), title VARCHAR(255), description VARCHAR(100000), concept INT UNSIGNED NOT NULL)");

  //  connection.query("CREATE TABLE Keywords(id INT UNSIGNED NOT NULL AUTO_INCREMENT, PRIMARY KEY(id), keyword VARCHAR(50) NOT NULL)");
  //  connection.query("CREATE TABLE DomainDictionary(keyword INT UNSIGNED NOT NULL, domain INT UNSIGNED NOT NULL)");
  //  connection.query("CREATE TABLE TechniqueDictionary(keyword INT UNSIGNED NOT NULL, technique INT UNSIGNED NOT NULL)");
  //  connection.query("CREATE TABLE Users(id INT UNSIGNED NOT NULL AUTO_INCREMENT, PRIMARY KEY(id), username VARCHAR(255) NOT NULL, password VARCHAR(255) NOT NULL, email VARCHAR(255))");
  //  connection.query("CREATE TABLE DomainVersions(domain INT UNSIGNED NOT NULL, version INT UNSIGNED NOT NULL, timestamp DATETIME, auther INT UNSIGNED)");
  //  connection.query("CREATE TABLE TechniqueVersions(concept INT UNSIGNED NOT NULL, version INT UNSIGNED NOT NULL, timestamp DATETIME, auther INT UNSIGNED)");
}


}


}

int main() {

  try {
    protolayer::persistence::dropDatabase();
    protolayer::persistence::createDatabase();
    protolayer::persistence::createTables();

  } catch (protolayer::database::Exception& ex) {
    std::cout << ex.getMessage() << std::endl;
    return 1;

  } catch (protolayer::persistence::Exception& ex) {
    std::cout << ex.getMessage() << std::endl;
    return 1;

  }

  return 0;
}
