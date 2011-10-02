#ifndef PROTOLAYER_CONTAINERSERVICE_ROOTCONCEPTINSTANCEIMPL_H
#define PROTOLAYER_CONTAINERSERVICE_ROOTCONCEPTINSTANCEIMPL_H

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
class RootConceptInstanceImpl : public ::protolayer::RootConceptInstance
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
  RootConceptInstanceImpl(iostream::XdrInputStream& istream);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~RootConceptInstanceImpl();

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
  RootConceptInstanceImpl(const RootConceptInstanceImpl& conceptInstanceImpl);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  RootConceptInstanceImpl& operator=(const RootConceptInstanceImpl& conceptInstanceImpl);

  /**
   * TODO: Documentation
   *
   */
  void decodeInstances(iostream::XdrInputStream& istream);

  /**
   * TODO: Documentation
   *
   */
  void decodeReferences(iostream::XdrInputStream& istream);

  /**
   * TODO: Documentation
   *
   */
  void encodeAttributes(iostream::XdrOutputStream& ostream);

};


}


}


#endif // PROTOLAYER_CONTAINERSERVICE_ROOTCONCEPTINSTANCEIMPL_H
