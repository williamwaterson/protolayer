#ifndef PROTOLAYER_CARBON_EVENTLOOPTIMERLISTENER_H
#define PROTOLAYER_CARBON_EVENTLOOPTIMERLISTENER_H

#include "forward.h"

namespace protolayer
{

namespace carbon
{

/**
 * TODO: Documentation
 * <p>
 */
class EventLoopTimerListener
{
  /** TODO: Documentation */
  EventLoopTimerRef _eventLoopTimerRef;

public:
  /** TODO: Documentation */
  static const double DurationSecond;

  /** TODO: Documentation */
  static const double DurationMillisecond;

  /** TODO: Documentation */
  static const double DurationMicrosecond;

  /** TODO: Documentation */
  static const double DurationNanosecond;

  /** TODO: Documentation */
  static const double DurationMinute;

  /** TODO: Documentation */
  static const double DurationHour;

  /** TODO: Documentation */
  static const double DurationDay;

  /** TODO: Documentation */
  static const double DurationNoWait;

  /** TODO: Documentation */
  static const double DurationForever;

  /**
   * TODO: Documentation
   * <p>
   */  
  static EventLoopTimerUPP getEventLoopTimerUPP();

public:
  /**
   * TODO: Documentation
   * <p>
   */
  EventLoopTimerListener(double delay, double interval);

  /**
   * TODO: Documentation
   * <p>
   */
  EventLoopTimerListener(double interval);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~EventLoopTimerListener();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void timerTriggered() = 0;

};

}

}

#endif // PROTOLAYER_CARBON_EVENTLOOPTIMERLISTENER_H
