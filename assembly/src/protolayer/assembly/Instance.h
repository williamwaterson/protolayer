#ifndef PROTOLAYER_INSTANCE_H
#define PROTOLAYER_INSTANCE_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/types.h>
#include <sys/uio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <map>
#include <set>

#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLChar.hpp>
#include <xercesc/util/XMLString.hpp>

#include <protolayer/protolayer-iostream.h>
#include <protolayer/protolayer-ontology.h>
#include <protolayer/protolayer-net.h>
//#include <protolayer/protolayer-xul.h>
#include <protolayer/protolayer-util.h>

#include "Exception.h"


namespace protolayer
{

namespace assembly
{

/**
 *  Forward declaration to allow the Reference class to
 *  befriend of Instance, allowing hidden modification
 *  of the reference map attribute for serialisation purposes
 *  when sent over the wire to the technique server.
 */
class Reference;

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.6 $
 */
class Instance : public util::Object
{
  /** TODO: Documentation */
  friend class Reference;

  /** TODO: Documentation */
  typedef std::set <Instance*> InstanceSetType;

  /** TODO: Documentation */
  typedef std::map <ontology::Association*,  InstanceSetType> ReferenceMapType;

private:
  /** TODO: Documentation */
  ontology::Type* _type;

  /** TODO: Documentation */
  std::string _name;

  /** TODO: Documentation */
  ReferenceMapType _references;

private:
  /** Structure tech:techId:version:instId */
  int _instId;

  /** Full structure urn:protolayer:tech:techId:version:instId */
  std::string _instanceUrn;

  /** Full structure urn:protolayer:tech:techId:version:instId */
  std::string _techniqueUrn;

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
  explicit Instance(ontology::Type& type) throw (Exception);

  /**
   * TODO: Documentation
   * <p>
   */
  Instance(iostream::XdrInputStream& stream,
		  std::map <int, void*> addressMappings);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Instance();

  /**
   * TODO: Documentation
   *
   */
  ontology::Type& getType();

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
   *
   */
  bool instantiates(ontology::Type& type);

  /**
   * TODO: Documentation
   * <p>
   */
  void setName(const std::string& name);

  /**
   * TODO: Documentation
   * <p>
   */
  const std::string& getName() const;

  /**
   * TODO: Documentation
   * <p>
   */
  void setTechniqueUrn(const std::string& techniqueUrn);

  /**
   * TODO: Documentation
   * <p>
   */
  const std::string& getTechniqueUrn() const;

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Instance(const Instance& instance);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Instance& operator=(const Instance& instance);

};


}


}


#endif // PROTOLAYER_INSTANCE_H
