#include <string>

#include <protolayer/protolayer-nameservice.h>
#include <protolayer/protolayer-containerservice.h>

#include "InstanceTest.hpp"

int main(int argc, char ** argv)
{
  protolayer::assembly::InstanceTest instanceTest;
  instanceTest.testSuite();

  return 0;
}

