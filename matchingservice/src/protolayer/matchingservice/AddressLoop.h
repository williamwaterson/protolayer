#ifndef PROTOLAYER_MATCHINGSERVICE_ADDRESSLOOP_H
#define PROTOLAYER_MATCHINGSERVICE_ADDRESSLOOP_H

#include <string>
#include <map>
#include <set>
#include <pthread.h>

#include "Exception.h"


namespace protolayer
{

namespace matchingservice
{

/**
 * Simple endless loop of addresses displaying set-like
 * behaviour. All modifiers and accessors use a simple
 * spinlock to control thread access. This arrangement
 * need to be improved in future re-implementations.
 */
class AddressLoop
{
  /** Use pthreads mutexes as pthread spinlock unavailable on OS X 10.2 */
  //  pthread_spinlock_t _lock;
  mutable pthread_mutex_t _mutex;

  /** Use pthreads mutexes as pthread spinlock unavailable on OS X 10.2 */
  pthread_mutexattr_t _mutexattr;

  /** Stateful iterator for tracking where in the loop we have reached */
  mutable std::set <std::string>::const_iterator _iterator;

  /** The set of addresses to be iterated over */
  std::set <std::string> _addresses;

public:
  /**
   * Constructs an instance of this class to create a collection of
   * addresses with the supplied address as the first only element.
   * Subsequent additions through the modifying methods on this class,
   * add and remove addresses.
   *
   * @param firstAddress
   *   the initial entry in the address loop. This must be a valid
   *   internet address.
   */
  explicit AddressLoop(const std::string& firstAddress);

  /**
   * Destroys this instance, using locking to ensure thread-safe destruction.
   */
  ~AddressLoop();

  /**
   * Adds the supplied address to the set of available addresses
   * returned by this loop.
   *
   * @param address
   *   the address to be added to the address loop
   */
  void addAddress(const std::string& address);

  /**
   * Removes the specified address from the set of available
   * addresses returned by this loop.
   *
   * @param address
   *   the address to remove to the address loop
   */
  void removeAddress(const std::string& address);

  /**
   * Returns the number available addresses within this loop.
   *
   * @return
   *   the number of addresses available in this loop
   */
  int getNumberAddresses() const;

  /**
   * Returns true if the address loop contains no addresses.
   * 
   * @return
   *   true if the address loop contains no addresses
   */
  bool isEmpty() const;

  /**
   * Returns true if the address loop contains addresses.
   *
   * @return
   *   true if the address loop contains addresses
   */
  bool containsAddresses() const;

  /**
   * Returns the next available address in the loop by copying
   * it to the supplied result string reference.
   *
   * @param result
   *   the placeholder for the result
   */
  void next(std::string& result) const;

};

}

}

#endif // PROTOLAYER_MATCHINGSERVICE_ADDRESSLOOP_H
