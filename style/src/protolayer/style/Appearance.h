#ifndef PROTOLAYER_STYLE_APPEARANCE_H
#define PROTOLAYER_STYLE_APPEARANCE_H


namespace protolayer
{

namespace style
{

/**
 * TODO: Documentation
 * <p>
 */
class Appearance
{
  /** TODO: Documentation */
  bool _renderable;

  /** TODO: Documentation */
  float _modifierAlpha;

  /** TODO: Documentation */
  float _color[4];

  /** TODO: Documentation */
  float _lineWidth;

public:
  /**
   * TODO: Documentation
   *
   */
  Appearance();

  /**
   * TODO: Documentation
   *
   */
  ~Appearance();

  /**
   * TODO: Documentation
   *
   */
  float getLineWidth() const;

  /**
   * TODO: Documentation
   *
   */
  float getModifierAlpha() const;

  /**
   * TODO: Documentation
   *
   */
  bool isRenderable() const;

  /**
   * TODO: Documentation
   *
   */
  float* getColor();

  /**
   * TODO: Documentation
   *
   */
  void setRenderable(bool flag);

  /**
   * TODO: Documentation
   *
   */
  void setModifierAlpha(float alpha);

  /**
   * TODO: Documentation
   *
   */
  void setColor3(float color[3]);

  /**
   * TODO: Documentation
   *
   */
  void setColor(float color[4]);

  /**
   * TODO: Documentation
   *
   */
  void setColor(float red, float green, float blue, float alpha);

private:
  /**
   * TODO: Documentation
   *
   */
  Appearance(const Appearance& appearance);

  /**
   * TODO: Documentation
   *
   */
  Appearance& operator=(const Appearance& appearance);
  
};


}


}


#endif // PROTOLAYER_STYLE_APPEARANCE_H
