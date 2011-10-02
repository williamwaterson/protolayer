#ifndef PROTOLAYER_WORKFLOW_TIMELINE_H
#define PROTOLAYER_WORKFLOW_TIMELINE_H

#include <deque>

#include "Task.h"


namespace protolayer
{

namespace workflow
{

/**
 * TODO: Documentation
 * <p>
 */
class Timeline
{
private:
  /** TODO: Documentation */
  unsigned int _undoDepth;

  /** TODO: Documentation */
  std::deque <Task*> _taskQueue;

  /** TODO: Documentation */
  std::deque <Task*>::iterator _currentTask;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Timeline();

  /**
   * TODO: Documentation
   * <p>
   */
  ~Timeline();

  /**
   * TODO: Documentation
   * <p>
   */
  void displaySearchPerspective();

  /**
   * TODO: Documentation
   * <p>
   */
  void displayInstancePerspective();

  /**
   * TODO: Documentation
   * <p>
   */
  void displayConceptPerspective();

  /**
   * TODO: Documentation
   * <p>
   */
  void displaySpatialPerspective();

  /**
   * TODO: Documentation
   *
   */
  void setToSelectState();

  /**
   * TODO: Documentation
   *
   */
  void setToCreateInstanceState();

  /**
   * TODO: Documentation
   *
   */
  void setToCreateReferenceState();

  /**
   * TODO: Documentation
   *
   */
  void setToPanCameraState();
  
  /**
   * TODO: Documentation
   *
   */
  void setToMoveCameraState();

  /**
   * TODO: Documentation
   *
   */
  void setToTargetCameraState();

  /**
   * TODO: Documentation
   *
   */
  void upLayer();

  /**
   * TODO: Documentation
   *
   */
  void downLayer();

  /**
   * TODO: Documentation
   *
   */
  void zoomIn();

  /**
   * TODO: Documentation
   *
   */
  void zoomOut();

  /**
   * TODO: Documentation
   *
   */
  void redo();

  /**
   * TODO: Documentation
   *
   */
  void undo();

private:
  /**
   * TODO: Documentation
   *
   */
  Timeline(const Timeline& timeline);

  /**
   * TODO: Documentation
   *
   */
  Timeline& operator=(const Timeline& timeline);

  /**
   * TODO: Documentation
   * <p>
   */
  void clearStaleHistory();

  /**
   * TODO: Documentation
   * <p>
   */
  void append(Task& task);

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

};


}


}


#endif // PROTOLAYER_WORKFLOW_TIMELINE_H
