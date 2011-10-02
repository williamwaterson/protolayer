#ifndef PROTOLAYER_NET_PROTOCOLHEADER_H
#define PROTOLAYER_NET_PROTOCOLHEADER_H


namespace protolayer
{

namespace net
{

/**
 * TODO: Documentation
 * <p>
 */
class ProtocolHeader
{
public:
  enum Version {VERSION_1
               };

  /** TODO: Documentation */
  enum Type {NAME_SERVICE,
	     CONTAINER_SERVICE,
	     PUBLISHING_SERVICE,
	     COMPILE_SERVICE};

};


}


}


#endif // PROTOLAYER_NET_PROTOCOLHEADER_H
