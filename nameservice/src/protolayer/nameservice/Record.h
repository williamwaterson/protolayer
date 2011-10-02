#ifndef PROTOLAYER_NAMESERVICE_RECORD_H
#define PROTOLAYER_NAMESERVICE_RECORD_H

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

#include "Exception.h"

namespace protolayer
{

namespace nameservice
{

/**
 * TODO: Documentation
 * <p>
 */
class Record
{
  /** TODO: Documentation */
  std::set <std::string> _keywords;

  /** TODO: Documentation */
  std::string _description;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Record() throw (Exception);

  /**
   * TODO: Documentation
   * <p>
   */
  explicit Record(iostream::XdrInputStream& istream)
    throw (Exception);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Record();

  /**
   * TODO: Documentation
   * <p>
   */
  void encode(iostream::XdrOutputStream& ostream);

  /**
   * TODO: Documentation
   * <p>
   */
  void setDescription(const std::string& decription);

  /**
   * TODO: Documentation
   * <p>
   */
  std::string& getDescription();

  /**
   * TODO: Documentation
   * <p>
   */
  const std::string& getDescription() const;

  /**
   * TODO: Documentation
   * <p>
   */
  void setKeywords(const std::set <std::string>& keyword);

  /**
   * TODO: Documentation
   * <p>
   */
  std::set <std::string>& getKeywords();

  /**
   * TODO: Documentation
   * <p>
   */
  const std::set <std::string>& getKeywords() const;

private:
  /**
   * TODO: Documentation
   *
   */
  Record(const Record& record);

  /**
   * TODO: Documentation
   *
   */
  Record& operator=(const Record& record);

};


}


}


#endif // PROTOLAYER_NAMESERVICE_RECORD_H
