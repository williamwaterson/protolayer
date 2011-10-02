#include <string>
#include "protolayer/protolayer-ontologydto.h"

#include "AssociationTest.hpp"
#include "DomainTest.hpp"
#include "EndTest.hpp"
#include "GeneralisationTest.hpp"
#include "TypeTest.hpp"

int main(int argc, char ** argv)
{
  protolayer::ontologydto::TypeTest typeTest;
  typeTest.testSuite();

  protolayer::ontologydto::GeneralisationTest genTest;
  genTest.testSuite();

  protolayer::ontologydto::EndTest endTest;
  endTest.testSuite();

  protolayer::ontologydto::AssociationTest associationTest;
  associationTest.testSuite();

  protolayer::ontologydto::DomainTest domainTest;
  domainTest.testSuite();

  return 0;
}

