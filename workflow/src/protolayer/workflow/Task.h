#ifndef PROTOLAYER_WORKFLOW_TASK_H
#define PROTOLAYER_WORKFLOW_TASK_H

#include <deque>

#include "Step.h"


namespace protolayer
{

namespace workflow
{

/**
 * TODO: Documentation
 * <p>
 */
class Task
{
private:
  /** TODO: Documentation */
  unsigned int _undoDepth;

  /** TODO: Documentation */
  std::deque <Step*> _stepQueue;

  /** TODO: Documentation */
  std::deque <Step*>::iterator _currentStep;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Task();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Task();

  /**
   * TODO: Documentation
   *
   */
  void doit();

  /**
   * TODO: Documentation
   *
   */
  void undo();

  /**
   * TODO: Documentation
   * <p>
   */
  bool canRedo();

  /**
   * TODO: Documentation
   * <p>
   */
  bool canUndo();

protected:
  /**
   * TODO: Documentation
   * <p>
   */
  void append(Step& step);

private:
  /**
   * TODO: Documentation
   *
   */
  Task(const Task& task);

  /**
   * TODO: Documentation
   *
   */
  Task& operator=(const Task& task);

  /**
   * TODO: Documentation
   * <p>
   */
  void clearStaleHistory();
};


}


}


#endif // PROTOLAYER_WORKFLOW_TASK_H
