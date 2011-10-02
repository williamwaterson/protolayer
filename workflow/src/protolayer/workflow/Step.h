#ifndef PROTOLAYER_WORKFLOW_STEP_H
#define PROTOLAYER_WORKFLOW_STEP_H

#include <string>
#include <vector>

#include "Action.h"


namespace protolayer
{

namespace workflow
{

/**
 * TODO: Documentation
 * <p>
 */
class Step
{
private:
  /** TODO: Documentation */
  bool _locked;

  /** TODO: Documentation */
  std::string _text;

  /** TODO: Documentation */
  std::string _description;

  /** TODO: Documentation */
  std::string _tip;

  /** TODO: Documentation */
  std::vector <Action*> _actions;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Step(const std::string& text,
       const std::string& description,
       const std::string& tip);

  /**
   * TODO: Documentation
   * <p>
   */
  ~Step();

  /**
   * TODO: Documentation
   * <p>
   */
  void append(Action& action);

  /**
   * TODO: Documentation
   * <p>
   */
  void doit();

  /**
   * TODO: Documentation
   * <p>
   */
  void undo();

  /**
   * TODO: Documentation
   * <p>
   */
  const std::string& getText() const;

  /**
   * TODO: Documentation
   * <p>
   */
  const std::string& getDescription() const;

  /**
   * TODO: Documentation
   * <p>
   */
  const std::string& getTip() const;

private:
  /**
   * TODO: Documentation
   *
   */
  Step(const Step& step);

  /**
   * TODO: Documentation
   *
   */
  Step& operator=(const Step& step);

};


}


}


#endif // PROTOLAYER_WORKFLOW_STEP_H
