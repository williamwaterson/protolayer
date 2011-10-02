#ifndef PROTOLAYER_NAMESERVICE_TECHNIQUERECORD_H
#define PROTOLAYER_NAMESERVICE_TECHNIQUERECORD_H

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <netinet/in.h>
#include <unistd.h>

#include <set>

#include <protolayer/protolayer-iostream.h>
#include <protolayer/protolayer-net.h>

#include "Record.h"
#include "Exception.h"


namespace protolayer
{

namespace nameservice
{

/**
 * TODO: Documentation
 * <p>
 */
class TechniqueRecord : public Record
{
  /** TODO: Documentation */
  std::string _implementedConceptUrn;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  TechniqueRecord() throw (Exception);

  /**
   * TODO: Documentation
   * <p>
   */
  explicit TechniqueRecord(iostream::XdrInputStream& istream)
    throw (Exception);

  /**
   * TODO: Documentation
   * <p>
   */
  void encode(iostream::XdrOutputStream& ostream);

  /**
   * TODO: Documentation
   * <p>
   */
  void setImplementedConceptUrn(const std::string& conceptUrn);

  /**
   * TODO: Documentation
   * <p>
   */
  std::string& getImplementedConceptUrn();

  /**
   * TODO: Documentation
   * <p>
   */
  const std::string& getImplementedConceptUrn() const;

private:
  /**
   * TODO: Documentation
   *
   */
  TechniqueRecord(const TechniqueRecord& techniqueRecord);

  /**
   * TODO: Documentation
   *
   */
  TechniqueRecord& operator=(const TechniqueRecord& techniqueRecord);

};


}


}


#endif // PROTOLAYER_NAMESERVICE_TECHNIQUERECORD_H
