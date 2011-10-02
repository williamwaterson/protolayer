#ifndef PROTOLAYER_DOMAINDEPENDENCY_H
#define PROTOLAYER_DOMAINDEPENDENCY_H

#include <protolayer/protolayer-iostream.h>

#include "Domain.h"

namespace protolayer
{

namespace ontology
{

/** TODO: Documentation */
class Ontology;

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class DomainDependency
{
public:
  /** TODO: Documentation */
  friend class Ontology;

private:
  /** TODO: Documentation */
  mutable bool _tag;

  /** TODO: Documentation */
  Domain* _fromDomain;

  /** TODO: Documentation */
  Domain* _toDomain;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  DomainDependency(Domain& fromDomain, Domain& toDomain);

  /**
   * TODO: Documentation
   * <p>
   */
  DomainDependency(iostream::XdrInputStream& stream,
                   std::map <int, void*>& addressMappings);

  /**
   * TODO: Documentation
   * <p>
   */
  ~DomainDependency();

  /**
   * TODO: Documentation
   * <p>
   */
  void encode(iostream::XdrOutputStream& stream);

  /**
   * TODO: Documentation
   * <p>
   */
  Domain& getFromDomain();

  /**
   * TODO: Documentation
   * <p>
   */
  Domain& getToDomain();

  /**
   * TODO: Documentation
   * <p>
   */
  bool isFromDomain(Domain& instance);

  /**
   * TODO: Documentation
   * <p>
   */
  bool isToDomain(Domain& instance);

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  DomainDependency(const DomainDependency& domainDependency);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  DomainDependency& operator=(const DomainDependency& domainDependency);

};


}


}


#endif // PROTOLAYER_DOMAINDEPENDENCY_H
