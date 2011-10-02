#ifndef PROTOLAYER_SEQUENCE_H
#define PROTOLAYER_SEQUENCE_H

#include <queue>
#include <set>
#include <sys/time.h>
#include <vector>

#include "protolayer/protolayer-util.h"

#include "Action.h"

namespace protolayer
{

namespace animation
{

struct Event
{
  float _time;

  Action* _action;

  Event(float t, Action& action) : _time(t), _action(&action)
  {
  }

};


struct Comparison
{
  bool operator () (const Event* left, const Event* right) {
    return left->_time > right->_time;
  }

};

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.3 $
 */
class Sequence : public Action
{
public:
  /** TODO: Documentation */
  typedef util::SetIterator <Action> ActionIteratorType;

  /** TODO: Documentation */
  typedef util::SetIterator <Event> EventIteratorType;

private:
  /** TODO: Documentation */
  typedef std::set <Action*> ActionSetType;

  /** TODO: Documentation */
  typedef std::set <Event*> EventSetType;

  /** TODO: Documentation */
  typedef std::vector <Event*, std::allocator <Event*> > EventVectorType;

  /** TODO: Documentation */
  typedef std::priority_queue <Event*, EventVectorType, Comparison> EventQueueType;

private:
  /** TODO: Documentation */
  bool _inProgress;

  /** TODO: Documentation */
  float _timeStarted;

  /** TODO: Documentation */
  float _timeCurrent;

  /** TODO: Documentation */
  float _timeElapsed;

  /** TODO: Documentation */
  struct timeval _tick;

  /** TODO: Documentation */
  ActionSetType _actions;

  /** TODO: Documentation */
  EventSetType _events;

  /** TODO: Documentation */
  EventSetType _activeEvents;

  /** TODO: Documentation */
  EventQueueType _queue;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Sequence();

  /**
   * TODO: Documentation
   * <p>
   */
  ~Sequence();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void commence(float timeStarted);

  /**
   * Returns true if the transition has commenced.
   * <p>
   */
  virtual bool inProgress();

  /**
   * Performs a single increment in the action over time according
   * to the particular action type implemented by the derived class.
   * <p>
   */
  virtual void increment(float timeCurrent);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void postComplete();

  /**
   * TODO: Documentation
   * <p>
   */
  Event* createEvent(float relativeTime, Action& action);

  /**
   * TODO: Documentation
   * <p>
   */
  void destroyEvent(Event& event);

  /**
   * TODO: Documentation
   * <p>
   */
  void clearEvents();

  /**
   * TODO: Documentation
   * <p>
   */
  ActionIteratorType getActions();

  /**
   * TODO: Documentation
   * <p>
   */
  EventIteratorType getEvents();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Sequence(const Sequence& sequence);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Sequence& operator=(const Sequence& sequence);

};


}


}


#endif // PROTOLAYER_SEQUENCE_H
