#include <stdio.h>
#include <iostream.h>
#include <protolayer/protolayer-util.h>
#include <protolayer/protolayer.h>


int main()
{
  return 1;
}


class ExtendedTechnique : public ::protolayer::TechniqueService
{
public:
  /** TODO: Documentation */
  ExtendedTechnique() : protolayer::TechniqueService("urn:protolayer:tech1")
  {
  }

  /**
   * TODO: Documentation
   *
   */
  void populate(protolayer::RootConceptInstance& instance)
  {
    std::cout << "populate called on instance" << std::endl;
  }

  /**
   * TODO: Documentation
   *
   */
  void validate(protolayer::RootConceptInstance& instance)
  {
    std::cout << "validate called on instance" << std::endl;
  }

  /**
   * TODO: Documentation
   *
   */
  void evaluate(protolayer::RootConceptInstance& instance)
  {
    std::cout << "evaluate called on instance" << std::endl;
  }

};


extern "C" ::protolayer::TechniqueService* constructTechniqueService()
{
  ExtendedTechnique* created = 0;
  created = new ExtendedTechnique();
  std::cout << "created address " << created << std::endl;
  if (created == 0) {
    printf("failed to construct\n");
  }

  return created;
}
