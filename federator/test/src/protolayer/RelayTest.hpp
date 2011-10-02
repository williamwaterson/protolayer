#ifndef PROTOLAYER_ONTOLOGY_RELAYTEST_HPP
#define PROTOLAYER_ONTOLOGY_RELAYTEST_HPP

#include <iostream.h>
#include <map>
#include <string>

#include <protolayer/protolayer-relayservice.h>

namespace protolayer
{

namespace federator
{

class RelayTest
{
public:
  /**
   * TODO: Documentation
   *
   */
  RelayTest()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
 ~RelayTest()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testSuite()
  {
    try {
      setUp();
      testConstruction();
      tearDown();

    } catch (relayservice::Exception ex) {
      std::cout << ex.getMessage() << std::endl;
    }
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void setUp()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testConstruction()
  {
    relayservice::Client client(80005);

    int id = 1;
    std::string location = "127.0.0.1";
    client.addLocation(id, location);
    location = client.nextLocation(1);

    std::cout << location << std::endl;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void tearDown()
  {
  }

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  RelayTest(const RelayTest& relayTest);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  RelayTest& operator=(const RelayTest& relayTest);

};


}


}


#endif // PROTOLAYER_RELAY_RELAYTEST_H
