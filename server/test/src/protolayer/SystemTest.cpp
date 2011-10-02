#include <iostream>

#include <protolayer/protolayer-util.h>
#include <protolayer/xml.h>

#include "protolayer/protolayer-ontology.h"


int main(int argc, char ** argv)
{
  using namespace protolayer;

  //  std::string fileName(argv[0]);
  Ontology* ontology = 0;

  try {
    //    ontology = new Ontology(fileName);
  } catch (OntologyException ex) {
    std::cout << ex.getMessage() << std::endl;
    return 1;
  }

  return 0;
}

