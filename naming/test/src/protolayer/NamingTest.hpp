#ifndef PROTOLAYER_ONTOLOGY_FACADETEST_HPP
#define PROTOLAYER_ONTOLOGY_FACADETEST_HPP

#include <map>
#include <string>
#include <iostream>

#include "protolayer/protolayer-naming.h"

namespace protolayer
{

namespace naming
{

class NamingTest
{
public:
  /**
   * TODO: Documentation
   *
   */
  NamingTest()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
  ~NamingTest()
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
      testScopedName();
      tearDown();

    } catch (...) {
      std::cout << "Failure" << std::endl;
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
  void tearDown()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testScopedName()
  {
  }

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  NamingTest(const NamingTest& namingTest);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  NamingTest& operator=(const NamingTest& namingTest);

};


}


}


#endif // PROTOLAYER_ONTOLOGY_FACADETEST_H
