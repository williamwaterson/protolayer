#ifndef MESON_GRANULARITYLEVELSCENE_H
#define MESON_GRANULARITYLEVELSCENE_H

#include <vector>

#include "../../forward.h"
#include "ReferenceArrow.h"
#include "LayerHexMesh.h"
#include "LayeredSceneSelectionModel.h"


/** TODO: Documentation */
namespace protolayer
{

namespace proto
{

class LayeredScene : public scenegraph::Scene
{
public:
  /** TODO: Documentation */
  typedef std::vector<LayerHexMesh*>::iterator LayerHexMeshIteratorType;

  /** TODO: Documentation */
  typedef std::vector<LayerHexMesh*>::reverse_iterator DownwardsLayerHexMeshIteratorType;

  /** TODO: Documentation */
  static const float VERTICAL_SPACING;

private:
  /** TODO: Documentation */
  assembly::Domain* _domain;

  /** TODO: Documentation */
  std::vector <LayerHexMesh*> _layers;

  /** TODO: Documentation */
  scenegraph::Group _root;

  /** TODO: Documentation */
  LayerHexMesh* _activeLayer;

  /** TODO: Documentation */
  LayerHexMesh* _previousLayer;

  /** TODO: Documentation */
  geometry::HexMesh* _activeHexMesh;

  /** TODO: Documentation */
  geometry::HexMesh* _dormantHexMesh;

  /** TODO: Documentation */
  scenegraph::Group* _cameraGroup;

  /** TODO: Documentation */
  fx::AnimationAction* _moveCameraAction;

  /** TODO: Documentation */
  style::Appearance _sublayerAppearance;

  /** TODO: Documentation */
  style::Appearance _superLayerAppearance;

  /** TODO: Documentation */
  style::Appearance _activeAppearance;

  /** TODO: Documentation */
  style::Appearance _nextAppearance;

  /** TODO: Documentation */
  style::Appearance _selectedAppearance;

  /** TODO: Documentation */
  fx::AlphaShift* _alphaShiftDim;

  /** TODO: Documentation */
  fx::AlphaShift* _alphaShiftBrighten;

  /** TODO: Documentation */
  fx::AlphaShift* _alphaShiftDimEdges;

  /** TODO: Documentation */
  fx::AlphaShift* _alphaShiftBrightenEdges;

  /** TODO: Documentation */
  fx::AlphaShift* _alphaShiftDisappear;

  /** TODO: Documentation */
  fx::AlphaShift* _alphaShiftNodeDisappear;

  /** TODO: Documentation */
  fx::AlphaShift* _alphaShiftNodeDisappearEdges;

  /** TODO: Documentation */
  fx::AlphaShift* _alphaShiftAppear;

  /** TODO: Documentation */
  scenegraph::Camera _camera;

  /** TODO: Documentation */
  LayeredSceneSelectionModel _selectionModel;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit LayeredScene(assembly::Assembly& assembly);

  /**
   * TODO: Documentation
   * <p>
   */
  explicit LayeredScene(assembly::Domain& domain);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~LayeredScene();

  /**
   * TODO: Documentation
   * <p>
   */
  bool hasReachedBottomLayer();

  /**
   * TODO: Documentation
   * <p>
   */
  bool hasReachedTopLayer();

  /**
   * TODO: Documentation
   * <p>
   */
  LayerHexMesh& getActiveLayer();

  /**
   * TODO: Documentation
   * <p>
   */
  LayerHexMesh* getPreviousLayer();

  /**
   * TODO: Documentation
   * <p>
   */
  geometry::HexMesh& getActiveHexMesh();

  /**
   * TODO: Documentation
   * <p>
   */
  geometry::HexMesh& getDormantHexMesh();

  /**
   * TODO: Documentation
   * <p>
   */
  fx::AlphaShift& getAlphaShiftDim();

  /**
   * TODO: Documentation
   * <p>
   */
  fx::AlphaShift& getAlphaShiftBrighten();

  /**
   * TODO: Documentation
   * <p>
   */
  fx::AlphaShift& getAlphaShiftDimEdges();

  /**
   * TODO: Documentation
   * <p>
   */
  fx::AlphaShift& getAlphaShiftBrightenEdges();

  /**
   * TODO: Documentation
   * <p>
   */
  fx::AlphaShift& getAlphaShiftDisappear();

  /**
   * TODO: Documentation
   * <p>
   */
  fx::AlphaShift& getAlphaShiftNodeDissappear();

  /**
   * TODO: Documentation
   * <p>
   */
  fx::AlphaShift& getAlphaShiftNodeDissappearEdges();

  /**
   * TODO: Documentation
   * <p>
   */
  fx::AlphaShift& getAlphaShiftAppear();

  /**
   * TODO: Documentation
   * <p>
   */
  fx::AnimationAction& getMoveCameraAction();

  /**
   * TODO: Documentation
   * <p>
   */
  assembly::Domain& getDomain();

  /**
   * TODO: Documentation
   * <p>
   */
  LayeredSceneSelectionModel& getSelectionModel();

  /**
   * TODO: Documentation
   * <p>
   */
  scenegraph::Camera& getCamera();

  /**
   * TODO: Documentation
   * <p>
   */
  scenegraph::Shot& getShot();

  /**
   * TODO: Documentation
   * <p>
   */
  void moveToTopLayer();

  /**
   * TODO: Documentation
   * <p>
   */
  void moveToBottomLayer();

  /**
   * TODO: Documentation
   * <p>
   */
  void triggerUpLayer();

  /**
   * TODO: Documentation
   * <p>
   */
  void triggerDownLayer();

  /**
   * TODO: Documentation
   * <p>
   */
  void triggerMoveToLayer(assembly::Layer& layer);

  /**
   * TODO: Documentation
   * <p>
   */
  void triggerMoveToLayer(LayerHexMesh& layer);

  /**
   * TODO: Documentation
   * <p>
   */
  int getNumberLayers() const;

  /**
   * TODO: Documentation
   * <p>
   */
  bool isActiveLayer(LayerHexMesh& layer);

  /**
   * TODO: Documentation
   * <p>
   */
  LayerHexMeshIteratorType getLayerHexMeshesUpwards();

  /**
   * TODO: Documentation
   * <p>
   */
  DownwardsLayerHexMeshIteratorType getLayerHexMeshesDownwards();

  /**
   * TODO: Documentation
   * <p>
   */
  LayerHexMeshIteratorType getUpwardsLayerHexMeshEnd();

  /**
   * TODO: Documentation
   * <p>
   */
  DownwardsLayerHexMeshIteratorType getDownwardsLayerHexMeshEnd();

};


}


}


#endif // MESON_GRANULARITYLEVELSCENE_H
