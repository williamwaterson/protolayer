#ifndef PROTOLAYER_ONTOLOGY_FACADETEST_HPP
#define PROTOLAYER_ONTOLOGY_FACADETEST_HPP

#include <map>
#include <string>

#include "protolayer/protolayer-database.h"
#include <protolayer/protolayer-dto.h>
#include "protolayer/protolayer-ontologydto.h"


namespace protolayer
{

namespace database
{

class FacadeTest
{
public:
  /**
   * TODO: Documentation
   *
   */
  FacadeTest()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
  ~FacadeTest()
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
      testUser();
      tearDown();

      setUp();
      testDomain();
      tearDown();

      setUp();
      testType();
      tearDown();

      setUp();
      testEnd();
      tearDown();

      setUp();
      testAssociation();
      tearDown();

      setUp();
      testGeneralisation();
      tearDown();

      setUp();
      testTechnique();
      tearDown();

    } catch (database::Exception ex) {
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
  void testUser()
  {
    dto::UserDTO userDTO;
    userDTO.getUsername() = "fred";
    userDTO.getPassword() = "fredpassword";
    userDTO.getEmail() = "fred@emailaddress";
    create(userDTO);
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testDomain()
  {
    protolayer::ontologydto::DomainDTO domainDTO;
    domainDTO.getTitle() = "Chemistry";
    domainDTO.getDescription() = "A longer description";
    create(domainDTO);
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testType()
  {
    protolayer::ontologydto::TypeDTO typeDTO;
    typeDTO.getName() = "Atom";
    typeDTO.isAbstract() = true;
    typeDTO.isLeaf() = false;
    typeDTO.isSingleton() = false;
    int id = create(typeDTO);

    bool result = findType(id);
    result = findType(id + 1);

    ontologydto::TypeDTO findObject;
    try {
      retrieve(id, findObject);
    } catch (...) {
      std::cout << "Incorrectly failed to get stored object" << std::endl;
    }

    try {
      retrieve(id + 1, findObject);
    } catch (...) {
      std::cout << "Correctly failed to get stored object" << std::endl;
    }

    findObject.getId() = id;
    try {
      retrieve(findObject);
    } catch (...) {
      std::cout << "Incorrectly failed to get stored object" << std::endl;
    }

    findObject.getId() = id + 1;
    try {
      retrieve(findObject);
    } catch (...) {
      std::cout << "Correctly failed to get stored object" << std::endl;
    }

    removeType(id);
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testEnd()
  {
    protolayer::ontologydto::EndDTO endDTO;
    create(endDTO);
  }


  /**
   * TODO: Documentation
   * <p>
   */
  void testAssociation()
  {
    protolayer::ontologydto::AssociationDTO assocDTO;
    create(assocDTO);
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testGeneralisation()
  {
    protolayer::ontologydto::GeneralisationDTO genDTO;
    create(genDTO);
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testTechnique()
  {
    protolayer::dto::TechniqueDTO techDTO;
    create(techDTO);
  }

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  FacadeTest(const FacadeTest& FacadeTest);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  FacadeTest& operator=(const FacadeTest& FacadeTest);

};


}


}


#endif // PROTOLAYER_ONTOLOGY_FACADETEST_H
