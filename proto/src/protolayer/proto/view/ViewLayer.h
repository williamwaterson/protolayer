#ifndef PROTOLAYER_PROTO_VIEWLAYER_H
#define PROTOLAYER_PROTO_VIEWLAYER_H

#include <map>
#include <set>

#include "../forward.h"
#include <WebKit/CarbonUtils.h>
#include <WebKit/HIWebView.h>
#include <Carbon/Carbon.h>

#include "visualisation/DomainScene.h"
#include "visualisation/EditGeometryScene.h"
#include "visualisation/HeadsUpScene.h"
#include "search/WebDelegate.h"


namespace protolayer
{

namespace proto
{

/**
 * TODO: Documentation
 * <p>
 */
class ViewLayer
{
public:
  /**
   * TODO: Documentation
   *
   */
  static ViewLayer* match(HIViewRef control);

private:
  /** TODO: Documentation */
  WindowRef _windowRef;

  /** TODO: Documentation */
  EventHandlerRef _eventHandlerRef;

  /** TODO: Documentation */
  EventLoopTimerRef _animationTimerRef;

  /** TODO: Documentaton */
  HIViewRef _contentView;

  /** TODO: Documentation */
  HIViewRef _popupControlRef;

  /** TODO: Documentation */
  MenuRef _popupControlMenuRef;

  /** TODO: Documentation */
  HIViewRef _modeControlRef;

  /** TODO: Documentation */
  HIViewRef _viewControlRef;

  /** TODO: Documentation */
  HIViewRef _searchFieldRef;

  /** TODO: Documentation */
  HIViewRef _renderViewRef;

  /** TODO: Documentation */
  HIViewRef _statusPlacardRef;

  /** TODO: Documentation */
  HIViewRef _instanceTreeRef;

  /** TODO: Documentation */
  HIViewRef _conceptTreeRef;

  /** TODO: Documentation */
  HIViewRef _spatialTreeRef;

  /** TODO: Documentation */
  HIViewRef _webViewRef;

  /** TODO: Documentation */
  HIViewRef _selectButtonRef;

  /** TODO: Documentation */
  HIViewRef _createNodeButtonRef;

  /** TODO: Documentation */
  HIViewRef _createReferenceButtonRef;

  /** TODO: Documentation */
  HIViewRef _instanceModeButtonRef;

  /** TODO: Documentation */
  HIViewRef _conceptModeButtonRef;

  /** TODO: Documentation */
  HIViewRef _searchModeButtonRef;

  /** TODO: Documentation */
  HIViewRef _moveCameraButtonRef;

  /** TODO: Documentation */
  HIViewRef _panCameraButtonRef;

  /** TODO: Documentation */
  HIViewRef _targetCameraButtonRef;

  /** TODO: Documentation */
  HIViewRef _zoomCameraButtonRef;

  /** TODO: Documentation */
  HIViewRef _zoomInCameraButtonRef;

  /** TODO: Documentation */
  HIViewRef _zoomOutCameraButtonRef;

  /** TODO: Documentation */
  HIViewRef _upLayerButtonRef;

  /** TODO: Documentation */
  HIViewRef _downLayerButtonRef;

  /** TODO: Documentation */
  HIViewRef _currentViewRef;

  /** TODO: Documentation */
  HIViewRef _currentSupplementViewRef;

  /** TODO: Documentation */
  HIViewRef _separatorRef;

  /** TODO: Documentation */
  HIViewRef _renderPaneRef;

  /** TODO: Documentation */
  short _separatorPosition;

  /** TODO: Documentation */
  MenuRef _searchFieldMenuRef;

  /** TODO: Documentation */
  static const GLint attrib[];

  /** TODO: Documentation */
  Rect* _bounds;

  /** TODO: Documentation */
  Rect* _rendererBounds;

  /** TODO: Documentation */
  AGLContext _aglContext;

  /** TODO: Documentation */
  AGLPixelFormat _aglPixelFormat;

  /** TODO: Documentation */
  renderer::Space* _space;

  /** TODO: Documentation */
  DomainScene* _rootScene;

  /** TODO: Documentation */
  EditGeometryScene* _geometryScene;

  /** TODO: Documentation */
  HeadsUpScene* _headsUpScene;

  /** TODO: Documentation */
  std::set <LayeredScene*> _layeredScenes;

  /** TODO: Documentation */
  scenegraph::Shot* _headsUpShot;

  /** TODO: Documentation */
  scenegraph::Shot* _currentShot;

