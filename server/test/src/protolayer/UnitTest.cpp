#include <string>
#include "protolayer/protolayer-ontology.h"

#include "AssociationTest.hpp"
#include "DomainTest.hpp"
#include "EndTest.hpp"
#include "GeneralisationTest.hpp"
#include "MultiplicityTest.hpp"
#include "OntologyTest.hpp"
#include "OntologyExceptionTest.hpp"
#include "TypeTest.hpp"

int main(int argc, char ** argv)
{
  protolayer::OntologyTest ontologyTest;
  ontologyTest.testSuite();

  protolayer::OntologyExceptionTest ontoExceptionTest;
  ontoExceptionTest.testSuite();

  protolayer::AssociationTest associationTest;
  associationTest.testSuite();

  protolayer::DomainTest domainTest;
  domainTest.testSuite();

  protolayer::GeneralisationTest genTest;
  genTest.testSuite();

  protolayer::EndTest endTest;
  endTest.testSuite();

  protolayer::MultiplicityTest mulTest;
  mulTest.testSuite();

  protolayer::TypeTest typeTest;
  typeTest.testSuite();

  return 0;
}

