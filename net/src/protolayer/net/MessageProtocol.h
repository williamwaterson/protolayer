#ifndef PROTOLAYER_NET_MESSAGEPROTOCOL_H
#define PROTOLAYER_NET_MESSAGEPROTOCOL_H

namespace protolayer
{

namespace net
{

/**
 * TODO: Documentation
 * <p>
 */
class MessageProtocol
{
public:
  /** TODO: Documentation */
  enum Type {RESUME,
	     SUSPEND,
	     SHUTDOWN,
             ADDADDRESS,
             REMOVEADDRESS,
             GETAVAILABLEADDRESS,
	     ADD,
	     FIND,
	     GET,
	     REMOVE,
	     ADD_TYPE,
	     FIND_TYPE,
	     FIND_TYPE_BY_DOMAIN_AND_NAME,
	     GET_TYPE,
	     GET_TYPE_BY_DOMAIN_AND_NAME,
	     REMOVE_TYPE,
	     ADD_ASSOCIATION,
	     FIND_ASSOCIATION,
	     GET_ASSOCIATION,
	     REMOVE_ASSOCIATION,
	     ADD_GENERALISATION,
	     FIND_GENERALISATION,
	     GET_GENERALISATION,
	     REMOVE_GENERALISATION,
	     ADD_DOMAIN,
	     FIND_DOMAIN,
	     GET_DOMAIN,
	     REMOVE_DOMAIN,
	     ADD_TECHNIQUE,
	     FIND_TECHNIQUE,
	     GET_TECHNIQUE,
	     REMOVE_TECHNIQUE,
	     ADD_USER,
	     FIND_USER,
	     GET_USER,
	     REMOVE_USER,
	     GET_END,
	     FIND_END,
	     CONNECT,
	     SUBMIT,
	     REGISTER_ONTOLOGY,
	     REGISTER_TECHNIQUE,
	     UNREGISTER,
	     ADD_LOCATION,
	     REMOVE_LOCATION,
	     GET_NAMES,
	     GET_RECORD,
	     GET_ONTOLOGY,
	     GET_LOCATIONS,
	     NEXT_LOCATION,
	     POPULATE,
	     VALIDATE,
	     EVALUATE,
	     REQUEST,
	     REPLY,
	     ERROR};

  /**
   * TODO: Documentation
   *
   */
  //  static void signalError(iostream::XdrOutputStream& ostream)
  //  {
  //  ostream.write(ERROR);
  //  ostream.flush();
  //}

  /**
   * TODO: Documentation
   *
   */
  //  static void signalSuccess(iostream::XdrOutputStream& ostream)
  //{
  //  ostream.write(SUCCESS);
  //  ostream.flush();
  // }
  
};


}


}


#endif // PROTOLAYER_NET_MESSAGEPROTOCOL_H
