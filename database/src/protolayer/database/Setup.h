#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <mysql/mysql.h>

#include "ConnectionPool.h"

void dropDatabase() {
  try {
    database::Connection connection;  
    connection.query("DROP DATABASE IF EXISTS Protolayer");
  } catch (database::Exception ex) {
    std::cout << ex.getMessage() << std::endl;
  }
}

void createDatabase() {
  try {
    database::Connection connection;  
    connection.query("CREATE DATABASE Protolayer;");
  } catch (database::Exception ex) {
    std::cout << ex.getMessage() << std::endl;
  }
}


void createTables() {
  database::Connection connection;

  try {
    connection.query("USE Protolayer;");

    connection.query("CREATE TABLE Ontologies(id INT UNSIGNED NOT NULL AUTO_INCREMENT, PRIMARY KEY(id), urn VARCHAR(255), community_id INT UNSIGNED)");
    connection.query("CREATE TABLE Concepts(id INT UNSIGNED NOT NULL AUTO_INCREMENT, PRIMARY KEY(id), name VARCHAR(255), ontology_id INT UNSIGNED NOT NULL)");
    connection.query("CREATE TABLE Techniques(id INT UNSIGNED NOT NULL AUTO_INCREMENT, PRIMARY KEY(id), urn VARCHAR(255), concept_id INT UNSIGNED NOT NULL)");
    connection.query("CREATE TABLE Keywords(id INT UNSIGNED NOT NULL AUTO_INCREMENT, PRIMARY KEY(id))");
    connection.query("CREATE TABLE Communities(id INT UNSIGNED NOT NULL AUTO_INCREMENT, PRIMARY KEY(id))");
    connection.query("CREATE TABLE Keywords_Ontologies(keyword_id INT UNSIGNED, ontology_id INT UNSIGNED)");
    connection.query("CREATE TABLE Keywords_Techniques(keyword_id INT UNSIGNED, technique_id INT UNSIGNED)");
    connection.query("CREATE TABLE Keywords_Communities(keyword_id INT UNSIGNED, community_id INT UNSIGNED)");
    connection.query("CREATE TABLE Users(id INT UNSIGNED NOT NULL AUTO_INCREMENT, PRIMARY KEY(id), first_name VARCHAR(255), last_name VARCHAR(255), email VARCHAR(255))");
    connection.query("CREATE TABLE Communities_Users(community_id INT UNSIGNED, member_user_id INT UNSIGNED)");
    connection.query("CREATE TABLE Versions(id INT UNSIGNED NOT NULL AUTO_INCREMENT, PRIMARY KEY(id), modification_datetime DATETIME, modified_by_user_id INT UNSIGNED, xml_content LONGBLOB)");
    connection.query("CREATE TABLE Ontologies_Versions(ontology_id INT UNSIGNED NOT NULL, version_id INT UNSIGNED NOT NULL)");
    connection.query("CREATE TABLE Techniques_Versions(technique_id INT UNSIGNED NOT NULL, version_id INT UNSIGNED NOT NULL)");
  } catch (database::Exception& ex) {
    std::cout << ex.getMessage() << std::endl;
  }
}


int main() {
  dropDatabase();
  createDatabase();
  createTables();

  return 0;
}
