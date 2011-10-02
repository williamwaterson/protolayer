#include <string>

//#include <protolayer/protolayer-ontology.h>
//#include <protolayer/protolayer-nameservice.h>
//#include "OntologyTest.hpp"

#include "RelayTest.hpp"

int main(int argc, char ** argv)
{
  try {
    //    protolayer::ontology::OntologyTest ontologyTest;
    //    ontologyTest.testSuite();

    protolayer::federator::RelayTest relayTest;
    relayTest.testSuite();

  } catch (...) {
    std::cout << "failed general exception" << std::endl;
  }

  return 0;
}

