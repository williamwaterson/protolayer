#ifndef PROTOLAYER_CONTAINERSERVICE_IMMUTABLECONCEPTINSTANCEIMPL_H
#define PROTOLAYER_CONTAINERSERVICE_IMMUTABLECONCEPTINSTANCEIMPL_H

#include <stdexcept>
#include <map>

#include <protolayer/protolayer.h>
#include <protolayer/protolayer-iostream.h>

#include "Exception.h"

namespace protolayer
{

namespace containerservice
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.3 $
 */
class ImmutableConceptInstanceImpl : public ::protolayer::ImmutableConceptInstance
{
  /** TODO: Documentation */
  std::map <std::string, bool> _boolTuples;

  /** TODO: Documentation */
  std::map <std::string, short> _shortTuples;

  /** TODO: Documentation */
  std::map <std::string, int> _intTuples;

  /** TODO: Documentation */
  std::map <std::string, long> _longTuples;

  /** TODO: Documentation */
  std::map <std::string, float> _floatTuples;

  /** TODO: Documentation */
  std::map <std::string, double> _doubleTuples;

  /** TODO: Documentation */
  std::map <std::string, std::string> _stringTuples;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  ImmutableConceptInstanceImpl();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~ImmutableConceptInstanceImpl();

  /**
   * TODO: Documentation
   *
   */
  void encode(iostream::XdrOutputStream& stream);

  /**
   * TODO: Documentation
   *
   */
  bool getBoolValue(const std::string& name) const;

  /**
   * TODO: Documentation
   *
   */
  short getShortValue(const std::string& name) const;

  /**
   * TODO: Documentation
   *
   */
  long getLongValue(const std::string& name) const;

  /**
   * TODO: Documentation
   *
   */
  float getFloatValue(const std::string& name) const;

  /**
   * TODO: Documentation
   *
   */
  double getDoubleValue(const std::string& name) const;

  /**
   * TODO: Documentation
   *
   */
  const std::string& getStringValue(const std::string& name) const;

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  ImmutableConceptInstanceImpl(const ImmutableConceptInstanceImpl& conceptInstance);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  ImmutableConceptInstanceImpl& operator=(const ImmutableConceptInstanceImpl& conceptInstance);

};


}


}


#endif // PROTOLAYER_CONTAINERSERVICE_IMMUTABLECONCEPTINSTANCEIMPL_H
