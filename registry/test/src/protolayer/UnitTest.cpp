#include <string>

#include <protolayer/protolayer-ontologydto.h>
#include <protolayer/protolayer-ontoservice.h>
#include <protolayer/protolayer-database.h>
#include <protolayer/protolayer-persistence.h>

#include "ClientTest.hpp"

int main(int argc, char ** argv)
{
  try {
    protolayer::ontoservice::ClientTest clientTest;
    clientTest.testSuite();

  } catch (protolayer::database::Exception& ex) {
    std::cout << ex.getMessage() << std::endl;

  } catch (protolayer::persistence::Exception& ex) {
    std::cout << ex.getMessage() << std::endl;

  } catch (protolayer::Exception& ex) {
    std::cout << ex.getMessage() << std::endl;

  } catch (std::string msg) {
    std::cout << msg << std::endl;

  } catch (...) {
    std::cout << "failed general exception" << std::endl;
  }

  return 0;
}

