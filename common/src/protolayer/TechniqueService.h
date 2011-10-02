#ifndef PROTOLAYER_TECHNIQUE_H
#define PROTOLAYER_TECHNIQUE_H

#include <string>

#include "RootConceptInstance.h"

namespace protolayer
{

/**
 * TODO: Documentation
 * <p>
 */
class TechniqueService
{
  /** TODO: Documentation */
  const std::string _urn;

public:
  /**
   * TODO: Documentation
   *
   */
  TechniqueService(const std::string& urn);

  /**
   * TODO: Documentation
   *
   */
  virtual ~TechniqueService() = 0;

  /**
   * TODO: Documentation
   *
   */
  const std::string& getUrn() const;

  /**
   * TODO: Documentation
   *
   */
  virtual void populate(RootConceptInstance& instance) = 0;

  /**
   * TODO: Documentation
   *
   */
  virtual void validate(RootConceptInstance& instance) = 0;

  /**
   * TODO: Documentation
   *
   */
  virtual void evaluate(RootConceptInstance& instance) = 0;

  /**
   * TODO: Documentation
   *
   */
  //  virtual bool checkValue(const std::string& name, bool value);

  /**
   * TODO: Documentation
   *
   */
  //  virtual bool checkValue(const std::string& name, short value);

  /**
   * TODO: Documentation
   *
   */
  //  virtual bool checkValue(const std::string& name, int value);

  /**
   * TODO: Documentation
   *
   */
  //  virtual bool checkValue(const std::string& name, long value);

  /**
   * TODO: Documentation
   *
   */
  //  virtual bool checkValue(const std::string& name, float value);

  /**
   * TODO: Documentation
   *
   */
  //  virtual bool checkValue(const std::string& name, double value);

  /**
   * TODO: Documentation
   *
   */
  //  virtual bool checkValue(const std::string& name, const std::string& value);

};


}


#endif // PROTOLAYER_TECHNIQUE_H
