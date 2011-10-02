#ifndef PROTOLAYER_REGISTRY_CLIENTTEST_HPP
#define PROTOLAYER_REGISTRY_CLIENTTEST_HPP

#include <iostream.h>
#include <map>
#include <string>

#include <protolayer/protolayer-util.h>

#include "protolayer/protolayer-ontoservice.h"
#include "protolayer/protolayer-ontologydto.h"
#include "protolayer/protolayer-dto.h"

namespace protolayer
{

namespace ontoservice
{

class ClientTest
{
public:
  /**
   * TODO: Documentation
   *
   */
  ClientTest()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
 ~ClientTest()
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
      //      testType();
      tearDown();

      setUp();
      //      testUser();
      tearDown();

      setUp();
      //      testAssociation();
      tearDown();

      setUp();
      //      testDomain();
      tearDown();

      setUp();
      testCreateDomain();
      tearDown();

      setUp();
      //      testDisallowedDomainRemoval();
      tearDown();

      setUp();
      //      testTechnique();
      tearDown();

      setUp();
      //      testGeneralisation();
      tearDown();

    } catch (ontology::Exception ex) {
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
  void testType()
  {
    ontologydto::TypeDTO object;

    object.getName() = "Atom";
    object.isAbstract() = true;
    object.isLeaf() = false;
    object.isSingleton() = false;

    int id;

    ontoservice::Client client(80003);
    id = client.add(object);

    bool result = client.findType(id);

    result = client.findType(id + 1);

    ontologydto::TypeDTO findObject;
    result = client.retrieve(id, findObject); 

    try {
      result = client.retrieve(id + 1, findObject);
    } catch (...) {
      std::cout << "Successful failure" << std::endl;
    }

    result = client.retrieve(findObject);

    findObject.getId() = id + 1;

    try {
      result = client.retrieve(findObject);
    } catch (...) {
      std::cout << "Successful failure" << std::endl;
    }

    client.removeType(id);
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testDomain()
  {
    ontologydto::DomainDTO domain;

    ontoservice::Client client(80003);
    int id1 = client.add(domain);
    int id2 = client.add(domain);
    
    client.retrieve(id1, domain);
    client.retrieve(id2, domain);

    client.removeDomain(id1);
    client.removeDomain(id2);
  }

  void testDisallowedDomainRemoval()
  {
    ontoservice::Client client(80003);

    ontologydto::DomainDTO* domain = 0;

    ontologydto::TypeDTO* type = 0;


    domain = new ontologydto::DomainDTO("Chemistry");

    type = new ontologydto::TypeDTO("Element");
    domain->getTypes().insert(type);

    type = new ontologydto::TypeDTO("Atom");
    domain->getTypes().insert(type);

    type = new ontologydto::TypeDTO("Bond");
    domain->getTypes().insert(type);

    type = new ontologydto::TypeDTO("Molecule");
    domain->getTypes().insert(type);

    type = new ontologydto::TypeDTO("Chemical");
    domain->getTypes().insert(type);

    type = new ontologydto::TypeDTO("Phase");
    domain->getTypes().insert(type);

    type = new ontologydto::TypeDTO();
    type->getName() = "Composite";
    domain->getTypes().insert(type);


    ontologydto::AssociationDTO* assoc = new ontologydto::AssociationDTO("Atom", "Element");
    domain->getAssociations().insert(assoc);

    assoc = new ontologydto::AssociationDTO("Bond", "Atom");
    domain->getAssociations().insert(assoc);

    assoc = new ontologydto::AssociationDTO("Molecule", "Atom");
    domain->getAssociations().insert(assoc);

    assoc = new ontologydto::AssociationDTO("Molecule", "Bond");
    domain->getAssociations().insert(assoc);

    assoc = new ontologydto::AssociationDTO("Molecule", "Bond");
    domain->getAssociations().insert(assoc);

    assoc = new ontologydto::AssociationDTO("Phase", "Chemical");
    domain->getAssociations().insert(assoc);    

    assoc = new ontologydto::AssociationDTO("Composite", "Phase");
    domain->getAssociations().insert(assoc);

    int chemistryDomainId = client.add(*domain);
    ontologydto::DomainDTO chDTO;
    client.retrieve(chemistryDomainId, chDTO);

    delete domain;


    domain = new ontologydto::DomainDTO("Spatial");

    type = new ontologydto::TypeDTO("Vertex");
    domain->getTypes().insert(type);

    type = new ontologydto::TypeDTO("Edge");
    domain->getTypes().insert(type);

    type = new ontologydto::TypeDTO("Face");
    domain->getTypes().insert(type);

    type = new ontologydto::TypeDTO("Region");
    domain->getTypes().insert(type);

    assoc = new ontologydto::AssociationDTO("Edge", "Vertex");
    domain->getAssociations().insert(assoc);

    assoc = new ontologydto::AssociationDTO("Face", "Edge");
    domain->getAssociations().insert(assoc);

    assoc = new ontologydto::AssociationDTO("Region", "Face");
    domain->getAssociations().insert(assoc);

    int spatialDomainId = client.add(*domain);


    ontologydto::DomainDTO sDTO;
    client.retrieve(spatialDomainId, sDTO);

    delete domain;
    domain = new ontologydto::DomainDTO("Chemical Engineering (Coarse Grained)");

    type = new ontologydto::TypeDTO("Particulate");
    domain->getTypes().insert(type);

    type = new ontologydto::TypeDTO("System");
    domain->getTypes().insert(type);

    type = new ontologydto::TypeDTO("Stream");
    domain->getTypes().insert(type);

    assoc = new ontologydto::AssociationDTO("System", "Particulate");
    domain->getAssociations().insert(assoc);

    assoc = new ontologydto::AssociationDTO("Particulate", "1:Composite");
    domain->getAssociations().insert(assoc);

    assoc = new ontologydto::AssociationDTO("Stream", "System");
    domain->getAssociations().insert(assoc);

    ontologydto::GeneralisationDTO* gen = new ontologydto::GeneralisationDTO("Stream", "System");
    domain->_generalisations.insert(gen);

    int chemengId = client.add(*domain);
    ontologydto::DomainDTO ceDTO;

    client.retrieve(chemengId, ceDTO);

    try {
      client.removeDomain(spatialDomainId);
      client.removeDomain(chemistryDomainId);
      client.removeDomain(chemengId);

    } catch (database::Exception& ex) {
      std::cout << "database::Exception " << ex.getMessage() << std::endl;

    } catch (persistence::Exception& ex) {
      std::cout << "persistence::Exception " << ex.getMessage() << std::endl;

    } catch (...) {
      std::cout << "Some other exception type" << std::endl;
      
    }

  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testCreateDomain()
  {
    ontoservice::Client client(80003);

    ontologydto::DomainDTO* domain = 0;

    ontologydto::TypeDTO* type = 0;


    domain = new ontologydto::DomainDTO("Chemistry");

    type = new ontologydto::TypeDTO("Element");
    domain->getTypes().insert(type);

    type = new ontologydto::TypeDTO("Atom");
    domain->getTypes().insert(type);

    type = new ontologydto::TypeDTO("Bond");
    domain->getTypes().insert(type);

    type = new ontologydto::TypeDTO("Molecule");
    domain->getTypes().insert(type);

    type = new ontologydto::TypeDTO("Chemical");
    domain->getTypes().insert(type);

    type = new ontologydto::TypeDTO("Phase");
    domain->getTypes().insert(type);

    type = new ontologydto::TypeDTO();
    type->getName() = "Composite";
    domain->getTypes().insert(type);


    ontologydto::AssociationDTO* assoc = new ontologydto::AssociationDTO("Atom", "Element");
    domain->getAssociations().insert(assoc);

    assoc = new ontologydto::AssociationDTO("Bond", "Atom");
    domain->getAssociations().insert(assoc);

    assoc = new ontologydto::AssociationDTO("Molecule", "Atom");
    domain->getAssociations().insert(assoc);

    assoc = new ontologydto::AssociationDTO("Molecule", "Bond");
    domain->getAssociations().insert(assoc);

    assoc = new ontologydto::AssociationDTO("Molecule", "Bond");
    domain->getAssociations().insert(assoc);

    assoc = new ontologydto::AssociationDTO("Phase", "Chemical");
    domain->getAssociations().insert(assoc);    

    assoc = new ontologydto::AssociationDTO("Composite", "Phase");
    domain->getAssociations().insert(assoc);

    int chemistryDomainId = client.add(*domain);
    ontologydto::DomainDTO chDTO;
    client.retrieve(chemistryDomainId, chDTO);

    delete domain;


    domain = new ontologydto::DomainDTO("Spatial");

    type = new ontologydto::TypeDTO("Vertex");
    domain->getTypes().insert(type);

    type = new ontologydto::TypeDTO("Edge");
    domain->getTypes().insert(type);

    type = new ontologydto::TypeDTO("Face");
    domain->getTypes().insert(type);

    type = new ontologydto::TypeDTO("Region");
    domain->getTypes().insert(type);

    assoc = new ontologydto::AssociationDTO("Edge", "Vertex");
    domain->getAssociations().insert(assoc);

    assoc = new ontologydto::AssociationDTO("Face", "Edge");
    domain->getAssociations().insert(assoc);

    assoc = new ontologydto::AssociationDTO("Region", "Face");
    domain->getAssociations().insert(assoc);

    int spatialDomainId = client.add(*domain);


    ontologydto::DomainDTO sDTO;
    client.retrieve(spatialDomainId, sDTO);

    delete domain;
    domain = new ontologydto::DomainDTO("Chemical Engineering (Coarse Grained)");

    type = new ontologydto::TypeDTO("Particulate");
    domain->getTypes().insert(type);

    type = new ontologydto::TypeDTO("System");
    domain->getTypes().insert(type);

    type = new ontologydto::TypeDTO("Stream");
    domain->getTypes().insert(type);

    assoc = new ontologydto::AssociationDTO("System", "Particulate");
    domain->getAssociations().insert(assoc);

    assoc = new ontologydto::AssociationDTO("Particulate", "1:Composite");
    domain->getAssociations().insert(assoc);

    assoc = new ontologydto::AssociationDTO("Stream", "System");
    domain->getAssociations().insert(assoc);

    ontologydto::GeneralisationDTO* gen = new ontologydto::GeneralisationDTO("Stream", "System");
    domain->_generalisations.insert(gen);

    int chemengId = client.add(*domain);
    ontologydto::DomainDTO ceDTO;

    client.retrieve(chemengId, ceDTO);

    client.removeDomain(chemengId);
    client.removeDomain(spatialDomainId);
    client.removeDomain(chemistryDomainId);



    /*
    assoc.getFromEnd().getConceptId() = bondId;
    assoc.getToEnd().getConceptId() = atomId;
    client.add(assoc);

    assoc.getFromEnd().getConceptId() = moleculeId;
    assoc.getToEnd().getConceptId() = atomId;
    client.add(assoc);

    assoc.getFromEnd().getConceptId() = moleculeId;
    assoc.getToEnd().getConceptId() = bondId;
    client.add(assoc);

    assoc.getFromEnd().getConceptId() = chemicalId;
    assoc.getToEnd().getConceptId() = moleculeId;
    client.add(assoc);

    assoc.getFromEnd().getConceptId() = phaseId;
    assoc.getToEnd().getConceptId() = chemicalId;
    client.add(assoc);



    assoc.getFromEnd().getConceptId() = systemId;
    assoc.getToEnd().getConceptId() = compositeId;
    client.add(assoc);

    assoc.getFromEnd().getConceptId() = compositeId;
    assoc.getToEnd().getConceptId() = phaseId;
    client.add(assoc);

    assoc.getFromEnd().getConceptId() = particulateId;
    assoc.getToEnd().getConceptId() = compositeId;
    client.add(assoc);



    ontologydto::DomainDTO findDomain;
    bool result = client.retrieve(chemistryId, findDomain); 

    findDomain.getTypes();
    */
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testAssociation()
  {
    ontologydto::AssociationDTO association;

    ontoservice::Client client(80003);
    int id = client.add(association);

    client.removeAssociation(id);
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testGeneralisation()
  {
    ontologydto::GeneralisationDTO generalisation;

    ontoservice::Client client(80003);
    int id = client.add(generalisation);

    client.removeGeneralisation(id);
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testUser()
  {
    dto::UserDTO user;
    user.getUsername() = "fred";
    user.getPassword() = "fredpassword";
    user.getEmail() = "fred@emailaddress";

    ontoservice::Client client(80003);
    int id = client.add(user);

    client.removeUser(id);
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void testTechnique()
  {
    dto::TechniqueDTO technique;

    ontoservice::Client client(80003);
    int id = client.add(technique);

    client.removeTechnique(id);
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
  ClientTest(const ClientTest& clientTest);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  ClientTest& operator=(const ClientTest& clientTest);

};


}


}


#endif // PROTOLAYER_REGISTRY_CLIENTTEST_H
