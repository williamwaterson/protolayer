#include <string>
#include "protolayer/protolayer-database.h"

#include "FacadeTest.hpp"

int main(int argc, char ** argv)
{
  protolayer::database::FacadeTest facadeTest;
  facadeTest.testSuite();

  return 0;
}

