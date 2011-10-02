#include "ViewLayer.h"


namespace protolayer
{ 

namespace proto
{

namespace
{

std::set <ViewLayer*> allViewLayers;


short int PLACARD_HEIGHT = 20;

short int BUTTON_HEIGHT = 20;

short int BUTTON_WIDTH = 20;

short int BUTTON_INSET = 0;

short int BUTTON_SEPARATION_DISTANCE = 5;

short int INITIAL_SEPARATOR_POSITION = 4;

short int SEPARATOR_WIDTH = 4;

short int SEARCHFIELD_WIDTH = 300;


}


WindowRef& ViewLayer::getWindow()
{
  return _windowRef;
}


HIViewRef ViewLayer::getInstanceTree() {
  return _instanceTreeRef;
}


HIViewRef ViewLayer::getSpatialTree() {
  return _spatialTreeRef;
}


HIViewRef ViewLayer::getSearchModeButtonRef()
{
  return  _searchModeButtonRef;
}


HIViewRef ViewLayer::getSearchField()
{
  return _searchFieldRef;
}


HIViewRef ViewLayer::getMoveCameraButtonRef()
{
  return _moveCameraButtonRef;
}


HIViewRef ViewLayer::getPanCameraButtonRef()
{
  return _panCameraButtonRef;
}


HIViewRef ViewLayer::getTargetCameraButtonRef()
{
  return _targetCameraButtonRef;
}


HIViewRef ViewLayer::getZoomCameraButton()
{
  return _zoomCameraButtonRef;
}


HIViewRef ViewLayer::getZoomInCameraButtonRef()
{
  return _zoomInCameraButtonRef;
}


HIViewRef ViewLayer::getZoomOutCameraButtonRef()
{
  return _zoomOutCameraButtonRef;
}


HIViewRef ViewLayer::getUpLayerButtonRef()
{
  return _upLayerButtonRef;
}


HIViewRef ViewLayer::getDownLayerButtonRef()
{
  return _downLayerButtonRef;
}


HIViewRef ViewLayer::getRenderPane() {
  return _renderPaneRef;
}


scenegraph::Shot& ViewLayer::getCurrentShot() {
  return *_currentShot;
}


void ViewLayer::setCurrentShot(scenegraph::Shot& shot) {
  _currentShot->setRenderable(false);
  _currentShot = &shot;
  _currentShot->setRenderable(true);
}


scenegraph::Shot& ViewLayer::getRootShot()
{
  return *_rootShot;
}


renderer::Space& ViewLayer::getSpace()
{
  return *_space;
}


HIViewRef ViewLayer::getSelectButton()
{
  return _selectButtonRef;
}


HIViewRef ViewLayer::getContentView()
{
  return _contentView;
}


HIViewRef ViewLayer::getCreateNodeButton()
{
  return _createNodeButtonRef;
}


HIViewRef ViewLayer::getSeparator()
{
  return _separatorRef;
}


HIViewRef ViewLayer::getCreateReferenceButtonRef()
{
  return _createReferenceButtonRef;      
}


HIViewRef ViewLayer::getInstanceModeButtonRef()
{
  return _instanceModeButtonRef;
}


HIViewRef ViewLayer::getConceptModeButtonRef()
{
  return _conceptModeButtonRef;
}


void ViewLayer::constructSpace()
{
  _space = new renderer::Space();
  _space->setBackgroundColor(0.5372549f, 0.576470588f, 0.6392156862f, 1.0f);

  short width = _rendererBounds->right - _rendererBounds->left;
  short height = _rendererBounds->bottom - _rendererBounds->top;
  float aspectRatio =  (float) width / (float) height;

  _space->init();
  _space->setDimensions(width, height);
}


void ViewLayer::constructShots(assembly::Assembly& assembly)
{
  _rootScene = new DomainScene(assembly);
  _rootShot = new scenegraph::Shot(*_rootScene, _rootScene->getCamera());
  _currentShot = _rootShot;

  _shots[_rootScene] = _rootShot;

  _headsUpScene = new HeadsUpScene();
  _headsUpShot = new scenegraph::Shot(*_headsUpScene, _headsUpScene->getCamera());
  _headsUpShot->setDepthCulling(false);
  _headsUpShot->setRenderable(true);
  _headsUpShot->setSelectable(true);

  _space->addShot(*_headsUpShot);
  _space->addShot(*_rootShot);

  typedef DomainScene::DomainNodeIteratorType DPIterType;
  for (DPIterType iter = _rootScene->getDomainNodes(); iter.hasNext(); ) {
    DomainNode& domainNode = iter.next();
    LayeredScene& scene = domainNode.getLayeredScene();
    scenegraph::Shot& shot = domainNode.getShot();
    shot.setFrontFaceCull(true);

    _layeredShots.insert(&shot);
    _shots[&scene] = &shot;

    _zoomInTransitions[&shot] =
      new fx::Transition(300000.0f, *_rootShot, shot);
    _zoomOutTransitions[&shot] =
      new fx::Transition(300000.0f, shot, *_rootShot);

    shot.setRenderable(false);
    _space->addShot(shot);
  }
 
 _geometryScene = new EditGeometryScene();
  _geometryShot = new scenegraph::Shot(*_geometryScene,
				     _geometryScene->getCamera());
  _shots[_geometryScene] = _geometryShot;
  _geometryShot->setRenderable(false);
  _space->addShot(*_geometryShot);

  _dissolveToGeometryScene = new fx::Dissolve(300000.0f);

  int inset = 4;

  //
  //  Rect portRect;
  // GetWindowPortBounds(_windowRef, &portRect);
  //  InvalWindowRect(_windowRef, &portRect);

  //  resize(_rendererBounds->left, _rendererBounds->top,
  //	 _rendererBounds->right, _rendererBounds->bottom);



  swapRendererPortsAndDisplay();

  /*
  short paneWidth = right - left;
  short paneHeight = bottom - top;
  int placardHeight = paneHeight - inset;
  //  _graphPane = new osx::Pane(*_space, 0, 0, paneWidth, placardHeight);

  add(*_graphPane);
  _graphPane->show();
  _graphPane->activate();

  _toolBarPlacard = new ToolBarPlacard(0, placardHeight, paneWidth);

  add(*_toolBarPlacard);
  _toolBarPlacard->show();
  _toolBarPlacard->activate();
  */
  //  _animator = new osx::Animator(*_graphPane);

}


HIViewRef ViewLayer::getConceptTree()
{
  return _conceptTreeRef;
}


void ViewLayer::rendererBoundsChanged()
{
  Rect portRect;
  GetWindowPortBounds(_windowRef, &portRect);
  InvalWindowRect(_windowRef, &portRect);

  resize(_rendererBounds->left, _rendererBounds->top,
	 _rendererBounds->right, _rendererBounds->bottom);

  swapRendererPortsAndDisplay();
}


void ViewLayer::updateRendererMouse()
{
  /*
  Pane* pane = reinterpret_cast <Pane*> (userData);
  GetEventParameter(event,
		    kEventParamMouseLocation,
		    typeQDPoint,
		    NULL,
		    sizeof(::Point),
		    NULL,
		    &(pane->_mousePosition));

  GetWindowBounds(const_cast <WindowRef&> (_windowRef),
		  kWindowContentRgn,
		  &(pane->_windowBounds));

  pane->_mousePosition.h -= pane->_windowBounds.left;
  pane->_mousePosition.v -= pane->_windowBounds.top;

  HIRect bounds;
  HIViewGetBounds(pane->getControlRef(), &bounds);
  HIPoint topLeftPoint;
  topLeftPoint.x = bounds.origin.x;
  topLeftPoint.y = bounds.origin.y;
  HIViewConvertPoint(&topLeftPoint, pane->getControlRef(), NULL);

  pane->_mousePosition.h -= topLeftPoint.x;
  pane->_mousePosition.v -= topLeftPoint.y;

  pane->_mousePosition.v = pane->getControlBounds().bottom - pane->_mousePosition.v;
  pane->getSpace().setMousePosition(pane->_mousePosition.h, pane->_mousePosition.v);
  */
}


void ViewLayer::initRenderer()
{
}


void ViewLayer::display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  _space->display();

