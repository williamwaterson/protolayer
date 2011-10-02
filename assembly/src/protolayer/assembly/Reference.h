#ifndef PROTOLAYER_REFERENCE_H
#define PROTOLAYER_REFERENCE_H

#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLChar.hpp>
#include <xercesc/util/XMLString.hpp>

#include <protolayer/protolayer-iostream.h>
#include <protolayer/protolayer-ontology.h>
#include <protolayer/protolayer-util.h>

#include "Exception.h"
#include "Instance.h"

namespace protolayer
{

namespace assembly
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.3 $
 */
class Reference : public util::Object
{
  /** TODO: Documentation */
  ontology::Association* _association;

  /** TODO: Documentation */
  Instance* _fromInstance;

  /** TODO: Documentation */
  Instance* _toInstance;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Reference(ontology::Association& association,
            Instance& fromInstance,
            Instance& toInstance)
    throw (Exception);

  /**
   * TODO: Documentation
   * <p>
   */
  Reference(iostream::XdrInputStream& stream,
            std::map <int, void*>& addressMappings);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Reference();

  /**
   * TODO: Documentation
   * <p>
   */
  ontology::Association& getAssociation();

  /**
   * TODO: Documentation
   * <p>
   */
  void encode(iostream::XdrOutputStream& stream);

  /**
   * TODO: Documentation
   * <p>
   */
  void encode(xercesc::DOMElement& element);

  /**
   * TODO: Documentation
   * <p>
   */
  Instance& getFromInstance();

  /**
   * TODO: Documentation
   * <p>
   */
  Instance& getToInstance();

  /**
   * TODO: Documentation
   * <p>
   */
  bool isAssociation(ontology::Association& association);

  /**
   * TODO: Documentation
   * <p>
   */
  bool isFromInstance(Instance& instance);

  /**
   * TODO: Documentation
   * <p>
   */
  bool isToInstance(Instance& instance);

  /**
   * TODO: Documentation
   * <p>
   */
  bool involves(Instance& instance);

  /**
   * TODO: Documentation
   * <p>
   */
  bool involves(Instance& someInstance, Instance& anotherInstance);

  /**
   * TODO: Documentation
   * <p>
   */
  bool matches(Instance& fromInstance, Instance& toInstance);

  /**
   * TODO: Documentation
   * <p>
   */
  bool isEquivalent(Reference& reference);

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Reference(const Reference& reference);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Reference& operator=(const Reference& reference);

};


}


}


#endif // PROTOLAYER_REFERENCE_H
