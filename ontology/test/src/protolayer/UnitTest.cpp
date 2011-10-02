#include <string>
#include "protolayer/protolayer-ontology.h"
#include "protolayer/protolayer-ontologydto.h"


#include "AssociationTest.hpp"
#include "DomainTest.hpp"
#include "EndTest.hpp"
#include "GeneralisationTest.hpp"
//#include "MultiplicityTest.hpp"
#include "OntologyTest.hpp"
//#include "OntologyExceptionTest.hpp"
#include "TypeTest.hpp"

int main(int argc, char ** argv)
{
  protolayer::ontology::OntologyTest ontologyTest;
  ontologyTest.testSuite();

  //  protolayer::ontology::ExceptionTest ontoExceptionTest;
  //  ontoExceptionTest.testSuite();

  protolayer::ontology::AssociationTest associationTest;
  associationTest.testSuite();

  protolayer::ontology::DomainTest domainTest;
  domainTest.testSuite();

  protolayer::ontology::GeneralisationTest genTest;
  genTest.testSuite();

  protolayer::ontology::EndTest endTest;
  endTest.testSuite();

  protolayer::ontology::TypeTest typeTest;
  typeTest.testSuite();

  return 0;
}

