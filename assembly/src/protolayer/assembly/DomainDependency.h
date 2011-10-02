#ifndef PROTOLAYER_ASSEMBLY_DOMAINDEPENDENCY_H
#define PROTOLAYER_ASSEMBLY_DOMAINDEPENDENCY_H

#include <protolayer/protolayer-iostream.h>

#include "Domain.h"

namespace protolayer
{

namespace assembly
{

/** TODO: Documentation */
class Assembly;

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.3 $
 */
class DomainDependency
{
public:
  /** TODO: Documentation */
  friend class Assembly;

private:
  /** TODO: Documentation */
  mutable bool _tag;

  /** TODO: Documentation */
  ontology::DomainDependency* _domainDependency;

  /** TODO: Documentation */
  Domain* _fromDomain;

  /** TODO: Documentation */
  Domain* _toDomain;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  DomainDependency(ontology::DomainDependency& domainDependency,
                           Domain& fromDomain,
                           Domain& toDomain);

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
  ontology::DomainDependency& getDomainDependency();

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

  /**
   * TODO: Documentation
   * <p>
   */
  bool instantiates(ontology::DomainDependency& dependency) const;

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


#endif // PROTOLAYER_ASSEMBLY_DOMAINDEPENDENCY_H