  /** TODO: Documentation */
  scenegraph::Shot* _rootShot;

  /** TODO: Documentation */
  scenegraph::Shot* _geometryShot;

  /** TODO: Documentation */
  std::set <scenegraph::Shot*> _layeredShots;

  /** TODO: Documentation */
  std::map <scenegraph::Scene*, scenegraph::Shot*> _shots;

  /** TODO: Documentation */
  std::map <scenegraph::Shot*, fx::Transition*> _zoomInTransitions;

  /** TODO: Documentation */
  std::map <scenegraph::Shot*, fx::Transition*> _zoomOutTransitions;

  /** TODO: Documentation */
  fx::Dissolve* _dissolveToGeometryScene;

  /** TODO: Documentation */
  std::vector <std::string> _items;

  /** TODO: Documentation */
  std::map <int, ontology::Domain*> _domainIDMappings;

  /** TODO: Documentation */
  std::map <int, ontology::Type*> _typeIDMappings;

  /** TODO: Documentation */
  std::map <int, ontology::Association*> _associationIDMappings;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  ViewLayer();

  /**
   * TODO: Documentation
   * <p>
   */
  ~ViewLayer();

  /**
   * TODO: Documentation
   * <p>
   */
  void constructShots(assembly::Assembly& assembly);

  /**
   * TODO: Documentation
   * <p>
   */
  void populateConceptSelectCombo(ontology::Ontology& ontology);

  /**
   * TODO: Documentation
   * <p>
   */
  void constructSpace();

  /**
   * TODO: Documentation
   * <p>
   */
  WindowRef& getWindow();

  /**
   * TODO: Documentation
   *
   */
  HIViewRef getRenderPane();

  /**
   * TODO: Documentation
   *
   */
  scenegraph::Shot& getCurrentShot();

  /**
   * TODO: Documentation
   *
   */
  void setCurrentShot(scenegraph::Shot& shot);

  /**
   * TODO: Documentation
   * <p>
   */
  scenegraph::Shot& getRootShot();

  /**
   * TODO: Documentation
   * <p>
   */
  renderer::Space& getSpace();

  /**
   * TODO: Documentation
   * <p>
   */
  Rect& getRendererBounds();
 
  /**
   * TODO: Documentation
   *
   */
  scenegraph::Camera& getCamera();

  /** TODO: Documentation */
  HIViewRef getSelectButton();

  /** TODO: Documentation */
  HIViewRef getContentView();

  /** TODO: Documentation */
  HIViewRef getCreateNodeButton();

  /** TODO: Documentation */
  HIViewRef getSeparator();

  /** TODO: Documentation */
  HIViewRef getCreateReferenceButtonRef();

  /**
   * TODO: Documentation
   * <p>
   */
  HIViewRef getConceptTree();

  /**
   * TODO: Documentation
   *
   */
  HIViewRef getInstanceModeButtonRef();

  /**
   * TODO: Documentation
   *
   */
  HIViewRef getConceptModeButtonRef();

  /**
   * TODO: Documentation
   *
   */
  HIViewRef getInstanceTree();

  /**
   * TODO: Documentation
   *
   */
  HIViewRef getSpatialTree();

  /**
   * TODO: Documentation
   *
   */
  HIViewRef getSearchModeButtonRef();

  /**
   * TODO: Documentation
   *
   */
  HIViewRef getSearchField();

  /**
   * TODO: Documentation
   *
   */
  HIViewRef getMoveCameraButtonRef();

  /**
   * TODO: Documentation
   *
   */
  HIViewRef getPanCameraButtonRef();

  /**
   * TODO: Documentation
   *
   */
  HIViewRef getTargetCameraButtonRef();

  /**
   * TODO: Documentation
   *
   */
  HIViewRef getZoomCameraButton();

  /**
   * TODO: Documentation
   *
   */
  HIViewRef getZoomInCameraButtonRef();

  /**
   * TODO: Documentation
   *
   */
  HIViewRef getZoomOutCameraButtonRef();

  /**
   * TODO: Documentation
   *
   */
  HIViewRef getUpLayerButtonRef();

  /**
   * TODO: Documentation
   *
   */
  HIViewRef getDownLayerButtonRef();

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
  scenegraph::Shot& getShot();

  /**
   * TODO: Documentation
   *
   */
  void constructHandlers();

  /**
   * TODO: Documentation
   * <p>
   */
  void updateRendererMouse();

