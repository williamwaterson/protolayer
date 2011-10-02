#include "EventLoopTimerListener.h"


namespace protolayer
{

namespace carbon
{

const double EventLoopTimerListener::DurationSecond = kEventDurationSecond;

const double EventLoopTimerListener::DurationMillisecond = kEventDurationMillisecond;

const double EventLoopTimerListener::DurationMicrosecond = kEventDurationMicrosecond;

const double EventLoopTimerListener::DurationNanosecond = kEventDurationNanosecond;

const double EventLoopTimerListener::DurationMinute = kEventDurationMinute;

const double EventLoopTimerListener::DurationHour = kEventDurationHour;

const double EventLoopTimerListener::DurationDay = kEventDurationDay;

const double EventLoopTimerListener::DurationNoWait = kEventDurationNoWait;

const double EventLoopTimerListener::DurationForever = kEventDurationForever;


void eventLoopHandler(EventLoopTimerRef timerRef,
                      void* userData)
{
  EventLoopTimerListener* listener =
    reinterpret_cast <EventLoopTimerListener*> (userData);
  listener->timerTriggered();
}


const EventLoopTimerUPP eventLoopTimerUPP =
  NewEventLoopTimerUPP(eventLoopHandler);


EventLoopTimerUPP EventLoopTimerListener::getEventLoopTimerUPP()
{
  return eventLoopTimerUPP;
}


EventLoopTimerListener::EventLoopTimerListener(double delay,
                                               double interval)
{
  void* listener = reinterpret_cast <void*> (this);
  //  InstallEventLoopTimer(GetCurrentEventLoop(),
  InstallEventLoopTimer(GetMainEventLoop(),
                        delay,
                        interval,
                        eventLoopTimerUPP,
                        listener,
                        &_eventLoopTimerRef);
}


EventLoopTimerListener::EventLoopTimerListener(double interval)
{
  void* listener = reinterpret_cast <void*> (this);
  //  InstallEventLoopTimer(GetCurrentEventLoop(),
  InstallEventLoopTimer(GetMainEventLoop(),
                        0,
                        interval,
                        eventLoopTimerUPP,
                        listener,
                        &_eventLoopTimerRef);
}


EventLoopTimerListener::~EventLoopTimerListener()
{
  RemoveEventLoopTimer(_eventLoopTimerRef);
}


}


}
