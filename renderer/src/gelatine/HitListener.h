#ifndef GELATINE_HITLISTENER_H
#define GELATINE_HITLISTENER_H

namespace gelatine
{


/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.1.1.1 $
 */
template <class TargetParam> class HitListener
{
public:
  /** TODO: Documentation */
  typedef TargetParam TargetType;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  HitListener();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~HitListener() = 0;

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void mouseHit(TargetParam& hit) = 0;

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  HitListener(const HitListener& listener);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  HitListener& operator=(const HitListener& listener);

};


template <class TargetParam>
HitListener <TargetParam>::HitListener()
{
}


template <class TargetParam>
HitListener <TargetParam>::~HitListener()
{
}


template <class TargetParam>
void HitListener <TargetParam>::mouseHit(TargetParam& target)
{
}


}


#endif // GELATINE_HITLISTENER_H
