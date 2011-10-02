#include <iostream.h>

#include <protolayer/protolayer-containerservice.h>

#include <string>
#include <protolayer/protolayer-assembly.h>
#include <protolayer/protolayer-ontology.h>
#include <protolayer/protolayer-xml.h>

#include "InstanceTest.hpp"

int main(int argc, char ** argv)
{
  protolayer::assembly::InstanceTest instanceTest;
  instanceTest.testSuite();
  //  try {
  //    protolayer::containerservice::Client _client(50000);




    //    _client.populate(instance);
    //    _client.validate(instance);
    //    _client.evaluate(instance);

  //  } catch (protolayer::containerservice::Exception ex) {
  //    std::cout << "failed" << std::endl;
  //  }

  return 0;
}