  /**
   * TODO: Documentation
   * <p>
   */
  void rendererBoundsChanged();

  /**
   * TODO: Documentation
   * <p>
   */
  void initRenderer();

  /**
   * TODO: Documentation
   * <p>
   */
  void disposeRenderer();

  /**
   * TODO: Documentation
   * <p>
   */
  void swapRendererPortsAndDisplay();

  /**
   * TODO: Documentation
   * <p>
   */
  void evaluateControlPositions();

  /**
   * TODO: Documentation
   * <p>
   */
  void displaySearchMode();

  /**
   * TODO: Documentation
   * <p>
   */
  void displayInstanceAssemblyMode();

  /**
   * TODO: Documentation
   * <p>
   */
  void displayConceptAssemblyMode();

  /**
   * TODO: Documentation
   * <p>
   */
  void displaySpatialMode();
 
  /**
   * TODO: Documentation
   * <p>
   */
  void display();

  /**
   * TODO: Documentation
   * <p>
   */
  void resize(short left, short top, short right, short bottom);

private:
  /**
   * TODO: Documentation
   *
   */
  void constructSmallButton(const char* label, HIViewRef& buttonRef, short left, short top);

  /**
   * TODO: Documentation
   * <p>
   */
  void displayMode(HIViewRef modeView);

  /**
   * TODO: Documentation
   * <p>
   */
  void displaySupplementView(HIViewRef view);

  /**
   * TODO: Documentation
   * <p>
   */
  void nullifySupplementView();

  /**
   * TODO: Documentation
   * <p>
   */
  void constructWindow(short left,
		       short top,
		       short right,
		       short bottom);

  /**
   * TODO: Documentation
   * <p>
   */
  void constructSeparator();

  /**
   * TODO: Documentation
   * <p>
   */
  void constructSelectButton();

  /**
   * TODO: Documentation
   * <p>
   */
  void constructNodeCreationButton();

  /**
   * TODO: Documentation
   * <p>
   */
  void constructReferenceCreationButton();

  /**
   * TODO: Documentation
   * <p>
   */
  void constructInstanceModeButton();

  /**
   * TODO: Documentation
   * <p>
   */
  void constructConceptModeButton();

  /**
   * TODO: Documentation
   * <p>
   */
  void constructGeometryModeButton();

  /**
   * TODO: Documentation
   * <p>
   */
  void constructSearchModeButton();

  /**
   * TODO: Documentation
   * <p>
   */
  void constructMoveCameraButton();

  /**
   * TODO: Documentation
   * <p>
   */
  void constructPanCameraButton();

  /**
   * TODO: Documentation
   * <p>
   */
  void constructTargetCameraButton();

  /**
   * TODO: Documentation
   * <p>
   */
  void constructZoomInButton();

  /**
   * TODO: Documentation
   * <p>
   */
  void constructZoomOutButton();

  /**
   * TODO: Documentation
   * <p>
   */
  void constructZoomButton();

  /**
   * TODO: Documentation
   * <p>
   */
  void constructUpLayerButton();

  /**
   * TODO: Documentation
   * <p>
   */
  void constructDownLayerButton();

  /**
   * TODO: Documentation
   * <p>
   */
  void constructWindow();

  /**
   * TODO: Documentation
   * <p>
   */
  void constructRenderView();

  /**
   * TODO: Documentation
   * <p>
   */
  void constructInstanceButtonGroup();

  /**
   * TODO: Documentation
   * <p>
   */
  void constructWebView();

  /**
   * TODO: Documentation
   * <p>
   */
  void constructStatusPlacard();

  /**
   * TODO: Documentation
   * <p>
   */
  void constructSpatialTreeView();

  /**
   * TODO: Documentation
   * <p>
   */
  void constructConceptTreeView();

  /**
   * TODO: Documentation
   * <p>
   */
  void constructInstanceTreeView();

  /**
   * TODO: Documentation
   * <p>
   */
  void constructConceptSelectCombo();

  /**
   * TODO: Documentation
   * <p>
   */
  void constructSearchField();

  /**
   * TODO: Documentation
   * <p>
   */
  void constructViewControls();

  /**
   * TODO: Documentation
   * <p>
   */
  void constructModeControls();

  /**
   * TODO: Documentation
   * <p>
   */
  void constructSmallButton(Rect& bounds, const char* label, HIViewRef& buttonref);

};


}


}


#endif // PROTOLAYER_PROTO_VIEWLAYER_H