  glFlush();
  aglSwapBuffers(_aglContext);
}


void
ViewLayer::resize(short left, short top, short right, short bottom)
{
  aglSetCurrentContext(_aglContext);
  aglUpdateContext(_aglContext);

  short width = right - left;
  short height = bottom - top;
  float aspectRatio =  (float) width / (float) height;

  //  float fieldOfViewY = 45.0f * _model.getSpace().getCurrentShot().getCamera().getZoom();
  //  float fieldOfViewY = 45.0f * _space->getShots().next().getCamera().getZoom();

  float fieldOfViewY = 1;

  Rect portRect;
  GetWindowPortBounds(_windowRef, &portRect);
  short portHeight = portRect.bottom - portRect.top;

  //  GLint bufferRect[4];
  //  bufferRect[0] = _rendererBounds->left; // x
  //  bufferRect[1] = portHeight - _rendererBounds->bottom; // y
  //  bufferRect[2] = _rendererBounds->right - _rendererBounds->left; // width
  //  bufferRect[3] = _rendererBounds->bottom - _rendererBounds->top; // height

  GLint bufferRect[4];
  bufferRect[0] = _separatorPosition + 2; // _rendererBounds->left; // x
  bufferRect[1] = PLACARD_HEIGHT;  // _rendererBounds->top; // y
  bufferRect[2] = _rendererBounds->right - _rendererBounds->left - _separatorPosition - 2 - 2; // width
  bufferRect[3] = _rendererBounds->bottom - _rendererBounds->top - PLACARD_HEIGHT - 50; // height
  aglSetInteger(_aglContext, AGL_BUFFER_RECT, bufferRect);

  aglSetInteger(_aglContext, AGL_BUFFER_RECT, bufferRect);
  aglEnable(_aglContext, AGL_BUFFER_RECT);

  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(fieldOfViewY, aspectRatio, 1.0f, 1000.0f);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  InvalWindowRect(_windowRef, &portRect);
  _space->resize(width, height);

  Rect bounds;
  bounds.left = _separatorPosition + 2;
  bounds.top = 50;
  bounds.right =  _rendererBounds->right - 2;
  bounds.bottom = bounds.top + bufferRect[3];
  SetControlBounds(_renderPaneRef, &bounds);
}


void
ViewLayer::disposeRenderer()
{
  //  _space->dispose();

  aglSetCurrentContext(NULL);
  aglSetDrawable(_aglContext, NULL);

  aglDestroyContext(_aglContext);
  aglDestroyPixelFormat(_aglPixelFormat);

  _aglContext = NULL;
  _aglPixelFormat = NULL;
}


void
ViewLayer::swapRendererPortsAndDisplay()
{
  GrafPtr savedPort;
  GetPort(&savedPort);

  SetPort(GetWindowPort(_windowRef));
  //  aglSetDrawable(_aglContext, GetWindowPort(_windowRef));
  aglSetCurrentContext(_aglContext);

  display();

  Rect portRect;
  GetWindowPortBounds(_windowRef, &portRect);
  InvalWindowRect(_windowRef, &portRect);

  SetPort(savedPort);
}


ViewLayer* ViewLayer::match(HIViewRef control)
{
  typedef std::set <ViewLayer*>::iterator IterType;
  for (IterType iter = allViewLayers.begin(); iter != allViewLayers.end(); iter++) {
    ViewLayer* window = *iter;
    if (window->_conceptTreeRef == control) {
      return window;
    }
  }

  return 0;
}


ViewLayer::ViewLayer()
{
  GDHandle screen = GetMainDevice();
  Rect bounds;
  GetAvailableWindowPositioningBounds(screen, &bounds);
  
  float goldenRatio = 1.61803399;
  float browserWindowWidth = bounds.right / (1 + goldenRatio * goldenRatio);
  float assemblyWindowWidth = bounds.right - browserWindowWidth;
  float firstRowHeight = browserWindowWidth * goldenRatio;

  short left = (short) (bounds.left + browserWindowWidth);
  short top = (short) bounds.top;
  short right = (short) bounds.right;
  short bottom = (short) (bounds.top + firstRowHeight);

  allViewLayers.insert(this);

  _currentViewRef = NULL;
  _currentSupplementViewRef = NULL;
  _separatorPosition = 200;

  constructWindow(left, top, right, bottom);

  constructWebView();

  constructSearchField();
  constructViewControls();
  constructModeControls();

  constructConceptSelectCombo();

  constructConceptTreeView();
  constructInstanceTreeView();
  constructSpatialTreeView();
  constructStatusPlacard();

  constructSeparator();

  constructRenderView();

  constructSelectButton();
  constructNodeCreationButton();
  constructReferenceCreationButton();

  constructInstanceModeButton();
  constructConceptModeButton();
  constructGeometryModeButton();
  constructSearchModeButton();

  constructMoveCameraButton();
  constructPanCameraButton();
  constructTargetCameraButton();
  constructZoomButton();
  constructZoomInButton();
  constructZoomOutButton();

  constructUpLayerButton();
  constructDownLayerButton();

  constructSpace();

  evaluateControlPositions();

  // Don't install standard event handler as it swallows low level mouse events turning them into clicks
  //  InstallStandardEventHandler(GetControlEventTarget(_contentView));
}


void ViewLayer::evaluateControlPositions()
{
  Rect bounds;

  GetWindowBounds(_windowRef, kWindowContentRgn, &bounds);
  short pos = bounds.right - bounds.left - SEARCHFIELD_WIDTH;
  bounds.left = pos;
  bounds.right = pos + SEARCHFIELD_WIDTH;
  bounds.top = 0;
  bounds.bottom = 17;
  SetControlBounds(_searchFieldRef, &bounds);

  GetWindowBounds(_windowRef, kWindowContentRgn, &bounds);
  bounds.left = 0;
  bounds.bottom = bounds.bottom - bounds.top - PLACARD_HEIGHT;
  bounds.top = 50;
  bounds.right = bounds.left + _separatorPosition - 2;
  SetControlBounds(_spatialTreeRef, &bounds);

  GetWindowBounds(_windowRef, kWindowContentRgn, &bounds);
  bounds.left = 0;
  bounds.bottom = bounds.bottom - bounds.top - PLACARD_HEIGHT;
  bounds.top = 50;
  bounds.right = bounds.left + _separatorPosition - 2;
  SetControlBounds(_conceptTreeRef, &bounds);

  GetWindowBounds(_windowRef, kWindowContentRgn, &bounds);
  bounds.left = 0;
  bounds.bottom = bounds.bottom - bounds.top - PLACARD_HEIGHT;
  bounds.top = 50;
  bounds.right = bounds.left + _separatorPosition - 2;
  SetControlBounds(_instanceTreeRef, &bounds);

  GetWindowBounds(_windowRef, kWindowContentRgn, &bounds);
  bounds.left = 0;
  bounds.top = bounds.bottom - bounds.top - PLACARD_HEIGHT;
  bounds.right = bounds.left + 100;
  bounds.bottom = bounds.top + PLACARD_HEIGHT;
  SetControlBounds(_statusPlacardRef, &bounds);

  HIRect hiBounds;
        
  HIViewGetBounds(_contentView, &hiBounds);
  hiBounds.origin.y += 50;
  hiBounds.size.height -= 70;
  HIViewSetFrame(_webViewRef, &hiBounds);

  GetWindowBounds(_windowRef, kWindowContentRgn, _rendererBounds);
  aglSetCurrentContext(_aglContext);

  GLint bufferRect[4];
  bufferRect[0] = _separatorPosition + 2; // _rendererBounds->left; // x
  bufferRect[1] = PLACARD_HEIGHT;  // _rendererBounds->top; // y
  bufferRect[2] = _rendererBounds->right - _rendererBounds->left - _separatorPosition - 2 - 2; // width
  bufferRect[3] = _rendererBounds->bottom - _rendererBounds->top - PLACARD_HEIGHT - 50; // height
  aglSetInteger(_aglContext, AGL_BUFFER_RECT, bufferRect);
}


void ViewLayer::constructWindow(short left,
				short top,
				short right,
				short bottom)
{
  Rect bounds;
  bounds.left = left;
  bounds.right = right;
  bounds.top = 100;
  bounds.bottom = bottom;

  OSStatus err;

  err = CreateNewWindow(kDocumentWindowClass,
			kWindowCloseBoxAttribute |
			kWindowFullZoomAttribute |
			kWindowCollapseBoxAttribute |
			kWindowResizableAttribute |
			kWindowStandardHandlerAttribute |
			kWindowMetalAttribute |
			kWindowCompositingAttribute,
			&bounds ,&_windowRef);

  //  err = CreateNewWindow(kDocumentWindowClass,
  //			kWindowCloseBoxAttribute |
  //		kWindowFullZoomAttribute |
  //		kWindowCollapseBoxAttribute |
  //		kWindowResizableAttribute |
  //		kWindowStandardHandlerAttribute |
  //		kWindowMetalAttribute |
  //		kWindowCompositingAttribute,
  //		&bounds ,&_windowRef);

  err = HIViewFindByID(HIViewGetRoot(_windowRef),
		       kHIViewWindowContentID,
		       &_contentView);
}


Rect& ViewLayer::getRendererBounds()
{
  return *_rendererBounds;
}


void ViewLayer::constructRenderView()
{
  _rendererBounds = new Rect();
  GetWindowBounds(_windowRef, kWindowContentRgn, _rendererBounds);

  short width = _rendererBounds->right - _rendererBounds->left;
  short height = _rendererBounds->bottom - _rendererBounds->top;
  float aspectRatio =  (float) width / (float) height;

  const GLint attrib[] = {AGL_RGBA, AGL_DOUBLEBUFFER,
			  AGL_DEPTH_SIZE, 20,
			  AGL_SAMPLE_BUFFERS_ARB, 1,
			  AGL_NO_RECOVERY, AGL_NONE};

  _aglPixelFormat = aglChoosePixelFormat(NULL, 0, attrib);
  _aglContext = aglCreateContext(_aglPixelFormat, NULL);
  aglSetCurrentContext(_aglContext);

  Rect portRect;
  GetWindowPortBounds(_windowRef, &portRect);

  short portHeight = portRect.bottom - portRect.top;
  short portWidth = portRect.right - portRect.left;

  GLint bufferRect[4];
  bufferRect[0] = _separatorPosition + 2; // _rendererBounds->left; // x
  bufferRect[1] = PLACARD_HEIGHT;  // _rendererBounds->top; // y
  bufferRect[2] = _rendererBounds->right - _rendererBounds->left - _separatorPosition - 2 - 2; // width
  bufferRect[3] = _rendererBounds->bottom - _rendererBounds->top - PLACARD_HEIGHT - 50; // height

  aglSetInteger(_aglContext, AGL_BUFFER_RECT, bufferRect);
  aglEnable(_aglContext, AGL_BUFFER_RECT);

  aglSetDrawable(_aglContext, GetWindowPort(_windowRef));

  //  _space->init();
  //  _space->setDimensions(width, height);




  bufferRect[0] = _separatorPosition + 2; // _rendererBounds->left; // x
  bufferRect[1] = PLACARD_HEIGHT;  // _rendererBounds->top; // y
  bufferRect[2] = _rendererBounds->right - _rendererBounds->left - _separatorPosition - 2 - 2; // width
  bufferRect[3] = _rendererBounds->bottom - _rendererBounds->top - PLACARD_HEIGHT - 50; // height

  Rect bounds;

  bounds.left = _separatorPosition + 2;
  bounds.top = 50;
  bounds.right =  _rendererBounds->right - 2;
  bounds.bottom = bounds.top + bufferRect[3];

  OSStatus result = CreateUserPaneControl(_windowRef,
                                          &bounds,
                                          kControlSupportsFocus,
                                          &_renderPaneRef);

  HIViewAddSubview (_contentView, _separatorRef);
  HIViewSetVisible(_separatorRef, true);
}


void ViewLayer::constructSmallButton(const char* label, HIViewRef& buttonRef, short left, short top)
{
  Rect bounds;

  bounds.left = left;
  bounds.top = top;
  bounds.right = bounds.left + BUTTON_WIDTH;
  bounds.bottom = bounds.top + BUTTON_HEIGHT;

  CFStringRef labelCFSTR = CFStringCreateWithCString(kCFAllocatorDefault, label, kCFStringEncodingMacRoman);
  OSStatus err = CreateBevelButtonControl(_windowRef,
					  &bounds,
					  labelCFSTR,
					  kControlBevelButtonSmallBevel,
					  kControlBehaviorSingleValueMenu,
					  NULL, 0, 0, 0,
					  &buttonRef);
  CFRelease(labelCFSTR);
}


void ViewLayer::constructSelectButton()
{
  constructSmallButton("S", _selectButtonRef, 0, 25);

  HIViewAddSubview(_contentView, _modeControlRef);
  HIViewSetVisible(_modeControlRef, true);
}


void ViewLayer::constructNodeCreationButton()
{
  constructSmallButton("N", _createNodeButtonRef, 25, 25);

  HIViewAddSubview (_contentView, _createNodeButtonRef);
  HIViewSetVisible(_createNodeButtonRef, true);
}


void ViewLayer::constructReferenceCreationButton()
{
  constructSmallButton("R", _createReferenceButtonRef, 50, 25);

  HIViewAddSubview (_contentView, _createReferenceButtonRef);
  HIViewSetVisible(_createReferenceButtonRef, true);
}


void ViewLayer::constructInstanceModeButton()
{
  constructSmallButton("I", _instanceModeButtonRef, 0, 0);

  HIViewAddSubview (_contentView, _instanceModeButtonRef);
  HIViewSetVisible(_instanceModeButtonRef, true);
}


void ViewLayer::constructConceptModeButton()
{
  constructSmallButton("C", _conceptModeButtonRef, 25, 0);

  HIViewAddSubview (_contentView, _conceptModeButtonRef);
  HIViewSetVisible(_conceptModeButtonRef, true);
}


void ViewLayer::constructGeometryModeButton()
{
}


void ViewLayer::constructSearchModeButton()
{
  constructSmallButton("S", _searchModeButtonRef, 50, 0);

  HIViewAddSubview (_contentView, _searchModeButtonRef);
  HIViewSetVisible(_searchModeButtonRef, true);
}


void ViewLayer::constructMoveCameraButton()
{
  constructSmallButton("M", _moveCameraButtonRef, 75, 0);

  HIViewAddSubview (_contentView, _moveCameraButtonRef);
  HIViewSetVisible(_moveCameraButtonRef, true);
}


void ViewLayer::constructPanCameraButton()
{
  constructSmallButton("P", _panCameraButtonRef, 100, 0);

  HIViewAddSubview (_contentView, _panCameraButtonRef);
  HIViewSetVisible(_panCameraButtonRef, true);
}


void ViewLayer::constructTargetCameraButton()
{
  constructSmallButton("T", _targetCameraButtonRef, 125, 0);

  HIViewAddSubview (_contentView, _targetCameraButtonRef);
  HIViewSetVisible(_targetCameraButtonRef, true);
}


void ViewLayer::constructZoomButton()
{
  constructSmallButton("+", _zoomCameraButtonRef, 150, 0);

  HIViewAddSubview (_contentView, _zoomCameraButtonRef);
  HIViewSetVisible(_zoomCameraButtonRef, true);
}


void ViewLayer::constructZoomInButton()
{
  constructSmallButton("+", _zoomInCameraButtonRef, 175, 0);

  HIViewAddSubview (_contentView, _zoomInCameraButtonRef);
  HIViewSetVisible(_zoomInCameraButtonRef, true);
}


void ViewLayer::constructZoomOutButton()
{
  constructSmallButton("-", _zoomOutCameraButtonRef, 200, 0);

  HIViewAddSubview (_contentView, _zoomOutCameraButtonRef);
  HIViewSetVisible(_zoomOutCameraButtonRef, true);
}


void ViewLayer::constructUpLayerButton()
{
  constructSmallButton("U", _upLayerButtonRef, 225, 0);

  HIViewAddSubview (_contentView, _upLayerButtonRef);
  HIViewSetVisible(_upLayerButtonRef, true);
}


void ViewLayer::constructDownLayerButton()
{
  constructSmallButton("D", _downLayerButtonRef, 250, 0);

  HIViewAddSubview (_contentView, _downLayerButtonRef);
  HIViewSetVisible(_downLayerButtonRef, true);
}


void ViewLayer::constructSeparator()
{
  OSStatus err;

  Rect bounds;

  err = GetWindowBounds(_windowRef, kWindowContentRgn, &bounds);

  bounds.left = _separatorPosition - 2;
  bounds.top = 50;
  bounds.right =  _separatorPosition + 2;
  bounds.bottom = bounds.bottom - bounds.top - PLACARD_HEIGHT;

  err = CreateUserPaneControl(_windowRef,
			      &bounds,
			      kControlSupportsEmbedding,
			      &_separatorRef);

  HIViewAddSubview (_contentView, _separatorRef);
  HIViewSetVisible(_separatorRef, true);
}


void ViewLayer::constructStatusPlacard()
{
  Rect bounds;

  GetWindowBounds(_windowRef, kWindowContentRgn, &bounds);

  bounds.left = 0;
  bounds.top = bounds.bottom - bounds.top - PLACARD_HEIGHT;
  bounds.right = bounds.left + 100;
  bounds.bottom = bounds.top + PLACARD_HEIGHT;

  OSStatus err = CreateStaticTextControl(_windowRef,
					 &bounds,
					 CFSTR("Placard Text"),
					 NULL,
					 &_statusPlacardRef);

  ControlSize controlSize;
  controlSize = kControlSizeSmall;
  SetControlData(_statusPlacardRef, 0, kControlSizeTag, sizeof(controlSize), &controlSize);

  HIViewAddSubview(_contentView, _statusPlacardRef);
  HIViewSetVisible(_statusPlacardRef, true);
}


void ViewLayer::constructWebView()
{  
  WebInitForCarbon();
  OSStatus err = HIWebViewCreate(&_webViewRef);
  //  openUrl(_webViewRef, CFSTR("http://protolayer.com"));
  openUrl(_webViewRef, CFSTR("http://www.fox.com/arresteddev/"));
  HIRect bounds;
        
  HIViewGetBounds(_contentView, &bounds);
  bounds.origin.y += 50;
  bounds.size.height -= 70;

  HIViewSetFrame(_webViewRef, &bounds);
}


void ViewLayer::nullifySupplementView()
{
  if (_currentSupplementViewRef != NULL) {
    HIViewRemoveFromSuperview(_currentSupplementViewRef);
    _currentSupplementViewRef = NULL;
  }
}


void ViewLayer::displaySupplementView(HIViewRef view)
{
  if (_currentSupplementViewRef != NULL && _currentSupplementViewRef != view) {
    HIViewRemoveFromSuperview(_currentSupplementViewRef);
  }

  if (_currentSupplementViewRef != view) {
    HIViewAddSubview(_contentView, view);
    HIViewSetVisible(view, true);
    _currentSupplementViewRef = view;
  }
}


void ViewLayer::displaySpatialMode()
{
  aglSetDrawable(_aglContext, GetWindowPort(_windowRef));
  displayMode(_renderViewRef);
  displaySupplementView(_spatialTreeRef);
}


void ViewLayer::displaySearchMode()
{
  aglSetDrawable(_aglContext, NULL);
  displayMode(_webViewRef);
  nullifySupplementView();
}


void ViewLayer::displayInstanceAssemblyMode()
{
  aglSetDrawable(_aglContext, GetWindowPort(_windowRef));
  displayMode(_renderViewRef);
  displaySupplementView(_instanceTreeRef);
}


void ViewLayer::displayConceptAssemblyMode()
{
  aglSetDrawable(_aglContext, GetWindowPort(_windowRef));
  displayMode(_renderViewRef);
  displaySupplementView(_conceptTreeRef);
  display();
  rendererBoundsChanged();
}


void ViewLayer::displayMode(HIViewRef modeView)
{
  if (_currentViewRef != NULL && _currentViewRef != modeView) {
    HIViewRemoveFromSuperview(_currentViewRef);
  }

  if (_currentViewRef != modeView) {
    HIViewAddSubview(_contentView, modeView);
    HIViewSetVisible(modeView, true);
    _currentViewRef = modeView;
  }
}


void ViewLayer::constructSpatialTreeView()
{
  Rect bounds;
  Boolean frameAndFocus = false;
  OSStatus err;

  err = GetWindowBounds(_windowRef, kWindowContentRgn, &bounds);

  bounds.left = 0;
  bounds.bottom = bounds.bottom - bounds.top - PLACARD_HEIGHT;
  bounds.top = 50;
  bounds.right = bounds.left + _separatorPosition - 2;

  err = CreateDataBrowserControl(NULL, &bounds, kDataBrowserListView, &_spatialTreeRef);

  err = SetDataBrowserHasScrollBars (_spatialTreeRef, false, false);





  DataBrowserTableViewColumnID column;
  DataBrowserListViewHeaderDesc description;
  DataBrowserPropertyDesc columnPropertyDescription;

  DataBrowserListViewColumnDesc columnDescription;

  columnDescription.propertyDesc.propertyID = 'ENTI';
  columnDescription.propertyDesc.propertyType = kDataBrowserTextType;
  columnDescription.propertyDesc.propertyFlags = kDataBrowserListViewSelectionColumn;

  columnDescription.headerBtnDesc.version = kDataBrowserLatestCallbacks;
  columnDescription.headerBtnDesc.minimumWidth = 20;
  columnDescription.headerBtnDesc.maximumWidth = 1000;
  columnDescription.headerBtnDesc.titleOffset = 0;
  columnDescription.headerBtnDesc.titleString = CFSTR("Spatials");
  columnDescription.headerBtnDesc.initialOrder = kDataBrowserOrderIncreasing;


  columnDescription.headerBtnDesc.version = kDataBrowserListViewLatestHeaderDesc;
  columnDescription.headerBtnDesc.btnFontStyle.flags = kControlUseFontMask | kControlUseJustMask;

  columnDescription.headerBtnDesc.btnContentInfo.contentType = kControlNoContent;
  columnDescription.headerBtnDesc.btnFontStyle.just = teFlushDefault;
  columnDescription.headerBtnDesc.btnFontStyle.font = kControlFontViewSystemFont;
  columnDescription.headerBtnDesc.btnFontStyle.style = 0;

  columnDescription.headerBtnDesc.titleString = NULL ; // CFSTR( "" );

  err = AddDataBrowserListViewColumn(_spatialTreeRef, &columnDescription, 0); 

  //  err = SetDataBrowserListViewDisclosureColumn(_spatialTreeRef, 'ENTI', true); 
  //  if(err) std::cout << "Error occured setting diclosure column." << std::endl;

  err = SetDataBrowserSelectionFlags(_spatialTreeRef, kDataBrowserSelectOnlyOne); 
  //  if(err) std::cout << "Error occured setting selection flags" << std::endl;
}


void ViewLayer::constructConceptTreeView()
{
  Rect bounds;
  Boolean frameAndFocus = false;
  OSStatus err;

  err = GetWindowBounds(_windowRef, kWindowContentRgn, &bounds);

  bounds.left = 0;
  bounds.bottom = bounds.bottom - bounds.top - PLACARD_HEIGHT;
  bounds.top = 50;
  bounds.right = bounds.left + _separatorPosition - 2;

  err = CreateDataBrowserControl(NULL, &bounds, kDataBrowserListView, &_conceptTreeRef);

  err = SetDataBrowserHasScrollBars (_conceptTreeRef, false, false);




  DataBrowserTableViewColumnID column;
  DataBrowserListViewHeaderDesc description;
  DataBrowserPropertyDesc columnPropertyDescription;

  DataBrowserListViewColumnDesc columnDescription;

  columnDescription.propertyDesc.propertyID = 'ENTI';
  columnDescription.propertyDesc.propertyType = kDataBrowserTextType;
  columnDescription.propertyDesc.propertyFlags = kDataBrowserListViewSelectionColumn;

  columnDescription.headerBtnDesc.version = kDataBrowserLatestCallbacks;
  columnDescription.headerBtnDesc.minimumWidth = 20;
  columnDescription.headerBtnDesc.maximumWidth = 1000;
  columnDescription.headerBtnDesc.titleOffset = 0;
  columnDescription.headerBtnDesc.titleString = CFSTR("Concepts");
  columnDescription.headerBtnDesc.initialOrder = kDataBrowserOrderIncreasing;


  columnDescription.headerBtnDesc.version = kDataBrowserListViewLatestHeaderDesc;
  columnDescription.headerBtnDesc.btnFontStyle.flags = kControlUseFontMask | kControlUseJustMask;

  columnDescription.headerBtnDesc.btnContentInfo.contentType = kControlNoContent;
  columnDescription.headerBtnDesc.btnFontStyle.just = teFlushDefault;
  columnDescription.headerBtnDesc.btnFontStyle.font = kControlFontViewSystemFont;
  columnDescription.headerBtnDesc.btnFontStyle.style = 0;

  columnDescription.headerBtnDesc.titleString = NULL ; // CFSTR( "" );

  err = AddDataBrowserListViewColumn(_conceptTreeRef, &columnDescription, 0); 

  err = SetDataBrowserListViewDisclosureColumn(_conceptTreeRef, 'ENTI', true); 
  // DataBrowserSetMetric(_conceptTreeRef, kDataBrowserMetricDisclosureColumnPerDepthGap, false, 0);

  //Just reset the width with SetDataBrowserTableViewNamedColumnWidth in
  //response to kDataBrowserContainerOpened and kDataBrowserContainerClosed
  //notifications.


  //  if(err) std::cout << "Error occured setting diclosure column." << std::endl;

  err = SetDataBrowserSelectionFlags(_conceptTreeRef, kDataBrowserSelectOnlyOne); 
  //  if(err) std::cout << "Error occured setting selection flags" << std::endl;



}


void ViewLayer::constructInstanceTreeView()
{
  Rect bounds;
  Boolean frameAndFocus = false;
  OSStatus err;

  err = GetWindowBounds(_windowRef, kWindowContentRgn, &bounds);

  bounds.left = 0;
  bounds.bottom = bounds.bottom - bounds.top - PLACARD_HEIGHT;
  bounds.top = 50;
  bounds.right = bounds.left + _separatorPosition - 2;

  err = CreateDataBrowserControl(NULL, &bounds, kDataBrowserListView, &_instanceTreeRef);

  err = SetDataBrowserHasScrollBars (_instanceTreeRef, false, false);






  DataBrowserTableViewColumnID column;
  DataBrowserListViewHeaderDesc description;
  DataBrowserPropertyDesc columnPropertyDescription;

  DataBrowserListViewColumnDesc columnDescription;

  columnDescription.propertyDesc.propertyID = 'ENTI';
  columnDescription.propertyDesc.propertyType = kDataBrowserTextType;
  columnDescription.propertyDesc.propertyFlags = kDataBrowserDefaultPropertyFlags;

  columnDescription.headerBtnDesc.version = kDataBrowserLatestCallbacks;
  columnDescription.headerBtnDesc.minimumWidth = 20;
  columnDescription.headerBtnDesc.maximumWidth = 1000;
  columnDescription.headerBtnDesc.titleOffset = 0;
  columnDescription.headerBtnDesc.titleString = CFSTR("Instances");
  columnDescription.headerBtnDesc.initialOrder = kDataBrowserOrderIncreasing;


  columnDescription.headerBtnDesc.version = kDataBrowserListViewLatestHeaderDesc;
  columnDescription.headerBtnDesc.btnFontStyle.flags = kControlUseFontMask | kControlUseJustMask;

  columnDescription.headerBtnDesc.btnContentInfo.contentType = kControlNoContent;
  columnDescription.headerBtnDesc.btnFontStyle.just = teFlushDefault;
  columnDescription.headerBtnDesc.btnFontStyle.font = kControlFontViewSystemFont;
  columnDescription.headerBtnDesc.btnFontStyle.style = 0;

  columnDescription.headerBtnDesc.titleString = NULL ; // CFSTR( "" );

  err = AddDataBrowserListViewColumn(_instanceTreeRef, &columnDescription, 0); 

  //  err = SetDataBrowserListViewDisclosureColumn(_instanceTreeRef, 'ENTI', true); 
  //  if(err) std::cout << "Error occured setting diclosure column." << std::endl;

  err = SetDataBrowserSelectionFlags(_instanceTreeRef, kDataBrowserSelectOnlyOne); 
  //  if(err) std::cout << "Error occured setting selection flags" << std::endl;


}


void ViewLayer::constructConceptSelectCombo()
{
  Rect popupRect;

  popupRect.left = 100;
  popupRect.top = 23;
  popupRect.right = popupRect.left + 120;
  popupRect.bottom = 100;

  CreatePopupButtonControl(_windowRef, &popupRect, NULL, -12345, true, -1, 0, 0, &_popupControlRef);
 
  HIViewSetVisible(_popupControlRef, true); 
  HIViewAddSubview (_contentView, _popupControlRef);

  ControlSize controlSize;
  controlSize = kControlSizeSmall;
  SetControlData(_popupControlRef, 0, kControlSizeTag, sizeof(controlSize), &controlSize);
  //  SetControlFontSize(_popupControlRef, 0, kControlSizeTag, sizeof(controlSize), &controlSize);

  //  Style outStyle;
  //  SInt16 fontSize;

  //  GetThemeFont(kThemeSmallSystemFont, smSystemScript, NULL, &fontSize, &outStyle);
  //  SetMenuFont(menu, kThemeSmallSystemFont, fontSize);

  //kControlFontSmallSystemFont

  CreateNewMenu(1, kMenuItemAttrDynamic|kMenuItemAttrSectionHeader, &_popupControlMenuRef);

  SetControlData(_popupControlRef, kControlEntireControl, kControlPopupButtonMenuRefTag, sizeof(_popupControlMenuRef), &_popupControlMenuRef);

  //  InstallEventHandler(GetControlEventTarget(_popupControlMenuRef),
  //		      selectButtonHandlerUPP,
  //		      GetEventTypeCount(buttonEventTypes),
  //		      buttonEventTypes,
  //		      reinterpret_cast <void*> (this),
  //		      NULL);

  //  const char* name = domain->getName().c_str();
  //      CFStringRef nameCFSTR = CFStringCreateWithCString(kCFAllocatorDefault, name, kCFStringEncodingMacRoman);
  // status = SetDataBrowserItemDataText(itemData, nameCFSTR);
  // CFRelease(nameCFSTR);

  //  SetControlData(_popupControlRef, 0, kControlPopupButtonMenuRefTag, sizeof(controlSize), &controlSize);

  //SetControlData and  or kControlPopupButtonOwnedMenuRefTag.
}


void ViewLayer::populateConceptSelectCombo(ontology::Ontology& ontology)
{
  typedef ontology::Ontology::Ontology::DomainIteratorType DomainIterType;
  typedef ontology::Ontology::Ontology::TypeIteratorType TypeIterType;

  // To fix for compilation error
  //  for (DomainIterType iterator = ontology.getDomains(); iterator.hasNext(); ) {
  //    ontology::Domain& domain = iterator.next();
  //  for (TypeIterType typeIter = domain.getTypes(); typeIter.hasNext(); ) {
  //    ontology::Type& type = typeIter.next();
  //    CFStringRef nameCFSTR = CFStringCreateWithCString(kCFAllocatorDefault, type.getName().c_str(), kCFStringEncodingMacRoman);
  //    AppendMenuItemTextWithCFString(_popupControlMenuRef, nameCFSTR, 0, 0, NULL);
  //  }
  //}
}


void ViewLayer::constructSearchField()
{
  HIRect rect;

  rect.origin.x = 0;
  rect.origin.y = 0;
  rect.size.width = SEARCHFIELD_WIDTH;
  rect.size.height = 17;

  HISearchFieldCreate(&rect,
		      NULL, // kHISearchFieldAttributesSearchIcon | kHISearchFieldAttributesCancel,
		      NULL,
		      CFSTR(""),
		      &_searchFieldRef);

  ControlSize controlSize;
  controlSize = kControlSizeSmall;
  SetControlData(_searchFieldRef, 0, kControlSizeTag, sizeof(controlSize), &controlSize);

  HIViewSetVisible(_searchFieldRef, true);
  HIViewAddSubview (_contentView, _searchFieldRef);
}


void ViewLayer::constructViewControls()
{
  HIRect rect;

  rect.origin.x = 250;
  rect.origin.y = 25;
  rect.size.width = 100;
  rect.size.height = 17;

  //  HISegmentedViewCreate(&rect, &_viewControlRef);
  //  HISegmentedViewSetSegmentCount(_viewControlRef, 4);

  //  HIViewAddSubview (_contentView, _viewControlRef);
  //  HIViewSetVisible(_viewControlRef, true);

  //  ControlSize controlSize;
  //  controlSize = kControlSizeSmall;
  //  SetControlData(_viewControlRef, 0, kControlSizeTag, sizeof(controlSize), &controlSize);
}


void ViewLayer::constructModeControls()
{
  HIRect rect;

  rect.origin.x = 0;
  rect.origin.y = 0;
  rect.size.width = 100;
  rect.size.height = 17;

  //  HISegmentedViewCreate(&rect, &_modeControlRef);
  //  HISegmentedViewSetSegmentCount(_modeControlRef, 4);

  //  ControlSize controlSize;
  //  controlSize = kControlSizeSmall;
  //  SetControlData(_modeControlRef, 0, kControlSizeTag, sizeof(controlSize), &controlSize);

  //  HIViewAddSubview (_contentView, _modeControlRef);
  //  HIViewSetVisible(_modeControlRef, true);
}


ViewLayer::~ViewLayer()
{
  RemoveEventLoopTimer(_animationTimerRef);
  HIViewRemoveFromSuperview(_webViewRef);
  allViewLayers.erase(this);
}


}


}
